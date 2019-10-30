// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#include "NativeIPMMimeType.hpp"  // my header
#include "jni_base_h/Marshal.hpp"

namespace ProtonMail {

NativeIPMMimeType::NativeIPMMimeType() : ::djinni::JniInterface<::ProtonMail::IPMMimeType, NativeIPMMimeType>("ch/protonmail/android/utils/nativelib/IPMMimeType$CppProxy") {}

NativeIPMMimeType::~NativeIPMMimeType() = default;


CJNIEXPORT void JNICALL Java_ch_protonmail_android_utils_nativelib_IPMMimeType_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::ProtonMail::IPMMimeType>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jstring JNICALL Java_ch_protonmail_android_utils_nativelib_IPMMimeType_00024CppProxy_native_1getValue(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ProtonMail::IPMMimeType>(nativeRef);
        auto r = ref->getValue();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_ch_protonmail_android_utils_nativelib_IPMMimeType_00024CppProxy_native_1getType(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ProtonMail::IPMMimeType>(nativeRef);
        auto r = ref->getType();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_ch_protonmail_android_utils_nativelib_IPMMimeType_00024CppProxy_native_1getGroup(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ProtonMail::IPMMimeType>(nativeRef);
        auto r = ref->getGroup();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_ch_protonmail_android_utils_nativelib_IPMMimeType_00024CppProxy_native_1setGroup(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_g)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ProtonMail::IPMMimeType>(nativeRef);
        ref->setGroup(::djinni::String::toCpp(jniEnv, j_g));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_ch_protonmail_android_utils_nativelib_IPMMimeType_00024CppProxy_createInstance(JNIEnv* jniEnv, jobject /*this*/, jstring j_type, jstring j_value)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::ProtonMail::IPMMimeType::create_instance(::djinni::String::toCpp(jniEnv, j_type),
                                                            ::djinni::String::toCpp(jniEnv, j_value));
        return ::djinni::release(::ProtonMail::NativeIPMMimeType::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace ProtonMail
