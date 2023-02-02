#include "model.h"

Model :: Model() {
    name = "NULL";
    flows.clear();
    systems.clear();
}

Model :: Model(const string name, vector<Flow*> &flows, vector<System*> &systems) : name(name), flows(flows), systems(systems) {}
Model :: Model(const string name):name(name) {}

Model :: Model(Model &obj) {
    if(&obj == this)
        return;

    name = obj.getName();
}

Model :: ~Model() {}

string Model :: getName() const{
    return name;
}

void Model :: setName(const string name) {
    this->name = name;
}

Model :: itFlow Model :: getFlowBegin() {
    return flows.begin();
}

Model :: itFlow Model :: getFlowEnd() {
    return flows.end();
}
    
int Model :: getFlowSize() {
    return flows.size();
}   

Model :: itSystem Model :: getSystemBegin() {
    return systems.begin();
}

Model :: itSystem Model :: getSystemEnd() {
    return systems.end();
}

int Model :: getSystemSize() {
    return systems.size();
} 

void Model :: add(System* subSystem) {
    systems.push_back(subSystem);
}

void Model :: add(Flow* flow) {
    flows.push_back(flow);
}

bool Model :: remove(System* obj) {
    for(auto thisystem = systems.begin(); thisystem != systems.end(); thisystem++) {
        if(*thisystem == obj) {
            systems.erase(thisystem);
            return true;
        }
    }
    return false;
}

bool Model :: remove(Flow* obj) {
    for(auto thisFlows = flows.begin(); thisFlows != flows.end(); thisFlows++) {
        if(*thisFlows == obj) {
            flows.erase(thisFlows);
            return true;
        }
    }
    return false;
}

Model& Model :: operator=(const Model& obj) {
    if(this != &obj) {
        this->flows.clear();
        this->systems.clear();
        this->flows.insert(this->flows.begin(), obj.flows.begin(), obj.flows.end());
        this->systems.insert(this->systems.begin(), obj.systems.begin(), obj.systems.end());
    }
    return *this;
}

void Model :: clear() {
    name = "NULL";
    flows.clear();
    systems.clear();
}

void Model :: run(int start, int finish, int increment) {
    vector<Flow*> :: iterator ItFlow;

    System* source;
    System* target;

    vector<float> flowValue;

    unsigned int i = 0;
    unsigned int j = 0;
    float initial = 0.0;

    for (i = 0; i < flows.size(); i++) {
        flowValue.push_back(initial);
    }

    for(int index = start; index < finish; index += increment) {
        i = 0;
        ItFlow = flows.begin();
        while (i != flows.size()) {
            flowValue[i] = (*ItFlow)->execute();
            ItFlow++;
            i++;
        }
        j = 0;
        while (j != flows.size()) {
            source = flows[j]->getSource();
            source->setValue(source->getValue() - flowValue[j]);

            target = flows[j]->getTarget();
            target->setValue(target->getValue() + flowValue[j]);
            j++;
        }
    }
    
}

void Model :: show() {
    cout << endl;
}