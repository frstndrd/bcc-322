#include "flowExponential.h"

FlowExponential::FlowExponential() {
    name = "NULL";
    source = NULL;
    target = NULL;
}

FlowExponential::FlowExponential(Flow &obj) {
    if(&obj == this)
        return;
    
    name = obj.getName();
    source = obj.getSource();
    target = obj.getTarget();
};

FlowExponential::FlowExponential(const string name, System *source, System *target):FlowConcrete(name, source, target) {};
FlowExponential::~FlowExponential() {}

float FlowExponential::execute(){
    return getSource()->getValue() * 0.01;
};