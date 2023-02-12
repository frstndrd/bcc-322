#include "flowLogistical.h"

FlowLogistical::FlowLogistical() {
    name = "NULL";
    source = NULL;
    target = NULL;
}

FlowLogistical::FlowLogistical(Flow &obj) {
    if(&obj == this)
        return;

    name = obj.getName();
    source = obj.getSource();
    target = obj.getTarget();
};

FlowLogistical::FlowLogistical(const string name, System *origin, System *target):FlowConcrete(name, origin, target) {};
FlowLogistical::~FlowLogistical() {}

float FlowLogistical::execute(){
    return ((0.01 * getTarget()->getValue()) * (1 - getTarget()->getValue() / 70));
};  