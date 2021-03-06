// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#include "NativeIAddress.hpp"  // my header
#include "jni_base_h/Marshal.hpp"

namespace ProtonMail {

NativeIAddress::NativeIAddress() : ::djinni::JniInterface<::ProtonMail::IAddress, NativeIAddress>("ch/protonmail/android/utils/nativelib/IAddress$CppProxy") {}

NativeIAddress::~NativeIAddress() = default;


CJNIEXPORT void JNICALL Java_ch_protonmail_android_utils_nativelib_IAddress_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::ProtonMail::IAddress>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jstring JNICALL Java_ch_protonmail_android_utils_nativelib_IAddress_00024CppProxy_native_1getStreetAddress(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ProtonMail::IAddress>(nativeRef);
        auto r = ref->getStreetAddress();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_ch_protonmail_android_utils_nativelib_IAddress_00024CppProxy_native_1getExtendedAddress(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ProtonMail::IAddress>(nativeRef);
        auto r = ref->getExtendedAddress();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_ch_protonmail_android_utils_nativelib_IAddress_00024CppProxy_native_1getLocality(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ProtonMail::IAddress>(nativeRef);
        auto r = ref->getLocality();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_ch_protonmail_android_utils_nativelib_IAddress_00024CppProxy_native_1getRegion(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ProtonMail::IAddress>(nativeRef);
        auto r = ref->getRegion();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_ch_protonmail_android_utils_nativelib_IAddress_00024CppProxy_native_1getPostalCode(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ProtonMail::IAddress>(nativeRef);
        auto r = ref->getPostalCode();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_ch_protonmail_android_utils_nativelib_IAddress_00024CppProxy_native_1getCountry(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ProtonMail::IAddress>(nativeRef);
        auto r = ref->getCountry();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_ch_protonmail_android_utils_nativelib_IAddress_00024CppProxy_native_1getTypes(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ProtonMail::IAddress>(nativeRef);
        auto r = ref->getTypes();
        return ::djinni::release(::djinni::List<::djinni::String>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_ch_protonmail_android_utils_nativelib_IAddress_00024CppProxy_native_1getPoBox(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ProtonMail::IAddress>(nativeRef);
        auto r = ref->getPoBox();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_ch_protonmail_android_utils_nativelib_IAddress_00024CppProxy_native_1getPoBoxes(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ProtonMail::IAddress>(nativeRef);
        auto r = ref->getPoBoxes();
        return ::djinni::release(::djinni::List<::djinni::String>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_ch_protonmail_android_utils_nativelib_IAddress_00024CppProxy_createInstance(JNIEnv* jniEnv, jobject /*this*/, jstring j_type, jstring j_street, jstring j_extendstreet, jstring j_locality, jstring j_region, jstring j_zip, jstring j_country, jstring j_pobox)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::ProtonMail::IAddress::create_instance(::djinni::String::toCpp(jniEnv, j_type),
                                                         ::djinni::String::toCpp(jniEnv, j_street),
                                                         ::djinni::String::toCpp(jniEnv, j_extendstreet),
                                                         ::djinni::String::toCpp(jniEnv, j_locality),
                                                         ::djinni::String::toCpp(jniEnv, j_region),
                                                         ::djinni::String::toCpp(jniEnv, j_zip),
                                                         ::djinni::String::toCpp(jniEnv, j_country),
                                                         ::djinni::String::toCpp(jniEnv, j_pobox));
        return ::djinni::release(::ProtonMail::NativeIAddress::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace ProtonMail
