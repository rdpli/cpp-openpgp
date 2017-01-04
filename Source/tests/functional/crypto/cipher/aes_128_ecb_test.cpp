//
//  aes_128_ecb_text.cpp
//  OpenPGP
//
//  Created by Yanfeng Zhang on 10/31/16.
//  Copyright © 2016 Yanfeng Zhang. All rights reserved.
//
#import "utils_test.h"
#include <encryption/AES.h>


namespace tests {
    namespace cipher_tests {
        SUITE(aes_128_ecb)
        {
            
            TEST(gfsbox) {
                const std::string AES128_ECB_GFSBOX_KEY = "00000000000000000000000000000000";
                
                const std::vector<std::string> AES128_ECB_GFSBOX_PLAIN = {
                    "f34481ec3cc627bacd5dc3fb08f273e6",
                    "9798c4640bad75c7c3227db910174e72",
                    "96ab5c2ff612d9dfaae8c31f30c42168",
                    "6a118a874519e64e9963798a503f1d35",
                    "cb9fceec81286ca3e989bd979b0cb284",
                    "b26aeb1874e47ca8358ff22378f09144",
                    "58c8e00b2631686d54eab84b91f0aca1",
                };
                
                const std::vector<std::string> AES128_ECB_GFSBOX_CIPHER = {
                    "0336763e966d92595a567cc9ce537f5e",
                    "a9a1631bf4996954ebc093957b234589",
                    "ff4f8391a6a40ca5b25d23bedd44a597",
                    "dc43be40be0e53712f7e2bf5ca707209",
                    "92beedab1895a94faa69b632e5cc47ce",
                    "459264f4798f6a78bacb89c15ed3d601",
                    "08a4e2efec8a8e3312ca7460b9040bbf",
                };
                
                VERIFY_ARE_EQUAL(AES128_ECB_GFSBOX_PLAIN.size(), AES128_ECB_GFSBOX_CIPHER.size());
                const std::string UNHEX_AES128_ECB_GFSBOX_KEY = unhexlify(AES128_ECB_GFSBOX_KEY);
                for ( unsigned int i = 0; i < AES128_ECB_GFSBOX_PLAIN.size(); ++i ) {
                    auto aes128 = AES(UNHEX_AES128_ECB_GFSBOX_KEY);
                    VERIFY_ARE_EQUAL(hexlify(aes128.encrypt(unhexlify(AES128_ECB_GFSBOX_PLAIN[i]))), AES128_ECB_GFSBOX_CIPHER[i]);
                    VERIFY_ARE_EQUAL(hexlify(aes128.decrypt(unhexlify(AES128_ECB_GFSBOX_CIPHER[i]))), AES128_ECB_GFSBOX_PLAIN[i]);
                }
            }
            
            TEST(sbox) {
                const std::vector<std::string> AES128_ECB_SBOX_KEY = {
                    "10a58869d74be5a374cf867cfb473859",
                    "caea65cdbb75e9169ecd22ebe6e54675",
                    "a2e2fa9baf7d20822ca9f0542f764a41",
                    "b6364ac4e1de1e285eaf144a2415f7a0",
                    "64cf9c7abc50b888af65f49d521944b2",
                    "47d6742eefcc0465dc96355e851b64d9",
                    "3eb39790678c56bee34bbcdeccf6cdb5",
                    "64110a924f0743d500ccadae72c13427",
                    "18d8126516f8a12ab1a36d9f04d68e51",
                    "f530357968578480b398a3c251cd1093",
                    "da84367f325d42d601b4326964802e8e",
                    "e37b1c6aa2846f6fdb413f238b089f23",
                    "6c002b682483e0cabcc731c253be5674",
                    "143ae8ed6555aba96110ab58893a8ae1",
                    "b69418a85332240dc82492353956ae0c",
                    "71b5c08a1993e1362e4d0ce9b22b78d5",
                    "e234cdca2606b81f29408d5f6da21206",
                    "13237c49074a3da078dc1d828bb78c6f",
                    "3071a2a48fe6cbd04f1a129098e308f8",
                    "90f42ec0f68385f2ffc5dfc03a654dce",
                    "febd9a24d8b65c1c787d50a4ed3619a9",
                };
                
                const std::string AES128_ECB_SBOX_PLAIN = "00000000000000000000000000000000";
                
                const std::vector<std::string> AES128_ECB_SBOX_CIPHER = {
                    "6d251e6944b051e04eaa6fb4dbf78465",
                    "6e29201190152df4ee058139def610bb",
                    "c3b44b95d9d2f25670eee9a0de099fa3",
                    "5d9b05578fc944b3cf1ccf0e746cd581",
                    "f7efc89d5dba578104016ce5ad659c05",
                    "0306194f666d183624aa230a8b264ae7",
                    "858075d536d79ccee571f7d7204b1f67",
                    "35870c6a57e9e92314bcb8087cde72ce",
                    "6c68e9be5ec41e22c825b7c7affb4363",
                    "f5df39990fc688f1b07224cc03e86cea",
                    "bba071bcb470f8f6586e5d3add18bc66",
                    "43c9f7e62f5d288bb27aa40ef8fe1ea8",
                    "3580d19cff44f1014a7c966a69059de5",
                    "806da864dd29d48deafbe764f8202aef",
                    "a303d940ded8f0baff6f75414cac5243",
                    "c2dabd117f8a3ecabfbb11d12194d9d0",
                    "fff60a4740086b3b9c56195b98d91a7b",
                    "8146a08e2357f0caa30ca8c94d1a0544",
                    "4b98e06d356deb07ebb824e5713f7be3",
                    "7a20a53d460fc9ce0423a7a0764c6cf2",
                    "f4a70d8af877f9b02b4c40df57d45b17",
                };
                
                VERIFY_ARE_EQUAL(AES128_ECB_SBOX_KEY.size(), AES128_ECB_SBOX_CIPHER.size());
                const std::string UNHEX_AES128_ECB_SBOX_PLAIN = unhexlify(AES128_ECB_SBOX_PLAIN);
                for ( unsigned int i = 0; i < AES128_ECB_SBOX_KEY.size(); ++i ) {
                    auto aes128 = AES(unhexlify(AES128_ECB_SBOX_KEY[i]));
                    VERIFY_ARE_EQUAL(hexlify(aes128.encrypt(UNHEX_AES128_ECB_SBOX_PLAIN)), AES128_ECB_SBOX_CIPHER[i]);
                    VERIFY_ARE_EQUAL(aes128.decrypt(unhexlify(AES128_ECB_SBOX_CIPHER[i])), UNHEX_AES128_ECB_SBOX_PLAIN);
                }
            }
            
            TEST(varkey) {
                const std::vector<std::string> AES128_ECB_VARKEY_KEY = {
                    "80000000000000000000000000000000",
                    "c0000000000000000000000000000000",
                    "e0000000000000000000000000000000",
                    "f0000000000000000000000000000000",
                    "f8000000000000000000000000000000",
                    "fc000000000000000000000000000000",
                    "fe000000000000000000000000000000",
                    "ff000000000000000000000000000000",
                    "ff800000000000000000000000000000",
                    "ffc00000000000000000000000000000",
                    "ffe00000000000000000000000000000",
                    "fff00000000000000000000000000000",
                    "fff80000000000000000000000000000",
                    "fffc0000000000000000000000000000",
                    "fffe0000000000000000000000000000",
                    "ffff0000000000000000000000000000",
                    "ffff8000000000000000000000000000",
                    "ffffc000000000000000000000000000",
                    "ffffe000000000000000000000000000",
                    "fffff000000000000000000000000000",
                    "fffff800000000000000000000000000",
                    "fffffc00000000000000000000000000",
                    "fffffe00000000000000000000000000",
                    "ffffff00000000000000000000000000",
                    "ffffff80000000000000000000000000",
                    "ffffffc0000000000000000000000000",
                    "ffffffe0000000000000000000000000",
                    "fffffff0000000000000000000000000",
                    "fffffff8000000000000000000000000",
                    "fffffffc000000000000000000000000",
                    "fffffffe000000000000000000000000",
                    "ffffffff000000000000000000000000",
                    "ffffffff800000000000000000000000",
                    "ffffffffc00000000000000000000000",
                    "ffffffffe00000000000000000000000",
                    "fffffffff00000000000000000000000",
                    "fffffffff80000000000000000000000",
                    "fffffffffc0000000000000000000000",
                    "fffffffffe0000000000000000000000",
                    "ffffffffff0000000000000000000000",
                    "ffffffffff8000000000000000000000",
                    "ffffffffffc000000000000000000000",
                    "ffffffffffe000000000000000000000",
                    "fffffffffff000000000000000000000",
                    "fffffffffff800000000000000000000",
                    "fffffffffffc00000000000000000000",
                    "fffffffffffe00000000000000000000",
                    "ffffffffffff00000000000000000000",
                    "ffffffffffff80000000000000000000",
                    "ffffffffffffc0000000000000000000",
                    "ffffffffffffe0000000000000000000",
                    "fffffffffffff0000000000000000000",
                    "fffffffffffff8000000000000000000",
                    "fffffffffffffc000000000000000000",
                    "fffffffffffffe000000000000000000",
                    "ffffffffffffff000000000000000000",
                    "ffffffffffffff800000000000000000",
                    "ffffffffffffffc00000000000000000",
                    "ffffffffffffffe00000000000000000",
                    "fffffffffffffff00000000000000000",
                    "fffffffffffffff80000000000000000",
                    "fffffffffffffffc0000000000000000",
                    "fffffffffffffffe0000000000000000",
                    "ffffffffffffffff0000000000000000",
                    "ffffffffffffffff8000000000000000",
                    "ffffffffffffffffc000000000000000",
                    "ffffffffffffffffe000000000000000",
                    "fffffffffffffffff000000000000000",
                    "fffffffffffffffff800000000000000",
                    "fffffffffffffffffc00000000000000",
                    "fffffffffffffffffe00000000000000",
                    "ffffffffffffffffff00000000000000",
                    "ffffffffffffffffff80000000000000",
                    "ffffffffffffffffffc0000000000000",
                    "ffffffffffffffffffe0000000000000",
                    "fffffffffffffffffff0000000000000",
                    "fffffffffffffffffff8000000000000",
                    "fffffffffffffffffffc000000000000",
                    "fffffffffffffffffffe000000000000",
                    "ffffffffffffffffffff000000000000",
                    "ffffffffffffffffffff800000000000",
                    "ffffffffffffffffffffc00000000000",
                    "ffffffffffffffffffffe00000000000",
                    "fffffffffffffffffffff00000000000",
                    "fffffffffffffffffffff80000000000",
                    "fffffffffffffffffffffc0000000000",
                    "fffffffffffffffffffffe0000000000",
                    "ffffffffffffffffffffff0000000000",
                    "ffffffffffffffffffffff8000000000",
                    "ffffffffffffffffffffffc000000000",
                    "ffffffffffffffffffffffe000000000",
                    "fffffffffffffffffffffff000000000",
                    "fffffffffffffffffffffff800000000",
                    "fffffffffffffffffffffffc00000000",
                    "fffffffffffffffffffffffe00000000",
                    "ffffffffffffffffffffffff00000000",
                    "ffffffffffffffffffffffff80000000",
                    "ffffffffffffffffffffffffc0000000",
                    "ffffffffffffffffffffffffe0000000",
                    "fffffffffffffffffffffffff0000000",
                    "fffffffffffffffffffffffff8000000",
                    "fffffffffffffffffffffffffc000000",
                    "fffffffffffffffffffffffffe000000",
                    "ffffffffffffffffffffffffff000000",
                    "ffffffffffffffffffffffffff800000",
                    "ffffffffffffffffffffffffffc00000",
                    "ffffffffffffffffffffffffffe00000",
                    "fffffffffffffffffffffffffff00000",
                    "fffffffffffffffffffffffffff80000",
                    "fffffffffffffffffffffffffffc0000",
                    "fffffffffffffffffffffffffffe0000",
                    "ffffffffffffffffffffffffffff0000",
                    "ffffffffffffffffffffffffffff8000",
                    "ffffffffffffffffffffffffffffc000",
                    "ffffffffffffffffffffffffffffe000",
                    "fffffffffffffffffffffffffffff000",
                    "fffffffffffffffffffffffffffff800",
                    "fffffffffffffffffffffffffffffc00",
                    "fffffffffffffffffffffffffffffe00",
                    "ffffffffffffffffffffffffffffff00",
                    "ffffffffffffffffffffffffffffff80",
                    "ffffffffffffffffffffffffffffffc0",
                    "ffffffffffffffffffffffffffffffe0",
                    "fffffffffffffffffffffffffffffff0",
                    "fffffffffffffffffffffffffffffff8",
                    "fffffffffffffffffffffffffffffffc",
                    "fffffffffffffffffffffffffffffffe",
                    "ffffffffffffffffffffffffffffffff",
                };
                
                const std::string AES128_ECB_VARKEY_PLAIN = "00000000000000000000000000000000";
                
                const std::vector<std::string> AES128_ECB_VARKEY_CIPHER = {
                    "0edd33d3c621e546455bd8ba1418bec8",
                    "4bc3f883450c113c64ca42e1112a9e87",
                    "72a1da770f5d7ac4c9ef94d822affd97",
                    "970014d634e2b7650777e8e84d03ccd8",
                    "f17e79aed0db7e279e955b5f493875a7",
                    "9ed5a75136a940d0963da379db4af26a",
                    "c4295f83465c7755e8fa364bac6a7ea5",
                    "b1d758256b28fd850ad4944208cf1155",
                    "42ffb34c743de4d88ca38011c990890b",
                    "9958f0ecea8b2172c0c1995f9182c0f3",
                    "956d7798fac20f82a8823f984d06f7f5",
                    "a01bf44f2d16be928ca44aaf7b9b106b",
                    "b5f1a33e50d40d103764c76bd4c6b6f8",
                    "2637050c9fc0d4817e2d69de878aee8d",
                    "113ecbe4a453269a0dd26069467fb5b5",
                    "97d0754fe68f11b9e375d070a608c884",
                    "c6a0b3e998d05068a5399778405200b4",
                    "df556a33438db87bc41b1752c55e5e49",
                    "90fb128d3a1af6e548521bb962bf1f05",
                    "26298e9c1db517c215fadfb7d2a8d691",
                    "a6cb761d61f8292d0df393a279ad0380",
                    "12acd89b13cd5f8726e34d44fd486108",
                    "95b1703fc57ba09fe0c3580febdd7ed4",
                    "de11722d893e9f9121c381becc1da59a",
                    "6d114ccb27bf391012e8974c546d9bf2",
                    "5ce37e17eb4646ecfac29b9cc38d9340",
                    "18c1b6e2157122056d0243d8a165cddb",
                    "99693e6a59d1366c74d823562d7e1431",
                    "6c7c64dc84a8bba758ed17eb025a57e3",
                    "e17bc79f30eaab2fac2cbbe3458d687a",
                    "1114bc2028009b923f0b01915ce5e7c4",
                    "9c28524a16a1e1c1452971caa8d13476",
                    "ed62e16363638360fdd6ad62112794f0",
                    "5a8688f0b2a2c16224c161658ffd4044",
                    "23f710842b9bb9c32f26648c786807ca",
                    "44a98bf11e163f632c47ec6a49683a89",
                    "0f18aff94274696d9b61848bd50ac5e5",
                    "82408571c3e2424540207f833b6dda69",
                    "303ff996947f0c7d1f43c8f3027b9b75",
                    "7df4daf4ad29a3615a9b6ece5c99518a",
                    "c72954a48d0774db0b4971c526260415",
                    "1df9b76112dc6531e07d2cfda04411f0",
                    "8e4d8e699119e1fc87545a647fb1d34f",
                    "e6c4807ae11f36f091c57d9fb68548d1",
                    "8ebf73aad49c82007f77a5c1ccec6ab4",
                    "4fb288cc2040049001d2c7585ad123fc",
                    "04497110efb9dceb13e2b13fb4465564",
                    "75550e6cb5a88e49634c9ab69eda0430",
                    "b6768473ce9843ea66a81405dd50b345",
                    "cb2f430383f9084e03a653571e065de6",
                    "ff4e66c07bae3e79fb7d210847a3b0ba",
                    "7b90785125505fad59b13c186dd66ce3",
                    "8b527a6aebdaec9eaef8eda2cb7783e5",
                    "43fdaf53ebbc9880c228617d6a9b548b",
                    "53786104b9744b98f052c46f1c850d0b",
                    "b5ab3013dd1e61df06cbaf34ca2aee78",
                    "7470469be9723030fdcc73a8cd4fbb10",
                    "a35a63f5343ebe9ef8167bcb48ad122e",
                    "fd8687f0757a210e9fdf181204c30863",
                    "7a181e84bd5457d26a88fbae96018fb0",
                    "653317b9362b6f9b9e1a580e68d494b5",
                    "995c9dc0b689f03c45867b5faa5c18d1",
                    "77a4d96d56dda398b9aabecfc75729fd",
                    "84be19e053635f09f2665e7bae85b42d",
                    "32cd652842926aea4aa6137bb2be2b5e",
                    "493d4a4f38ebb337d10aa84e9171a554",
                    "d9bff7ff454b0ec5a4a2a69566e2cb84",
                    "3535d565ace3f31eb249ba2cc6765d7a",
                    "f60e91fc3269eecf3231c6e9945697c6",
                    "ab69cfadf51f8e604d9cc37182f6635a",
                    "7866373f24a0b6ed56e0d96fcdafb877",
                    "1ea448c2aac954f5d812e9d78494446a",
                    "acc5599dd8ac02239a0fef4a36dd1668",
                    "d8764468bb103828cf7e1473ce895073",
                    "1b0d02893683b9f180458e4aa6b73982",
                    "96d9b017d302df410a937dcdb8bb6e43",
                    "ef1623cc44313cff440b1594a7e21cc6",
                    "284ca2fa35807b8b0ae4d19e11d7dbd7",
                    "f2e976875755f9401d54f36e2a23a594",
                    "ec198a18e10e532403b7e20887c8dd80",
                    "545d50ebd919e4a6949d96ad47e46a80",
                    "dbdfb527060e0a71009c7bb0c68f1d44",
                    "9cfa1322ea33da2173a024f2ff0d896d",
                    "8785b1a75b0f3bd958dcd0e29318c521",
                    "38f67b9e98e4a97b6df030a9fcdd0104",
                    "192afffb2c880e82b05926d0fc6c448b",
                    "6a7980ce7b105cf530952d74daaf798c",
                    "ea3695e1351b9d6858bd958cf513ef6c",
                    "6da0490ba0ba0343b935681d2cce5ba1",
                    "f0ea23af08534011c60009ab29ada2f1",
                    "ff13806cf19cc38721554d7c0fcdcd4b",
                    "6838af1f4f69bae9d85dd188dcdf0688",
                    "36cf44c92d550bfb1ed28ef583ddf5d7",
                    "d06e3195b5376f109d5c4ec6c5d62ced",
                    "c440de014d3d610707279b13242a5c36",
                    "f0c5c6ffa5e0bd3a94c88f6b6f7c16b9",
                    "3e40c3901cd7effc22bffc35dee0b4d9",
                    "b63305c72bedfab97382c406d0c49bc6",
                    "36bbaab22a6bd4925a99a2b408d2dbae",
                    "307c5b8fcd0533ab98bc51e27a6ce461",
                    "829c04ff4c07513c0b3ef05c03e337b5",
                    "f17af0e895dda5eb98efc68066e84c54",
                    "277167f3812afff1ffacb4a934379fc3",
                    "2cb1dc3a9c72972e425ae2ef3eb597cd",
                    "36aeaa3a213e968d4b5b679d3a2c97fe",
                    "9241daca4fdd034a82372db50e1a0f3f",
                    "c14574d9cd00cf2b5a7f77e53cd57885",
                    "793de39236570aba83ab9b737cb521c9",
                    "16591c0f27d60e29b85a96c33861a7ef",
                    "44fb5c4d4f5cb79be5c174a3b1c97348",
                    "674d2b61633d162be59dde04222f4740",
                    "b4750ff263a65e1f9e924ccfd98f3e37",
                    "62d0662d6eaeddedebae7f7ea3a4f6b6",
                    "70c46bb30692be657f7eaa93ebad9897",
                    "323994cfb9da285a5d9642e1759b224a",
                    "1dbf57877b7b17385c85d0b54851e371",
                    "dfa5c097cdc1532ac071d57b1d28d1bd",
                    "3a0c53fa37311fc10bd2a9981f513174",
                    "ba4f970c0a25c41814bdae2e506be3b4",
                    "2dce3acb727cd13ccd76d425ea56e4f6",
                    "5160474d504b9b3eefb68d35f245f4b3",
                    "41a8a947766635dec37553d9a6c0cbb7",
                    "25d6cfe6881f2bf497dd14cd4ddf445b",
                    "41c78c135ed9e98c096640647265da1e",
                    "5a4d404d8917e353e92a21072c3b2305",
                    "02bc96846b3fdc71643f384cd3cc3eaf",
                    "9ba4a9143f4e5d4048521c4f8877d88e",
                    "a1f6258c877d5fcd8964484538bfc92c",
                };
                VERIFY_ARE_EQUAL(AES128_ECB_VARKEY_KEY.size(), AES128_ECB_VARKEY_CIPHER.size());
                const std::string UNHEX_AES128_ECB_VARKEY_PLAIN = unhexlify(AES128_ECB_VARKEY_PLAIN);
                for ( unsigned int i = 0; i < AES128_ECB_VARKEY_KEY.size(); ++i ) {
                    auto aes128 = AES(unhexlify(AES128_ECB_VARKEY_KEY[i]));
                    VERIFY_ARE_EQUAL(hexlify(aes128.encrypt(UNHEX_AES128_ECB_VARKEY_PLAIN)), AES128_ECB_VARKEY_CIPHER[i]);
                    VERIFY_ARE_EQUAL(aes128.decrypt(unhexlify(AES128_ECB_VARKEY_CIPHER[i])), UNHEX_AES128_ECB_VARKEY_PLAIN);
                }
            }
            
            TEST(vartxt) {
                const std::string AES128_ECB_VARTXT_KEY = "00000000000000000000000000000000";
                
                static const std::vector<std::string> AES128_ECB_VARTXT_PLAIN = {
                    "80000000000000000000000000000000",
                    "c0000000000000000000000000000000",
                    "e0000000000000000000000000000000",
                    "f0000000000000000000000000000000",
                    "f8000000000000000000000000000000",
                    "fc000000000000000000000000000000",
                    "fe000000000000000000000000000000",
                    "ff000000000000000000000000000000",
                    "ff800000000000000000000000000000",
                    "ffc00000000000000000000000000000",
                    "ffe00000000000000000000000000000",
                    "fff00000000000000000000000000000",
                    "fff80000000000000000000000000000",
                    "fffc0000000000000000000000000000",
                    "fffe0000000000000000000000000000",
                    "ffff0000000000000000000000000000",
                    "ffff8000000000000000000000000000",
                    "ffffc000000000000000000000000000",
                    "ffffe000000000000000000000000000",
                    "fffff000000000000000000000000000",
                    "fffff800000000000000000000000000",
                    "fffffc00000000000000000000000000",
                    "fffffe00000000000000000000000000",
                    "ffffff00000000000000000000000000",
                    "ffffff80000000000000000000000000",
                    "ffffffc0000000000000000000000000",
                    "ffffffe0000000000000000000000000",
                    "fffffff0000000000000000000000000",
                    "fffffff8000000000000000000000000",
                    "fffffffc000000000000000000000000",
                    "fffffffe000000000000000000000000",
                    "ffffffff000000000000000000000000",
                    "ffffffff800000000000000000000000",
                    "ffffffffc00000000000000000000000",
                    "ffffffffe00000000000000000000000",
                    "fffffffff00000000000000000000000",
                    "fffffffff80000000000000000000000",
                    "fffffffffc0000000000000000000000",
                    "fffffffffe0000000000000000000000",
                    "ffffffffff0000000000000000000000",
                    "ffffffffff8000000000000000000000",
                    "ffffffffffc000000000000000000000",
                    "ffffffffffe000000000000000000000",
                    "fffffffffff000000000000000000000",
                    "fffffffffff800000000000000000000",
                    "fffffffffffc00000000000000000000",
                    "fffffffffffe00000000000000000000",
                    "ffffffffffff00000000000000000000",
                    "ffffffffffff80000000000000000000",
                    "ffffffffffffc0000000000000000000",
                    "ffffffffffffe0000000000000000000",
                    "fffffffffffff0000000000000000000",
                    "fffffffffffff8000000000000000000",
                    "fffffffffffffc000000000000000000",
                    "fffffffffffffe000000000000000000",
                    "ffffffffffffff000000000000000000",
                    "ffffffffffffff800000000000000000",
                    "ffffffffffffffc00000000000000000",
                    "ffffffffffffffe00000000000000000",
                    "fffffffffffffff00000000000000000",
                    "fffffffffffffff80000000000000000",
                    "fffffffffffffffc0000000000000000",
                    "fffffffffffffffe0000000000000000",
                    "ffffffffffffffff0000000000000000",
                    "ffffffffffffffff8000000000000000",
                    "ffffffffffffffffc000000000000000",
                    "ffffffffffffffffe000000000000000",
                    "fffffffffffffffff000000000000000",
                    "fffffffffffffffff800000000000000",
                    "fffffffffffffffffc00000000000000",
                    "fffffffffffffffffe00000000000000",
                    "ffffffffffffffffff00000000000000",
                    "ffffffffffffffffff80000000000000",
                    "ffffffffffffffffffc0000000000000",
                    "ffffffffffffffffffe0000000000000",
                    "fffffffffffffffffff0000000000000",
                    "fffffffffffffffffff8000000000000",
                    "fffffffffffffffffffc000000000000",
                    "fffffffffffffffffffe000000000000",
                    "ffffffffffffffffffff000000000000",
                    "ffffffffffffffffffff800000000000",
                    "ffffffffffffffffffffc00000000000",
                    "ffffffffffffffffffffe00000000000",
                    "fffffffffffffffffffff00000000000",
                    "fffffffffffffffffffff80000000000",
                    "fffffffffffffffffffffc0000000000",
                    "fffffffffffffffffffffe0000000000",
                    "ffffffffffffffffffffff0000000000",
                    "ffffffffffffffffffffff8000000000",
                    "ffffffffffffffffffffffc000000000",
                    "ffffffffffffffffffffffe000000000",
                    "fffffffffffffffffffffff000000000",
                    "fffffffffffffffffffffff800000000",
                    "fffffffffffffffffffffffc00000000",
                    "fffffffffffffffffffffffe00000000",
                    "ffffffffffffffffffffffff00000000",
                    "ffffffffffffffffffffffff80000000",
                    "ffffffffffffffffffffffffc0000000",
                    "ffffffffffffffffffffffffe0000000",
                    "fffffffffffffffffffffffff0000000",
                    "fffffffffffffffffffffffff8000000",
                    "fffffffffffffffffffffffffc000000",
                    "fffffffffffffffffffffffffe000000",
                    "ffffffffffffffffffffffffff000000",
                    "ffffffffffffffffffffffffff800000",
                    "ffffffffffffffffffffffffffc00000",
                    "ffffffffffffffffffffffffffe00000",
                    "fffffffffffffffffffffffffff00000",
                    "fffffffffffffffffffffffffff80000",
                    "fffffffffffffffffffffffffffc0000",
                    "fffffffffffffffffffffffffffe0000",
                    "ffffffffffffffffffffffffffff0000",
                    "ffffffffffffffffffffffffffff8000",
                    "ffffffffffffffffffffffffffffc000",
                    "ffffffffffffffffffffffffffffe000",
                    "fffffffffffffffffffffffffffff000",
                    "fffffffffffffffffffffffffffff800",
                    "fffffffffffffffffffffffffffffc00",
                    "fffffffffffffffffffffffffffffe00",
                    "ffffffffffffffffffffffffffffff00",
                    "ffffffffffffffffffffffffffffff80",
                    "ffffffffffffffffffffffffffffffc0",
                    "ffffffffffffffffffffffffffffffe0",
                    "fffffffffffffffffffffffffffffff0",
                    "fffffffffffffffffffffffffffffff8",
                    "fffffffffffffffffffffffffffffffc",
                    "fffffffffffffffffffffffffffffffe",
                    "ffffffffffffffffffffffffffffffff",
                };
                
                static const std::vector<std::string> AES128_ECB_VARTXT_CIPHER = {
                    "3ad78e726c1ec02b7ebfe92b23d9ec34",
                    "aae5939c8efdf2f04e60b9fe7117b2c2",
                    "f031d4d74f5dcbf39daaf8ca3af6e527",
                    "96d9fd5cc4f07441727df0f33e401a36",
                    "30ccdb044646d7e1f3ccea3dca08b8c0",
                    "16ae4ce5042a67ee8e177b7c587ecc82",
                    "b6da0bb11a23855d9c5cb1b4c6412e0a",
                    "db4f1aa530967d6732ce4715eb0ee24b",
                    "a81738252621dd180a34f3455b4baa2f",
                    "77e2b508db7fd89234caf7939ee5621a",
                    "b8499c251f8442ee13f0933b688fcd19",
                    "965135f8a81f25c9d630b17502f68e53",
                    "8b87145a01ad1c6cede995ea3670454f",
                    "8eae3b10a0c8ca6d1d3b0fa61e56b0b2",
                    "64b4d629810fda6bafdf08f3b0d8d2c5",
                    "d7e5dbd3324595f8fdc7d7c571da6c2a",
                    "f3f72375264e167fca9de2c1527d9606",
                    "8ee79dd4f401ff9b7ea945d86666c13b",
                    "dd35cea2799940b40db3f819cb94c08b",
                    "6941cb6b3e08c2b7afa581ebdd607b87",
                    "2c20f439f6bb097b29b8bd6d99aad799",
                    "625d01f058e565f77ae86378bd2c49b3",
                    "c0b5fd98190ef45fbb4301438d095950",
                    "13001ff5d99806efd25da34f56be854b",
                    "3b594c60f5c8277a5113677f94208d82",
                    "e9c0fc1818e4aa46bd2e39d638f89e05",
                    "f8023ee9c3fdc45a019b4e985c7e1a54",
                    "35f40182ab4662f3023baec1ee796b57",
                    "3aebbad7303649b4194a6945c6cc3694",
                    "a2124bea53ec2834279bed7f7eb0f938",
                    "b9fb4399fa4facc7309e14ec98360b0a",
                    "c26277437420c5d634f715aea81a9132",
                    "171a0e1b2dd424f0e089af2c4c10f32f",
                    "7cadbe402d1b208fe735edce00aee7ce",
                    "43b02ff929a1485af6f5c6d6558baa0f",
                    "092faacc9bf43508bf8fa8613ca75dea",
                    "cb2bf8280f3f9742c7ed513fe802629c",
                    "215a41ee442fa992a6e323986ded3f68",
                    "f21e99cf4f0f77cea836e11a2fe75fb1",
                    "95e3a0ca9079e646331df8b4e70d2cd6",
                    "4afe7f120ce7613f74fc12a01a828073",
                    "827f000e75e2c8b9d479beed913fe678",
                    "35830c8e7aaefe2d30310ef381cbf691",
                    "191aa0f2c8570144f38657ea4085ebe5",
                    "85062c2c909f15d9269b6c18ce99c4f0",
                    "678034dc9e41b5a560ed239eeab1bc78",
                    "c2f93a4ce5ab6d5d56f1b93cf19911c1",
                    "1c3112bcb0c1dcc749d799743691bf82",
                    "00c55bd75c7f9c881989d3ec1911c0d4",
                    "ea2e6b5ef182b7dff3629abd6a12045f",
                    "22322327e01780b17397f24087f8cc6f",
                    "c9cacb5cd11692c373b2411768149ee7",
                    "a18e3dbbca577860dab6b80da3139256",
                    "79b61c37bf328ecca8d743265a3d425c",
                    "d2d99c6bcc1f06fda8e27e8ae3f1ccc7",
                    "1bfd4b91c701fd6b61b7f997829d663b",
                    "11005d52f25f16bdc9545a876a63490a",
                    "3a4d354f02bb5a5e47d39666867f246a",
                    "d451b8d6e1e1a0ebb155fbbf6e7b7dc3",
                    "6898d4f42fa7ba6a10ac05e87b9f2080",
                    "b611295e739ca7d9b50f8e4c0e754a3f",
                    "7d33fc7d8abe3ca1936759f8f5deaf20",
                    "3b5e0f566dc96c298f0c12637539b25c",
                    "f807c3e7985fe0f5a50e2cdb25c5109e",
                    "41f992a856fb278b389a62f5d274d7e9",
                    "10d3ed7a6fe15ab4d91acbc7d0767ab1",
                    "21feecd45b2e675973ac33bf0c5424fc",
                    "1480cb3955ba62d09eea668f7c708817",
                    "66404033d6b72b609354d5496e7eb511",
                    "1c317a220a7d700da2b1e075b00266e1",
                    "ab3b89542233f1271bf8fd0c0f403545",
                    "d93eae966fac46dca927d6b114fa3f9e",
                    "1bdec521316503d9d5ee65df3ea94ddf",
                    "eef456431dea8b4acf83bdae3717f75f",
                    "06f2519a2fafaa596bfef5cfa15c21b9",
                    "251a7eac7e2fe809e4aa8d0d7012531a",
                    "3bffc16e4c49b268a20f8d96a60b4058",
                    "e886f9281999c5bb3b3e8862e2f7c988",
                    "563bf90d61beef39f48dd625fcef1361",
                    "4d37c850644563c69fd0acd9a049325b",
                    "b87c921b91829ef3b13ca541ee1130a6",
                    "2e65eb6b6ea383e109accce8326b0393",
                    "9ca547f7439edc3e255c0f4d49aa8990",
                    "a5e652614c9300f37816b1f9fd0c87f9",
                    "14954f0b4697776f44494fe458d814ed",
                    "7c8d9ab6c2761723fe42f8bb506cbcf7",
                    "db7e1932679fdd99742aab04aa0d5a80",
                    "4c6a1c83e568cd10f27c2d73ded19c28",
                    "90ecbe6177e674c98de412413f7ac915",
                    "90684a2ac55fe1ec2b8ebd5622520b73",
                    "7472f9a7988607ca79707795991035e6",
                    "56aff089878bf3352f8df172a3ae47d8",
                    "65c0526cbe40161b8019a2a3171abd23",
                    "377be0be33b4e3e310b4aabda173f84f",
                    "9402e9aa6f69de6504da8d20c4fcaa2f",
                    "123c1f4af313ad8c2ce648b2e71fb6e1",
                    "1ffc626d30203dcdb0019fb80f726cf4",
                    "76da1fbe3a50728c50fd2e621b5ad885",
                    "082eb8be35f442fb52668e16a591d1d6",
                    "e656f9ecf5fe27ec3e4a73d00c282fb3",
                    "2ca8209d63274cd9a29bb74bcd77683a",
                    "79bf5dce14bb7dd73a8e3611de7ce026",
                    "3c849939a5d29399f344c4a0eca8a576",
                    "ed3c0a94d59bece98835da7aa4f07ca2",
                    "63919ed4ce10196438b6ad09d99cd795",
                    "7678f3a833f19fea95f3c6029e2bc610",
                    "3aa426831067d36b92be7c5f81c13c56",
                    "9272e2d2cdd11050998c845077a30ea0",
                    "088c4b53f5ec0ff814c19adae7f6246c",
                    "4010a5e401fdf0a0354ddbcc0d012b17",
                    "a87a385736c0a6189bd6589bd8445a93",
                    "545f2b83d9616dccf60fa9830e9cd287",
                    "4b706f7f92406352394037a6d4f4688d",
                    "b7972b3941c44b90afa7b264bfba7387",
                    "6f45732cf10881546f0fd23896d2bb60",
                    "2e3579ca15af27f64b3c955a5bfc30ba",
                    "34a2c5a91ae2aec99b7d1b5fa6780447",
                    "a4d6616bd04f87335b0e53351227a9ee",
                    "7f692b03945867d16179a8cefc83ea3f",
                    "3bd141ee84a0e6414a26e7a4f281f8a2",
                    "d1788f572d98b2b16ec5d5f3922b99bc",
                    "0833ff6f61d98a57b288e8c3586b85a6",
                    "8568261797de176bf0b43becc6285afb",
                    "f9b0fda0c4a898f5b9e6f661c4ce4d07",
                    "8ade895913685c67c5269f8aae42983e",
                    "39bde67d5c8ed8a8b1c37eb8fa9f5ac0",
                    "5c005e72c1418c44f569f2ea33ba54f3",
                    "3f5b8cc9ea855a0afa7347d23e8d664e",
                };
                
                VERIFY_ARE_EQUAL(AES128_ECB_VARTXT_PLAIN.size(), AES128_ECB_VARTXT_CIPHER.size());
                const std::string UNHEX_AES128_ECB_VARTXT_KEY = unhexlify(AES128_ECB_VARTXT_KEY);
                for ( unsigned int i = 0; i < AES128_ECB_VARTXT_PLAIN.size(); ++i ) {
                    auto aes128 = AES(UNHEX_AES128_ECB_VARTXT_KEY);
                    VERIFY_ARE_EQUAL(hexlify(aes128.encrypt(unhexlify(AES128_ECB_VARTXT_PLAIN[i]))), AES128_ECB_VARTXT_CIPHER[i]);
                    VERIFY_ARE_EQUAL(hexlify(aes128.decrypt(unhexlify(AES128_ECB_VARTXT_CIPHER[i]))), AES128_ECB_VARTXT_PLAIN[i]);
                }
            }
        }
    }
}
