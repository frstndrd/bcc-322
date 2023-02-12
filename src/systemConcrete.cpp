#include "systemConcrete.h"

SystemConcrete::SystemConcrete() {
    name = "NULL";
    value = 0;
}

SystemConcrete::SystemConcrete(System &obj) {
    if (&obj == this) 
        return;

    name = obj.getName();
    value = obj.getValue();
};

SystemConcrete::SystemConcrete(const string name, float value):name(name), value(value) {}
SystemConcrete::SystemConcrete(const string name):name(name) {}
SystemConcrete::SystemConcrete(float value):value(value) {}
SystemConcrete::~SystemConcrete() {}

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

