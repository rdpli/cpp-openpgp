// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#include "bridge/i_p_m_custom.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class PMNIPMCustom;

namespace OBJ_ProtonMail {

class IPMCustom
{
public:
    using CppType = std::shared_ptr<::ProtonMail::IPMCustom>;
    using CppOptType = std::shared_ptr<::ProtonMail::IPMCustom>;
    using ObjcType = PMNIPMCustom*;

    using Boxed = IPMCustom;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace OBJ_ProtonMail

