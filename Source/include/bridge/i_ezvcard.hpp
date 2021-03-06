// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#pragma once

#include <memory>
#include <string>
#include <vector>

namespace ProtonMail {

class IVCard;

class IEzvcard {
public:
    virtual ~IEzvcard() {}

    static std::shared_ptr<IVCard> parse_first(const std::string & value);

    static std::vector<std::shared_ptr<IVCard>> parse_all(const std::string & value);

    static std::string write(const std::shared_ptr<IVCard> & vcard);

    static std::string write_all(const std::vector<std::shared_ptr<IVCard>> & vcards);
};

}  // namespace ProtonMail
