// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#import "PMNOpenPgp+Private.h"
#import "PMNOpenPgp.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "DJIMarshal+Private.h"
#import "PMNAddress+Private.h"
#import "PMNDecryptSignVerify+Private.h"
#import "PMNEncryptPackage+Private.h"
#import "PMNEncryptSignPackage+Private.h"
#import "PMNOpenPgpKey+Private.h"
#include <exception>
#include <stdexcept>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface PMNOpenPgp ()

- (id)initWithCpp:(const std::shared_ptr<::ProtonMail::OpenPgp>&)cppRef;

@end

@implementation PMNOpenPgp {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::ProtonMail::OpenPgp>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::ProtonMail::OpenPgp>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

+ (nullable PMNOpenPgp *)createInstance {
    try {
        auto objcpp_result_ = ::ProtonMail::OpenPgp::create_instance();
        return ::OBJ_ProtonMail::OpenPgp::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nullable PMNOpenPgp *)createInstanceWithAddress:(nonnull PMNAddress *)address {
    try {
        auto objcpp_result_ = ::ProtonMail::OpenPgp::create_instance_with_address(::OBJ_ProtonMail::Address::toCpp(address));
        return ::OBJ_ProtonMail::OpenPgp::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nullable PMNOpenPgp *)createInstanceWithAddresses:(nonnull NSArray<PMNAddress *> *)address {
    try {
        auto objcpp_result_ = ::ProtonMail::OpenPgp::create_instance_with_addresses(::djinni::List<::OBJ_ProtonMail::Address>::toCpp(address));
        return ::OBJ_ProtonMail::OpenPgp::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nonnull NSString *)updateSinglePassphrase:(nonnull NSString *)privateKey
                               oldPassphrase:(nonnull NSString *)oldPassphrase
                               newPassphrase:(nonnull NSString *)newPassphrase {
    try {
        auto objcpp_result_ = ::ProtonMail::OpenPgp::update_single_passphrase(::djinni::String::toCpp(privateKey),
                                                                              ::djinni::String::toCpp(oldPassphrase),
                                                                              ::djinni::String::toCpp(newPassphrase));
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (void)enableDebug:(BOOL)isDebug {
    try {
        ::ProtonMail::OpenPgp::enable_debug(::djinni::Bool::toCpp(isDebug));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (BOOL)checkPassphrase:(nonnull NSString *)privateKey
             passphrase:(nonnull NSString *)passphrase {
    try {
        auto objcpp_result_ = ::ProtonMail::OpenPgp::check_passphrase(::djinni::String::toCpp(privateKey),
                                                                      ::djinni::String::toCpp(passphrase));
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nonnull NSArray<PMNOpenPgpKey *> *)updateKeysPassphrase:(nonnull NSArray<PMNOpenPgpKey *> *)privateKeys
                                             oldPassphrase:(nonnull NSString *)oldPassphrase
                                             newPassphrase:(nonnull NSString *)newPassphrase {
    try {
        auto objcpp_result_ = ::ProtonMail::OpenPgp::update_keys_passphrase(::djinni::List<::OBJ_ProtonMail::OpenPgpKey>::toCpp(privateKeys),
                                                                            ::djinni::String::toCpp(oldPassphrase),
                                                                            ::djinni::String::toCpp(newPassphrase));
        return ::djinni::List<::OBJ_ProtonMail::OpenPgpKey>::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nonnull NSString *)decryptMessageWithAddress:(nonnull PMNAddress *)address
                                    encryptText:(nonnull NSString *)encryptText
                                      passphras:(nonnull NSString *)passphras {
    try {
        auto objcpp_result_ = ::ProtonMail::OpenPgp::decrypt_message_with_address(::OBJ_ProtonMail::Address::toCpp(address),
                                                                                  ::djinni::String::toCpp(encryptText),
                                                                                  ::djinni::String::toCpp(passphras));
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nonnull NSData *)decryptAttachmentWithAddress:(nonnull PMNAddress *)address
                                             key:(nonnull NSData *)key
                                            data:(nonnull NSData *)data
                                       passphras:(nonnull NSString *)passphras {
    try {
        auto objcpp_result_ = ::ProtonMail::OpenPgp::decrypt_attachment_with_address(::OBJ_ProtonMail::Address::toCpp(address),
                                                                                     ::djinni::Binary::toCpp(key),
                                                                                     ::djinni::Binary::toCpp(data),
                                                                                     ::djinni::String::toCpp(passphras));
        return ::djinni::Binary::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nonnull NSData *)randomBits:(int32_t)bits {
    try {
        auto objcpp_result_ = ::ProtonMail::OpenPgp::random_bits(::djinni::I32::toCpp(bits));
        return ::djinni::Binary::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (BOOL)addAddress:(nonnull PMNAddress *)address {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->add_address(::OBJ_ProtonMail::Address::toCpp(address));
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (BOOL)removeAddress:(nonnull NSString *)addressId {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->remove_address(::djinni::String::toCpp(addressId));
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (BOOL)cleanAddresses {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->clean_addresses();
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull PMNOpenPgpKey *)generateKey:(nonnull NSString *)userName
                                domain:(nonnull NSString *)domain
                            passphrase:(nonnull NSString *)passphrase
                                  bits:(int32_t)bits {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->generate_key(::djinni::String::toCpp(userName),
                                                                ::djinni::String::toCpp(domain),
                                                                ::djinni::String::toCpp(passphrase),
                                                                ::djinni::I32::toCpp(bits));
        return ::OBJ_ProtonMail::OpenPgpKey::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)updatePrivateInfo:(nonnull NSString *)privateKey {
    try {
        _cppRefHandle.get()->update_private_info(::djinni::String::toCpp(privateKey));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSString *)encryptMessage:(nonnull NSString *)addressId
                           plainText:(nonnull NSString *)plainText
                           passphras:(nonnull NSString *)passphras {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->encrypt_message(::djinni::String::toCpp(addressId),
                                                                   ::djinni::String::toCpp(plainText),
                                                                   ::djinni::String::toCpp(passphras));
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSString *)encryptMessageSingleKey:(nonnull NSString *)publicKey
                                    plainText:(nonnull NSString *)plainText
                                   privateKey:(nonnull NSString *)privateKey
                                    passphras:(nonnull NSString *)passphras {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->encrypt_message_single_key(::djinni::String::toCpp(publicKey),
                                                                              ::djinni::String::toCpp(plainText),
                                                                              ::djinni::String::toCpp(privateKey),
                                                                              ::djinni::String::toCpp(passphras));
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSString *)decryptMessage:(nonnull NSString *)encryptText
                           passphras:(nonnull NSString *)passphras {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->decrypt_message(::djinni::String::toCpp(encryptText),
                                                                   ::djinni::String::toCpp(passphras));
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSString *)decryptMessageSingleKey:(nonnull NSString *)encryptText
                                   privateKey:(nonnull NSString *)privateKey
                                    passphras:(nonnull NSString *)passphras {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->decrypt_message_single_key(::djinni::String::toCpp(encryptText),
                                                                              ::djinni::String::toCpp(privateKey),
                                                                              ::djinni::String::toCpp(passphras));
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull PMNEncryptSignPackage *)encryptMessageSignExternal:(nonnull NSString *)publicKey
                                                   privateKey:(nonnull NSString *)privateKey
                                                    plainText:(nonnull NSString *)plainText
                                                    passphras:(nonnull NSString *)passphras {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->encrypt_message_sign_external(::djinni::String::toCpp(publicKey),
                                                                                 ::djinni::String::toCpp(privateKey),
                                                                                 ::djinni::String::toCpp(plainText),
                                                                                 ::djinni::String::toCpp(passphras));
        return ::OBJ_ProtonMail::EncryptSignPackage::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull PMNDecryptSignVerify *)decryptMessageVerify:(nonnull NSString *)publicKey
                                            privateKey:(nonnull NSString *)privateKey
                                             passphras:(nonnull NSString *)passphras
                                             encrypted:(nonnull NSString *)encrypted
                                             signature:(nonnull NSString *)signature {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->decrypt_message_verify(::djinni::String::toCpp(publicKey),
                                                                          ::djinni::String::toCpp(privateKey),
                                                                          ::djinni::String::toCpp(passphras),
                                                                          ::djinni::String::toCpp(encrypted),
                                                                          ::djinni::String::toCpp(signature));
        return ::OBJ_ProtonMail::DecryptSignVerify::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSString *)signDetached:(nonnull NSString *)privateKey
                         plainText:(nonnull NSString *)plainText
                         passphras:(nonnull NSString *)passphras {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->sign_detached(::djinni::String::toCpp(privateKey),
                                                                 ::djinni::String::toCpp(plainText),
                                                                 ::djinni::String::toCpp(passphras));
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (BOOL)signDetachedVerify:(nonnull NSString *)publicKey
                 signature:(nonnull NSString *)signature
                 plainText:(nonnull NSString *)plainText {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->sign_detached_verify(::djinni::String::toCpp(publicKey),
                                                                        ::djinni::String::toCpp(signature),
                                                                        ::djinni::String::toCpp(plainText));
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull PMNEncryptPackage *)encryptAttachment:(nonnull NSString *)addressId
                                   unencryptData:(nonnull NSData *)unencryptData
                                        fileName:(nonnull NSString *)fileName
                                       passphras:(nonnull NSString *)passphras {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->encrypt_attachment(::djinni::String::toCpp(addressId),
                                                                      ::djinni::Binary::toCpp(unencryptData),
                                                                      ::djinni::String::toCpp(fileName),
                                                                      ::djinni::String::toCpp(passphras));
        return ::OBJ_ProtonMail::EncryptPackage::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull PMNEncryptPackage *)encryptAttachmentSingleKey:(nonnull NSString *)publicKey
                                            unencryptData:(nonnull NSData *)unencryptData
                                                 fileName:(nonnull NSString *)fileName
                                               privateKey:(nonnull NSString *)privateKey
                                                passphras:(nonnull NSString *)passphras {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->encrypt_attachment_single_key(::djinni::String::toCpp(publicKey),
                                                                                 ::djinni::Binary::toCpp(unencryptData),
                                                                                 ::djinni::String::toCpp(fileName),
                                                                                 ::djinni::String::toCpp(privateKey),
                                                                                 ::djinni::String::toCpp(passphras));
        return ::OBJ_ProtonMail::EncryptPackage::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSData *)decryptAttachment:(nonnull NSData *)key
                                 data:(nonnull NSData *)data
                            passphras:(nonnull NSString *)passphras {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->decrypt_attachment(::djinni::Binary::toCpp(key),
                                                                      ::djinni::Binary::toCpp(data),
                                                                      ::djinni::String::toCpp(passphras));
        return ::djinni::Binary::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSData *)decryptAttachmentSingleKey:(nonnull NSData *)key
                                          data:(nonnull NSData *)data
                                    privateKey:(nonnull NSString *)privateKey
                                     passphras:(nonnull NSString *)passphras {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->decrypt_attachment_single_key(::djinni::Binary::toCpp(key),
                                                                                 ::djinni::Binary::toCpp(data),
                                                                                 ::djinni::String::toCpp(privateKey),
                                                                                 ::djinni::String::toCpp(passphras));
        return ::djinni::Binary::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSData *)decryptAttachmentWithPassword:(nonnull NSData *)key
                                             data:(nonnull NSData *)data
                                         password:(nonnull NSString *)password {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->decrypt_attachment_with_password(::djinni::Binary::toCpp(key),
                                                                                    ::djinni::Binary::toCpp(data),
                                                                                    ::djinni::String::toCpp(password));
        return ::djinni::Binary::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSData *)getPublicKeySessionKey:(nonnull NSData *)keyPackage
                                passphrase:(nonnull NSString *)passphrase {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->get_public_key_session_key(::djinni::Binary::toCpp(keyPackage),
                                                                              ::djinni::String::toCpp(passphrase));
        return ::djinni::Binary::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSData *)getPublicKeySessionKeySingleKey:(nonnull NSData *)keyPackage
                                         privateKey:(nonnull NSString *)privateKey
                                         passphrase:(nonnull NSString *)passphrase {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->get_public_key_session_key_single_key(::djinni::Binary::toCpp(keyPackage),
                                                                                         ::djinni::String::toCpp(privateKey),
                                                                                         ::djinni::String::toCpp(passphrase));
        return ::djinni::Binary::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSData *)getSymmetricSessionKey:(nonnull NSData *)keyPackage
                                  password:(nonnull NSString *)password {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->get_symmetric_session_key(::djinni::Binary::toCpp(keyPackage),
                                                                             ::djinni::String::toCpp(password));
        return ::djinni::Binary::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSData *)getNewPublicKeyPackage:(nonnull NSData *)session
                                 publicKey:(nonnull NSString *)publicKey {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->get_new_public_key_package(::djinni::Binary::toCpp(session),
                                                                              ::djinni::String::toCpp(publicKey));
        return ::djinni::Binary::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSData *)getNewSymmetricKeyPackage:(nonnull NSData *)session
                                     password:(nonnull NSString *)password {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->get_new_symmetric_key_package(::djinni::Binary::toCpp(session),
                                                                                 ::djinni::String::toCpp(password));
        return ::djinni::Binary::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSString *)encryptMessageAes:(nonnull NSString *)plainText
                               password:(nonnull NSString *)password {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->encrypt_message_aes(::djinni::String::toCpp(plainText),
                                                                       ::djinni::String::toCpp(password));
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSString *)decryptMessageAes:(nonnull NSString *)encryptedMessage
                               password:(nonnull NSString *)password {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->decrypt_message_aes(::djinni::String::toCpp(encryptedMessage),
                                                                       ::djinni::String::toCpp(password));
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSString *)encryptMailboxPwd:(nonnull NSString *)unencryptedPwd
                                   salt:(nonnull NSString *)salt {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->encrypt_mailbox_pwd(::djinni::String::toCpp(unencryptedPwd),
                                                                       ::djinni::String::toCpp(salt));
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSString *)decryptMailboxPwd:(nonnull NSString *)encryptedPwd
                                   salt:(nonnull NSString *)salt {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->decrypt_mailbox_pwd(::djinni::String::toCpp(encryptedPwd),
                                                                       ::djinni::String::toCpp(salt));
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSString *)readClearsignedMessage:(nonnull NSString *)signedMessage {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->read_clearsigned_message(::djinni::String::toCpp(signedMessage));
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (int32_t)throwAnException {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->throw_an_exception();
        return ::djinni::I32::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSString *)encryptHashCbc:(nonnull NSString *)plainText
                            password:(nonnull NSString *)password {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->encrypt_hash_cbc(::djinni::String::toCpp(plainText),
                                                                    ::djinni::String::toCpp(password));
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSString *)decryptHashCbc:(nonnull NSString *)encryptedText
                            password:(nonnull NSString *)password {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->decrypt_hash_cbc(::djinni::String::toCpp(encryptedText),
                                                                    ::djinni::String::toCpp(password));
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace OBJ_ProtonMail {

auto OpenPgp::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto OpenPgp::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<PMNOpenPgp>(cpp);
}

}  // namespace OBJ_ProtonMail

@end
