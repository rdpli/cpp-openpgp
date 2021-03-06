//
//  binary_property.hpp
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


#ifndef binary_property_hpp
#define binary_property_hpp

#include <stdio.h>

#include "vcard_property.hpp"
#include "has_alt_Id.hpp"
#include "media_type_parameter.hpp"

namespace ezvcard {

/**
 * Represents a property whose value contains binary data.
 * @author Michael Angstadt
 * param <T> the class used for representing the content type of the resource
 */
template <typename T>
class BinaryProperty : public VCardProperty, HasAltId {
    static_assert(std::is_base_of<MediaTypeParameter, T>::value, "BinaryProperty<T>: T must be extent of MediaTypeParameter type :-(");
    
public:
    typedef std::shared_ptr<BinaryProperty> Ptr;
    
protected:
    /**
     * The content type of the resource (for example, a JPEG image).
     */
    std::shared_ptr<T> _contentType;
    /**
     * The decoded data.
     */
    std::string _data;
    
    /**
     * The URL to the resource.
     */
    std::string _url;
    
//    BinaryProperty();
    
    /**
     * Creates a binary property.
     * @param url_or_data the URL/data to the resource
     * @param type the content type
     */
    BinaryProperty(const std::string& url_or_data, const std::shared_ptr<T>& type, bool isBinary) {
        //setUrl(url, type);
        if (isBinary) {
            _data = url_or_data;
        } else {
            _url = url_or_data;
        }
        _contentType = type;
    }
    
    bool isBinaryProperty() {
        return true;
    }
    bool isDataNull() {
        return _data.empty();
    }
    
public:
    std::string getAltId() {
        return _parameters->getAltId();
    }
    
    void setAltId(const std::string& altId) {
        _parameters->setAltId(altId);
    }
    
//    /**
//     * Creates a binary property.
//     * @param data the binary data
//     * @param type the content type
//     */
//    public BinaryProperty(byte[] data, T type) {
//        setData(data, type);
//    }
//    
//    /**
//     * Creates a binary property.
//     * @param in an input stream to the binary data (will be closed)
//     * @param type the content type
//     * @throws IOException if there is a problem reading from the input stream
//     */
//    public BinaryProperty(InputStream in, T type) throws IOException {
//        this(new Gobble(in).asByteArray(), type);
//    }
//    
//    /**
//     * Creates a binary property.
//     * @param file the file containing the binary data
//     * @param type the content type
//     * @throws IOException if there is a problem reading from the file
//     */
//    public BinaryProperty(File file, T type) throws IOException {
//        this(new BufferedInputStream(new FileInputStream(file)), type);
//    }
//    
//    /**
//     * Copy constructor.
//     * @param original the property to make a copy of
//     */
//    public BinaryProperty(BinaryProperty<T> original) {
//        super(original);
//        data = (original.data == null) ? null : original.data.clone();
//        url = original.url;
//        contentType = original.contentType;
//    }
    
    /**
     * Gets the binary data of the resource.
     * @return the binary data or null if there is none
     */
    std::string getData() {
        return _data;
    }
    
    /**
     * Sets the binary data of the resource.
     * @param data the binary data
     * @param type the content type (e.g. "JPEG image")
     */
    void setData(const std::string& data, const std::shared_ptr<T>& type) {
        _url = "";
        _data = data;
        setContentType(type);
    }
    
    /**
     * Gets the URL to the resource
     * @return the URL or null if there is none
     */
    std::string getUrl() {
        return _url;
    }
    
    /**
     * Sets the URL to the resource.
     * @param url the URL
     * @param type the content type (e.g. "JPEG image")
     */
    void setUrl(const std::string& url, const std::shared_ptr<T>& type) {
        _url = url;
        _data = "";
        setContentType(type);
    }
    
    /**
     * Gets the content type of the resource.
     * @return the content type (e.g. "JPEG image")
     */
    std::shared_ptr<T> getContentType() {
        return _contentType;
    }
    
    /**
     * Sets the content type of the resource.
     * @param contentType the content type (e.g. "JPEG image")
     */
    void setContentType(const std::shared_ptr<T>&  contentType) {
        _contentType = contentType;
    }

//    /**
//     * Gets the vCard 4.0 TYPE parameter. This should NOT be used to get the
//     * TYPE parameter for 2.1/3.0 vCards. Use {@link #getContentType} instead.
//     * <p>
//     * <b>Supported versions:</b> {@code 4.0}
//     * </p>
//     * @return the TYPE value (typically, this will be either "work" or "home")
//     * or null if it doesn't exist
//     */
//    public String getType() {
//        return parameters.getType();
//    }
//    
//    /**
//     * Sets the vCard 4.0 TYPE parameter. This should NOT be used to set the
//     * TYPE parameter for 2.1/3.0 vCards. Use {@link #setContentType} instead.
//     * <p>
//     * <b>Supported versions:</b> {@code 4.0}
//     * </p>
//     * @param type the TYPE value (should be either "work" or "home") or null to
//     * remove
//     */
//    public void setType(String type) {
//        parameters.setType(type);
//    }
//    
//    @Override
//    public List<Pid> getPids() {
//        return super.getPids();
//    }
//    
//    @Override
//    public Integer getPref() {
//        return super.getPref();
//    }
//    
//    @Override
//    public void setPref(Integer pref) {
//        super.setPref(pref);
//    }

protected:
    void _validate(std::list<ValidationWarning::Ptr>& warnings, const VCardVersion::Ptr& version, const std::shared_ptr<VCard>& vcard) {
        if (_url == "" && _data == "") {
            warnings.push_back(std::make_shared<ValidationWarning>(8));
        }
    }
//
//    @Override
//    protected Map<String, Object> toStringValues() {
//        Map<String, Object> values = new LinkedHashMap<String, Object>();
//        values.put("data", (data == null) ? "null" : "length: " + data.length);
//        values.put("url", url);
//        values.put("contentType", contentType);
//        return values;
//    }
//    
//    @Override
//    public int hashCode() {
//        final int prime = 31;
//        int result = super.hashCode();
//        result = prime * result + ((contentType == null) ? 0 : contentType.hashCode());
//        result = prime * result + Arrays.hashCode(data);
//        result = prime * result + ((url == null) ? 0 : url.hashCode());
//        return result;
//    }
//    
//    @Override
//    public boolean equals(Object obj) {
//        if (this == obj) return true;
//        if (!super.equals(obj)) return false;
//        BinaryProperty<?> other = (BinaryProperty<?>) obj;
//        if (contentType == null) {
//            if (other.contentType != null) return false;
//        } else if (!contentType.equals(other.contentType)) return false;
//        if (!Arrays.equals(data, other.data)) return false;
//        if (url == null) {
//            if (other.url != null) return false;
//        } else if (!url.equals(other.url)) return false;
//        return true;
//    }
};


}

#endif /* binary_property_hpp */
