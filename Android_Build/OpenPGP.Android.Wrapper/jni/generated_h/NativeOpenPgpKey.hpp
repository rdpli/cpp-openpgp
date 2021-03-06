// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#pragma once

#include "bridge/open_pgp_key.hpp"
#include "jni_base_h/djinni_support.hpp"

namespace ProtonMail {

class NativeOpenPgpKey final {
public:
    using CppType = ::ProtonMail::OpenPgpKey;
    using JniType = jobject;

    using Boxed = NativeOpenPgpKey;

    ~NativeOpenPgpKey();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    NativeOpenPgpKey();
    friend ::djinni::JniClass<NativeOpenPgpKey>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("ch/protonmail/android/utils/nativelib/OpenPgpKey") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Z)V") };
    const jfieldID field_mKeyId { ::djinni::jniGetFieldID(clazz.get(), "mKeyId", "Ljava/lang/String;") };
    const jfieldID field_mPublicKey { ::djinni::jniGetFieldID(clazz.get(), "mPublicKey", "Ljava/lang/String;") };
    const jfieldID field_mPrivateKey { ::djinni::jniGetFieldID(clazz.get(), "mPrivateKey", "Ljava/lang/String;") };
    const jfieldID field_mFingerPrint { ::djinni::jniGetFieldID(clazz.get(), "mFingerPrint", "Ljava/lang/String;") };
    const jfieldID field_mIsUpdated { ::djinni::jniGetFieldID(clazz.get(), "mIsUpdated", "Z") };
};

}  // namespace ProtonMail
