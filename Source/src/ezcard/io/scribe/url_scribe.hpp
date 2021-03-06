//
//  url_scribe.hpp
//  OpenPGP
//
//  Created by Yanfeng Zhang on 6/4/17.
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

#ifndef url_scribe_hpp
#define url_scribe_hpp

#include "uri_property_scribe.hpp"
#include "url.hpp"

namespace ezvcard {
    

class UrlScribe : public UriPropertyScribe<Url> {
    
public:
    typedef std::shared_ptr<UrlScribe> Ptr;
    
    UrlScribe() : UriPropertyScribe<Url>(Url::PROPERTYNAME) {
        
    }
    
    
protected:
    Url::Ptr _parseValue(const std::string& value) {
        return std::make_shared<Url>(value);
    }
    std::string _className() {
        return "UrlScribe";
    }
};

}
#endif /* url_scribe_hpp */
