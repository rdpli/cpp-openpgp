// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#import "PMNEncryptSignPackage+Private.h"
#import "DJIMarshal+Private.h"
#include <cassert>

namespace OBJ_ProtonMail {

auto EncryptSignPackage::toCpp(ObjcType obj) -> CppType
{
    assert(obj);
    return {::djinni::String::toCpp(obj.encrypted),
            ::djinni::String::toCpp(obj.signature)};
}

auto EncryptSignPackage::fromCpp(const CppType& cpp) -> ObjcType
{
    return [[PMNEncryptSignPackage alloc] initWithEncrypted:(::djinni::String::fromCpp(cpp.encrypted))
                                                  signature:(::djinni::String::fromCpp(cpp.signature))];
}

}  // namespace OBJ_ProtonMail
