// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#pragma once

#include "bridge/i_nickname.hpp"
#include "jni_base_h/djinni_support.hpp"

namespace ProtonMail {

class NativeINickname final : ::djinni::JniInterface<::ProtonMail::INickname, NativeINickname> {
public:
    using CppType = std::shared_ptr<::ProtonMail::INickname>;
    using CppOptType = std::shared_ptr<::ProtonMail::INickname>;
    using JniType = jobject;

    using Boxed = NativeINickname;

    ~NativeINickname();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeINickname>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeINickname>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeINickname();
    friend ::djinni::JniClass<NativeINickname>;
    friend ::djinni::JniInterface<::ProtonMail::INickname, NativeINickname>;

};

}  // namespace ProtonMail
