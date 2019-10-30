// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#import "PMNINickname+Private.h"
#import "PMNINickname.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "DJIMarshal+Private.h"
#include <exception>
#include <stdexcept>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface PMNINickname ()

- (id)initWithCpp:(const std::shared_ptr<::ProtonMail::INickname>&)cppRef;

@end

@implementation PMNINickname {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::ProtonMail::INickname>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::ProtonMail::INickname>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

- (nonnull NSString *)getNickname {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getNickname();
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSString *)getType {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getType();
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSArray<NSString *> *)getValues {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getValues();
        return ::djinni::List<::djinni::String>::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nullable PMNINickname *)createInstance:(nonnull NSString *)type
                                    value:(nonnull NSString *)value {
    try {
        auto objcpp_result_ = ::ProtonMail::INickname::create_instance(::djinni::String::toCpp(type),
                                                                       ::djinni::String::toCpp(value));
        return ::OBJ_ProtonMail::INickname::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace OBJ_ProtonMail {

auto INickname::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto INickname::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<PMNINickname>(cpp);
}

}  // namespace OBJ_ProtonMail

@end
