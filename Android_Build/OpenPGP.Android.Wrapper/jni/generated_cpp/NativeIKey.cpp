// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#include "NativeIKey.hpp"  // my header
#include "jni_base_h/Marshal.hpp"

namespace ProtonMail {

NativeIKey::NativeIKey() : ::djinni::JniInterface<::ProtonMail::IKey, NativeIKey>("ch/protonmail/android/utils/nativelib/IKey$CppProxy") {}

NativeIKey::~NativeIKey() = default;


CJNIEXPORT void JNICALL Java_ch_protonmail_android_utils_nativelib_IKey_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::ProtonMail::IKey>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jstring JNICALL Java_ch_protonmail_android_utils_nativelib_IKey_00024CppProxy_native_1getText(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ProtonMail::IKey>(nativeRef);
        auto r = ref->getText();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_ch_protonmail_android_utils_nativelib_IKey_00024CppProxy_native_1setText(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_text)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ProtonMail::IKey>(nativeRef);
        ref->setText(::djinni::String::toCpp(jniEnv, j_text));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jbyteArray JNICALL Java_ch_protonmail_android_utils_nativelib_IKey_00024CppProxy_native_1getBinary(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ProtonMail::IKey>(nativeRef);
        auto r = ref->getBinary();
        return ::djinni::release(::djinni::Binary::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_ch_protonmail_android_utils_nativelib_IKey_00024CppProxy_native_1setBinary(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jbyteArray j_data)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ProtonMail::IKey>(nativeRef);
        ref->setBinary(::djinni::Binary::toCpp(jniEnv, j_data));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jstring JNICALL Java_ch_protonmail_android_utils_nativelib_IKey_00024CppProxy_native_1getGroup(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ProtonMail::IKey>(nativeRef);
        auto r = ref->getGroup();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_ch_protonmail_android_utils_nativelib_IKey_00024CppProxy_native_1setGroup(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_g)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ProtonMail::IKey>(nativeRef);
        ref->setGroup(::djinni::String::toCpp(jniEnv, j_g));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jint JNICALL Java_ch_protonmail_android_utils_nativelib_IKey_00024CppProxy_native_1getPref(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ProtonMail::IKey>(nativeRef);
        auto r = ref->getPref();
        return ::djinni::release(::djinni::I32::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_ch_protonmail_android_utils_nativelib_IKey_00024CppProxy_native_1setPref(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jint j_pref)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ProtonMail::IKey>(nativeRef);
        ref->setPref(::djinni::I32::toCpp(jniEnv, j_pref));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

}  // namespace ProtonMail
