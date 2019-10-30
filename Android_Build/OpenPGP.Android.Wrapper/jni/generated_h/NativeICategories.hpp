// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#pragma once

#include "bridge/i_categories.hpp"
#include "jni_base_h/djinni_support.hpp"

namespace ProtonMail {

class NativeICategories final : ::djinni::JniInterface<::ProtonMail::ICategories, NativeICategories> {
public:
    using CppType = std::shared_ptr<::ProtonMail::ICategories>;
    using CppOptType = std::shared_ptr<::ProtonMail::ICategories>;
    using JniType = jobject;

    using Boxed = NativeICategories;

    ~NativeICategories();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeICategories>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeICategories>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeICategories();
    friend ::djinni::JniClass<NativeICategories>;
    friend ::djinni::JniInterface<::ProtonMail::ICategories, NativeICategories>;

};

}  // namespace ProtonMail