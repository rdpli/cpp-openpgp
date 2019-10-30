// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#include "bridge/i_v_card.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class PMNIVCard;

namespace OBJ_ProtonMail {

class IVCard
{
public:
    using CppType = std::shared_ptr<::ProtonMail::IVCard>;
    using CppOptType = std::shared_ptr<::ProtonMail::IVCard>;
    using ObjcType = PMNIVCard*;

    using Boxed = IVCard;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace OBJ_ProtonMail

