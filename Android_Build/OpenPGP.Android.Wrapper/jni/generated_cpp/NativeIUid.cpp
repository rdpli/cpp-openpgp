// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#include "NativeIUid.hpp"  // my header
#include "jni_base_h/Marshal.hpp"

namespace ProtonMail {

NativeIUid::NativeIUid() : ::djinni::JniInterface<::ProtonMail::IUid, NativeIUid>("ch/protonmail/android/utils/nativelib/IUid$CppProxy") {}

NativeIUid::~NativeIUid() = default;


CJNIEXPORT void JNICALL Java_ch_protonmail_android_utils_nativelib_IUid_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::ProtonMail::IUid>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jstring JNICALL Java_ch_protonmail_android_utils_nativelib_IUid_00024CppProxy_native_1getValue(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ProtonMail::IUid>(nativeRef);
        auto r = ref->getValue();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_ch_protonmail_android_utils_nativelib_IUid_00024CppProxy_createInstance(JNIEnv* jniEnv, jobject /*this*/, jstring j_uuid)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::ProtonMail::IUid::create_instance(::djinni::String::toCpp(jniEnv, j_uuid));
        return ::djinni::release(::ProtonMail::NativeIUid::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace ProtonMail
