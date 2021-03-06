//
//  vobject_property.cpp
//  OpenPGP
//
//  Created by Yanfeng Zhang on 12/5/16.
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

#include "vobject_property.hpp"

namespace vinnie {
    
    VObjectProperty::~VObjectProperty() {
        
    }
    
    /**
     * Creates an empty property.
     */
    VObjectProperty::VObjectProperty() {
        _parameters = std::make_shared<VObjectParameters>();
    }
    
    /**
     * Create a new property.
     * @param name the property name (should contain only letters, numbers, and
     * dashes; letters should be uppercase by convention)
     * @param value the property value
     */
    VObjectProperty::VObjectProperty(const std::string& name, const std::string& value) {
        _parameters = std::make_shared<VObjectParameters>();
        //this(null, name, value);
    }
    
    /**
     * Creates a new property
     * @param group the group name (should contain only letters, numbers, and
     * dashes; can be null)
     * @param name the property name (should contain only letters, numbers, and
     * dashes; letters should be uppercase by convention)
     * @param value the property value
     */
    VObjectProperty::VObjectProperty(const std::string& group, const std::string& name, const std::string& value) {
        _parameters = std::make_shared<VObjectParameters>();
        //this(group, name, new VObjectParameters(), value);
    }
    
    /**
     * Creates a new property
     * @param group the group name (should contain only letters, numbers, and
     * dashes; can be null)
     * @param name the property name (should contain only letters, numbers, and
     * dashes; letters should be uppercase by convention)
     * @param parameters the property parameters (cannot be null)
     * @param value the property value
     */
    VObjectProperty::VObjectProperty(const std::string& group, const std::string& name, const VObjectParameters::Ptr& parameters, const std::string& value) {
        _group = group;
        _name = name;
        _parameters = parameters;
        _value = value;
    }
    
    
    /**
     * Gets the group name (note: iCalendar properties do not use group names).
     * @return the group name or null if the property doesn't have one
     */
    std::string VObjectProperty::getGroup() {
        return _group;
    }
    
    /**
     * Sets the group name (note: iCalendar properties do not use group names).
     * @param group the group name or null to remove (should contain only
     * letters, numbers, and dashes)
     */
    void VObjectProperty::setGroup(const std::string& group) {
        _group = group;
    }
    
    /**
     * Gets the property name.
     * @return the property name
     */
    std::string VObjectProperty::getName() {
        return _name;
    }
    
    /**
     * Sets the property name.
     * @param name the property name (should contain only letters, numbers, and
     * dashes; letters should be uppercase by convention)
     */
    void VObjectProperty::setName(const std::string& name) {
        _name = name;
    }
    
    /**
     * Gets the parameters.
     * @return the parameters
     */
    VObjectParameters::Ptr VObjectProperty::getParameters() {
        return _parameters;
    }
    
    /**
     * Sets the parameters.
     * @param parameters the parameters (cannot be null)
     */
    void VObjectProperty::setParameters(const VObjectParameters::Ptr& parameters) {
        _parameters = parameters;
    }
    
    /**
     * Gets the property value.
     * @return the property value
     */
    std::string VObjectProperty::getValue() {
        return _value;
    }
    
    /**
     * Sets the property value.
     * @param value the property value
     */
    void VObjectProperty::setValue(const std::string& value) {
        _value = value;
    }
    
    
    
    //@Override
    //public int hashCode() {
    //    final int prime = 31;
    //    int result = 1;
    //    result = prime * result + ((group == null) ? 0 : group.hashCode());
    //    result = prime * result + ((name == null) ? 0 : name.hashCode());
    //    result = prime * result + ((parameters == null) ? 0 : parameters.hashCode());
    //    result = prime * result + ((value == null) ? 0 : value.hashCode());
    //    return result;
    //}
    //
    
    bool VObjectProperty::equals(const Ptr &obj) {
        if (obj == nullptr)
            return false;
        if (this == obj.get())
            return true;
        if (_group != obj->getGroup()) {
            return false;
        }
        if (_name != obj->getName()) {
            return false;
        }
        if (_value != obj->getValue()) {
            return false;
        }
        
        if (!_parameters->equals(obj->_parameters)) {
            return false;
        }
        
        return true;
    }
    
    //@Override
    //public String toString() {
    //    return "VObjectProperty [group=" + group + ", name=" + name + ", parameters=" + parameters + ", value=" + value + "]";
    //}
    
}
