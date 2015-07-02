#include "StdAfx.h"
#include "openpgp_wrapper.h"
#include <stdio.h>
#include <stdlib.h>


#include <openpgp/openpgp.h>
#include <openpgp/PMPGPMessage.h>
#include <openpgp/PGPMessage.h>
#include <utilities/utility.h>
#include <utilities/utilities.h>
#include <openpgp/private_key.h>
#include <openpgp/encrypt.h>
#include <openpgp/decrypt.h>

#include <utilities/utilities.h>
#include <utilities/includes.h>
#include <utilities/BBS.h>
#include <utilities/base64.h>
#include <hash/Hash.h>

#include <encryption/AES.h>

extern "C" {

JNIEXPORT jint JNICALL
Java_ch_protonmail_android_utils_OpenPGP_test1(JNIEnv* env, jobject o, jint x, jint y)
{
	return 100000;
}
//

JNIEXPORT jstring JNICALL
Java_ch_protonmail_android_utils_OpenPGP_test2(JNIEnv* env, jobject o, jint x)
{
	const std::string str_test = "This is a hello word from native through jni";
	jstring jsRet = 0;


	if (!str_test.empty())
	{
		jsRet = (env)->NewStringUTF((const char*) str_test.c_str());

	}
	return jsRet;
}


// openpgp functions

JNIEXPORT jint JNICALL
Java_ch_protonmail_android_utils_OpenPGP_SetupKeys(JNIEnv* env, jobject o, jstring jpriv_key, jstring jpub_key, jstring jpassphrase)
{
    try
    {
        jboolean isCopy;
        const char* c_private_key = env->GetStringUTFChars(jpriv_key, &isCopy);
        std::string str_priv_key = std::string(c_private_key);
        if (isCopy == JNI_TRUE) {
            env->ReleaseStringUTFChars(jpriv_key, c_private_key);
        }

        const char* c_public_key = env->GetStringUTFChars(jpub_key, &isCopy);
        std::string str_pub_key = std::string(c_public_key);
        if (isCopy == JNI_TRUE) {
            env->ReleaseStringUTFChars(jpub_key, c_public_key);
        }

        const char* c_passphrase = env->GetStringUTFChars(jpassphrase, &isCopy);
        std::string str_passphrase = std::string(c_passphrase);
        if (isCopy == JNI_TRUE) {
            env->ReleaseStringUTFChars(jpassphrase, c_passphrase);
        }

		PGPSecretKey secret_key;
	    secret_key.set_is_debug(false);
		secret_key.read(str_priv_key);

		PGPPublicKey public_key;
	    public_key.set_is_debug(false);
	   	public_key.read(str_pub_key);

	    std::string verifyString = "this is a protonmail encryption test string";
	    LOG_E("Start encrypt check");
	    PGPMessage encrypted = encrypt_pka(public_key, verifyString);
		LOG_E("Start decroypt check");
	    std::string clain_txt = decrypt_pka(secret_key, encrypted, str_passphrase, false);
	    LOG_E("Check pwd");
	    if(verifyString == clain_txt)
	    {
	    	LOG_E("return ok");
	        return 1;
	    }
    }
    catch (const std::runtime_error& error)
    {
    	LOG_E("runtime_error");
    }
    catch (const std::exception& e)
    {
    	LOG_E("exception");
    }
    catch (...)
    {
    	LOG_E("Other exception");
    }

    LOG_E("not ok");
	return 0;
}

JNIEXPORT jstring JNICALL
Java_ch_protonmail_android_utils_OpenPGP_EncryptMessage(JNIEnv* env, jobject o, jstring junencrypt_message, jstring jpub_key)
{
	try
    {
        jboolean isCopy;
        const char* c_public_key = env->GetStringUTFChars(jpub_key, &isCopy);
        std::string str_pub_key = std::string(c_public_key);
        if (isCopy == JNI_TRUE) {
            env->ReleaseStringUTFChars(jpub_key, c_public_key);
        }

        const char* c_un_encrypt_msg = env->GetStringUTFChars(junencrypt_message, &isCopy);
        std::string str_unencrypt_msg = std::string(c_un_encrypt_msg);
        if (isCopy == JNI_TRUE) {
            env->ReleaseStringUTFChars(junencrypt_message, c_un_encrypt_msg);
        }


        PGPPublicKey pub(str_pub_key);
        PGPMessage encrypted_pgp = encrypt_pka(pub, str_unencrypt_msg);
        std::string encrypt_message = encrypted_pgp.write();

        jstring jsRet = 0;
		if (!encrypt_message.empty())
		{
			jsRet = (env)->NewStringUTF((const char*) encrypt_message.c_str());
		}
		return jsRet;
    }
    catch (const std::runtime_error& error)
    {
    }
    catch (const std::exception& e)
    {
    }
    catch (...)
    {
    }
	return 0;
}

JNIEXPORT jstring JNICALL
Java_ch_protonmail_android_utils_OpenPGP_DecryptMessage(JNIEnv* env, jobject o, jstring jencrypted_message, jstring jpriv_key, jstring jpassphrase)
{
	try
    {
        jboolean isCopy;
        const char* c_encrypted_msg = env->GetStringUTFChars(jencrypted_message, &isCopy);
        std::string str_encrypted_msg = std::string(c_encrypted_msg);
        if (isCopy == JNI_TRUE) {
            env->ReleaseStringUTFChars(jencrypted_message, c_encrypted_msg);
        }

        const char* c_private_key = env->GetStringUTFChars(jpriv_key, &isCopy);
        std::string str_priv_key = std::string(c_private_key);
        if (isCopy == JNI_TRUE) {
            env->ReleaseStringUTFChars(jpriv_key, c_private_key);
        }

        const char* c_passphrase = env->GetStringUTFChars(jpassphrase, &isCopy);
        std::string str_passphrase = std::string(c_passphrase);
        if (isCopy == JNI_TRUE) {
            env->ReleaseStringUTFChars(jpassphrase, c_passphrase);
        }

        pm::PMPGPMessage pm_pgp_msg(str_encrypted_msg);

        PGPSecretKey secret_key;
	    secret_key.set_is_debug(false);
		secret_key.read(str_priv_key);

        std::string test_plain_txt = decrypt_pka(secret_key, pm_pgp_msg, str_passphrase, false);
        jstring jsRet = 0;
		if (!test_plain_txt.empty())
		{
			jsRet = (env)->NewStringUTF((const char*) test_plain_txt.c_str());
		}
		return jsRet;
    }
    catch (const std::runtime_error& error)
    {
    }
    catch (const std::exception& e)
    {
    }
    catch (...)
    {
    }
    return 0;
}

JNIEXPORT jstring JNICALL
Java_ch_protonmail_android_utils_OpenPGP_EncryptMessageAES(JNIEnv* env, jobject o, jstring unencrypt_message, jstring password)
{
	try
    {
        std::string str_unencrypt_message = (*env).GetStringUTFChars(unencrypt_message, 0);
		std::string str_password = (*env).GetStringUTFChars(password, 0);

        PGPMessage encrypted_sym = encrypt_sym(str_password, str_unencrypt_message, "", 9, 0, true, nullptr, "");
        std::string encrypt_message = encrypted_sym.write();

        jstring jsRet = 0;
		if (!encrypt_message.empty())
		{
			jsRet = (env)->NewStringUTF((const char*) encrypt_message.c_str());
		}
		return jsRet;
    }
    catch (const std::runtime_error& error)
    {
    }
    catch (const std::exception& e)
    {
    }
    catch (...)
    {
    }
	return 0;
}
JNIEXPORT jstring JNICALL
Java_ch_protonmail_android_utils_OpenPGP_DecryptMessageAES(JNIEnv* env, jobject o, jstring encrypted_message, jstring password)
{
	try
    {
        std::string str_encrypted_message = (*env).GetStringUTFChars(encrypted_message, 0);
		std::string str_password = (*env).GetStringUTFChars(password, 0);

        pm::PMPGPMessage pm_pgp_msg(str_encrypted_message);
        std::string out_unencrypt_msg = decrypt_sym(pm_pgp_msg, str_password);

        jstring jsRet = 0;
		if (!out_unencrypt_msg.empty())
		{
			jsRet = (env)->NewStringUTF((const char*) out_unencrypt_msg.c_str());
		}

		return jsRet;
    }
    catch (const std::runtime_error& error)
    {
    }
    catch (const std::exception& e)
    {
    }
    catch (...)
    {
    }
    return 0;
}

JNIEXPORT jstring JNICALL
Java_ch_protonmail_android_utils_OpenPGP_EncryptMailboxPWD(JNIEnv* env, jobject o, jstring unencrypt_pwd, jstring salt)
{
    try
    {
        std::string str_unencrypt_message = (*env).GetStringUTFChars(unencrypt_pwd, 0);
        std::string str_password = (*env).GetStringUTFChars(salt, 0);

        PGPMessage encrypted_sym = encrypt_sym(str_password, str_unencrypt_message, "", 9, 0, true, nullptr, "");
        std::string encrypt_message = hexlify(encrypted_sym.write(1));

        jstring jsRet = 0;
        if (!encrypt_message.empty())
        {
            jsRet = (env)->NewStringUTF((const char*) encrypt_message.c_str());
        }
        return jsRet;
    }
    catch (const std::runtime_error& error)
    {
    }
    catch (const std::exception& e)
    {
    }
    catch (...)
    {
    }
    return 0;
//     jstring jsRet = jsRet = (env)->NewStringUTF("");
//     try
//     {
//         std::string str_unencrypt_message = (*env).GetStringUTFChars(unencrypt_pwd, 0);
//         std::string str_password = (*env).GetStringUTFChars(salt, 0);

//         const std::string key_factory = "3b98f67c7fcec923b56a8e74bffffc00358ac382840d7bf131071ff6353562f85051397ab6f39f832d9dcc49724dce94eb65ff282f83266b57e8a9306adb04149d6f14998cfdcd5a526e0c81a5d1696e39ddc86c3c3bd5e672f70356b87198589eab94a0943a94960241a9587d7bf05c139f391daeda316290008a85616ed1fb7fa9ed060b931823f8e59c7457c2e9f7a2b4c6ee87404243254c970b926e7f5c4dd8f4194366a4d8e3da95c2ccc55b06bbf436f81c759b4fc1342bd27f1d356235f7a3c56ed216f90e45efedd3229a92d63ef1e825c1e4e243520fa3663ce89de6e5279e68e890e0d6b5653d405412719b45adeef94a8f95d29b6fb70c6c6f53b1687687829ed36ca3bc3db989c38f07536868ca45f2cd02e2ba5fe413e61b346d7c6003b3d9b54c1b93abe4cfcef6f2fd84faa0b11dc94f2a076268b761c7b2be5116da3a1a31e872a1437a81a7648f3b060313969e066246193baf9299f49851f4c0df3c84acf799c46d50c6666782744c99b18dec752d26815addc0598aa1";
//         const int factory_size = 768;

//         const int iKeySize = 64; //(32 * 2)
//         const int iIVSize = 16; //(32 * 2)
//         const int hmacSize = 32;

//         const int iKeyOne = 20;  //first key position
//         const int iKeyTwo = 100;
//         const int iKeyThree = 180;
//         std::string key_one = unhexlify(key_factory.substr(iKeyOne, iKeySize));   //for salt hash
//         //std::cout << "key_one:" << hexlify(key_one) << std::endl;
//         std::string key_two = unhexlify(key_factory.substr(iKeyTwo, iKeySize));    //for aes cbc 256
//         //std::cout << "key_two:" << hexlify(key_two) << std::endl;
//         LOG_E("key_two %s", hexlify(key_two).c_str()); /* 1  */
//         std::string key_three = unhexlify(key_factory.substr(iKeyThree, iKeySize));  //for enc data hash
//         //std::cout << "key_three:" << hexlify(key_three) << std::endl;
//         std::string random_iv = unhexlify(str_password) + BBS().rand_b(iIVSize);
//         random_iv = random_iv.substr(0, iIVSize);
//         //std::cout << "random:" << hexlify(random_iv) << std::endl;
//         LOG_E("random_iv %s", hexlify(random_iv).c_str()); /* 1  */
//         //std::string hash_salt = hash_hmac("sha256", salt_value, key_one, true);
//         //std::cout << "hash_salt:" << hexlify(hash_salt) << std::endl;
//         //std::cout << "hash+plain" << hexlify(hash_salt + plaintext) << std::endl;
//         std::string enc_data = pm::aes_cbc_256_encrypt(key_two, random_iv, str_unencrypt_message);
//         //std::cout << "enc_data:" << hexlify(enc_data) << std::endl;
//         LOG_E("enc_data %s", hexlify(enc_data).c_str()); /* 1  */
//         std::string hash_enc_data = pm::hash_hmac("sha256", random_iv + enc_data, key_three, true);

//         LOG_E("hash_enc_data %s", hexlify(hash_enc_data).c_str());
//         //std::cout << "hash_enc_data:" << hexlify(hash_enc_data) << std::endl;
//         std::string encrypt_message = hexlify(hash_enc_data + random_iv + enc_data);
// LOG_E("encrypt_message %s", encrypt_message.c_str());
//        // LOG_E("unencrypt_message %s", str_unencrypt_message.c_str()); /* 1  */

//         //std::string encrypt_message = pm::encrypt_mailbox_password(str_unencrypt_message, str_password);
//         jstring jsRet = 0;
//         if (!encrypt_message.empty())
//         {
//             jsRet = (env)->NewStringUTF((const char*) encrypt_message.c_str());
//         }
//         return jsRet;
//     }
//     catch (const std::runtime_error& error)
//     {
//     }
//     catch (const std::exception& e)
//     {
//     }
//     catch (...)
//     {
//     }
//     return 0;
}

JNIEXPORT jstring JNICALL
Java_ch_protonmail_android_utils_OpenPGP_DecryptMailboxPWD(JNIEnv* env, jobject o, jstring encrypted_pwd, jstring salt)
{
    try
    {
        std::string str_encrypted_message = (*env).GetStringUTFChars(encrypted_pwd, 0);
        std::string str_password = (*env).GetStringUTFChars(salt, 0);

        str_encrypted_message = unhexlify(str_encrypted_message);
        pm::PMPGPMessage pm_pgp_msg(str_encrypted_message);
        std::string out_unencrypt_msg = decrypt_sym(pm_pgp_msg, str_password);

        jstring jsRet = 0;
        if (!out_unencrypt_msg.empty())
        {
            jsRet = (env)->NewStringUTF((const char*) out_unencrypt_msg.c_str());
        }

        return jsRet;
    }
    catch (const std::runtime_error& error)
    {
    }
    catch (const std::exception& e)
    {
    }
    catch (...)
    {
    }
    return 0;
    // jstring jsRet = jsRet = (env)->NewStringUTF("");
    // try
    // {
    //     std::string str_encrypted_message = (*env).GetStringUTFChars(encrypted_pwd, 0);
    //     std::string str_password = (*env).GetStringUTFChars(salt, 0);
    //     //LOG_E("out_unencrypt_msg");


    //     const std::string key_factory = "3b98f67c7fcec923b56a8e74bffffc00358ac382840d7bf131071ff6353562f85051397ab6f39f832d9dcc49724dce94eb65ff282f83266b57e8a9306adb04149d6f14998cfdcd5a526e0c81a5d1696e39ddc86c3c3bd5e672f70356b87198589eab94a0943a94960241a9587d7bf05c139f391daeda316290008a85616ed1fb7fa9ed060b931823f8e59c7457c2e9f7a2b4c6ee87404243254c970b926e7f5c4dd8f4194366a4d8e3da95c2ccc55b06bbf436f81c759b4fc1342bd27f1d356235f7a3c56ed216f90e45efedd3229a92d63ef1e825c1e4e243520fa3663ce89de6e5279e68e890e0d6b5653d405412719b45adeef94a8f95d29b6fb70c6c6f53b1687687829ed36ca3bc3db989c38f07536868ca45f2cd02e2ba5fe413e61b346d7c6003b3d9b54c1b93abe4cfcef6f2fd84faa0b11dc94f2a076268b761c7b2be5116da3a1a31e872a1437a81a7648f3b060313969e066246193baf9299f49851f4c0df3c84acf799c46d50c6666782744c99b18dec752d26815addc0598aa1";
    //     const int factory_size = 768;

    //     const int iKeySize = 64; //(32 * 2)
    //     const int iIVSize = 16; //(32 * 2)
    //     const int hmacSize = 32;

    //     const int iKeyOne = 20;  //first key position
    //     const int iKeyTwo = 100;
    //     const int iKeyThree = 180;

    //     std::string key_one = unhexlify(key_factory.substr(iKeyOne, iKeySize));   //for salt hash
    //     // //std::cout << "key_one:" << hexlify(key_one) << std::endl;
    //     std::string key_two = unhexlify(key_factory.substr(iKeyTwo, iKeySize));    //for aes cbc 256
    //     // //std::cout << "key_two:" << hexlify(key_two) << std::endl;
    //     std::string key_three = unhexlify(key_factory.substr(iKeyThree, iKeySize));  //for enc data hash
    //     // //std::cout << "key_three:" << hexlify(key_three) << std::endl;
    //     LOG_E("ENC %s", str_encrypted_message.c_str()); /* 1  */
    //     std::string unhexlify_enc_value = unhexlify(str_encrypted_message);
    //     // //std::cout << "input:" << enc_value << std::endl;
    //     //LOG_E("base64 %s", base64_encode(unhexlify_enc_value).c_str()); /* 1  */
    //     //LOG_E("unhexlify %s", hexlify(unhexlify_enc_value).c_str()); /* 1  */

    //     std::string hash_enc_data = unhexlify_enc_value.substr(0, hmacSize);
    //     // //std::cout << "hash_enc_data:" << hexlify(hash_enc_data) << std::endl;
    //     std::string random_iv = unhexlify_enc_value.substr(hmacSize, iIVSize);
    //     // //std::cout << "random:" << hexlify(random_iv) << std::endl;
    //     LOG_E("random_iv %s", random_iv.c_str()); /* 1  */
    //     int enc_data_start = hmacSize + iIVSize;
    //     std::string enc_data = unhexlify_enc_value.substr(enc_data_start);
    //     // //std::cout << "enc_data:" << hexlify(enc_data) << std::endl;

    //     std::string match_hash_enc_data = pm::hash_hmac("sha256", random_iv + enc_data, key_three, true);
    //     //LOG_E("match_hash_enc_data %s", hexlify(match_hash_enc_data).c_str()); /* 1  */

    //     // //std::cout << "match_hash_enc_data:" << hexlify(match_hash_enc_data) << std::endl;

    //     // //std::cout << hexlify(match_hash_enc_data) << std::endl;
    //     // //std::cout << hexlify(hash_enc_data) << std::endl;

    //     int compare =match_hash_enc_data.compare(hash_enc_data );
    //     if( compare  != 0)
    //     {
    //         LOG_E("1 not match"); /* 1  */
    //         //std::cout << "hash_enc_data not match" << std::endl;
    //         //return "hash_enc_data not match";
    //         return jsRet;
    //     }
    //     else
    //     {
    //         LOG_E("1 check ok"); /* 1  */
    //     }


    //     //LOG_E("random_iv %s", random_iv.c_str()); /* 1  */
    //     //LOG_E("str_password %s", str_password.c_str()); /* 1  */
    //     if(random_iv.find(str_password) != 0 && str_password.find(random_iv) != 0)
    //     {
    //         //std::cout << "salt not match" << std::endl;
    //         //return random_iv;
    //         LOG_E("2 not match"); /* 1  */
    //         return jsRet;
    //     }
    //     else
    //     {
    //         LOG_E("2 check ok"); /* 1  */
    //     }

    //     std::string decrypt_data = pm::aes_cbc_256_decrypt(key_two, random_iv, enc_data);
    //     LOG_E("decrypt_data %s", decrypt_data.c_str()); /* 1  */
    //     LOG_E("decrypt_data %s", hexlify(decrypt_data).c_str()); /* 1  */
    //     // //std::cout << decrypt_data << std::endl;


    //     // LOG_E("encrypted_message %s", str_encrypted_message.c_str()); /* 1  */
    //     // LOG_E("salt %s", str_password.c_str()); /* 1  */
    //     // std::string out_unencrypt_msg = pm::decrypt_mailbox_password(str_encrypted_message, str_password);

    //     std::string out_unencrypt_msg = decrypt_data;
    //     if (!out_unencrypt_msg.empty())
    //     {
    //         //LOG_E("out_unencrypt_msg !empty");
    //         //LOG_E("Hello %s", out_unencrypt_msg.c_str()); /* 1  */
    //         jsRet = (env)->NewStringUTF((const char*) out_unencrypt_msg.c_str());
    //     }
    //     //LOG_E("after check");
    //     return jsRet;
    // }
    // catch (const std::runtime_error& error)
    // {
    //     LOG_E("exception one");
    // }
    // catch (const std::exception& e)
    // {
    //     LOG_E("exception two");
    // }
    // catch (...)
    // {
    //     LOG_E("exception other");
    // }
    // LOG_E("bad");
    // return jsRet;
}



JNIEXPORT jbyteArray JNICALL
Java_ch_protonmail_android_utils_OpenPGP_DecryptAttachmentArmored(JNIEnv* env, jobject o, jstring key_package, jstring data_package, jstring priv_key, jstring passphrase)
{
    try
    {
        std::string str_key_package = (*env).GetStringUTFChars(key_package, 0);
        std::string str_data_package = (*env).GetStringUTFChars(data_package, 0);

        std::string str_private_key = (*env).GetStringUTFChars(priv_key, 0);
        std::string str_password = (*env).GetStringUTFChars(passphrase, 0);

        pm::PMPGPMessage pm_pgp_msg(str_key_package);
        pm_pgp_msg.append(str_data_package);

        PGPSecretKey secret_key;
        secret_key.set_is_debug(false);
        secret_key.read(str_private_key);

        std::string test_plain_txt = decrypt_pka(secret_key, pm_pgp_msg, str_password, false);

        int len = test_plain_txt.size();
        jbyteArray array = env->NewByteArray(len);

        // //HERE I GET THE ERROR, I HAVE BEEN TRYING WITH len/2 and WORKS , PROBABLY SOME BYTS ARE GETTING LOST.
        (*env).SetByteArrayRegion (array, 0, len, (jbyte*)(test_plain_txt.c_str()));

        return array;
    }
    catch (const std::runtime_error& error)
    {
    }
    catch (const std::exception& e)
    {
    }
    catch (...)
    {
    }
    return 0;
}

JNIEXPORT jbyteArray JNICALL
Java_ch_protonmail_android_utils_OpenPGP_DecryptAttachment(JNIEnv* env, jobject o, jbyteArray key, jbyteArray data, jstring jprivate_key, jstring passphrase)
{
    try
    {
        // get length of bytes
        int srcLen=(*env).GetArrayLength(key);
        jbyte key_packet[srcLen];
        (*env).GetByteArrayRegion(key, 0, srcLen, key_packet);
        // key string package
        std::string str_key_package = std::string((char* )key_packet, srcLen);
        (*env).ReleaseByteArrayElements(key, key_packet , 0);

        srcLen=(*env).GetArrayLength(data);
        jbyte data_packet[srcLen];
        (*env).GetByteArrayRegion(data, 0, srcLen, data_packet);
        // data string package
        std::string str_data_package = std::string((char* )data_packet, srcLen);
        (*env).ReleaseByteArrayElements(data, data_packet , 0);


        std::string str_private_key = (*env).GetStringUTFChars(jprivate_key, 0);
        std::string str_password = (*env).GetStringUTFChars(passphrase, 0);

        pm::PMPGPMessage pm_pgp_msg(str_key_package);
        pm_pgp_msg.append(str_data_package);

        PGPSecretKey secret_key;
        secret_key.set_is_debug(false);
        secret_key.read(str_private_key);

        std::string test_plain_txt = decrypt_pka(secret_key, pm_pgp_msg, str_password, false);

        int len = test_plain_txt.size();
        jbyteArray array = env->NewByteArray(len);

        (*env).SetByteArrayRegion (array, 0, len, (jbyte*)(test_plain_txt.c_str()));


       // (*env).DeleteLocalRef (jniEnv, jprivate_key);

        return array;
    }
    catch (const std::runtime_error& error)
    {
    }
    catch (const std::exception& e)
    {
    }
    catch (...)
    {
    }
    return 0;

}


JNIEXPORT jobject JNICALL
Java_ch_protonmail_android_utils_OpenPGP_EncryptAttachment(JNIEnv* env, jobject o, jbyteArray data, jstring public_key)
{
    try
    {
        // get length of bytes
        int srcLen=(*env).GetArrayLength(data);
        jbyte plain_data[srcLen];
        (*env).GetByteArrayRegion(data, 0, srcLen, plain_data);
        std::string un_encrypted_data = std::string((char* )plain_data, srcLen);
        (*env).ReleaseByteArrayElements(data, plain_data , 0);

        std::string str_public_key = (*env).GetStringUTFChars(public_key, 0);

        ///
//LOG_E("Step 1");
        std::string str_session_key = generat_session_key();
//LOG_E("Step 1-1 : %s", str_session_key.c_str());
//LOG_E("Step 1-1 : %d", str_session_key.size());

//LOG_E("Step 1-2 : %d", str_public_key.size());
//LOG_E("Step 1-2 : %s", str_public_key.c_str());

        PGPPublicKey pub;
	    pub.set_is_debug(false);
	   	pub.read(str_public_key);

//    LOG_E("Step 1-3");

        //std::string k_out = pub.write();
//LOG_E("Step 1-4 : %d", k_out.size());
//LOG_E("Step 1-4 : %s", k_out.c_str());

        PGPMessage enrypted_session_key = encrypt_pka_only_session(pub, str_session_key);

 //           LOG_E("Step 1-5");
        //session key package
        std::string enrypted_session_key_data = enrypted_session_key.write(1);

//LOG_E("Step 2");

        PGPMessage encrypted_att = encrypt_pka_only_data(str_session_key, un_encrypted_data, "", 9, 0);
        std::string encrypted_data = encrypted_att.write(1);

//LOG_E("Step 3");

        jclass clazz = (*env).FindClass("ch/protonmail/android/utils/EncryptPackage");
        // Get the method id of an empty constructor in clazz
        jmethodID constructor = (*env).GetMethodID(clazz, "<init>", "()V");
        // Create an instance of clazz
        jobject obj = (*env).NewObject(clazz, constructor);
        // Get Field references
        jfieldID key_fieldID = (*env).GetFieldID(clazz, "KeyPackage", "[B");
        jfieldID data_fieldID = (*env).GetFieldID(clazz, "DataPackage", "[B");


        int len = enrypted_session_key_data.size();
        jbyteArray key_array = env->NewByteArray(len);
        (*env).SetByteArrayRegion (key_array, 0, len, (jbyte*)(enrypted_session_key_data.c_str()));
        (*env).SetObjectField(obj, key_fieldID, key_array);

        len = encrypted_data.size();
        jbyteArray data_array = env->NewByteArray(len);
        (*env).SetByteArrayRegion (data_array, 0, len, (jbyte*)(encrypted_data.c_str()));
        (*env).SetObjectField(obj, data_fieldID, data_array);

        return obj;
    }
    catch (const std::runtime_error& error)
    {
    LOG_E("Step 4");

    LOG_E("%s", error.what());
    }
    catch (const std::exception& e)
    {
    LOG_E("Step 5");
    }
    catch (...)
    {
    LOG_E("Step 6");
    }
    return 0;
}


JNIEXPORT jbyteArray JNICALL
Java_ch_protonmail_android_utils_OpenPGP_GetPublicKeySessionKey(JNIEnv* env, jobject o, jbyteArray key, jstring priv_key, jstring passphrase)
{
    try
    {
        // get length of bytes
        int srcLen=(*env).GetArrayLength(key);
        jbyte key_packet[srcLen];
        (*env).GetByteArrayRegion(key, 0, srcLen, key_packet);
        // key string package
        std::string str_key_package = std::string((char* )key_packet, srcLen);
        (*env).ReleaseByteArrayElements(key, key_packet , 0);

        std::string str_private_key = (*env).GetStringUTFChars(priv_key, 0);
        std::string str_password = (*env).GetStringUTFChars(passphrase, 0);

        pm::PMPGPMessage pm_pgp_msg(str_key_package);

        PGPSecretKey secret_key;
        secret_key.set_is_debug(false);
        secret_key.read(str_private_key);

        std::string sessionKey = decrypt_pka_only_session(secret_key, pm_pgp_msg, str_password);

        int len = sessionKey.size();
        jbyteArray array = env->NewByteArray(len);
        (*env).SetByteArrayRegion (array, 0, len, (jbyte*)(sessionKey.c_str()));

        return array;
    }
    catch (const std::runtime_error& error)
    {
        LOG_E("%s", error.what());
    }
    catch (const std::exception& e)
    {
        LOG_E("%s", e.what());
    }
    catch (...)
    {
        LOG_E("exceiption");
    }
    return 0;
}

JNIEXPORT jbyteArray JNICALL
Java_ch_protonmail_android_utils_OpenPGP_GetSymmetricSessionKey(JNIEnv* env, jobject o, jbyteArray key, jstring password)
{
    try
    {
        // get length of bytes
        int srcLen=(*env).GetArrayLength(key);
        jbyte key_packet[srcLen];
        (*env).GetByteArrayRegion(key, 0, srcLen, key_packet);
        // key string package
        std::string str_key_package = std::string((char* )key_packet, srcLen);
        (*env).ReleaseByteArrayElements(key, key_packet , 0);

        std::string str_password = (*env).GetStringUTFChars(password, 0);

        pm::PMPGPMessage pm_pgp_msg(str_key_package);

        std::string sessionKey = decrypt_pka_only_sym_session(pm_pgp_msg, str_password);

        int len = sessionKey.size();
        jbyteArray array = env->NewByteArray(len);
        (*env).SetByteArrayRegion (array, 0, len, (jbyte*)(sessionKey.c_str()));

        return array;
    }
    catch (const std::runtime_error& error)
    {
    }
    catch (const std::exception& e)
    {
    }
    catch (...)
    {
    }
    return 0;
}


JNIEXPORT jbyteArray JNICALL
Java_ch_protonmail_android_utils_OpenPGP_GetNewPublicKeyPackage(JNIEnv* env, jobject o, jbyteArray key, jstring publicKey)
{
    try
    {
        // get length of bytes
        int srcLen=(*env).GetArrayLength(key);
        jbyte key_session[srcLen];
        (*env).GetByteArrayRegion(key, 0, srcLen, key_session);
        // key string package
        std::string str_session_key = std::string((char* )key_session, srcLen);
        (*env).ReleaseByteArrayElements(key, key_session , 0);

        std::string str_public_key = (*env).GetStringUTFChars(publicKey, 0);

        PGPPublicKey pub(str_public_key);

        PGPMessage out_msg = encrypt_pka_only_session(pub, str_session_key);

        std::string new_key_package = out_msg.write(0);

        int len = new_key_package.size();
        jbyteArray array = env->NewByteArray(len);
        (*env).SetByteArrayRegion (array, 0, len, (jbyte*)(new_key_package.c_str()));

        return array;
    }
    catch (const std::runtime_error& error)
    {
        LOG_E("%s", error.what());
    }
    catch (const std::exception& e)
    {
        LOG_E("%s", e.what());
    }
    catch (...)
    {
        LOG_E("exception");
    }
    return 0;
}
JNIEXPORT jbyteArray JNICALL
Java_ch_protonmail_android_utils_OpenPGP_GetNewSymmetricKeyPackage(JNIEnv* env, jobject o, jbyteArray key, jstring password)
{
    try
    {
        // get length of bytes
        int srcLen=(*env).GetArrayLength(key);
        jbyte key_session[srcLen];
        (*env).GetByteArrayRegion(key, 0, srcLen, key_session);
        // key string package
        std::string str_session_key = std::string((char* )key_session, srcLen);
        (*env).ReleaseByteArrayElements(key, key_session , 0);

        std::string str_password = (*env).GetStringUTFChars(password, 0);

        PGPMessage out_msg = encrypt_pka_only_sym_session(str_password, str_session_key);

        std::string new_key_package = out_msg.write(1);

        int len = new_key_package.size();
        jbyteArray array = env->NewByteArray(len);
        (*env).SetByteArrayRegion (array, 0, len, (jbyte*)(new_key_package.c_str()));

        return array;
    }
    catch (const std::runtime_error& error)
    {
    }
    catch (const std::exception& e)
    {
    }
    catch (...)
    {
    }
    return 0;
}



}