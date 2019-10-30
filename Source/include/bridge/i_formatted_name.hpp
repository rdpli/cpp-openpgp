// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#pragma once

#include <memory>
#include <string>

namespace ProtonMail {

/**ezvcard part */
class IFormattedName {
public:
    virtual ~IFormattedName() {}

    virtual std::string getLanguage() = 0;

    virtual void setLanguage(const std::string & language) = 0;

    virtual std::string getParameter(const std::string & name) = 0;

    virtual std::string getValue() = 0;

    static std::shared_ptr<IFormattedName> create_instance(const std::string & name);
};

}  // namespace ProtonMail
