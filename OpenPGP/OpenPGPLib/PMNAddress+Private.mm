// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#import "PMNAddress+Private.h"
#import "DJIMarshal+Private.h"
#import "PMNOpenPgpKey+Private.h"
#include <cassert>

namespace OBJ_ProtonMail {

auto Address::toCpp(ObjcType obj) -> CppType
{
    assert(obj);
    return {::djinni::String::toCpp(obj.addressId),
            ::djinni::String::toCpp(obj.addressName),
            ::djinni::List<::OBJ_ProtonMail::OpenPgpKey>::toCpp(obj.keys)};
}

auto Address::fromCpp(const CppType& cpp) -> ObjcType
{
    return [[PMNAddress alloc] initWithAddressId:(::djinni::String::fromCpp(cpp.address_id))
                                     addressName:(::djinni::String::fromCpp(cpp.address_name))
                                            keys:(::djinni::List<::OBJ_ProtonMail::OpenPgpKey>::fromCpp(cpp.keys))];
}

}  // namespace OBJ_ProtonMail
