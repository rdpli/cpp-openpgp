// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#include "NativeDecryptSignVerify.hpp"  // my header
#include "jni_base_h/Marshal.hpp"

namespace ProtonMail {

NativeDecryptSignVerify::NativeDecryptSignVerify() = default;

NativeDecryptSignVerify::~NativeDecryptSignVerify() = default;

auto NativeDecryptSignVerify::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<NativeDecryptSignVerify>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.plain_text)),
                                                           ::djinni::get(::djinni::Bool::fromCpp(jniEnv, c.verify)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto NativeDecryptSignVerify::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 3);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<NativeDecryptSignVerify>::get();
    return {::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_mPlainText)),
            ::djinni::Bool::toCpp(jniEnv, jniEnv->GetBooleanField(j, data.field_mVerify))};
}

}  // namespace ProtonMail