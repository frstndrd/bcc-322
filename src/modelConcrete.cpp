#include "modelConcrete.h"

static vector<Model*> models;

ModelConcrete::ModelConcrete() {
    name = "NULL";
    flows.clear();
    systems.clear();
}

ModelConcrete::ModelConcrete(const string name, vector<Flow*> &flows, vector<System*> &systems) : name(name), flows(flows), systems(systems) {}
ModelConcrete::ModelConcrete(const string name):name(name) {}

ModelConcrete::ModelConcrete(Model &obj) {
    if(&obj == this)
        return;

    name = obj.getName();
}

ModelConcrete::~ModelConcrete() {}

Model* Model::createModel(const string& id) {
    return ModelConcrete::createModel(id);
}

Model* ModelConcrete::createModel(const string& name) {
    Model* model = new ModelConcrete(name);
    models.push_back(model);

    return model;
}

System* ModelConcrete::createSystem(
    const string& name = "",
    const double& value = 0
) {
    System* system = new SystemConcrete();
    system->setName(name);
    system->setValue(value);
    
    this->add(system);

    return system;
}

string ModelConcrete::getName() const{
    return name;
}

void ModelConcrete::setName(const string name) {
    this->name = name;
}

ModelConcrete::itFlow ModelConcrete::getFlowBegin() {
    return flows.begin();
}

ModelConcrete::itFlow ModelConcrete::getFlowEnd() {
    return flows.end();
}
    
int ModelConcrete::getFlowSize() {
    return flows.size();
}   

ModelConcrete::itSystem ModelConcrete::getSystemBegin() {
    return systems.begin();
}

ModelConcrete::itSystem ModelConcrete::getSystemEnd() {
    return systems.end();
}

int ModelConcrete::getSystemSize() {
    return systems.size();
} 

void ModelConcrete::add(System* subSystem) {
    systems.push_back(subSystem);
}

void ModelConcrete::add(Flow* flow) {
    flows.push_back(flow);
}

bool ModelConcrete::remove(System* obj) {
    for(auto thisystem = systems.begin(); thisystem != systems.end(); thisystem++) {
        if(*thisystem == obj) {
            systems.erase(thisystem);
            return true;
        }
    }
    return false;
}

bool ModelConcrete::remove(Flow* obj) {
    for(auto thisFlows = flows.begin(); thisFlows != flows.end(); thisFlows++) {
        if(*thisFlows == obj) {
            flows.erase(thisFlows);
            return true;
        }
    }
    return false;
}

ModelConcrete& ModelConcrete::operator=(const ModelConcrete& obj) {
    if(this != &obj) {
        this->flows.clear();
        this->systems.clear();
        this->flows.insert(this->flows.begin(), obj.flows.begin(), obj.flows.end());
        this->systems.insert(this->systems.begin(), obj.systems.begin(), obj.systems.end());
    }
    return *this;
}

void ModelConcrete::clear() {
    name = "NULL";
    flows.clear();
    systems.clear();
}

void ModelConcrete::run(int start, int finish, int increment) {
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

void ModelConcrete::show() {
    cout << endl;
}