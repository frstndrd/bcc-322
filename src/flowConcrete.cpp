#include "flowConcrete.h"

FlowConcrete::FlowConcrete() {
    name = "NULL";
    source = NULL;
    target = NULL;
}

FlowConcrete::FlowConcrete(Flow &obj) {
    if(&obj == this)
        return;

    name = obj.getName();
    source = obj.getSource();
    target = obj.getTarget();
}

FlowConcrete::FlowConcrete(const string name, System *source, System *target):name(name), source(source), target(target) {};
FlowConcrete::~FlowConcrete() {};

string FlowConcrete::getName() const {
    return name;
}

void FlowConcrete::setName(const string name) {
    this->name = name;
}

System *FlowConcrete::getSource() const {
    return source;
}

void FlowConcrete::setSource(System *source) {
    this->source = source;
}

System *FlowConcrete::getTarget() const {
    return target;
}

void FlowConcrete::setTarget(System *target) {
    this->target = target;
}

/*
bool Flow::operator==(const Flow &obj) const {
    return name == obj.getName() && source == obj.getSource() && target == obj.getTarget();
}

bool FlowConcrete:: operator!= (const Flow &obj) const {
    return !(obj == *this);
}
*/

Flow &FlowConcrete::operator= (const Flow &obj) {
    if (&obj == this)
        return *this;

    name = obj.getName();
    source = obj.getSource();
    target = obj.getTarget();
    
    return *this;
}