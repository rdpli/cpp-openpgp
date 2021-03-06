// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#include "bridge/i_email.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class PMNIEmail;

namespace OBJ_ProtonMail {

class IEmail
{
public:
    using CppType = std::shared_ptr<::ProtonMail::IEmail>;
    using CppOptType = std::shared_ptr<::ProtonMail::IEmail>;
    using ObjcType = PMNIEmail*;

    using Boxed = IEmail;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace OBJ_ProtonMail

