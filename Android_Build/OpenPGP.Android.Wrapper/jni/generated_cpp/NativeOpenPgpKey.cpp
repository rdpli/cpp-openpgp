// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#include "NativeOpenPgpKey.hpp"  // my header
#include "jni_base_h/Marshal.hpp"

namespace ProtonMail {

NativeOpenPgpKey::NativeOpenPgpKey() = default;

NativeOpenPgpKey::~NativeOpenPgpKey() = default;

auto NativeOpenPgpKey::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<NativeOpenPgpKey>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.key_id)),
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.public_key)),
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.private_key)),
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.finger_print)),
                                                           ::djinni::get(::djinni::Bool::fromCpp(jniEnv, c.isUpdated)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto NativeOpenPgpKey::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 6);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<NativeOpenPgpKey>::get();
    return {::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_mKeyId)),
            ::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_mPublicKey)),
            ::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_mPrivateKey)),
            ::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_mFingerPrint)),
            ::djinni::Bool::toCpp(jniEnv, jniEnv->GetBooleanField(j, data.field_mIsUpdated))};
}

}  // namespace ProtonMail
