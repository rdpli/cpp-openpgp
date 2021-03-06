// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#import "PMNIPhoto+Private.h"
#import "PMNIPhoto.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "DJIMarshal+Private.h"
#include <exception>
#include <stdexcept>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface PMNIPhoto ()

- (id)initWithCpp:(const std::shared_ptr<::ProtonMail::IPhoto>&)cppRef;

@end

@implementation PMNIPhoto {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::ProtonMail::IPhoto>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::ProtonMail::IPhoto>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

+ (nullable PMNIPhoto *)createInstance:(nonnull NSData *)rawData
                                  type:(nonnull NSString *)type
                              isBinary:(BOOL)isBinary {
    try {
        auto objcpp_result_ = ::ProtonMail::IPhoto::create_instance(::djinni::Binary::toCpp(rawData),
                                                                    ::djinni::String::toCpp(type),
                                                                    ::djinni::Bool::toCpp(isBinary));
        return ::OBJ_ProtonMail::IPhoto::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSString *)getEncodedData {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getEncodedData();
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSData *)getRawData {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getRawData();
        return ::djinni::Binary::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSString *)getURL {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getURL();
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSString *)getImageType {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getImageType();
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (BOOL)getIsBinary {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->getIsBinary();
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)setPhoto:(nonnull NSData *)rawData
            type:(nonnull NSString *)type
        isBinary:(BOOL)isBinary {
    try {
        _cppRefHandle.get()->setPhoto(::djinni::Binary::toCpp(rawData),
                                      ::djinni::String::toCpp(type),
                                      ::djinni::Bool::toCpp(isBinary));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace OBJ_ProtonMail {

auto IPhoto::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto IPhoto::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<PMNIPhoto>(cpp);
}

}  // namespace OBJ_ProtonMail

@end
