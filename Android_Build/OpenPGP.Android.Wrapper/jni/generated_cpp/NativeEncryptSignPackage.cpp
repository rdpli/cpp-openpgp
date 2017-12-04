// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#include "NativeEncryptSignPackage.hpp"  // my header
#include "jni_base_h/Marshal.hpp"

namespace ProtonMail {

NativeEncryptSignPackage::NativeEncryptSignPackage() = default;

NativeEncryptSignPackage::~NativeEncryptSignPackage() = default;

auto NativeEncryptSignPackage::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<NativeEncryptSignPackage>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.encrypted)),
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.signature)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto NativeEncryptSignPackage::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 3);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<NativeEncryptSignPackage>::get();
    return {::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_mEncrypted)),
            ::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_mSignature))};
}

}  // namespace ProtonMail