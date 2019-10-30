// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#import "PMNIPMMimeType+Private.h"
#import "PMNIPMMimeType.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "DJIMarshal+Private.h"
#include <exception>
#include <stdexcept>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface PMNIPMMimeType ()

- (id)initWithCpp:(const std::shared_ptr<::ProtonMail::IPMMimeType>&)cppRef;

@end

@implementation PMNIPMMimeType {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::ProtonMail::IPMMimeType>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::ProtonMail::IPMMimeType>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

- (nonnull NSString *)getValue {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getValue();
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSString *)getType {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getType();
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSString *)getGroup {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getGroup();
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)setGroup:(nonnull NSString *)g {
    try {
        _cppRefHandle.get()->setGroup(::djinni::String::toCpp(g));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nullable PMNIPMMimeType *)createInstance:(nonnull NSString *)type
                                      value:(nonnull NSString *)value {
    try {
        auto objcpp_result_ = ::ProtonMail::IPMMimeType::create_instance(::djinni::String::toCpp(type),
                                                                         ::djinni::String::toCpp(value));
        return ::OBJ_ProtonMail::IPMMimeType::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace OBJ_ProtonMail {

auto IPMMimeType::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto IPMMimeType::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<PMNIPMMimeType>(cpp);
}

}  // namespace OBJ_ProtonMail

@end
