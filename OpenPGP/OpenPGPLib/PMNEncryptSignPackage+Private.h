// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#import "PMNEncryptSignPackage.h"
#include "bridge/encrypt_sign_package.hpp"

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class PMNEncryptSignPackage;

namespace OBJ_ProtonMail {

struct EncryptSignPackage
{
    using CppType = ::ProtonMail::EncryptSignPackage;
    using ObjcType = PMNEncryptSignPackage*;

    using Boxed = EncryptSignPackage;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCpp(const CppType& cpp);
};

}  // namespace OBJ_ProtonMail
