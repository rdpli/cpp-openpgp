//
//  pgp.cpp
//  UNNetPGP
//
//  Created by Yanfeng Zhang on 1/21/15.
//
//  The MIT License
// 
//  Copyright (c) 2019 Proton Technologies AG
// 
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
// 
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
// 
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.


#include <openpgp/pgp.h>
#include <package/packets.h>

std::string PGP::format_string(std::string data, uint8_t line_length) const{
    std::string out = "";
    for(unsigned int i = 0; i < data.size(); i += line_length){
        out += data.substr(i, line_length) + "\n";
    }
    return out;
}

PGP::PGP():
armored(true),
ASCII_Armor(255), // default uint8_t(-1); use 255 to avoid compiler complaints
Armor_Header(),
packets()
{}

PGP::PGP(const PGP & copy):
armored(copy.armored),
ASCII_Armor(copy.ASCII_Armor),
Armor_Header(copy.Armor_Header),
packets(copy.get_packets_clone())
{}

PGP::PGP(std::string & data, bool isRaw):
PGP()
{
    if (isRaw)
    {
        read_raw(data);
    }
    else
    {
        read(data);
    }
}

PGP::PGP(std::ifstream & f):
PGP()
{
    read(f);
}

PGP::~PGP(){
   packets.clear();
}

void PGP::read(std::string & data){
    std::string ori = data;
    
    // remove extra data and parse unsecured data
    unsigned int x = 0;
    
    // find and remove header
    while ((x < data.size()) && (data.substr(x, 15) != "-----BEGIN PGP ")){
        x++;
    }
    data = data.substr(x, data.size() - x);
    
    // remove carriage returns
    unsigned int y = 0;
    while (y < data.size()){
        if (data[y] == '\r'){
            data.replace(y, 1, "");
        }
        else{
            y++;
        }
    }
    
    // find type of PGP block
    for(x = 0; x < ASCII_ARMOR::MAX; x++) {
        auto armor = ASCII_ARMOR(x);
        std::string match = "-----BEGIN PGP " + toString(armor) + "-----";
        if (match == data.substr(0, match.size())){
            break;
        }
    }
    
    // no ASCII Armor header found
    if (x > 6){
        //std::cerr << "Warning: Beginning of Armor Header Line not found. Will attempt to read raw file data." << std::endl;
        read_raw(ori);
        return;
    }
    
    // Cleartext Signature Framework
    if (x == 6){
        throw std::runtime_error("Error: Data contains message section. Use PGPCleartextSignature to parse this data.");
    }
    
    if (ASCII_Armor != 255){ // if an ASCII Armor header was set (by a child class)
        if (ASCII_Armor != x){ // check if the parsed data is the same type
            std::cerr << "Warning: ASCII Armor does not match data type." << std::endl;
        }
    }
    
    ASCII_Armor = x;
    
    // remove newline after header
    x = 0;
    while ((x < data.size()) && data.substr(x, 1) != "\n"){
        x++;
    }
    if (x == data.size()){
        throw std::runtime_error("Error: End to Armor Header Line not found.");
    }
    
    data = data.substr(x + 1, data.size() - x - 1);
    
    // find header keys
     x = 0;
    if (data.substr(x, 1) == "\n") {
        x --;
    } else {
        while ((x < data.size()) && (data.substr(x, 2) != "\n\n")){
            x++;
        }
    }
    
    std::string header_keys = data.substr(0, (++x)++);
    
    // remove header keys + empty line
    data = data.substr(x, data.size() - x);
    
    // parse Armor Key
    while (header_keys.size()){
        x = 6;
        while ((x < header_keys.size()) && (header_keys[x] != '\n')){
            x++;
        }
        
        // find colon ':'
        unsigned int y = 0;
        while (header_keys[y] != ':') y++;
        std::string header = header_keys.substr(0, y);
        
        Armor_Header.push_back(std::pair <std::string, std::string>(header, header_keys.substr(y + 1, x - y - 1)));
        
        bool found = false;
        for(unsigned int i = 0; i < 5; i++){
            if (header == ASCII_Armor_Key[i]){
                found = true;
                break;
            }
        }
        
        if (!found){
            std::cerr << "Warning: Unknown ASCII Armor Header Key \"" << header << "\"." << std::endl;
        }
        
        x++;
        header_keys = header_keys.substr(x, header_keys.size() - x);
    }
    
    // remove tail
    x = 0;
    while ((x < data.size()) && (data.substr(x, 13) != "-----END PGP ")){
        x++;
    }
    data = data.substr(0, x);
    
    // remove newlines
    y = 0;
    while (y < data.size()){
        if (data[y] == '\n'){
            data.replace(y, 1, "");
        }
        else{
            y++;
        }
    }
    
    // check for a checksum
    if (data[data.size() - 5] == '='){
        uint32_t checksum = (uint32_t)toint(radix642ascii(data.substr(data.size() - 4, 4)), 256);
        data = radix642ascii(data.substr(0, data.size() - 5));
        // check if the checksum is correct
        if (crc24(data) != checksum){
            std::cerr << "Warning: Given checksum does not match calculated value." << std::endl;
        }
    }
    else{
        data = radix642ascii(data);
        std::cerr << "Warning: No checksum found." << std::endl;
    }
    // //////////////////////////////////////////////////////////////////////////////////////////
    read_raw(data);
    armored = true;
}

void PGP::read(std::ifstream & file){
    std::stringstream s;
    s << file.rdbuf();
    std::string data = s.str();
    read(data);
}

void PGP::read_raw(std::string & data){
    uint8_t partial = 0;
    while (data.size()){
        packets.push_back(read_packet(data, partial));
    }
    
    if (partial){ // last packet must have been a partial packet
        (*(packets.rbegin())) -> set_partial(3); // set last partial packet to partial end
    }
    armored = false;
}

void PGP::read_raw(std::ifstream & file){
    std::stringstream s;
    s << file.rdbuf();
    std::string data = s.str();
    read_raw(data);
}

std::string PGP::show(const uint8_t indents, const uint8_t indent_size) const{
    std::stringstream out;
    for(Packet::Ptr const & p : packets){
        out << p -> show(indents, indent_size) << "\n";
    }
    return out.str();
}

std::string PGP::raw(const uint8_t header, const uint8_t tag) const{
    std::string out = "";
    for(Packet::Ptr const & p : packets){
        if (tag == 255 || p->get_tag() == tag)
            out += p -> write(header);
    }
    return out;
}

std::string PGP::write(const uint8_t armor, const uint8_t header, const uint8_t tag) const{
    std::string packet_string = raw(header);   // raw PGP data = binary, no ASCII headers
  //  std::cout << packet_string << std::endl;
    if ((armor == 1) || (!armor && !armored)){ // if no armor or if default, and not armored
        return packet_string;                  // return raw data
    }
    auto eArmor = ASCII_ARMOR(ASCII_Armor);
    std::string out = "-----BEGIN PGP " + toString(eArmor) + "-----\n";
    for(std::pair <std::string, std::string> const & key : Armor_Header){
        out += key.first + ": " + key.second + "\n";
    }
    out += "\n";
    return out + format_string(ascii2radix64(packet_string), MAX_LINE_LENGTH) + "=" + ascii2radix64(unhexlify(makehex(crc24(packet_string), 6))) +  "\n-----END PGP " + toString(eArmor) + "-----\n";
}


bool PGP::get_armored() const{
    return armored;
}

uint8_t PGP::get_ASCII_Armor() const{
    return ASCII_Armor;
}

std::vector <std::pair <std::string, std::string> > PGP::get_Armor_Header() const{
    return Armor_Header;
}

std::vector <Packet::Ptr> PGP::get_packets() const{
    return packets;
}

void PGP::update_packet(int index, Packet::Ptr ptr)
{
    packets[index] = ptr;
}

std::vector <Packet::Ptr> PGP::get_packets_clone() const{
    std::vector <Packet::Ptr> out;
    for(Packet::Ptr const & p : packets){
        out.push_back(p -> clone());
    }
    return out;
}

void PGP::set_armored(const bool a){
    armored = a;
}

void PGP::set_ASCII_Armor(const uint8_t armor){
    ASCII_Armor = armor;
    armored = true;
}

void PGP::set_Armor_Header(const std::vector <std::pair <std::string, std::string> > & header){
    Armor_Header = header;
}

void PGP::set_packets(const std::vector <Packet::Ptr> & p){
    packets.clear();
    for(Packet::Ptr const & t : p){
        packets.push_back(t -> clone());
    }
}

PGP & PGP::operator=(const PGP & copy){
    armored = copy.armored;
    ASCII_Armor = copy.ASCII_Armor;
    Armor_Header = copy.Armor_Header;
    packets = copy.get_packets_clone();
    return *this;
}
