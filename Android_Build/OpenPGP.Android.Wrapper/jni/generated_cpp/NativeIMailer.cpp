// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#include "NativeIMailer.hpp"  // my header

namespace ProtonMail {

NativeIMailer::NativeIMailer() : ::djinni::JniInterface<::ProtonMail::IMailer, NativeIMailer>("ch/protonmail/android/utils/nativelib/IMailer$CppProxy") {}

NativeIMailer::~NativeIMailer() = default;


CJNIEXPORT void JNICALL Java_ch_protonmail_android_utils_nativelib_IMailer_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::ProtonMail::IMailer>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

}  // namespace ProtonMail