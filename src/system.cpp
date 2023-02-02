#include "system.h"

System :: System() {
    name = "NULL";
    value = 0;
}

System :: System(System &obj) {
    if (&obj == this) 
        return;

    name = obj.getName();
    value = obj.getValue();
};

System :: System(const string name, float value):name(name), value(value) {}
System :: System(const string name):name(name) {}
System :: System(float value):value(value) {}

string System :: getName() const{
    return name;
};

void System :: setName(const string name) {
    this->name = name;
}

float System :: getValue() const{
    return value;
}

void System :: setValue(float value) {
    this->value = value;
}

System& System :: operator= (const System& obj) {
    if(&obj == this)
        return *this;
    
    name = obj.getName();
    value = obj.getValue();

    return *this;
}

System :: ~System() {}