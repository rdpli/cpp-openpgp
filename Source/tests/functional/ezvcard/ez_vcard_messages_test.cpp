//
//  ez_vcard_messages_test.cpp
//  OpenPGP
//
//  Created by Yanfeng Zhang on 1/17/17.
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



#include <stdio.h>
#include "utils_test.h"

#include <ezvcard/ezvcard.hpp>
#include <ezvcard/vcard.hpp>

#include "messages.hpp"


namespace tests {
    namespace ez_vcard_tests {
        SUITE(ez_vcard_messages_test)
        {
            auto messages = Messages::getInstance();
            
            TEST(getValidationWarning) {
                auto actual = messages->getValidationWarning(0);
                auto expected = messages->getMessage("validate.0");
                VERIFY_ARE_EQUAL(expected, actual);
            }
            
            TEST(getValidationWarning_does_not_exist) {
                auto msg = messages->getValidationWarning(5000);
                VERIFY_ARE_EQUAL(msg, "");
            }
            
            TEST(getParseMessage) {
                auto actual = messages->getParseMessage(0);
                auto expected = messages->getMessage("parse.0");
                VERIFY_ARE_EQUAL(expected, actual);
            }

            TEST(getParseMessage_does_not_exist) {
                auto msg = messages->getParseMessage(5000);
                VERIFY_IS_TRUE(msg.empty());
            }
//
//            TEST(getExceptionMessage) {
//                String actual = messages.getExceptionMessage(1);
//                String expected = messages.getMessage("exception.0", 1, messages.getMessage("exception.1"));
//                assertEquals(expected, actual);
//            }
//            
            TEST(getExceptionMessage_does_not_exist) {
                VERIFY_IS_TRUE(messages->getExceptionMessage(5000).empty());
            }
//
//            TEST(getIllegalArgumentException) {
//                String actual = messages.getIllegalArgumentException(1).getMessage();
//                String expected = messages.getMessage("exception.0", 1, messages.getMessage("exception.1"));
//                assertEquals(expected, actual);
//            }
//            
//            TEST(getIllegalArgumentException_does_not_exist) {
//                assertNull(messages.getIllegalArgumentException(5000));
//            }
            
            TEST(getMessage_does_not_exist) {
                VERIFY_IS_TRUE(messages->getMessage("does-not-exist").empty());
            }
        }
    }
}
