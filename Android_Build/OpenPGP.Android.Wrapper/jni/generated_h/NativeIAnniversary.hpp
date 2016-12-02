// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#pragma once

#include "bridge/i_anniversary.hpp"
#include "jni_base_h/djinni_support.hpp"

namespace ProtonMail {

class NativeIAnniversary final : ::djinni::JniInterface<::ProtonMail::IAnniversary, NativeIAnniversary> {
public:
    using CppType = std::shared_ptr<::ProtonMail::IAnniversary>;
    using CppOptType = std::shared_ptr<::ProtonMail::IAnniversary>;
    using JniType = jobject;

    using Boxed = NativeIAnniversary;

    ~NativeIAnniversary();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeIAnniversary>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeIAnniversary>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeIAnniversary();
    friend ::djinni::JniClass<NativeIAnniversary>;
    friend ::djinni::JniInterface<::ProtonMail::IAnniversary, NativeIAnniversary>;

};

}  // namespace ProtonMail
