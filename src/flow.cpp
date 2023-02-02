#include "flow.h"

Flow :: Flow() {
    name = "NULL";
    source = NULL;
    target = NULL;
}

Flow :: Flow(Flow &obj) {
    if(&obj == this)
        return;

    name = obj.getName();
    source = obj.getSource();
    target = obj.getTarget();
}

Flow :: Flow(const string name, System *source, System *target):name(name), source(source), target(target){};
Flow :: ~Flow() {};

string Flow::getName() const {
    return name;
}

void Flow :: setName(const string name) {
    this->name = name;
}

System *Flow::getSource() const {
    return source;
}

void Flow :: setSource(System *source) {
    this->source = source;
}

System *Flow :: getTarget() const {
    return target;
}

void Flow :: setTarget(System *target) {
    this->target = target;
}

bool Flow:: operator== (const Flow &obj) const {
    return name == obj.getName() && source == obj.getSource() && target == obj.getTarget();
}

bool Flow :: operator!= (const Flow &obj) const {
    return !(obj == *this);
}

Flow &Flow::operator= (const Flow &obj) {
    if (&obj == this)
        return *this;

    name = obj.getName();
    source = obj.getSource();
    target = obj.getTarget();
    
    return *this;
}