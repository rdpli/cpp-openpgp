// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#pragma once

#include "bridge/decrypt_sign_verify.hpp"
#include "jni_base_h/djinni_support.hpp"

namespace ProtonMail {

class NativeDecryptSignVerify final {
public:
    using CppType = ::ProtonMail::DecryptSignVerify;
    using JniType = jobject;

    using Boxed = NativeDecryptSignVerify;

    ~NativeDecryptSignVerify();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    NativeDecryptSignVerify();
    friend ::djinni::JniClass<NativeDecryptSignVerify>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("ch/protonmail/android/utils/nativelib/DecryptSignVerify") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(Ljava/lang/String;Z)V") };
    const jfieldID field_mPlainText { ::djinni::jniGetFieldID(clazz.get(), "mPlainText", "Ljava/lang/String;") };
    const jfieldID field_mVerify { ::djinni::jniGetFieldID(clazz.get(), "mVerify", "Z") };
};

}  // namespace ProtonMail
