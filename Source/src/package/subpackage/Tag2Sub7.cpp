#include <package/subpackage/Tag2Sub7.h>

Tag2Sub7::Tag2Sub7():
    Tag2Subpacket(7, 1),
    revocable()
{}

Tag2Sub7::Tag2Sub7(std::string & data):
    Tag2Sub7()
{
    read(data);
}

void Tag2Sub7::read(std::string & data){
    revocable = data[0];
    if (get_is_debug()) {
        std::cout << "Tag2Sub7:" << hexlify(revocable) << std::endl;
    }
}

std::string Tag2Sub7::show(const uint8_t indents, const uint8_t indent_size) const{
    unsigned int tab = indents * indent_size;
    return std::string(tab, ' ') + show_title() + "\n" + std::string(tab, ' ') + std::string("            Revocable: ") + (revocable?"True":"False");
}

std::string Tag2Sub7::raw() const{
    return (revocable?"\x01":zero);
}

bool Tag2Sub7::get_revocable() const{
    return revocable;
}

void Tag2Sub7::set_revocable(const bool r){
    revocable = r;
}

Tag2Subpacket::Ptr Tag2Sub7::clone() const{
    return std::make_shared <Tag2Sub7> (*this);
}
