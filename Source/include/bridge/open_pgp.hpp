// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace ProtonMail {

struct Address;
struct DecryptSignVerify;
struct EncryptPackage;
struct EncryptSignPackage;
struct OpenPgpKey;

/**
 *open_pgp_key_manager = interface +c {
 *    static create_instance() : open_pgp_key_manager;
 *}
 *generat new key with email address. Fix the UserID issue in protonmail system. on Feb 28, 17
 *static generate_key_with_email(email : string, passphrase : string, bits : i32) : open_pgp_key;
 * generate new key
 *static generate_new_key(user_id : string, email : string, passphrase : string, bits : i32) : open_pgp_key;
 */
class OpenPgp {
public:
    virtual ~OpenPgp() {}

    /**
     * create and init an instance those instance have addresses manager build in
     * if want deal with single key should use the static functions
     */
    static std::shared_ptr<OpenPgp> create_instance();

    /** create and init an instance with addresses */
    static std::shared_ptr<OpenPgp> create_instance_with_address(const Address & address);

    static std::shared_ptr<OpenPgp> create_instance_with_addresses(const std::vector<Address> & address);

    /**update single private key password */
    static std::string update_single_passphrase(const std::string & private_key, const std::string & old_passphrase, const std::string & new_passphrase);

    /**disable/enable debug model */
    static void enable_debug(bool isDebug);

    /**check is private key passphrase ok */
    static bool check_passphrase(const std::string & private_key, const std::string & passphrase);

    /**update multiple pgp private keys return are new keys */
    static std::vector<OpenPgpKey> update_keys_passphrase(const std::vector<OpenPgpKey> & private_keys, const std::string & old_passphrase, const std::string & new_passphrase);

    /**decrypt message use the address key ring with password */
    static std::string decrypt_message_with_address(const Address & address, const std::string & encrypt_text, const std::string & passphras);

    /**decrypt attachment use the address key ring with password */
    static std::vector<uint8_t> decrypt_attachment_with_address(const Address & address, const std::vector<uint8_t> & key, const std::vector<uint8_t> & data, const std::string & passphras);

    /**Random bits */
    static std::vector<uint8_t> random_bits(int32_t bits);

    /**add a new address into addresses list */
    virtual bool add_address(const Address & address) = 0;

    /**remove a exsit address from the list based on address id */
    virtual bool remove_address(const std::string & address_id) = 0;

    /**clean address list */
    virtual bool clean_addresses() = 0;

    /**generat new key pair */
    virtual OpenPgpKey generate_key(const std::string & user_name, const std::string & domain, const std::string & passphrase, int32_t bits, int32_t time) = 0;

    /**
     * old functions blow
     *update the information carried in the packet. //TODO need add more parameters
     */
    virtual void update_private_info(const std::string & private_key) = 0;

    /**encrypt message use address id */
    virtual std::string encrypt_message(const std::string & address_id, const std::string & plain_text, const std::string & passphras, bool trim) = 0;

    /**encrypt message use public key */
    virtual std::string encrypt_message_single_key(const std::string & public_key, const std::string & plain_text, const std::string & private_key, const std::string & passphras, bool trim) = 0;

    virtual std::string encrypt_message_single_binary_pub_key(const std::vector<uint8_t> & public_key, const std::string & plain_text, const std::string & private_key, const std::string & passphras, bool trim) = 0;

    virtual std::string decrypt_message(const std::string & encrypt_text, const std::string & passphras) = 0;

    virtual std::string decrypt_message_single_key(const std::string & encrypt_text, const std::string & private_key, const std::string & passphras) = 0;

    /**for signature */
    virtual EncryptSignPackage encrypt_message_sign_external(const std::string & public_key, const std::string & private_key, const std::string & plain_text, const std::string & passphras) = 0;

    virtual DecryptSignVerify decrypt_message_verify_single_key(const std::string & private_key, const std::string & passphras, const std::string & encrypted, const std::string & signature) = 0;

    virtual DecryptSignVerify decrypt_message_verify(const std::string & passphras, const std::string & encrypted, const std::string & signature) = 0;

    virtual std::string sign_detached(const std::string & private_key, const std::string & plain_text, const std::string & passphras) = 0;

    virtual bool sign_detached_verify_single_pub_key(const std::string & public_key, const std::string & signature, const std::string & plain_text) = 0;

    virtual bool sign_detached_verify_single_binary_pub_key(const std::vector<uint8_t> & public_key, const std::string & signature, const std::string & plain_text) = 0;

    virtual bool sign_detached_verify_single_private_key(const std::string & private_key, const std::string & signature, const std::string & plain_text) = 0;

    virtual bool sign_detached_verify(const std::string & signature, const std::string & plain_text) = 0;

    static bool findKeyid(const std::string & encrypt_text, const std::string & private_key);

    virtual EncryptPackage encrypt_attachment(const std::string & address_id, const std::vector<uint8_t> & unencrypt_data, const std::string & file_name, const std::string & passphras) = 0;

    virtual EncryptPackage encrypt_attachment_single_key(const std::string & public_key, const std::vector<uint8_t> & unencrypt_data, const std::string & file_name, const std::string & private_key, const std::string & passphras) = 0;

    virtual EncryptPackage encrypt_attachment_single_binary_key(const std::vector<uint8_t> & public_key, const std::vector<uint8_t> & unencrypt_data, const std::string & file_name, const std::string & private_key, const std::string & passphras) = 0;

    virtual std::vector<uint8_t> decrypt_attachment(const std::vector<uint8_t> & key, const std::vector<uint8_t> & data, const std::string & passphras) = 0;

    virtual std::vector<uint8_t> decrypt_attachment_single_key(const std::vector<uint8_t> & key, const std::vector<uint8_t> & data, const std::string & private_key, const std::string & passphras) = 0;

    virtual std::vector<uint8_t> decrypt_attachment_with_password(const std::vector<uint8_t> & key, const std::vector<uint8_t> & data, const std::string & password) = 0;

    virtual std::vector<uint8_t> get_public_key_session_key(const std::vector<uint8_t> & keyPackage, const std::string & passphrase) = 0;

    virtual std::vector<uint8_t> get_public_key_session_key_single_key(const std::vector<uint8_t> & keyPackage, const std::string & privateKey, const std::string & passphrase) = 0;

    virtual std::vector<uint8_t> get_symmetric_session_key(const std::vector<uint8_t> & keyPackage, const std::string & password) = 0;

    virtual std::vector<uint8_t> get_new_public_key_package(const std::vector<uint8_t> & session, const std::string & publicKey) = 0;

    virtual std::vector<uint8_t> get_new_public_key_package_binary(const std::vector<uint8_t> & session, const std::vector<uint8_t> & publicKey) = 0;

    virtual std::vector<uint8_t> get_new_symmetric_key_package(const std::vector<uint8_t> & session, const std::string & password) = 0;

    virtual std::string encrypt_message_aes(const std::string & plain_text, const std::string & password) = 0;

    virtual std::string decrypt_message_aes(const std::string & encrypted_message, const std::string & password) = 0;

    virtual std::string encrypt_mailbox_pwd(const std::string & unencrypted_pwd, const std::string & salt) = 0;

    virtual std::string decrypt_mailbox_pwd(const std::string & encrypted_pwd, const std::string & salt) = 0;

    virtual std::string read_clearsigned_message(const std::string & signed_message) = 0;

    static EncryptPackage split_message(const std::string & encrypted);

    static std::string combine_packages(const std::vector<uint8_t> & key, const std::vector<uint8_t> & data);

    /**test functions */
    virtual int32_t throw_an_exception() = 0;

    /**PBE */
    virtual std::string encrypt_hash_cbc(const std::string & plain_text, const std::string & password) = 0;

    virtual std::string decrypt_hash_cbc(const std::string & encrypted_text, const std::string & password) = 0;
};

}  // namespace ProtonMail
