// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#import "PMNOpenPgpKey+Private.h"
#import "DJIMarshal+Private.h"
#include <cassert>

namespace OBJ_ProtonMail {

auto OpenPgpKey::toCpp(ObjcType obj) -> CppType
{
    assert(obj);
    return {::djinni::String::toCpp(obj.keyId),
            ::djinni::String::toCpp(obj.publicKey),
            ::djinni::String::toCpp(obj.privateKey),
            ::djinni::String::toCpp(obj.fingerPrint),
            ::djinni::Bool::toCpp(obj.isUpdated)};
}

auto OpenPgpKey::fromCpp(const CppType& cpp) -> ObjcType
{
    return [[PMNOpenPgpKey alloc] initWithKeyId:(::djinni::String::fromCpp(cpp.key_id))
                                      publicKey:(::djinni::String::fromCpp(cpp.public_key))
                                     privateKey:(::djinni::String::fromCpp(cpp.private_key))
                                    fingerPrint:(::djinni::String::fromCpp(cpp.finger_print))
                                      isUpdated:(::djinni::Bool::fromCpp(cpp.isUpdated))];
}

}  // namespace OBJ_ProtonMail
