// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#pragma once

#include <memory>
#include <string>
#include <vector>

namespace ProtonMail {

class IOrganization {
public:
    virtual ~IOrganization() {}

    virtual std::vector<std::string> getValues() = 0;

    virtual std::string getValue() = 0;

    static std::shared_ptr<IOrganization> create_instance(const std::string & type, const std::string & value);
};

}  // namespace ProtonMail
