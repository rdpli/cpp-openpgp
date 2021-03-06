// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#include "NativeIGender.hpp"  // my header
#include "jni_base_h/Marshal.hpp"

namespace ProtonMail {

NativeIGender::NativeIGender() : ::djinni::JniInterface<::ProtonMail::IGender, NativeIGender>("ch/protonmail/android/utils/nativelib/IGender$CppProxy") {}

NativeIGender::~NativeIGender() = default;


CJNIEXPORT void JNICALL Java_ch_protonmail_android_utils_nativelib_IGender_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::ProtonMail::IGender>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jstring JNICALL Java_ch_protonmail_android_utils_nativelib_IGender_00024CppProxy_native_1getGender(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ProtonMail::IGender>(nativeRef);
        auto r = ref->getGender();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_ch_protonmail_android_utils_nativelib_IGender_00024CppProxy_native_1getText(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ProtonMail::IGender>(nativeRef);
        auto r = ref->getText();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_ch_protonmail_android_utils_nativelib_IGender_00024CppProxy_createInstance(JNIEnv* jniEnv, jobject /*this*/, jstring j_sex, jstring j_text)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::ProtonMail::IGender::create_instance(::djinni::String::toCpp(jniEnv, j_sex),
                                                        ::djinni::String::toCpp(jniEnv, j_text));
        return ::djinni::release(::ProtonMail::NativeIGender::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace ProtonMail
