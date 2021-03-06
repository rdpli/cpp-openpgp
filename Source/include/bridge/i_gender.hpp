// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#pragma once

#include <memory>
#include <string>

namespace ProtonMail {

class IGender {
public:
    virtual ~IGender() {}

    virtual std::string getGender() = 0;

    virtual std::string getText() = 0;

    static std::shared_ptr<IGender> create_instance(const std::string & sex, const std::string & text);
};

}  // namespace ProtonMail
