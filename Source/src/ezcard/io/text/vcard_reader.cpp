//
//  vcard_reader.cpp
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


#include <ezvcard/io/text/vcard_reader.hpp>
#include <ezvcard/io/syntax_rules.hpp>
#include "vobject_data_listener_impl.hpp"


namespace ezvcard {
    
    /**
     * Creates a new vCard reader.
     * @param str the string to read from
     */
    VCardReader::VCardReader(const std::string& str) : _defaultVersion(VCardVersion::V2_1()) {
        init(str, VCardVersion::V2_1());
    }
    
    /**
     * Creates a new vCard reader.
     * @param str the string to read from
     * @param defaultVersion the version to assume the vCard is in until a
     * VERSION property is encountered (defaults to 2.1)
     */
    VCardReader::VCardReader(const std::string& str, VCardVersion::Ptr defaultVersion) : _defaultVersion(VCardVersion::V2_1()) {
        init(str, defaultVersion);
    }
    
    void VCardReader::init(const std::string &str, VCardVersion::Ptr defaultVersion) {
        SyntaxRules rules = SyntaxRules::vcard();
        rules.setDefaultSyntaxStyle(defaultVersion->getSyntaxStyle());
        _reader = std::make_shared<VObjectReader>(str, rules);
        _defaultVersion = defaultVersion;
    }
    
    
    /**
     * Gets whether the reader will decode parameter values that use circumflex
     * accent encoding (enabled by default). This escaping mechanism allows
     * newlines and double quotes to be included in parameter values.
     * @return true if circumflex accent decoding is enabled, false if not
     * @see VObjectReader#isCaretDecodingEnabled()
     */
    bool VCardReader::isCaretDecodingEnabled() {
        return _reader->isCaretDecodingEnabled();
    }
    
    /**
     * Sets whether the reader will decode parameter values that use circumflex
     * accent encoding (enabled by default). This escaping mechanism allows
     * newlines and double quotes to be included in parameter values.
     * @param enable true to use circumflex accent decoding, false not to
     * @see VObjectReader#setCaretDecodingEnabled(boolean)
     */
    void VCardReader::setCaretDecodingEnabled(bool enable) {
        _reader->setCaretDecodingEnabled(enable);
    }
    
    
    VCard::Ptr VCardReader::_readNext() {
        auto listener = std::make_shared<VObjectDataListenerImpl>(_defaultVersion, _index);
        _reader->parse(listener);
        return listener->root;
    }
    
    
    
    
    
    
    
    //
    //    /**
    //     * Creates a new vCard reader.
    //     * @param in the input stream to read from
    //     */
    //    public VCardReader(InputStream in) {
    //        this(in, VCardVersion.V2_1);
    //    }
    //
    //    /**
    //     * Creates a new vCard reader.
    //     * @param in the input stream to read from
    //     * @param defaultVersion the version to assume the vCard is in until a
    //     * VERSION property is encountered (defaults to 2.1)
    //     */
    //    public VCardReader(InputStream in, VCardVersion defaultVersion) {
    //        this(new InputStreamReader(in), defaultVersion);
    //    }
    //
    //    /**
    //     * Creates a new vCard reader.
    //     * @param file the file to read from
    //     * @throws FileNotFoundException if the file doesn't exist
    //     */
    //    public VCardReader(File file) throws FileNotFoundException {
    //        this(file, VCardVersion.V2_1);
    //    }
    //
    //    /**
    //     * Creates a new vCard reader.
    //     * @param file the file to read from
    //     * @param defaultVersion the version to assume the vCard is in until a
    //     * VERSION property is encountered (defaults to 2.1)
    //     * @throws FileNotFoundException if the file doesn't exist
    //     */
    //    public VCardReader(File file, VCardVersion defaultVersion) throws FileNotFoundException {
    //        this(new BufferedReader(new FileReader(file)), defaultVersion);
    //    }
    //
    
    
    //
    //    /**
    //     * Gets the character set to use when the parser cannot determine what
    //     * character set to use to decode a quoted-printable property value.
    //     * @return the character set
    //     * @see VObjectReader#getDefaultQuotedPrintableCharset()
    //     */
    //    public Charset getDefaultQuotedPrintableCharset() {
    //        return reader.getDefaultQuotedPrintableCharset();
    //    }
    //
    //    /**
    //     * Sets the character set to use when the parser cannot determine what
    //     * character set to use to decode a quoted-printable property value.
    //     * @param charset the character set (cannot be null)
    //     * @see VObjectReader#setDefaultQuotedPrintableCharset
    //     */
    //    public void setDefaultQuotedPrintableCharset(Charset charset) {
    //        reader.setDefaultQuotedPrintableCharset(charset);
    //    }
    //
    
    
}
