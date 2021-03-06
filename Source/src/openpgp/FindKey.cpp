//
//  FindKey.cpp
//  OpenPGP_OSX_Lib
//
//  Created by Yanfeng Zhang on 4/7/15.
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


#include <openpgp/PGPKey.h>
#include <openpgp/FindKey.h>
#include <package/Tag6.h>
#include <package/Tag2.h>
#include <package/Tag5.h>
#include <package/Tag7.h>
#include <package/Tag14.h>

std::ostream & operator<<(std::ostream & stream, const PGPPublicKey & pgp){
    stream << hexlify(pgp.keyid());
    return stream;
}

PGPPublicKey Secret2PublicKey(const PGPSecretKey & pri){
    PGPPublicKey pub;
    pub.set_armored(pri.get_armored());
    pub.set_ASCII_Armor(1); // public key ASCII Armor Header value
    pub.set_Armor_Header(pri.get_Armor_Header());
    
    // clone packets; convert secret packets into public ones
    std::vector <Packet::Ptr> packets;
    for(Packet::Ptr const & p : pri.get_packets()){
        switch (p -> get_tag()){
            case 5:
            {
                std::string data = p -> raw();
                packets.push_back(Tag5(data).get_public_ptr());
                break;
            }
            case 7:
            {
                std::string data = p -> raw();
                packets.push_back(Tag7(data).get_public_ptr());
                break;
            }
            default:
                packets.push_back(p -> clone());
                break;
        }
    }
    pub.set_packets(packets);
    
    for(Packet::Ptr & p : packets){
        p.reset();
    }
    
    return pub;
}

PGPPublicKey::Ptr Secret2PublicKeyPtr(const PGPSecretKey & pri) {
    PGPPublicKey::Ptr pub = std::make_shared<PGPPublicKey>();
    
    pub->set_armored(pri.get_armored());
    pub->set_ASCII_Armor(1); // public key ASCII Armor Header value
    pub->set_Armor_Header(pri.get_Armor_Header());
    
    // clone packets; convert secret packets into public ones
    std::vector <Packet::Ptr> packets;
    for(Packet::Ptr const & p : pri.get_packets()){
        switch (p -> get_tag()){
            case 5:
            {
                std::string data = p -> raw();
                packets.push_back(Tag5(data).get_public_ptr());
                break;
            }
            case 7:
            {
                std::string data = p -> raw();
                packets.push_back(Tag7(data).get_public_ptr());
                break;
            }
            default:
                packets.push_back(p -> clone());
                break;
        }
    }
    pub->set_packets(packets);
    
    for(Packet::Ptr & p : packets){
        p.reset();
    }
    
    return pub;
}

PGPPublicKey::Ptr Secret2PublicKey(const PGPSecretKey::Ptr &pri) {
    PGPPublicKey::Ptr pub = std::make_shared<PGPPublicKey>();
    
    
    pub->set_armored(pri->get_armored());
    pub->set_ASCII_Armor(1); // public key ASCII Armor Header value
    pub->set_Armor_Header(pri->get_Armor_Header());
    
    // clone packets; convert secret packets into public ones
    std::vector <Packet::Ptr> packets;
    for(Packet::Ptr const & p : pri->get_packets()){
        switch (p -> get_tag()){
            case 5:
            {
                std::string data = p -> raw();
                packets.push_back(Tag5(data).get_public_ptr());
                break;
            }
            case 7:
            {
                std::string data = p -> raw();
                packets.push_back(Tag7(data).get_public_ptr());
                break;
            }
            default:
                packets.push_back(p -> clone());
                break;
        }
    }
    pub->set_packets(packets);
    
    for(Packet::Ptr & p : packets){
        p.reset();
    }
    
    return pub;
}

Key::Ptr find_signing_key(const PGPKey::Ptr & key, const uint8_t tag, const std::string & keyid){
    if ((key -> get_ASCII_Armor() == 1) || (key -> get_ASCII_Armor() == 2)){
        std::vector <Packet::Ptr> packets = key -> get_packets();
        for(Packet::Ptr const & p : packets){
            if (p -> get_tag() == tag){
                Key::Ptr signer = nullptr;
                switch (tag){
                    case 5:
                        signer = std::make_shared <Tag5> ();
                        break;
                    case 6:
                        signer = std::make_shared <Tag6> ();
                        break;
                    case 7:
                        signer = std::make_shared <Tag7> ();
                        break;
                    case 14:
                        signer = std::make_shared <Tag14> ();
                        break;
                    default:
                        throw std::runtime_error("Error: Not a key tag.");
                        break;
                }
                
                std::string data = p -> raw();
                signer -> read(data);
                
                // make sure key has signing material
                if ((signer -> get_pka() == 1) || // RSA (Encrypt or Sign)
                    (signer -> get_pka() == 3) || // RSA Sign-Only
                    (signer -> get_pka() == 17)){ // DSA
                    
                    // make sure the keyid matches the given one
                    // expects only full matches
                    if (keyid.size()){
                        if (signer -> get_keyid() == keyid){
                            return signer;
                        }
                        signer.reset();
                    }
                    else{
                        return signer;
                    }
                }
                signer.reset();
            }
        }
    }
    return nullptr;
}

Tag6::Ptr find_signing_key(const PGPPublicKey & key, const uint8_t tag, const std::string & keyid){
    Key::Ptr found = find_signing_key(std::make_shared <PGPKey> (key), tag);
    if (!found){
        return nullptr;
    }
    std::string data = found -> raw();
    return std::make_shared <Tag6> (data);
}

Tag5::Ptr find_signing_key(const PGPSecretKey & key, const uint8_t tag, const std::string & keyid){
    Key::Ptr found = find_signing_key(std::make_shared <PGPKey> (key), tag);
    if (!found){
        return nullptr;
    }
    std::string data = found -> raw();
    return std::make_shared <Tag5> (data);
}
