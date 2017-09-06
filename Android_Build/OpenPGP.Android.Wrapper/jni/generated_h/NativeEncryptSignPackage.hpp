// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#pragma once

#include "bridge/encrypt_sign_package.hpp"
#include "jni_base_h/djinni_support.hpp"

namespace ProtonMail {

class NativeEncryptSignPackage final {
public:
    using CppType = ::ProtonMail::EncryptSignPackage;
    using JniType = jobject;

    using Boxed = NativeEncryptSignPackage;

    ~NativeEncryptSignPackage();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    NativeEncryptSignPackage();
    friend ::djinni::JniClass<NativeEncryptSignPackage>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("ch/protonmail/android/utils/nativelib/EncryptSignPackage") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(Ljava/lang/String;Ljava/lang/String;)V") };
    const jfieldID field_mEncrypted { ::djinni::jniGetFieldID(clazz.get(), "mEncrypted", "Ljava/lang/String;") };
    const jfieldID field_mSignature { ::djinni::jniGetFieldID(clazz.get(), "mSignature", "Ljava/lang/String;") };
};

}  // namespace ProtonMail
