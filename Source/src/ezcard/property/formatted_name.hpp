//
//  formatted_name.hpp
//  OpenPGP
//
//  Created by Yanfeng Zhang on 1/10/17.
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


#ifndef formatted_name_hpp
#define formatted_name_hpp

#include <stdio.h>
#include <string>
#include <list>

#include "text_property.hpp"
#include "has_alt_Id.hpp"
#include "pid.hpp"
#include <bridge/i_formatted_name.hpp>

using namespace ProtonMail;

namespace ezvcard {
    

class FormattedName : public TextProperty, HasAltId, public IFormattedName {

public:
    const static std::string PROPERTYNAME;
    const static std::string CLASSNAME;
    
    typedef std::shared_ptr<FormattedName> Ptr;
    ~FormattedName();
    FormattedName(const std::string& name);
    //FormattedName(const FormattedName::Ptr& original);
    //FormattedName(const FormattedName* original);
    std::string getType();
    
    void setType(std::string type);
    //std::string getLanguage();
    //void setLanguage(std::string language);
    std::list<Pid::Ptr> getPids();
    int getPref(); //TODO::could try to use int64_t later
    void setPref(int pref);
    //FormattedName::Ptr copy();
    
protected: //PMObject part
    //override
    std::string _className() {
        return CLASSNAME;
    }
    
    std::string _getPropertyName() {
        return PROPERTYNAME;
    }
    
protected:
    std::string getAltId();
    void setAltId(const std::string& altId);

public://IFormattedName impl
    
    std::string getLanguage() final;
    void setLanguage(const std::string & language) final;
    std::string getValue() final;
    std::string getParameter(const std::string & name) final;
    
};

}

#endif /* formatted_name_hpp */
