//
//  OpenPGP.m
//  OpenPGP
//
//  Created by Yanfeng Zhang on 1/29/15.
//  Copyright (c) 2015 Yanfeng Zhang. All rights reserved.
//

#import "OpenPGP.h"
#include "PGPKey.h"
#include "openpgp.h"
#include "PGPMessage.h"
#include "encrypt.h"
#include "decrypt.h"
#include <exception>
#include "consts.h"
#include "base64.h"
#include "cfb.h"
#include "UTF8.h"
#include "mpi.h"
#include <openssl/bio.h>
#include <openssl/evp.h>

#include <algorithm>
#include <stdexcept>
#include <codecvt>

#include <openpgp/openpgp.h>
#include "PMPGPMessage.h"



@implementation OpenPGP
{
    PGPSecretKey* private_key_;
    PGPPublicKey* public_key_;
    BOOL isPrivKeyLoaded;
    BOOL isPubKeyLoaded;
    
    BOOL IsPasspharseRight;
    NSString* Passpharse;
    BOOL isDebugMode;
    
    pgp::openpgp test;
    
}


- (id)init
{
    self = [super init];
    if ( self )
    {
        private_key_ = new PGPSecretKey();
        private_key_->set_is_debug(false);
        
        public_key_ = new PGPPublicKey();
        public_key_->set_is_debug(false);
        
        isDebugMode = false;
        IsPasspharseRight = false;
        Passpharse = @"";
        
        isPrivKeyLoaded = false;
        isPubKeyLoaded = false;
    }
    return self;
}

- (void)dealloc
{
    delete private_key_;
    delete public_key_;
    //[super dealloc];
}

- (BOOL) SetupKeys:(NSString *)priv_key pubKey:(NSString *)pub_key pass:(NSString*) passphrase error:(NSError **) err;
{
    try
    {
        std::string str_priv_key = [priv_key UTF8String];
        
        if(isDebugMode)
            std::cout << str_priv_key;
        
        private_key_->read(str_priv_key);
        
        //std::cout << "KeyID:" << hexlify(private_key_->keyid()) << std::endl;
        
        std::string tmp = [pub_key UTF8String];
        public_key_->read(tmp);
        
        std::string verifyString = "this is a protonmail encryption test string";
        PGPMessage encrypted = encrypt_pka(*public_key_, verifyString);
        
        std::string clain_txt = decrypt_pka(*private_key_, encrypted, [passphrase UTF8String], false);
        if(verifyString == clain_txt)
        {
            Passpharse = passphrase;
            IsPasspharseRight = YES;
            return true;
        }
    }
    catch (const std::runtime_error& error)
    {
        if (err)
        {
            NSString *domain = @"com.ProtonMail.OpenPGP";
            NSString *desc = NSLocalizedString([NSString stringWithUTF8String:error.what()] , @"");
            NSDictionary *userInfo = @{ NSLocalizedDescriptionKey : desc };
            
            *err = [NSError errorWithDomain:domain code:10001 userInfo:userInfo];
        }
    }
    catch (const std::exception& e)
    {
        if (err)
        {
            NSString *domain = @"com.ProtonMail.OpenPGP";
            NSString *desc = NSLocalizedString([NSString stringWithUTF8String:e.what()] , @"");
            NSDictionary *userInfo = @{ NSLocalizedDescriptionKey : desc };
            
            *err = [NSError errorWithDomain:domain code:10002 userInfo:userInfo];
        }
        
    }
    catch (...)
    {
        if (err)
        {
            NSString *domain = @"com.ProtonMail.OpenPGP";
            NSString *desc = NSLocalizedString(@"Unknow errors", @"");
            NSDictionary *userInfo = @{ NSLocalizedDescriptionKey : desc };
            
            *err = [NSError errorWithDomain:domain code:10003 userInfo:userInfo];
        }
        
    }
    
    return false;
}


//Encrypt for user self
- (NSString *) encrypt_message:(NSString*) unencrypt_message error:(NSError**) err
{
    try
    {
        if(!IsPasspharseRight)
        {
            NSString *domain = @"com.ProtonMail.OpenPGP";
            NSString *desc = NSLocalizedString(@"you need load public key first" , @"");
            NSDictionary *userInfo = @{ NSLocalizedDescriptionKey : desc };
            
            *err = [NSError errorWithDomain:domain code:10004 userInfo:userInfo];
            return nil;
        }
        std::string unencrypt_msg = [unencrypt_message UTF8String];

        PGPMessage encrypted_pgp = encrypt_pka(*public_key_, unencrypt_msg);
        std::string encrypt_message = encrypted_pgp.write();
        return [[NSString alloc] initWithUTF8String:encrypt_message.c_str()];
    }
    catch (const std::runtime_error& error)
    {
        if (err)
        {
            NSString *domain = @"com.ProtonMail.OpenPGP";
            NSString *desc = NSLocalizedString([NSString stringWithUTF8String:error.what()] , @"");
            NSDictionary *userInfo = @{ NSLocalizedDescriptionKey : desc };
            
            *err = [NSError errorWithDomain:domain code:10001 userInfo:userInfo];
        }
    }
    catch (const std::exception& e)
    {
        if (err)
        {
            NSString *domain = @"com.ProtonMail.OpenPGP";
            NSString *desc = NSLocalizedString([NSString stringWithUTF8String:e.what()] , @"");
            NSDictionary *userInfo = @{ NSLocalizedDescriptionKey : desc };
            
            *err = [NSError errorWithDomain:domain code:10002 userInfo:userInfo];
        }
        
    }
    catch (...)
    {
        if (err)
        {
            NSString *domain = @"com.ProtonMail.OpenPGP";
            NSString *desc = NSLocalizedString(@"Unknow errors", @"");
            NSDictionary *userInfo = @{ NSLocalizedDescriptionKey : desc };
            
            *err = [NSError errorWithDomain:domain code:10003 userInfo:userInfo];
        }
        
    }
    return nil;
    
}

- (NSString *) encrypt_message:(NSString*) unencrypt_message pub_key:(NSString *)pub_key error:(NSError**) err;
{
    try
    {
        std::string unencrypt_msg = [unencrypt_message UTF8String];
        std::string user_pub_key = [pub_key UTF8String];
        PGPPublicKey pub(user_pub_key);
        PGPMessage encrypted_pgp = encrypt_pka(pub, unencrypt_msg);
        std::string encrypt_message = encrypted_pgp.write();        
        return [[NSString alloc] initWithUTF8String:encrypt_message.c_str()];
    }
    catch (const std::runtime_error& error)
    {
        if (err)
        {
            NSString *domain = @"com.ProtonMail.OpenPGP";
            NSString *desc = NSLocalizedString([NSString stringWithUTF8String:error.what()] , @"");
            NSDictionary *userInfo = @{ NSLocalizedDescriptionKey : desc };
            
            *err = [NSError errorWithDomain:domain code:10001 userInfo:userInfo];
        }
    }
    catch (const std::exception& e)
    {
        if (err)
        {
            NSString *domain = @"com.ProtonMail.OpenPGP";
            NSString *desc = NSLocalizedString([NSString stringWithUTF8String:e.what()] , @"");
            NSDictionary *userInfo = @{ NSLocalizedDescriptionKey : desc };
            
            *err = [NSError errorWithDomain:domain code:10002 userInfo:userInfo];
        }
        
    }
    catch (...)
    {
        if (err)
        {
            NSString *domain = @"com.ProtonMail.OpenPGP";
            NSString *desc = NSLocalizedString(@"Unknow errors", @"");
            NSDictionary *userInfo = @{ NSLocalizedDescriptionKey : desc };
            
            *err = [NSError errorWithDomain:domain code:10003 userInfo:userInfo];
        }
        
    }
    return nil;
    
}


- (NSString *) decrypt_message:(NSString*) encrypted_message error:(NSError**) err
{
    try
    {
        if(encrypted_message.length <= 0 )
        {
            if (err)
            {
                NSString *domain = @"com.ProtonMail.OpenPGP";
                NSString *desc = NSLocalizedString(@"The input message is not valid" , @"");
                NSDictionary *userInfo = @{ NSLocalizedDescriptionKey : desc };
                
                *err = [NSError errorWithDomain:domain code:10005 userInfo:userInfo];
            }
            return nil;
        }
        
        if(!IsPasspharseRight)
        {
            if (err)
            {
                NSString *domain = @"com.ProtonMail.OpenPGP";
                NSString *desc = NSLocalizedString(@"you need load private key first" , @"");
                NSDictionary *userInfo = @{ NSLocalizedDescriptionKey : desc };
                
                *err = [NSError errorWithDomain:domain code:10004 userInfo:userInfo];
            }
            return nil;
        }
        std::string encrypt_msg = [encrypted_message UTF8String];
        
        pm::PMPGPMessage pm_pgp_msg(encrypt_msg);
        
        std::string test_plain_txt = decrypt_pka(*private_key_, pm_pgp_msg, [self->Passpharse UTF8String], false);
        
        return [[NSString alloc] initWithUTF8String:test_plain_txt.c_str()];
    }
    catch (const std::runtime_error& error)
    {
        if (err)
        {
            NSString *domain = @"com.ProtonMail.OpenPGP";
            NSString *desc = NSLocalizedString([NSString stringWithUTF8String:error.what()] , @"");
            NSDictionary *userInfo = @{ NSLocalizedDescriptionKey : desc };
            
            *err = [NSError errorWithDomain:domain code:10001 userInfo:userInfo];
        }
    }
    catch (const std::exception& e)
    {
        if (err)
        {
            NSString *domain = @"com.ProtonMail.OpenPGP";
            NSString *desc = NSLocalizedString([NSString stringWithUTF8String:e.what()] , @"");
            NSDictionary *userInfo = @{ NSLocalizedDescriptionKey : desc };
            
            *err = [NSError errorWithDomain:domain code:10002 userInfo:userInfo];
        }
        
    }
    catch (...)
    {
        if (err)
        {
            NSString *domain = @"com.ProtonMail.OpenPGP";
            NSString *desc = NSLocalizedString(@"Unknow errors", @"");
            NSDictionary *userInfo = @{ NSLocalizedDescriptionKey : desc };
            
            *err = [NSError errorWithDomain:domain code:10003 userInfo:userInfo];
        }
    }
    return nil;
}


//- (NSString *) decrypt_message:(NSString*) encrypted_message error:(NSError**) err
//{
//
//    try
//    {
//        if(encrypted_message.length <= 0 )
//        {
//            if (err)
//            {
//                NSString *domain = @"com.ProtonMail.OpenPGP";
//                NSString *desc = NSLocalizedString(@"The input message is not valid" , @"");
//                NSDictionary *userInfo = @{ NSLocalizedDescriptionKey : desc };
//
//                *err = [NSError errorWithDomain:domain code:10005 userInfo:userInfo];
//            }
//            return nil;
//
//        }
//
//        if(!IsPasspharseRight)
//        {
//            if (err)
//            {
//                NSString *domain = @"com.ProtonMail.OpenPGP";
//                NSString *desc = NSLocalizedString(@"you need load private key first" , @"");
//                NSDictionary *userInfo = @{ NSLocalizedDescriptionKey : desc };
//
//                *err = [NSError errorWithDomain:domain code:10004 userInfo:userInfo];
//            }
//            return nil;
//        }
//
//        PGPMessage pgp_encrypted_msg;
//        std::string encrypt_msg = [encrypted_message UTF8String];
//
//        std::size_t start = encrypt_msg.find(protonmail_cryoto_headerMessage) + protonmail_cryoto_headerMessage.length();
//        if(start == std::string::npos)
//        {
//            if (err)
//            {
//                NSString *domain = @"com.ProtonMail.OpenPGP";
//                NSString *desc = NSLocalizedString(@"Bad protonmail pgp message" , @"");
//                NSDictionary *userInfo = @{ NSLocalizedDescriptionKey : desc };
//
//                *err = [NSError errorWithDomain:domain code:10006 userInfo:userInfo];
//            }
//            return nil;
//        }
//        std::size_t end = encrypt_msg.find(protonmail_cryoto_tailMessage);
//        if(end == std::string::npos)
//        {
//            if (err)
//            {
//                NSString *domain = @"com.ProtonMail.OpenPGP";
//                NSString *desc = NSLocalizedString(@"Bad protonmail pgp message" , @"");
//                NSDictionary *userInfo = @{ NSLocalizedDescriptionKey : desc };
//
//                *err = [NSError errorWithDomain:domain code:10006 userInfo:userInfo];
//            }
//            return nil;
//        }
//        end -= start;
//
//        std::string encrypted_msg = encrypt_msg.substr(start, end);
//        if(isDebugMode)
//            std::cout << encrypted_msg << std::endl;
//
//
//        std::size_t start_1 = encrypt_msg.find(protonmail_cryoto_headerRandomKey) + protonmail_cryoto_headerRandomKey.length();
//        if(start_1 == std::string::npos)
//        {
//            if (err)
//            {
//                NSString *domain = @"com.ProtonMail.OpenPGP";
//                NSString *desc = NSLocalizedString(@"Bad protonmail pgp message" , @"");
//                NSDictionary *userInfo = @{ NSLocalizedDescriptionKey : desc };
//
//                *err = [NSError errorWithDomain:domain code:10006 userInfo:userInfo];
//            }
//            return nil;
//        }
//        std::size_t end_1 = encrypt_msg.length() - protonmail_cryoto_tailRandomKey.length();
//        if(end_1 == std::string::npos)
//        {
//            if (err)
//            {
//                NSString *domain = @"com.ProtonMail.OpenPGP";
//                NSString *desc = NSLocalizedString(@"Bad protonmail pgp message" , @"");
//                NSDictionary *userInfo = @{ NSLocalizedDescriptionKey : desc };
//
//                *err = [NSError errorWithDomain:domain code:10006 userInfo:userInfo];
//            }
//            return nil;
//        }
//        start_1 -= start_1;
//
//        std::string encrypt_random_key = encrypt_msg.substr(start_1, end_1);
//        if(isDebugMode)
//            std::cout << encrypt_random_key << std::endl;
//
//        pgp_encrypted_msg.read(encrypt_random_key);
//        std::string clain_txt = decrypt_pka(*private_key_, pgp_encrypted_msg, [self->Passpharse UTF8String], false);
//        if(isDebugMode)
//            std::cout << clain_txt << std::endl;
//
//        std::string v = decode_utf8_base64(clain_txt);
//        if(isDebugMode)
//            std::cout << v.length() << std::endl;
//        if(isDebugMode)
//            std::cout << v << std::endl;
//
//        std::string decoded_message = decode_utf8_base64(encrypted_msg);
//        if(isDebugMode)
//            std::cout << decoded_message << std::endl;
//
//        std::string data = use_OpenPGP_CFB_decrypt(9, 9, decoded_message, v, false);
//        if(isDebugMode)
//            std::cout << data.length() << std::endl;
//        if(isDebugMode)
//            std::cout << data << std::endl;
//
//        //data = base64_decode(data);
//        auto data2 = decode_utf8_base64_msg(data);
//
//        if(isDebugMode)
//        {
//            std::cout << data.length() << std::endl;
//            std::cout << data << std::endl;
//
//            std::cout << data2.length() << std::endl;
//            std::cout << data2 << std::endl;
//        }
//        return [[NSString alloc] initWithUTF8String:data2.c_str()];
//    }
//    catch (const std::runtime_error& error)
//    {
//        if (err)
//        {
//            NSString *domain = @"com.ProtonMail.OpenPGP";
//            NSString *desc = NSLocalizedString([NSString stringWithUTF8String:error.what()] , @"");
//            NSDictionary *userInfo = @{ NSLocalizedDescriptionKey : desc };
//
//            *err = [NSError errorWithDomain:domain code:10001 userInfo:userInfo];
//        }
//    }
//    catch (const std::exception& e)
//    {
//        if (err)
//        {
//            NSString *domain = @"com.ProtonMail.OpenPGP";
//            NSString *desc = NSLocalizedString([NSString stringWithUTF8String:e.what()] , @"");
//            NSDictionary *userInfo = @{ NSLocalizedDescriptionKey : desc };
//
//            *err = [NSError errorWithDomain:domain code:10002 userInfo:userInfo];
//        }
//
//    }
//    catch (...)
//    {
//        if (err)
//        {
//            NSString *domain = @"com.ProtonMail.OpenPGP";
//            NSString *desc = NSLocalizedString(@"Unknow errors", @"");
//            NSDictionary *userInfo = @{ NSLocalizedDescriptionKey : desc };
//
//            *err = [NSError errorWithDomain:domain code:10003 userInfo:userInfo];
//        }
//    }
//    return nil;
//}
//



- (void)EnableDebug:(BOOL) isDebug
{
    isDebugMode = isDebug;
}

- (void)Test
{
    test.generate_new_key(2048, "123", "100");
}

@end
