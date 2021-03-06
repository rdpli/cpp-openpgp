//
//  structured_name_scribe.hpp
//  OpenPGP
//
//  Created by Yanfeng Zhang on 5/30/17.
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


#ifndef structured_name_scribe_hpp
#define structured_name_scribe_hpp

#include <stdio.h>

#include "vcard_property_scribe.hpp"
#include "vobject_property_values.hpp"
#include "structured_name.hpp"
#include <ezvcard/util/string_util.hpp>

namespace ezvcard {
    

/**
 * Marshals {@link StructuredName} properties.
 * @author Michael Angstadt
 */
class StructuredNameScribe : public VCardPropertyScribeWrapper<StructuredName> {
public:
    typedef std::shared_ptr<StructuredNameScribe> Ptr;

public:
    StructuredNameScribe();
    
    
protected:
    
    VCardDataType::Ptr _defaultDataType(const VCardVersion::Ptr& version) {
        return VCardDataType::TEXT;
    }

    std::string _writeText(const StructuredName::Ptr& property, const WriteContext::Ptr& context) {
        /*
         * StructuredValueBuilder cannot be used with 2.1 because it escapes
         * comma characters. For example, if someone's last name is "Foo,bar",
         * the comma character must NOT be escaped when written to a 2.1 vCard.
         *
         * The reason commas are not escaped in 2.1 is because 2.1 does not
         * allow multi-valued components like 3.0 and 4.0 do (for example,
         * multiple suffixes).
         *
         * If a StructuredName object has multi-valued components, and it is
         * being written to a 2.1 vCard, then ez-vcard will comma-delimit them
         * to prevent data loss. But this is not part of the 2.1 syntax.
         */
        if (context->getVersion() == VCardVersion::V2_1()) {
            SemiStructuredValueBuilder builder;
            builder.append(property->getFamily());
            builder.append(property->getGiven());
            builder.append(join(property->getAdditionalNames(), ","));
            builder.append(join(property->getPrefixes(), ","));
            builder.append(join(property->getSuffixes(), ","));
            return builder.build(false, context->isIncludeTrailingSemicolons());
        } else {
            StructuredValueBuilder builder;
            builder.append(property->getFamily());
            builder.append(property->getGiven());
            builder.append(property->getAdditionalNames());
            builder.append(property->getPrefixes());
            builder.append(property->getSuffixes());
            return builder.build(context->isIncludeTrailingSemicolons());
        }
    }
    
    StructuredName::Ptr _parseText(const std::string& value,
                                  const VCardDataType::Ptr& dataType,
                                  const VCardVersion::Ptr& version,
                                  const VCardParameters::Ptr& parameters,
                                  std::list<std::string> warnings) {
        auto property = std::make_shared<StructuredName>();
        if (version == VCardVersion::V2_1()) {
            /*
             * 2.1 does not recognize multi-valued components.
             */
            SemiStructuredValueIterator it(value);
            property->setFamily(it.next());
            property->setGiven(it.next());
            
            auto next = it.next();
            if (next != "") {
                property->addAdditionalName(next);
            }
            
            next = it.next();
            if (next != "") {
                property->addPrefix(next);
            }
            
            next = it.next();
            if (next != "") {
                property->addSuffix(next);
            }
        } else {
            StructuredValueIterator it(value);
            property->setFamily(it.nextValue());
            property->setGiven(it.nextValue());
            
            property->addAdditionalNames(it.nextComponent());
            property->addPrefixes(it.nextComponent());
            property->addSuffixes(it.nextComponent());
        }
        
        return property;
    }
    
    std::string _className() {
        return "StructuredNameScribe";
    }
    
//    @Override
//    protected void _writeXml(StructuredName property, XCardElement parent) {
//    @Override
//    protected StructuredName _parseXml(XCardElement element, VCardParameters parameters, ParseContext context) {
//    private static String s(String value) {
//    @Override
//    protected StructuredName _parseHtml(HCardElement element, ParseContext context) {
//    @Override
//    protected JCardValue _writeJson(StructuredName property) {
//    @Override
//    protected StructuredName _parseJson(JCardValue value, VCardDataType dataType, VCardParameters parameters, ParseContext context) {
};


}

#endif /* structured_name_scribe_hpp */
