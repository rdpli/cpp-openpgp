//
//  ezvcard_test.cpp
//  OpenPGP
//
//  Created by Yanfeng Zhang on 12/2/16.
//
//  The MIT License
// 
//  Copyright (c) 2019 Proton Technologies AG
// 
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
// 
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
// 
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.


#include "utils_test.h"
#include <ezvcard/ezvcard.hpp>
#include <ezvcard/vcard.hpp>
#include <ezvcard/io/chain/chaining_text_string_parser.hpp>
#include <regex>
#include "utility.h"

using namespace ezvcard;

namespace tests {
    namespace ez_vcard_tests {
        SUITE(ez_vcard_test)
        {
            TEST(correct_vCard4_with_photo) {
                // must have extra line ending
                std::string str = R"(BEGIN:VCARD
VERSION:4.0
PRODID:pm-ez-vcard 0.0.1
PHOTO:data:image/jpeg;base64,cLaxHfZiBSjwsi5i
FN:Andrew Smith
END:VCARD
)";
                str = ProtonMail::replaceAll(str, "\n", "\r\n"); // convert line ending for raw string

                // check and read from input
                auto vcard = Ezvcard::parse(str).first();
                auto formattedName = vcard->getFormattedName();
                VERIFY_ARE_EQUAL(formattedName->getValue(), "Andrew Smith");

                // clone and verify the new vCard
                auto newVCard = std::make_shared<VCard>();
                newVCard->setVersion(VCardVersion::V4_0());
                newVCard->setFormattedName(std::make_shared<FormattedName>(formattedName->getValue()));

                auto photos = vcard->getPhotos();
                for(auto photo : photos)
                    newVCard->addPhoto(photo);
                auto out = Ezvcard::write(newVCard)->go();
                VERIFY_ARE_EQUAL(out, str);
            }
            
            TEST(correct_vCard4_with_photo_ios_way) {
                // must have extra line ending
                std::string str = R"(BEGIN:VCARD
VERSION:4.0
PRODID:pm-ez-vcard 0.0.1
PHOTO:data:image/jpeg;base64,cLaxHfZiBSjwsi5i
FN:Andrew Smith
END:VCARD
)";
                str = ProtonMail::replaceAll(str, "\n", "\r\n"); // convert line ending for raw string
                
                // check and read from input
                auto vcard = Ezvcard::parse(str).first();
                auto formattedName = vcard->getFormattedName();
                VERIFY_ARE_EQUAL(formattedName->getValue(), "Andrew Smith");
                
                // clone and verify the new vCard
                auto newVCard = std::make_shared<VCard>();
                newVCard->setVersion(VCardVersion::V4_0());
                newVCard->setFormattedName(std::make_shared<FormattedName>(formattedName->getValue()));
                
                auto photo = vcard->getPhoto();
                auto newPhoto = Photo::create_instance(photo->getRawData(), photo->getImageType(), photo->getIsBinary());
                newVCard->setPhoto(newPhoto);
                auto out = Ezvcard::write(newVCard)->go();
                VERIFY_ARE_EQUAL(out, str);
            }
            
            TEST(correct_vCard3_with_photo) {
                std::string str = R"(BEGIN:VCARD
VERSION:3.0
PRODID:pm-ez-vcard 0.0.1
PHOTO;ENCODING=b:cLaxHfZiBSjwsi5i+Pu7OGfjmZtXtDavaNE4Sm1e0Nq9o0f/9kk=
FN:Andrew Smith
END:VCARD
)";
                str = ProtonMail::replaceAll(str, "\n", "\r\n");

                // check and read from input
                auto vcard = Ezvcard::parse(str).first();
                auto formattedName = vcard->getFormattedName();
                VERIFY_ARE_EQUAL(formattedName->getValue(), "Andrew Smith");

                // clone and verify the new vCard
                auto newVCard = std::make_shared<VCard>();
                newVCard->setVersion(VCardVersion::V3_0());
                newVCard->setFormattedName(std::make_shared<FormattedName>(formattedName->getValue()));
                auto photos = vcard->getPhotos();
                for(auto photo : photos)
                    newVCard->addPhoto(photo);
                auto out = Ezvcard::write(newVCard)->go();
                VERIFY_ARE_EQUAL(out, str);
            }
            
            TEST(test_vcard_with_bad_notes) {
                // must have extra line ending
                std::string str = R"(BEGIN:VCARD
VERSION:4.0
PRODID:pm-ez-vcard 0.0.1
NOTE:Поротата уште во декември едногласно го прогласи за виновен по пет точки за сексуална злоупотреба на деца помлади од 16 години. Самата пресуда и деталите на целиот случај остануваат тајна сè до следниот вторник поради правни причини.\n\n
END:VCARD
)";
                str = ProtonMail::replaceAll(str, "\n", "\r\n"); // convert line ending for raw string
                
                // clone and verify the new vCard
                auto newVCard = std::make_shared<VCard>();
                newVCard->setVersion(VCardVersion::V4_0());
                
                std::string note = "Поротата уште во декември едногласно го прогласи за виновен по пет точки за сексуална злоупотреба на деца помлади од 16 години. Самата пресуда и деталите на целиот случај остануваат тајна сè до следниот вторник поради правни причини.\n\n";
                Note::Ptr newNote = std::make_shared<ezvcard::Note>(note);
                newNote->setType("");
                newVCard->setNote(newNote);
                auto out = Ezvcard::write(newVCard)->go();
                VERIFY_ARE_EQUAL(out, str);
            }
            
            TEST(incorrect_v4_with_V3_photo_data_ios_way) {
                std::string str = R"(BEGIN:VCARD
VERSION:4.0
PRODID:pm-ez-vcard 0.0.1
PHOTO;ENCODING=b:cLaxHfZiBSk=
FN:Andrew Smith
END:VCARD
)";
                str = ProtonMail::replaceAll(str, "\n", "\r\n");
                
                // check and read from input
                auto vcard = Ezvcard::parse(str).first();
                auto formattedName = vcard->getFormattedName();
                VERIFY_ARE_EQUAL(formattedName->getValue(), "Andrew Smith");
                
                // clone and verify the new vCard
                auto newVCard = std::make_shared<VCard>();
                newVCard->setVersion(VCardVersion::V4_0());
                newVCard->setFormattedName(std::make_shared<FormattedName>(formattedName->getValue()));
                auto photo = vcard->getPhoto();
                auto newPhoto = Photo::create_instance(photo->getRawData(), photo->getImageType(), photo->getIsBinary());
                newVCard->setPhoto(newPhoto);
                auto out = Ezvcard::write(newVCard)->go();
                
                std::string rightStr = R"(BEGIN:VCARD
VERSION:4.0
PRODID:pm-ez-vcard 0.0.1
PHOTO:data:application/octet-stream;base64,cLaxHfZiBSk=
FN:Andrew Smith
END:VCARD
)";
                rightStr = ProtonMail::replaceAll(rightStr, "\n", "\r\n");
                VERIFY_ARE_EQUAL(out, rightStr);
            }
            
            TEST(incorrect_v4_with_V3_photo_data) {
                std::string str = R"(BEGIN:VCARD
VERSION:4.0
PRODID:pm-ez-vcard 0.0.1
PHOTO;ENCODING=b:cLaxHfZiBSk=
FN:Andrew Smith
END:VCARD
)";
                str = ProtonMail::replaceAll(str, "\n", "\r\n");
                
                // check and read from input
                auto vcard = Ezvcard::parse(str).first();
                auto formattedName = vcard->getFormattedName();
                VERIFY_ARE_EQUAL(formattedName->getValue(), "Andrew Smith");
                
                // clone and verify the new vCard
                auto newVCard = std::make_shared<VCard>();
                newVCard->setVersion(VCardVersion::V4_0());
                newVCard->setFormattedName(std::make_shared<FormattedName>(formattedName->getValue()));
                auto photos = vcard->getPhotos();
                for(auto photo : photos)
                    newVCard->addPhoto(photo);
                auto out = Ezvcard::write(newVCard)->go();
                
                std::string rightStr = R"(BEGIN:VCARD
VERSION:4.0
PRODID:pm-ez-vcard 0.0.1
PHOTO:data:application/octet-stream;base64,cLaxHfZiBSk=
FN:Andrew Smith
END:VCARD
)";
                rightStr = ProtonMail::replaceAll(rightStr, "\n", "\r\n");
                VERIFY_ARE_EQUAL(out, rightStr);
            }
            
            TEST(case_insensitive_group_string_query_test)
            {
                auto str =
                "BEGIN:VCARD\r\n"
                "VERSION:4.0\r\n"
                "PRODID:-//ProtonMail//ProtonMail vCard 1.0.0//EN\r\n"
                "ITEM1.CATEGORIES:Family,iOS dev team,9\r\n"
                "ITEM2.CATEGORIES:Family,10\r\n"
                "END:VCARD\r\n";
                
                auto vcard = Ezvcard::parse(str).first();
                
                auto c1 = vcard->getCategories("iTeM1");
                auto c2 = vcard->getCategories("ItEm2");
                
                auto c1All = c1->getValues();
                auto c2All = c2->getValues();
                
                auto check1 = std::vector<std::string>{"Family", "iOS dev team", "9"};
                VERIFY_ARE_EQUAL(c1All, check1);
                auto check2 = std::vector<std::string> {"Family", "10"};
                VERIFY_ARE_EQUAL(c2All, check2);
                
                auto newVCard = std::make_shared<VCard>();
                
                newVCard->setVersion(VCardVersion::V4_0());
                
                auto category1 = Categories::create_instance("item1", check1);
                auto category2 = Categories::create_instance("item2", check2);
                
                newVCard->addCategories(category1);
                newVCard->addCategories(category2);
                
                
                auto out = Ezvcard::write(newVCard)->go();
                
                auto outString =
                "BEGIN:VCARD\r\n"
                "VERSION:4.0\r\n"
                "PRODID:pm-ez-vcard 0.0.1\r\n"
                "item1.CATEGORIES:Family,iOS dev team,9\r\n"
                "item2.CATEGORIES:Family,10\r\n"
                "END:VCARD\r\n";
                
                VERIFY_ARE_EQUAL(out, outString);
                
                newVCard->setCategories(category1);
                newVCard->addCategories(category2);
                
                auto out1 = Ezvcard::write(newVCard)->go();
                VERIFY_ARE_EQUAL(out1, outString);
            }
            
            TEST(real_cases_test) {
                
                {
                    auto str =
                    "BEGIN:VCARD\r\n"
                    "VERSION:4.0\r\n"
                    "PRODID:-//ProtonMail//ProtonMail vCard 1.0.0//EN\r\n"
                    "ITEM1.CATEGORIES:Family,iOS dev team,9\r\n"
                    "ITEM2.CATEGORIES:Family,10\r\n"
                    "END:VCARD\r\n";
                    
                    auto vcard = Ezvcard::parse(str).first();
                    
                    auto c1 = vcard->getCategories("ITEM1");
                    auto c2 = vcard->getCategories("ITEM2");
                    
                    auto c1All = c1->getValues();
                    auto c2All = c2->getValues();

                    auto check1 = std::vector<std::string>{"Family", "iOS dev team", "9"};
                    VERIFY_ARE_EQUAL(c1All, check1);
                    auto check2 = std::vector<std::string> {"Family", "10"};
                    VERIFY_ARE_EQUAL(c2All, check2);
                    
                    auto newVCard = std::make_shared<VCard>();
                    
                    newVCard->setVersion(VCardVersion::V4_0());
                    
                    auto category1 = Categories::create_instance("item1", check1);
                    auto category2 = Categories::create_instance("item2", check2);
                    
                    newVCard->addCategories(category1);
                    newVCard->addCategories(category2);
                    
                    
                    auto out = Ezvcard::write(newVCard)->go();
                    
                    auto outString =
                    "BEGIN:VCARD\r\n"
                    "VERSION:4.0\r\n"
                    "PRODID:pm-ez-vcard 0.0.1\r\n"
                    "item1.CATEGORIES:Family,iOS dev team,9\r\n"
                    "item2.CATEGORIES:Family,10\r\n"
                    "END:VCARD\r\n";
                    
                    VERIFY_ARE_EQUAL(out, outString);
                    
                    newVCard->setCategories(category1);
                    newVCard->addCategories(category2);
                    
                    auto out1 = Ezvcard::write(newVCard)->go();
                    VERIFY_ARE_EQUAL(out1, outString);
                }
                
                {
                    std::string str =
                    "BEGIN:VCARD\r\n"
                    "VERSION:4.0\r\n"
                    "FN:1 feng\r\n"
                    "item1.EMAIL:feng@pm.me\r\n"
                    "item1.KEY:data\\:application/pgp-keys\\;base64\\,xsFNBFoyyy8BEACVQYZ2Rzq9r\r\n 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\r\n"
                    "item1.X-PM-ENCRYPT:false\r\n"
                    "item1.X-PM-SIGN:false\r\n"
                    "item1.X-PM-SCHEME:pgp-mime\r\n"
                    "UID:proton-web-a4a980af-798c-53cd-2e6e-1ceb0e1cfd5f\r\n"
                    "END:VCARD\r\n";
                    auto vcard = Ezvcard::parse(str).first();
                    auto keys = vcard->getKeys("item1");
                    auto mime = vcard->getPMScheme("item1");
                    
                    vcard->clearKeys();
                    for (auto key : keys) {
                        auto pref = key->getPref();
                        auto group = key->getGroup();
                     //   auto keyData = key->getData();
                       

                        VERIFY_ARE_EQUAL(INT32_MIN, pref);
                        VERIFY_IS_TRUE(group == "item1");
                      //  VERIFY_IS_TRUE(keyData != "");
                        vcard->addKey(key);
                    }
                    
                    
                    auto mimetype = mime->getValue();
                    VERIFY_ARE_EQUAL("pgp-mime", mimetype);
                    
                    auto vcardVersion = std::dynamic_pointer_cast<VCardVersion>(vcard->getVersion());
                    VERIFY_IS_TRUE(VCardVersion::V4_0()->equals(vcardVersion));
                    auto fn = vcard->getFormattedName();
                    VERIFY_IS_NOT_NULL(fn);
                    VERIFY_ARE_EQUAL("1 feng", fn->getValue());
                    
                    auto writer = Ezvcard::write(vcard);
                    auto actual = writer->go();
//                    VERIFY_ARE_EQUAL(actual, str);
                }
                
                {
                    std::string str =
                    "BEGIN:VCARD\r\n"
                    "VERSION:3.0\r\n"
                    "N:1\\;&\\;1\r\n"
                    "FN:1 & 1\r\n"
                    "EMAIL;TYPE=Email:test@example.com\r\n"
                    "EMAIL;TYPE=Home:test1@example.com\r\n"
                    "EMAIL;TYPE=Work:test3@example.com\r\n"
                    "END:VCARD\r\n";
                    auto vcard = Ezvcard::parse(str).first();
                    auto vcardVersion = std::dynamic_pointer_cast<VCardVersion>(vcard->getVersion());
                    VERIFY_IS_TRUE(VCardVersion::V3_0()->equals(vcardVersion));
                    auto fn = vcard->getFormattedName();
                    VERIFY_IS_NOT_NULL(fn);
                    VERIFY_ARE_EQUAL("1 & 1", fn->getValue());
                    
                    auto raw = vcard->getStructuredName();
                    //todo::later fix
//                    auto n_name = raw->getPropertyName();
//                    VERIFY_ARE_EQUAL(n_name, "N");
//                    auto n_value = raw->getValue();
//                    VERIFY_ARE_EQUAL(n_value, "1\\;&\\;1");
                    
                    auto emails = vcard->getEmails();
                    VERIFY_IS_TRUE(emails.size() == 3);
                    
                    auto email0 = emails[0];
                    auto type0 = email0->getParameter("TYPE");
                    auto addr0 = email0->getValue();
                    VERIFY_ARE_EQUAL(type0, "Email");
                    VERIFY_ARE_EQUAL(addr0, "test@example.com");
                    
                    auto email1 = emails[1];
                    auto type1 = email1->getParameter("TYPE");
                    auto addr1 = email1->getValue();
                    VERIFY_ARE_EQUAL(type1, "Home");
                    VERIFY_ARE_EQUAL(addr1, "test1@example.com");
                    
                    auto email2 = emails[2];
                    auto type2 = email2->getParameter("TYPE");
                    auto addr2 = email2->getValue();
                    VERIFY_ARE_EQUAL(type2, "Work");
                    VERIFY_ARE_EQUAL(addr2, "test3@example.com");
                    
                    //List<List<String>> warnings = new ArrayList<List<String>>();
                    //VCard vcard = Ezvcard.parse(str).warnings(warnings).first();
                    //assertVersion(VCardVersion.V2_1, vcard);
                    //assertEquals("John Doe", vcard.getFormattedName().getValue());
                    //assertWarningsLists(warnings, 0);
                }
                
                {
                    std::string str = "BEGIN:VCARD\r\nVERSION:4.0\r\nPRODID:pm-ez-vcard 0.0.1\r\nADR;TYPE=WORK:;;3170 Dublin Dr;South San Francisco;CA;94080;United States\r\nURL:123\r\nGENDER:123\r\nNOTE:123123123123123123\\n12\\n312312312kj3123\\nWard\\nSad\\nA\\nDa\\nAs\\nA\\nSd12\r\n 3\r\nTEL;TYPE=FAX:6176767087\r\nEND:VCARD\r\n";
                    auto vcard = Ezvcard::parse(str).first();
                    auto vcardVersion = std::dynamic_pointer_cast<VCardVersion>(vcard->getVersion());
                    VERIFY_IS_TRUE(VCardVersion::V4_0()->equals(vcardVersion));
                    
                    auto urls = vcard->getUrls();
                    for (auto url : urls) {
                        auto value = url->getValue();
                        VERIFY_IS_FALSE(value.empty());
                    }
                    //TODO:: add more verify
                }
                
                
                {
                    std::string str =
                    "BEGIN:VCARD\r\n"
                    "VERSION:3.0\r\n"
                    "PRODID:-//Apple Inc.//iPhone OS 11.2//EN\r\n"
                    "N:Bell;Kate;;;\r\n"
                    "FN: Kate  Bell\r\n"
                    "ORG:Creative Consulting;\r\n"
                    "TITLE:Producer\r\n"
                    "EMAIL;type=INTERNET;type=WORK;type=pref:kate-bell@mac.com\r\n"
                    "TEL;type=CELL;type=VOICE;type=pref:(555) 564-8583\r\n"
                    "TEL;type=MAIN:(415) 555-3695\r\n"
                    "item1.ADR;type=WORK;type=pref:;;165 Davis Street;Hillsborough;CA;94010;\r\n"
                    "item1.X-ABADR:us\r\n"
                    "item2.URL;type=pref:www.icloud.com\r\n"
                    "item2.X-ABLabel:_$!<HomePage>!$_\r\n"
                    "BDAY:1978-01-20\r\n"
                    "END:VCARD\r\n";
                    
                    
                    auto vcard = Ezvcard::parse(str).first();
                    auto vcardVersion = std::dynamic_pointer_cast<VCardVersion>(vcard->getVersion());
                    VERIFY_IS_TRUE(VCardVersion::V3_0()->equals(vcardVersion));
                    
                    auto bd = vcard->getBirthday();
                    
                    vcard->setVersion(VCardVersion::VCard4_0());
                    
                    auto writer = Ezvcard::write(vcard);
                    auto actual = writer->go();
                    std::cout << actual << std::endl;
                }
                
                {
                    std::string str =
                    "BEGIN:VCARD\r\n"
                    "VERSION:3.0\r\n"
                    "PHOTO;ENCODING=BASE64;TYPE=jpeg:ZGF0YQ==\r\n"
                    "\r\n"
                    "END:VCARD\r\n";
                    auto vcard = Ezvcard::parse(str).first();
                    std::cout << "actual" << std::endl;
                }
                
                {
                    std::string str =
                    "BEGIN:VCARD\r\n"
                    "VERSION:2.1\r\n"
                    "N:Mustermann;Erika;;Dr.;\r\n"
                    "FN:Dr. Erika Mustermann\r\n"
                    "ORG:Wikimedia\r\n"
                    "ROLE:Kommunikation\r\n"
                    "TITLE:Redaktion & Gestaltung\r\n"
                    "PHOTO;JPEG:http://commons.wikimedia.org/wiki/File:Erika_Mustermann_2010.jpg\r\n"
                    "TEL;WORK;VOICE:(0221) 9999123\r\n"
                    "TEL;HOME;VOICE:(0221) 1234567\r\n"
                    "ADR;HOME:;;Heidestrasse 17;Koeln;;51147;Deutschland\r\n"
                    "EMAIL;PREF;INTERNET:erika@mustermann.de\r\n"
                    "REV:20140301T221110Z\r\n"
                    "END:VCARD\r\n";
                    auto vcard = Ezvcard::parse(str).first();
                    std::cout << "actual" << std::endl;
                }
                
                
                {
                    std::string str =
                    "BEGIN:VCARD\r\n"
                    "VERSION:3.0\r\n"
                    "PRODID:-//Apple Inc.//Mac OS X 10.13.3//EN\r\n"
                    "N:;;;;\r\n"
                    "FN:Allsafe Cybersecurity\r\n"
                    "ORG:Allsafe Cybersecurity;\r\n"
                    "EMAIL;type=INTERNET;type=pref:elliotalderson@protonmail.com\r\n"
                    "TEL;type=pref:(212) 555-0179\r\n"
                    "ADR;type=pref:;;1010101010101;New York City;New York;10001;United States of America\r\n"
                    "NOTE:But I'm only a vigilante hacker by night. By day\\, justaregularcybersecurity engineer. Employee number ER28-0652\r\n"
                    "X-ABShowAs:COMPANY\r\n"
                    "UID:5e23f6b1-653e-41d5-a09c-28977dfe279c\r\n"
                    "X-ABUID:14F9D7A0-24AB-43F2-B0C7-7C56E746FC47:ABPerson\r\n"
                    "ANNIVERSARY;TYPE=x-bday:September 17, 1986\r\n"
                    "END:VCARD\r\n";
                    
                    auto vcard = Ezvcard::parse(str).first();
                    auto note = vcard->getNote();
                    std::cout << note->getNote() << std::endl;
                    std::cout << "actual" << std::endl;
                }
            }
            
            TEST(contacts_feng_1_test) {
                std::string str = "BEGIN:VCARD\r\nVERSION:4.0\r\nitem0.TEL;TYPE=Cell;PREF=0:6176767087\r\nitem1.TEL;TYPE=Work;PREF=1:6176767088\r\nitem0.ADR;TYPE=Address;PREF=0:3170 Dublin Dr,\\nSouth San Francisco, CA\r\n 94080\r\nORG:Org1\r\nORGANIZATION:Org2\r\nTITLE:T2\r\nTITLE:T1\r\nTITLE:T3\r\nNICKNAME:N1\r\nBDAY:N2\r\nURL:URL1\r\nROLE:Role1\r\nSOUND:Sound1\r\nCUSTOM1:CUS1\r\nCUSTOM2:CUS2\r\nNOTE:this is a note feng1\r\nEND:VCARD";
                auto vcard = Ezvcard::parse(str).first();
                auto vcardversion = std::dynamic_pointer_cast<VCardVersion>(vcard->getVersion());
                VERIFY_IS_TRUE(VCardVersion::V4_0()->equals(vcardversion));
                auto addr = vcard->getAddresses();
                VERIFY_IS_TRUE(addr.size() > 0);
                
                auto types = vcard->getPropertyTypes();
                VERIFY_IS_TRUE(types.size() > 0);
            }
            
            TEST(parse_first) {
                {
                    std::string str =
                    "BEGIN:VCARD\r\n"
                    "VERSION:2.1\r\n"
                    "FN:John Doe\r\n"
                    "END:VCARD\r\n";
                    auto vcard = Ezvcard::parse(str).first();
                    auto vcardversion = std::dynamic_pointer_cast<VCardVersion>(vcard->getVersion());
                    VERIFY_IS_TRUE(VCardVersion::V2_1()->equals(vcardversion));
                    auto fn = vcard->getFormattedName();
                    VERIFY_IS_NOT_NULL(fn);
                    VERIFY_ARE_EQUAL("John Doe", fn->getValue());
                    
                    //List<List<String>> warnings = new ArrayList<List<String>>();
                    //VCard vcard = Ezvcard.parse(str).warnings(warnings).first();
                    //assertVersion(VCardVersion.V2_1, vcard);
                    //assertEquals("John Doe", vcard.getFormattedName().getValue());
                    //assertWarningsLists(warnings, 0);
                }
            }
            
            TEST(parse_all) {
                std::string str =
                "BEGIN:VCARD\r\n"
                "VERSION:2.1\r\n"
                "FN:John Doe\r\n"
                "END:VCARD\r\n"
                "BEGIN:VCARD\r\n"
                "VERSION:3.0\r\n"
                "FN:Jane Doe\r\n"
                "END:VCARD\r\n";
                
                //List<List<String>> warnings = new ArrayList<List<String>>();
                auto vcards = Ezvcard::parse(str).all();
                //List<VCard> vcards = Ezvcard.parse(str).warnings(warnings).all();
                //Iterator<VCard> it = vcards.iterator();
                auto it = vcards.begin();
                VERIFY_IS_TRUE(it != vcards.end());
                VCard::Ptr vcard = *it;
                VERIFY_IS_NOT_NULL(vcard);
                auto vcardversion = std::dynamic_pointer_cast<VCardVersion>(vcard->getVersion());
                VERIFY_IS_TRUE(VCardVersion::V2_1()->equals(vcardversion));
                auto fn = vcard->getFormattedName();
                VERIFY_IS_NOT_NULL(fn);
                VERIFY_ARE_EQUAL("John Doe", fn->getValue());
                it++;
                vcard = *it;
                VERIFY_IS_NOT_NULL(vcard);
                vcardversion = std::dynamic_pointer_cast<VCardVersion>(vcard->getVersion());
                VERIFY_IS_TRUE(VCardVersion::V3_0()->equals(vcardversion));
                fn = vcard->getFormattedName();
                VERIFY_IS_NOT_NULL(fn);
                VERIFY_ARE_EQUAL("Jane Doe", fn->getValue());
                it++;
                VERIFY_IS_TRUE(it == vcards.end());
                // assertWarningsLists(warnings, 0, 0);
            }
            
            TEST(parse_register) {
                std::string str =
                "BEGIN:VCARD\r\n"
                "VERSION:2.1\r\n"
                "X-LUCKY-NUM:22\r\n"
                "END:VCARD\r\n";
                //
                //                VCard vcard = Ezvcard.parse(str).register(new LuckyNumScribe()).first();
                //                assertVersion(VCardVersion.V2_1, vcard);
                //                List<LuckyNumProperty> ext = vcard.getProperties(LuckyNumProperty.class);
                //                assertEquals(1, ext.size());
                //                assertEquals(22, ext.get(0).luckyNum);
            }
            
            
            TEST(parse_caretDecoding) {
                std::string str =
                "BEGIN:VCARD\r\n"
                "VERSION:4.0\r\n"
                "FN;X-TEST=George Herman ^'Babe^' Ruth:John Doe\r\n"
                "END:VCARD\r\n";
                
                //defaults to true
                VCard::Ptr vcard = Ezvcard::parse(str).first();
                VERIFY_IS_NOT_NULL(vcard);
                auto fn = vcard->getFormattedName();
                VERIFY_IS_NOT_NULL(fn);
                auto parameter = fn->getParameter("X-TEST");
                VERIFY_ARE_EQUAL("George Herman \"Babe\" Ruth", parameter);
                
                //                vcard = Ezvcard::parse(str).caretDecoding(true).first();
                //                assertEquals("George Herman \"Babe\" Ruth", vcard.getFormattedName().getParameter("X-TEST"));
                //
                //                vcard = Ezvcard.parse(str).caretDecoding(false).first();
                //                assertEquals("George Herman ^'Babe^' Ruth", vcard.getFormattedName().getParameter("X-TEST"));
            }
            //
            //            @Test
            //            public void parseXml_first() throws Exception {
            //                XCardBuilder xb = new XCardBuilder();
            //                xb.prop("fn", "<text>John Doe</text>");
            //                List<List<String>> warnings = new ArrayList<List<String>>();
            //
            //                VCard vcard = Ezvcard.parseXml(xb.toString()).warnings(warnings).first();
            //                assertVersion(VCardVersion.V4_0, vcard);
            //                assertEquals("John Doe", vcard.getFormattedName().getValue());
            //                assertWarningsLists(warnings, 0);
            //            }
            //
            //            @Test
            //            public void parseXml_all() throws Exception {
            //                XCardBuilder xb = new XCardBuilder();
            //                xb.prop("fn", "<text>John Doe</text>");
            //                xb.begin();
            //                xb.prop("fn", "<text>Jane Doe</text>");
            //                List<List<String>> warnings = new ArrayList<List<String>>();
            //
            //                List<VCard> vcards = Ezvcard.parseXml(xb.toString()).warnings(warnings).all();
            //                Iterator<VCard> it = vcards.iterator();
            //
            //                VCard vcard = it.next();
            //                assertVersion(VCardVersion.V4_0, vcard);
            //                assertEquals("John Doe", vcard.getFormattedName().getValue());
            //
            //                vcard = it.next();
            //                assertVersion(VCardVersion.V4_0, vcard);
            //                assertEquals("Jane Doe", vcard.getFormattedName().getValue());
            //
            //                assertWarningsLists(warnings, 0, 0);
            //
            //                assertFalse(it.hasNext());
            //            }
            //
            //            @Test
            //            public void parseXml_register() throws Exception {
            //                XCardBuilder xb = new XCardBuilder();
            //                xb.prop("http://luckynum.com", "lucky-num", "<num>22</num>");
            //
            //                VCard vcard = Ezvcard.parseXml(xb.toString()).register(new LuckyNumScribe()).first();
            //                assertVersion(VCardVersion.V4_0, vcard);
            //                List<LuckyNumProperty> ext = vcard.getProperties(LuckyNumProperty.class);
            //                assertEquals(1, ext.size());
            //                assertEquals(22, ext.get(0).luckyNum);
            //            }
            //
            //            @Test
            //            public void parseHtml_first() throws Exception {
            //                //@formatter:off
            //                String html =
            //                "<div class=\"vcard\">" +
            //                "<div class=\"fn\">John Doe</div>" +
            //                "</div>";
            //                //@formatter:on
            //
            //                List<List<String>> warnings = new ArrayList<List<String>>();
            //
            //                VCard vcard = Ezvcard.parseHtml(html).warnings(warnings).first();
            //                assertVersion(VCardVersion.V3_0, vcard);
            //                assertEquals("John Doe", vcard.getFormattedName().getValue());
            //                assertWarningsLists(warnings, 0);
            //            }
            //
            //            @Test
            //            public void parseHtml_all() throws Exception {
            //                //@formatter:off
            //                String html =
            //                "<html>" +
            //                "<div class=\"vcard\">" +
            //                "<div class=\"fn\">John Doe</div>" +
            //                "</div>" +
            //                "<div class=\"vcard\">" +
            //                "<div class=\"fn\">Jane Doe</div>" +
            //                "</div>" +
            //                "</html>";
            //                //@formatter:on
            //                List<List<String>> warnings = new ArrayList<List<String>>();
            //
            //                List<VCard> vcards = Ezvcard.parseHtml(html).warnings(warnings).all();
            //                Iterator<VCard> it = vcards.iterator();
            //
            //                VCard vcard = it.next();
            //                assertVersion(VCardVersion.V3_0, vcard);
            //                assertEquals("John Doe", vcard.getFormattedName().getValue());
            //
            //                vcard = it.next();
            //                assertVersion(VCardVersion.V3_0, vcard);
            //                assertEquals("Jane Doe", vcard.getFormattedName().getValue());
            //
            //                assertWarningsLists(warnings, 0, 0);
            //
            //                assertFalse(it.hasNext());
            //            }
            //
            //            @Test
            //            public void parseHtml_register() throws Exception {
            //                //@formatter:off
            //                String html =
            //                "<div class=\"vcard\">" +
            //                "<div class=\"x-lucky-num\">22</div>" +
            //                "</div>";
            //                //@formatter:on
            //
            //                VCard vcard = Ezvcard.parseHtml(html).register(new LuckyNumScribe()).first();
            //                assertVersion(VCardVersion.V3_0, vcard);
            //                List<LuckyNumProperty> ext = vcard.getProperties(LuckyNumProperty.class);
            //                assertEquals(1, ext.size());
            //                assertEquals(22, ext.get(0).luckyNum);
            //            }
            //
            //            @Test
            //            public void parseHtml_pageUrl() throws Exception {
            //                //@formatter:off
            //                String html =
            //                "<div class=\"vcard\">" +
            //                "<a href=\"profile.html\" class=\"url fn\">John Doe</a>" +
            //                "</div>";
            //                //@formatter:on
            //
            //                //without
            //                VCard vcard = Ezvcard.parseHtml(html).first();
            //                assertVersion(VCardVersion.V3_0, vcard);
            //                assertEquals("John Doe", vcard.getFormattedName().getValue());
            //                assertTrue(vcard.getSources().isEmpty());
            //                assertEquals("profile.html", vcard.getUrls().get(0).getValue());
            //
            //                //with
            //                vcard = Ezvcard.parseHtml(html).pageUrl("http://www.example.com/index.html").first();
            //                assertVersion(VCardVersion.V3_0, vcard);
            //                assertEquals("John Doe", vcard.getFormattedName().getValue());
            //                assertEquals("http://www.example.com/index.html", vcard.getSources().get(0).getValue());
            //                assertEquals("http://www.example.com/profile.html", vcard.getUrls().get(0).getValue());
            //            }
            //
            //            @Test
            //            public void parseJson_first() {
            //                //@formatter:off
            //                String json =
            //                "[\"vcard\"," +
            //                "[" +
            //                "[\"version\", {}, \"text\", \"4.0\"]," +
            //                "[\"fn\", {}, \"text\", \"John Doe\"]" +
            //                "]" +
            //                "]";
            //                //@formatter:on
            //
            //                List<List<String>> warnings = new ArrayList<List<String>>();
            //
            //                VCard vcard = Ezvcard.parseJson(json).warnings(warnings).first();
            //                assertVersion(VCardVersion.V4_0, vcard);
            //                assertEquals("John Doe", vcard.getFormattedName().getValue());
            //                assertWarningsLists(warnings, 0);
            //            }
            //
            //            @Test
            //            public void parseJson_all() {
            //                //@formatter:off
            //                String json =
            //                "[\"vcardstream\"," +
            //                "[\"vcard\"," +
            //                "[" +
            //                "[\"version\", {}, \"text\", \"4.0\"]," +
            //                "[\"fn\", {}, \"text\", \"John Doe\"]" +
            //                "]" +
            //                "]," +
            //                "[\"vcard\"," +
            //                "[" +
            //                "[\"version\", {}, \"text\", \"4.0\"]," +
            //                "[\"fn\", {}, \"text\", \"Jane Doe\"]" +
            //                "]" +
            //                "]" +
            //                "]";
            //                //@formatter:on
            //
            //                List<List<String>> warnings = new ArrayList<List<String>>();
            //
            //                List<VCard> vcards = Ezvcard.parseJson(json).warnings(warnings).all();
            //                Iterator<VCard> it = vcards.iterator();
            //
            //                VCard vcard = it.next();
            //                assertVersion(VCardVersion.V4_0, vcard);
            //                assertEquals("John Doe", vcard.getFormattedName().getValue());
            //
            //                vcard = it.next();
            //                assertVersion(VCardVersion.V4_0, vcard);
            //                assertEquals("Jane Doe", vcard.getFormattedName().getValue());
            //
            //                assertWarningsLists(warnings, 0, 0);
            //
            //                assertFalse(it.hasNext());
            //            }
            //
            //            @Test
            //            public void parseJson_register() {
            //                //@formatter:off
            //                String json =
            //                "[\"vcard\"," +
            //                "[" +
            //                "[\"version\", {}, \"text\", \"4.0\"]," +
            //                "[\"x-lucky-num\", {}, \"text\", \"22\"]" +
            //                "]" +
            //                "]";
            //                //@formatter:on
            //
            //                VCard vcard = Ezvcard.parseJson(json).register(new LuckyNumScribe()).first();
            //                assertVersion(VCardVersion.V4_0, vcard);
            //                List<LuckyNumProperty> ext = vcard.getProperties(LuckyNumProperty.class);
            //                assertEquals(1, ext.size());
            //                assertEquals(22, ext.get(0).luckyNum);
            //            }
            
            TEST(write_one) {
                VCard::Ptr vcard = std::make_shared<VCard>();
                auto v21 = VCardVersion::V2_1();
                vcard->setVersion(v21);
                vcard->setFormattedName(std::make_shared<FormattedName>("John Doe"));
                
                auto writer = Ezvcard::write(vcard);
                auto actual = writer->go();
                
                std::size_t found = actual.find("VERSION:2.1");
                VERIFY_IS_TRUE(found!=std::string::npos);
                found = actual.find("FN:John Doe");
                VERIFY_IS_TRUE(found!=std::string::npos);
            }
            
            TEST(write_multiple) {
                VCard::Ptr vcard1 = std::make_shared<VCard>();
                vcard1->setVersion(VCardVersion::V2_1());
                vcard1->setFormattedName(std::make_shared<FormattedName>("John Doe"));
                VCard::Ptr vcard2 = std::make_shared<VCard>();
                vcard2->setVersion(VCardVersion::V3_0());
                vcard2->setFormattedName(std::make_shared<FormattedName>("Jane Doe"));
                VCard::Ptr vcard3 = std::make_shared<VCard>();
                vcard3->setVersion(VCardVersion::V4_0());
                vcard3->setFormattedName(std::make_shared<FormattedName>("Janet Doe"));
                
                auto actual = Ezvcard::write( { vcard1, vcard2, vcard3 })->go();
                auto expected =
                "BEGIN:VCARD\r\n"
                "VERSION:2.1\r\n"
                "X-PRODID:" + Ezvcard::PRODID + Ezvcard::VERSION_NUMBER + "\r\n"
                "FN:John Doe\r\n"
                "END:VCARD\r\n"
                
                "BEGIN:VCARD\r\n"
                "VERSION:3.0\r\n"
                "PRODID:"  + Ezvcard::PRODID + Ezvcard::VERSION_NUMBER + "\r\n"
                "FN:Jane Doe\r\n"
                "END:VCARD\r\n"
                
                "BEGIN:VCARD\r\n"
                "VERSION:4.0\r\n"
                "PRODID:" + Ezvcard::PRODID + Ezvcard::VERSION_NUMBER + "\r\n"
                "FN:Janet Doe\r\n"
                "END:VCARD\r\n";
                
                VERIFY_ARE_EQUAL(actual, expected);
                
//                std::regex myRegex( ".*BEGIN:VCARD.*?VERSION:3\\.0.*?FN:Jane Doe.*?END:VCARD.*?BEGIN:VCARD.*?VERSION:4\\.0.*?FN:Janet Doe.*?END:VCARD.*", std::regex::extended);
//                if (std::regex_search(actual, myRegex)) {
//                    std::cout << "Text contains the phrase 'regular expressions'\n";
//                }
//                
//                auto words_begin = std::sregex_iterator(actual.begin(), actual.end(), myRegex);
//                auto words_end = std::sregex_iterator();
//                
//                std::cout << "Found "
//                << std::distance(words_begin, words_end)
//                << " words\n";
//                
//                while (words_begin != words_end) {
//                    std::smatch match = *words_begin;
//                    std::cout << match.str() << "\n";
//                    words_begin++;
//                }
//                
//                if (std::regex_match(actual, myRegex)) {
//                    std::cout<<"integer"<< std::endl;
//                } else {
//                    std::cout<<"Invalid input"<< std::endl;
//                }
            }
            
            TEST(write_version) {
                auto vcard1 = std::make_shared<VCard>();
                vcard1->setVersion(VCardVersion::V2_1());
                auto vcard2 = std::make_shared<VCard>();
                vcard2->setVersion(VCardVersion::V3_0());
                auto vcard3 = std::make_shared<VCard>();
                vcard3->setVersion(VCardVersion::V4_0());
                
                auto writer = Ezvcard::write( {vcard1, vcard2, vcard3} );
                writer->version(VCardVersion::V4_0());
                std::string actual = writer->go();
                
                auto expected =
                "BEGIN:VCARD\r\n"
                "VERSION:4.0\r\n"
                "PRODID:" + Ezvcard::PRODID + Ezvcard::VERSION_NUMBER + "\r\n"
                "END:VCARD\r\n"
                
                "BEGIN:VCARD\r\n"
                "VERSION:4.0\r\n"
                "PRODID:" + Ezvcard::PRODID + Ezvcard::VERSION_NUMBER + "\r\n"
                "END:VCARD\r\n"
                
                "BEGIN:VCARD\r\n"
                "VERSION:4.0\r\n"
                "PRODID:" + Ezvcard::PRODID + Ezvcard::VERSION_NUMBER + "\r\n"
                "END:VCARD\r\n";
                
                VERIFY_ARE_EQUAL(actual, expected);
            }
            
            TEST(write_prodId) {
                auto vcard = std::make_shared<VCard>();
                vcard->setVersion(VCardVersion::V3_0());
                
                auto actual = Ezvcard::write(vcard)->go();
                std::size_t found = actual.find("\r\nPRODID:");
                VERIFY_IS_TRUE(found!=std::string::npos);
                
                auto writer = Ezvcard::write(vcard);
                writer->prodId(true);
                actual = writer->go();
                found = actual.find("\r\nPRODID:");
                VERIFY_IS_TRUE(found!=std::string::npos);
                
                writer = Ezvcard::write(vcard);
                writer->prodId(false);
                actual = writer->go();
                found = actual.find("\r\nPRODID:");
                VERIFY_IS_FALSE(found!=std::string::npos);
            }
            
            TEST(write_caretEncoding) {
                auto vcard = std::make_shared<VCard>();
                vcard->setVersion(VCardVersion::V4_0());
                FormattedName::Ptr fn = std::make_shared<FormattedName>("Test");
                vcard->setFormattedName(fn);
                fn->getParameters()->put("X-TEST", "George Herman \"Babe\" Ruth");
                
                //default should be "false"
                VERIFY_THROWS(Ezvcard::write(vcard)->go(), std::invalid_argument);
                
                auto writer = Ezvcard::write(vcard);
                writer->caretEncoding(true);
                auto actual = writer->go();
                auto found = actual.find("\r\nFN;X-TEST=George Herman ^'Babe^' Ruth:");
                VERIFY_IS_TRUE(found!=std::string::npos);
                
                writer = Ezvcard::write(vcard);
                writer->caretEncoding(false);
                VERIFY_THROWS(writer->go(), std::invalid_argument);
            }
            
            TEST(write_versionStrict) {
                auto vcard = std::make_shared<VCard>();
                vcard->setVersion(VCardVersion::V4_0());
                vcard->setMailer("mailer"); //only supported by 2.1 and 3.0
                
                std::string actual = Ezvcard::write(vcard)->go();
                auto found = actual.find("\r\nMAILER:");
                VERIFY_IS_FALSE(found!=std::string::npos);
                
                auto writer = Ezvcard::write(vcard);
                writer->versionStrict(true);
                actual = writer->go();
                found = actual.find("\r\nMAILER:");
                VERIFY_IS_FALSE(found!=std::string::npos);
                
                writer = Ezvcard::write(vcard);
                writer->versionStrict(false);
                actual = writer->go();
                found = actual.find("\r\nMAILER:");
                VERIFY_IS_TRUE(found!=std::string::npos);
            }

            
            TEST(write_targetApplication) {
                std::string data = "data";
                auto vcard = std::make_shared<VCard>();
                vcard->addPhoto(std::make_shared<Photo>(data, ImageType::JPEG, true));
                
                //default value (null)
                {
                    auto writer = Ezvcard::write(vcard);
                    writer ->prodId(false);
                    writer->version(VCardVersion::V2_1());
                    auto actual = writer->go();
                    
                    auto expected =
                    "BEGIN:VCARD\r\n"
                    "VERSION:2.1\r\n"
                    "PHOTO;ENCODING=BASE64;TYPE=jpeg:ZGF0YQ==\r\n"
                    "END:VCARD\r\n";
                    VERIFY_ARE_EQUAL(expected, actual);
                }
                
                //with value
                {
                    auto writer = Ezvcard::write(vcard);
                    writer ->prodId(false);
                    writer->version(VCardVersion::V2_1());
                    writer->targetApplication(TargetApplication::OUTLOOK);
                    auto actual = writer->go();
                    auto expected =
                    "BEGIN:VCARD\r\n"
                    "VERSION:2.1\r\n"
                    "PHOTO;ENCODING=BASE64;TYPE=jpeg:ZGF0YQ==\r\n"
                    "\r\n"
                    "END:VCARD\r\n";
                    
                    VERIFY_ARE_EQUAL(expected, actual);
                }
                
                //with value
                {
                    auto testcard = std::make_shared<VCard>();
                    auto writer = Ezvcard::write(testcard);
                    writer ->prodId(true);
                    writer->version(VCardVersion::V4_0());
                    auto actual = writer->go();
                    auto expected =
                    "BEGIN:VCARD\r\n"
                    "VERSION:4.0\r\n"
                    "PRODID:" + Ezvcard::PRODID + Ezvcard::VERSION_NUMBER + "\r\n"
                    "END:VCARD\r\n";
                    auto ez = Ezvcard::parse(actual);
                    auto card = ez.first();
                    auto out = Ezvcard::write(card)->go();
                    
                    VERIFY_ARE_EQUAL(expected, actual);
                }
                
                
                
                
            }
            
            
            
            //            @Test
            //            public void write_file() throws Exception {
            //                VCard vcard = new VCard();
            //                File file = folder.newFile();
            //                Ezvcard.write(vcard).go(file);
            //                assertTrue(file.length() > 0);
            //            }
            //
            //            @Test
            //            public void writeXml_go() throws Exception {
            //                VCard vcard = new VCard();
            //                vcard.setFormattedName("John Doe");
            //
            //                String xml = Ezvcard.writeXml(vcard).go();
            //                assertTrue(xml.contains("<fn><text>John Doe</text></fn>"));
            //            }
            //
            //            @Test
            //            public void writeXml_dom() throws Exception {
            //                VCard vcard = new VCard();
            //                vcard.setFormattedName(new FormattedName("John Doe"));
            //
            //                Document actual = Ezvcard.writeXml(vcard).prodId(false).dom();
            //
            //                //@formatter:off
            //                String html =
            //                "<vcards xmlns=\"" + VCardVersion.V4_0.getXmlNamespace() + "\">" +
            //                "<vcard>" +
            //                "<fn><text>John Doe</text></fn>" +
            //                "</vcard>" +
            //                "</vcards>";
            //                Document expected = XmlUtils.toDocument(html);
            //                //@formatter:on
            //
            //                assertXMLEqual(expected, actual);
            //            }
            //
            //            @Test
            //            public void writeXml_one() throws Exception {
            //                VCard vcard = new VCard();
            //                vcard.setFormattedName("John Doe");
            //
            //                Document dom = Ezvcard.writeXml(vcard).dom();
            //                String actual = (String) xpath.evaluate("/v:vcards/v:vcard/v:fn/v:text", dom, XPathConstants.STRING);
            //                assertEquals(vcard.getFormattedName().getValue(), actual);
            //            }
            //
            //            @Test
            //            public void writeXml_multiple() throws Exception {
            //                VCard vcard1 = new VCard();
            //                vcard1.setFormattedName("John Doe");
            //                VCard vcard2 = new VCard();
            //                vcard2.setFormattedName("Jane Doe");
            //                VCard vcard3 = new VCard();
            //                vcard3.setFormattedName("Janet Doe");
            //
            //                Document dom = Ezvcard.writeXml(vcard1, vcard2, vcard3).dom();
            //                NodeList nl = (NodeList) xpath.evaluate("/v:vcards/v:vcard/v:fn/v:text", dom, XPathConstants.NODESET);
            //
            //                assertEquals(vcard1.getFormattedName().getValue(), nl.item(0).getTextContent());
            //                assertEquals(vcard2.getFormattedName().getValue(), nl.item(1).getTextContent());
            //                assertEquals(vcard3.getFormattedName().getValue(), nl.item(2).getTextContent());
            //            }
            //
            //            @Test
            //            public void writeXml_prodId() throws Exception {
            //                VCard vcard = new VCard();
            //
            //                Document dom = Ezvcard.writeXml(vcard).dom();
            //                Double count = (Double) xpath.evaluate("count(/v:vcards/v:vcard/v:prodid)", dom, XPathConstants.NUMBER);
            //                assertEquals(Double.valueOf(1), count);
            //
            //                dom = Ezvcard.writeXml(vcard).prodId(true).dom();
            //                count = (Double) xpath.evaluate("count(/v:vcards/v:vcard/v:prodid)", dom, XPathConstants.NUMBER);
            //                assertEquals(Double.valueOf(1), count);
            //
            //                dom = Ezvcard.writeXml(vcard).prodId(false).dom();
            //                count = (Double) xpath.evaluate("count(/v:vcards/v:vcard/v:prodid)", dom, XPathConstants.NUMBER);
            //                assertEquals(Double.valueOf(0), count);
            //            }
            //
            //            @Test
            //            public void writeXml_versionStrict() throws Exception {
            //                VCard vcard = new VCard();
            //                vcard.setMailer("mailer"); //only supported by 2.1 and 3.0
            //
            //                Document dom = Ezvcard.writeXml(vcard).dom();
            //                Double count = (Double) xpath.evaluate("count(/v:vcards/v:vcard/v:mailer)", dom, XPathConstants.NUMBER);
            //                assertEquals(Double.valueOf(0), count);
            //
            //                dom = Ezvcard.writeXml(vcard).versionStrict(true).dom();
            //                count = (Double) xpath.evaluate("count(/v:vcards/v:vcard/v:mailer)", dom, XPathConstants.NUMBER);
            //                assertEquals(Double.valueOf(0), count);
            //
            //                dom = Ezvcard.writeXml(vcard).versionStrict(false).dom();
            //                count = (Double) xpath.evaluate("count(/v:vcards/v:vcard/v:mailer)", dom, XPathConstants.NUMBER);
            //                assertEquals(Double.valueOf(1), count);
            //            }
            //
            //            @Test
            //            public void writeXml_indent() throws Exception {
            //                VCard vcard = new VCard();
            //                vcard.setFormattedName(new FormattedName("John Doe"));
            //
            //                String actual = Ezvcard.writeXml(vcard).indent(2).go();
            //                assertTrue(actual.contains("    <fn>" + NEWLINE + "      <text>John Doe</text>" + NEWLINE + "    </fn>"));
            //            }
            //
            //            @Test
            //            public void writeHtml_one() throws Exception {
            //                VCard vcard = new VCard();
            //                vcard.setFormattedName(new FormattedName("John Doe"));
            //
            //                String actual = Ezvcard.writeHtml(vcard).go();
            //                org.jsoup.nodes.Document document = Jsoup.parse(actual);
            //                assertEquals(1, document.select(".vcard").size());
            //                assertEquals(1, document.select(".vcard .fn").size());
            //            }
            //
            //            @Test
            //            public void writeHtml_multiple() throws Exception {
            //                VCard vcard1 = new VCard();
            //                vcard1.setFormattedName(new FormattedName("John Doe"));
            //                VCard vcard2 = new VCard();
            //                vcard2.setFormattedName(new FormattedName("Jane Doe"));
            //                VCard vcard3 = new VCard();
            //                vcard3.setFormattedName(new FormattedName("Janet Doe"));
            //
            //                String actual = Ezvcard.writeHtml(vcard1, vcard2, vcard3).go();
            //                org.jsoup.nodes.Document document = Jsoup.parse(actual);
            //                assertEquals(3, document.select(".vcard").size());
            //                assertEquals(3, document.select(".vcard .fn").size());
            //            }
            //
            //            @Test
            //            public void writeJson_one() {
            //                VCard vcard = new VCard();
            //                vcard.setFormattedName("John Doe");
            //
            //                //@formatter:off
            //                String expected =
            //                "[\"vcard\"," +
            //                "[" +
            //                "[\"version\",{},\"text\",\"4.0\"]," +
            //                "[\"fn\",{},\"text\",\"John Doe\"]" +
            //                "]" +
            //                "]";
            //                //@formatter:on
            //                String actual = Ezvcard.writeJson(vcard).prodId(false).go();
            //                assertEquals(expected, actual);
            //            }
            //
            //            @Test
            //            public void writeJson_multiple() {
            //                VCard vcard1 = new VCard();
            //                vcard1.setFormattedName(new FormattedName("John Doe"));
            //                VCard vcard2 = new VCard();
            //                vcard2.setFormattedName(new FormattedName("Jane Doe"));
            //                VCard vcard3 = new VCard();
            //                vcard3.setFormattedName(new FormattedName("Janet Doe"));
            //
            //                //@formatter:off
            //                String expected =
            //                "[" +
            //                "[\"vcard\"," +
            //                "[" +
            //                "[\"version\",{},\"text\",\"4.0\"]," +
            //                "[\"fn\",{},\"text\",\"John Doe\"]" +
            //                "]" +
            //                "]," +
            //                "[\"vcard\"," +
            //                "[" +
            //                "[\"version\",{},\"text\",\"4.0\"]," +
            //                "[\"fn\",{},\"text\",\"Jane Doe\"]" +
            //                "]" +
            //                "]," +
            //                "[\"vcard\"," +
            //                "[" +
            //                "[\"version\",{},\"text\",\"4.0\"]," +
            //                "[\"fn\",{},\"text\",\"Janet Doe\"]" +
            //                "]" +
            //                "]" +
            //                "]";
            //                //@formatter:on
            //                String actual = Ezvcard.writeJson(vcard1, vcard2, vcard3).prodId(false).go();
            //                assertEquals(expected, actual);
            //            }
            //
            //            @Test
            //            public void writeJson_prodId() {
            //                VCard vcard = new VCard();
            //
            //                String actual = Ezvcard.writeJson(vcard).go();
            //                assertTrue(actual.contains("[\"prodid\","));
            //
            //                actual = Ezvcard.writeJson(vcard).prodId(true).go();
            //                assertTrue(actual.contains("[\"prodid\","));
            //
            //                actual = Ezvcard.writeJson(vcard).prodId(false).go();
            //                assertFalse(actual.contains("[\"prodid\","));
            //            }
            //
            //            @Test
            //            public void writeJson_versionStrict() {
            //                VCard vcard = new VCard();
            //                vcard.setMailer("mailer"); //only supported by 2.1 and 3.0
            //
            //                String actual = Ezvcard.writeJson(vcard).go();
            //                assertFalse(actual.contains("[\"mailer\","));
            //
            //                actual = Ezvcard.writeJson(vcard).versionStrict(true).go();
            //                assertFalse(actual.contains("[\"mailer\","));
            //
            //                actual = Ezvcard.writeJson(vcard).versionStrict(false).go();
            //                assertTrue(actual.contains("[\"mailer\","));
            //            }
            //
            //            @Test
            //            public void writeJson_indent() {
            //                VCard vcard = new VCard();
            //
            //                //defaults to "false"
            //                String actual = Ezvcard.writeJson(vcard).go();
            //                assertTrue(actual.startsWith("[\"vcard\",[[\""));
            //
            //                actual = Ezvcard.writeJson(vcard).prettyPrint(true).go();
            //                assertTrue(actual.startsWith("[" + NEWLINE + "  \"vcard\"," + NEWLINE + "  [" + NEWLINE + "    ["));
            //
            //                actual = Ezvcard.writeJson(vcard).prettyPrint(false).go();
            //                assertTrue(actual.startsWith("[\"vcard\",[[\""));
            //            }
            //
            //            @Test
            //            public void writeJson_does_not_close_stream() throws Exception {
            //                VCard vcard = new VCard();
            //
            //                File file = folder.newFile();
            //                FileWriter writer = new FileWriter(file);
            //                try {
            //                    Ezvcard.writeJson(vcard).go(writer);
            //                    writer.write("test"); //an exception will be thrown if the writer is closed
            //                } finally {
            //                    writer.close();
            //                }
            //            }
            
            
        }
    }
}
