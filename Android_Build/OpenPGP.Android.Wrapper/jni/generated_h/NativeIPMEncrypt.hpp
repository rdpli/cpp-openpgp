// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#pragma once

#include "bridge/i_p_m_encrypt.hpp"
#include "jni_base_h/djinni_support.hpp"

namespace ProtonMail {

class NativeIPMEncrypt final : ::djinni::JniInterface<::ProtonMail::IPMEncrypt, NativeIPMEncrypt> {
public:
    using CppType = std::shared_ptr<::ProtonMail::IPMEncrypt>;
    using CppOptType = std::shared_ptr<::ProtonMail::IPMEncrypt>;
    using JniType = jobject;

    using Boxed = NativeIPMEncrypt;

    ~NativeIPMEncrypt();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeIPMEncrypt>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeIPMEncrypt>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeIPMEncrypt();
    friend ::djinni::JniClass<NativeIPMEncrypt>;
    friend ::djinni::JniInterface<::ProtonMail::IPMEncrypt, NativeIPMEncrypt>;

};

}  // namespace ProtonMail
