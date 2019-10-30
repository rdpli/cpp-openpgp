//
//  vcard_property_scribe.cpp
//  OpenPGP
//
//  Created by Yanfeng Zhang on 1/11/17.
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


#include "vcard_property_scribe.hpp"

#include "vobject_property_values.hpp"


namespace ezvcard {
    


VCardPropertyScribe::VCardPropertyScribe(const std::string& propertyName) {
    _propertyName = propertyName;
}
//    public VCardPropertyScribe(Class<T> clazz, String propertyName) {
//        this(clazz, propertyName, new QName(VCardVersion.V4_0.getXmlNamespace(), propertyName.toLowerCase()));
//    }
//    
//    /**
//     * Creates a new scribe.
//     * @param clazz the property class
//     * @param propertyName the property name (e.g. "FN")
//     * @param qname the XML element name and namespace to use for xCard
//     * documents (by default, the XML element name is set to the lower-cased
//     * property name, and the element namespace is set to the xCard namespace)
//     */
//    public VCardPropertyScribe(Class<T> clazz, String propertyName, QName qname) {
//        this.clazz = clazz;
//        this.propertyName = propertyName;
//        this.qname = qname;
//    }
//    
//    /**
//     * Gets the property class.
//     * @return the property class
//     */
//    public Class<T> getPropertyClass() {
//        return clazz;
//    }
//

///**
// * Gets the property name.
// * @return the property name (e.g. "FN")
// */
//std::string VCardPropertyScribe::getPropertyName() {
//    return _propertyName;
//}

std::string VCardPropertyScribe::_getPropertyName() {
    return _propertyName;
}

//
//    /**
//     * Gets this property's local name and namespace for xCard documents.
//     * @return the XML local name and namespace
//     */
//    public QName getQName() {
//        return qname;
//    }
//    



//
//    /**
//     * Marshals a property's value to an XML element (xCard).
//     * @param property the property
//     * @param element the property's XML element.
//     * @throws SkipMeException if the property should not be written to the data
//     * stream
//     */
//    public final void writeXml(T property, Element element) {
//        XCardElement xCardElement = new XCardElement(element);
//        _writeXml(property, xCardElement);
//    }
//    
//    /**
//     * Marshals a property's value to a JSON data stream (jCard).
//     * @param property the property
//     * @return the marshalled value
//     * @throws SkipMeException if the property should not be written to the data
//     * stream
//     */
//    public final JCardValue writeJson(T property) {
//        return _writeJson(property);
//    }


//    /**
//     * Unmarshals a property's value from an XML document (xCard).
//     * @param element the property's XML element
//     * @param parameters the parsed parameters
//     * @return the unmarshalled property and its warnings
//     * @throws CannotParseException if the marshaller could not parse the
//     * property's value
//     * @throws SkipMeException if the property should not be added to the final
//     * {@link VCard} object
//     */
//    public final Result<T> parseXml(Element element, VCardParameters parameters) {
//        List<String> warnings = new ArrayList<String>(0);
//        T property = _parseXml(new XCardElement(element), parameters, warnings);
//        property.setParameters(parameters);
//        return new Result<T>(property, warnings);
//    }
//    
//    /**
//     * Unmarshals the property from an HTML document (hCard).
//     * @param element the property's HTML element
//     * @return the unmarshalled property and its warnings
//     * @throws CannotParseException if the property value could not be parsed
//     * @throws SkipMeException if this type should NOT be added to the
//     * {@link VCard} object
//     * @throws EmbeddedVCardException if the property value is an embedded vCard
//     * (i.e. the AGENT property)
//     */
//    public final Result<T> parseHtml(HCardElement element) {
//        List<String> warnings = new ArrayList<String>(0);
//        T property = _parseHtml(element, warnings);
//        return new Result<T>(property, warnings);
//    }
//    
//    /**
//     * Unmarshals a property's value from a JSON data stream (jCard).
//     * @param value the property's JSON value
//     * @param dataType the data type
//     * @param parameters the parsed parameters
//     * @return the unmarshalled property and its warnings
//     * @throws CannotParseException if the marshaller could not parse the
//     * property's value
//     * @throws SkipMeException if the property should not be added to the final
//     * {@link VCard} object
//     */
//    public final Result<T> parseJson(JCardValue value, VCardDataType dataType, VCardParameters parameters) {
//        List<String> warnings = new ArrayList<String>(0);
//        T property = _parseJson(value, dataType, parameters, warnings);
//        property.setParameters(parameters);
//        return new Result<T>(property, warnings);
//    }


//
//    /**
//     * <p>
//     * Determines the property's default data type.
//     * </p>
//     * <p>
//     * When writing a plain-text vCard, if the data type of a property instance
//     * (as determined by the {@link #dataType} method) matches the default data
//     * type, then a VALUE parameter will *not* be written.
//     * </p>
//     * <p>
//     * When parsing a plain-text vCard, if a property has no VALUE parameter,
//     * then the property's default data type will be passed into the
//     * {@link #parseText} method.
//     * </p>
//     * @param version the vCard version
//     * @return the default data type or null if unknown
//     */
//    protected abstract VCardDataType _defaultDataType(VCardVersion version);


//
//    /**
//     * Marshals a property's value to a string.
//     * @param property the property
//     * @param context contains information about the vCard being written, such
//     * as the target version
//     * @return the marshalled value
//     * @throws SkipMeException if the property should not be written to the data
//     * stream
//     */
//    protected abstract String _writeText(T property, WriteContext context);
//    
//    /**
//     * <p>
//     * Marshals a property's value to an XML element (xCard).
//     * </p>
//     * <p>
//     * This method should be overridden by child classes that wish to support
//     * xCard. The default implementation of this method will append one child
//     * element to the property's XML element. The child element's name will be
//     * that of the property's data type (retrieved using the {@link #dataType}
//     * method), and the child element's text content will be set to the
//     * property's marshalled plain-text value (retrieved using the
//     * {@link #writeText} method).
//     * </p>
//     * @param property the property
//     * @param element the property's XML element
//     * @throws SkipMeException if the property should not be written to the data
//     * stream
//     */
//    protected void _writeXml(T property, XCardElement element) {
//        String value = writeText(property, new WriteContext(VCardVersion.V4_0, null, false));
//        VCardDataType dataType = dataType(property, VCardVersion.V4_0);
//        element.append(dataType, value);
//    }
//    
//    /**
//     * <p>
//     * Marshals a property's value to a JSON data stream (jCard).
//     * </p>
//     * <p>
//     * This method should be overridden by child classes that wish to support
//     * jCard. The default implementation of this method will create a jCard
//     * property that has a single JSON string value (generated by the
//     * {@link #writeText} method).
//     * </p>
//     * @param property the property
//     * @return the marshalled value
//     * @throws SkipMeException if the property should not be written to the data
//     * stream
//     */
//    protected JCardValue _writeJson(T property) {
//        String value = writeText(property, new WriteContext(VCardVersion.V4_0, null, false));
//        return JCardValue.single(value);
//    }
//    
//    /**
//     * Unmarshals a property from a plain-text vCard.
//     * @param value the value as read off the wire
//     * @param dataType the data type of the property value. The property's VALUE
//     * parameter is used to determine the data type. If the property has no
//     * VALUE parameter, then this parameter will be set to the property's
//     * default datatype, as determined by the {@link #defaultDataType} method.
//     * Note that the VALUE parameter is removed from the property's parameter
//     * list after it has been read.
//     * @param version the version of the vCard that is being parsed
//     * @param parameters the parsed parameters. These parameters will be
//     * assigned to the property object once this method returns. Therefore, do
//     * not assign any parameters to the property object itself whilst inside of
//     * this method, or else they will be overwritten.
//     * @param warnings allows the programmer to alert the user to any
//     * note-worthy (but non-critical) issues that occurred during the
//     * unmarshalling process
//     * @return the unmarshalled property object
//     * @throws CannotParseException if the marshaller could not parse the
//     * property's value
//     * @throws SkipMeException if the property should not be added to the final
//     * {@link VCard} object
//     */
//    protected abstract T _parseText(String value, VCardDataType dataType, VCardVersion version, VCardParameters parameters, List<String> warnings);
//    
//    /**
//     * <p>
//     * Unmarshals a property from an XML document (xCard).
//     * </p>
//     * <p>
//     * This method should be overridden by child classes that wish to support
//     * xCard. The default implementation of this method will find the first
//     * child element with the xCard namespace. The element's name will be used
//     * as the property's data type and its text content (escaped for inclusion
//     * in a text-based vCard, e.g. escaping comma characters) will be passed
//     * into the {@link #_parseText} method. If no such child element is found,
//     * then the parent element's text content will be passed into
//     * {@link #_parseText} and the data type will be {@code null}.
//     * </p>
//     * @param element the property's XML element
//     * @param parameters the parsed parameters. These parameters will be
//     * assigned to the property object once this method returns. Therefore, do
//     * not assign any parameters to the property object itself whilst inside of
//     * this method, or else they will be overwritten.
//     * @param warnings allows the programmer to alert the user to any
//     * note-worthy (but non-critical) issues that occurred during the
//     * unmarshalling process
//     * @return the unmarshalled property object
//     * @throws CannotParseException if the marshaller could not parse the
//     * property's value
//     * @throws SkipMeException if the property should not be added to the final
//     * {@link VCard} object
//     */
//    protected T _parseXml(XCardElement element, VCardParameters parameters, List<String> warnings) {
//        XCardValue firstValue = element.firstValue();
//        VCardDataType dataType = firstValue.getDataType();
//        String value = VObjectPropertyValues.escape(firstValue.getValue());
//        return _parseText(value, dataType, element.version(), parameters, warnings);
//    }
//    
//    /**
//     * <p>
//     * Unmarshals the property from an hCard (HTML document).
//     * </p>
//     * <p>
//     * This method should be overridden by child classes that wish to support
//     * hCard. The default implementation of this method will retrieve the HTML
//     * element's hCard value (as described in {@link HCardElement#value}), and
//     * pass it into the {@link #_parseText} method.
//     * </p>
//     * @param element the property's HTML element
//     * @param warnings allows the programmer to alert the user to any
//     * note-worthy (but non-critical) issues that occurred during the
//     * unmarshalling process
//     * @return the unmarshalled property object
//     * @throws CannotParseException if the property value could not be parsed
//     * @throws SkipMeException if this property should NOT be added to the
//     * {@link VCard} object
//     * @throws EmbeddedVCardException if the value of this property is an
//     * embedded vCard (i.e. the AGENT property)
//     */
//    protected T _parseHtml(HCardElement element, List<String> warnings) {
//        String value = VObjectPropertyValues.escape(element.value());
//        VCardParameters parameters = new VCardParameters();
//        T property = _parseText(value, null, VCardVersion.V3_0, parameters, warnings);
//        property.setParameters(parameters);
//        return property;
//    }
//    
//    /**
//     * <p>
//     * Unmarshals a property from a JSON data stream (jCard).
//     * </p>
//     * <p>
//     * This method should be overridden by child classes that wish to support
//     * jCard. The default implementation of this method will convert the jCard
//     * property value to a string and pass it into the {@link #_parseText}
//     * method.
//     * </p>
//     *
//     * <hr>
//     *
//     * <p>
//     * The following paragraphs describe the way in which this method's default
//     * implementation converts a jCard value to a string:
//     * </p>
//     * <p>
//     * If the jCard value consists of a single, non-array, non-object value,
//     * then the value is converted to a string. Special characters (backslashes,
//     * commas, and semicolons) are escaped in order to simulate what the value
//     * might look like in a plain-text vCard.<br>
//     * <code>["x-foo", {}, "text", "the;value"] --&gt; "the\;value"</code><br>
//     * <code>["x-foo", {}, "text", 2] --&gt; "2"</code>
//     * </p>
//     * <p>
//     * If the jCard value consists of multiple, non-array, non-object values,
//     * then all the values are appended together in a single string, separated
//     * by commas. Special characters (backslashes, commas, and semicolons) are
//     * escaped for each value in order to prevent commas from being treated as
//     * delimiters, and to simulate what the value might look like in a
//     * plain-text vCard.<br>
//     * <code>["x-foo", {}, "text", "one", "two,three"] --&gt;
//     * "one,two\,three"</code>
//     * </p>
//     * <p>
//     * If the jCard value is a single array, then this array is treated as a
//     * "structured value", and converted its plain-text representation. Special
//     * characters (backslashes, commas, and semicolons) are escaped for each
//     * value in order to prevent commas and semicolons from being treated as
//     * delimiters.<br>
//     * <code>["x-foo", {}, "text", ["one", ["two", "three"], "four;five"]]
//     * --&gt; "one;two,three;four\;five"</code>
//     * </p>
//     * <p>
//     * If the jCard value starts with a JSON object, then it is converted to an
//     * empty string (JSON objects are not supported by this method).<br>
//     * <code>["x-foo", , "text", {"one": 1}] --&gt; ""}</code>
//     * </p>
//     * <p>
//     * For all other cases, behavior is undefined.
//     * </p>
//     * @param value the property's JSON value
//     * @param dataType the data type
//     * @param parameters the parsed parameters. These parameters will be
//     * assigned to the property object once this method returns. Therefore, do
//     * not assign any parameters to the property object itself whilst inside of
//     * this method, or else they will be overwritten.
//     * @param warnings allows the programmer to alert the user to any
//     * note-worthy (but non-critical) issues that occurred during the
//     * unmarshalling process
//     * @return the unmarshalled property object
//     * @throws CannotParseException if the marshaller could not parse the
//     * property's value
//     * @throws SkipMeException if the property should not be added to the final
//     * {@link VCard} object
//     */
//    protected T _parseJson(JCardValue value, VCardDataType dataType, VCardParameters parameters, List<String> warnings) {
//        String valueStr = jcardValueToString(value);
//        return _parseText(valueStr, dataType, VCardVersion.V4_0, parameters, warnings);
//    }
//    
//    /**
//     * Converts a jCard value to its plain-text format representation.
//     * @param value the jCard value
//     * @return the plain-text format representation (for example, "1,2,3" for a
//     * list of values)
//     */
//    private static String jcardValueToString(JCardValue value) {
//        List<JsonValue> values = value.getValues();
//        if (values.size() > 1) {
//            List<String> multi = value.asMulti();
//            if (!multi.isEmpty()) {
//                return VObjectPropertyValues.writeList(multi);
//            }
//        }
//        
//        if (!values.isEmpty() && values.get(0).getArray() != null) {
//            List<List<String>> structured = value.asStructured();
//            if (!structured.isEmpty()) {
//                return VObjectPropertyValues.writeStructured(structured, true);
//            }
//        }
//        
//        return VObjectPropertyValues.escape(value.asSingle());
//    }
//    
//    /**
//     * Parses a date string.
//     * @param value the date string
//     * @return the parsed date
//     * @throws IllegalArgumentException if the date cannot be parsed
//     */
//    protected static Date date(String value) {
//        return VCardDateFormat.parse(value);
//    }
//    
//    /**
//     * Formats a {@link Date} object as a string.
//     * @param date the date
//     * @return a helper object for customizing the write operation
//     */
//    protected static DateWriter date(Date date) {
//        return new DateWriter(date);
//    }
//    
//    /**
//     * A helper class for writing date values.
//     */
//    protected static class DateWriter {
//        private Date date;
//        private boolean hasTime = true;
//        private boolean extended = false;
//        private boolean utc = true;
//        
//        /**
//         * Creates a new date writer object.
//         * @param date the date to format
//         */
//        public DateWriter(Date date) {
//            this.date = date;
//        }
//        
//        /**
//         * Sets whether to output the date's time component.
//         * @param hasTime true include the time, false if it's strictly a date
//         * (defaults to "true")
//         * @return this
//         */
//        public DateWriter time(boolean hasTime) {
//            this.hasTime = hasTime;
//            return this;
//        }
//        
//        /**
//         * Sets whether to use extended format or basic.
//         * @param extended true to use extended format, false to use basic
//         * (defaults to "false")
//         * @return this
//         */
//        public DateWriter extended(boolean extended) {
//            this.extended = extended;
//            return this;
//        }
//        
//        /**
//         * Sets whether to format the date in UTC time, or to include a UTC
//         * offset.
//         * @param utc true to format in UTC time, false to include the local
//         * timezone's UTC offset (defaults to "true")
//         * @return this
//         */
//        public DateWriter utc(boolean utc) {
//            this.utc = utc;
//            return this;
//        }
//        
//        /**
//         * Creates the date string.
//         * @return the date string
//         */
//        public String write() {
//            VCardDateFormat format;
//            if (hasTime) {
//                if (utc) {
//                    format = extended ? VCardDateFormat.UTC_DATE_TIME_EXTENDED : VCardDateFormat.UTC_DATE_TIME_BASIC;
//                } else {
//                    format = extended ? VCardDateFormat.DATE_TIME_EXTENDED : VCardDateFormat.DATE_TIME_BASIC;
//                }
//            } else {
//                format = extended ? VCardDateFormat.DATE_EXTENDED : VCardDateFormat.DATE_BASIC;
//            }
//            
//            return format.format(date);
//        }
//    }
//    
//    /**
//     * Creates a {@link CannotParseException} to indicate that a scribe could
//     * not find the necessary XML elements required in order to successfully
//     * parse a property (xCards only).
//     * @param dataTypes the expected data types (null for "unknown")
//     * @return the exception object (note that the exception is NOT thrown!)
//     */
//    protected static CannotParseException missingXmlElements(VCardDataType... dataTypes) {
//        String[] elements = new String[dataTypes.length];
//        for (int i = 0; i < dataTypes.length; i++) {
//            VCardDataType dataType = dataTypes[i];
//            elements[i] = (dataType == null) ? "unknown" : dataType.getName().toLowerCase();
//        }
//        return missingXmlElements(elements);
//    }
//    
//    /**
//     * Creates a {@link CannotParseException} to indicate that a scribe could
//     * not find the necessary XML elements required in order to successfully
//     * parse a property (xCards only).
//     * @param elements the names of the expected XML elements.
//     * @return the exception object (note that the exception is NOT thrown!)
//     */
//    protected static CannotParseException missingXmlElements(String... elements) {
//        return new CannotParseException(0, Arrays.toString(elements));
//    }


/**
 * <p>
 * Escapes special characters in a property value for writing to a
 * plain-text output stream.
 * </p>
 * <p>
 * If the target version is 2.1, then the value will be returned unchanged.
 * 2.1 only requires special characters to be escaped within properties that
 * make use of those special characters.
 * </p>
 * @param value the value to escape
 * @param context the write context
 * @return the escaped value
 */
std::string VCardPropertyScribe::escape(const std::string& value, const WriteContext::Ptr& context) {
    if (context->getVersion() == VCardVersion::V2_1()) {
        return value;
    }
    
    return VObjectPropertyValues::escape(value);
}


//    /**
//     * Represents the result of an unmarshal operation.
//     * @author Michael Angstadt
//     * @param <T> the unmarshalled property class
//     */
//    public static class Result<T extends VCardProperty> {
//        private final T property;
//        private final List<String> warnings;
//        
//        /**
//         * Creates a new result.
//         * @param property the property object
//         * @param warnings the warnings
//         */
//        public Result(T property, List<String> warnings) {
//            this.property = property;
//            this.warnings = warnings;
//        }
//        
//        /**
//         * Gets the warnings.
//         * @return the warnings
//         */
//        public List<String> getWarnings() {
//            return warnings;
//        }
//        
//        /**
//         * Gets the property object.
//         * @return the property object
//         */
//        public T getProperty() {
//            return property;
//        }
//    }
//}

}