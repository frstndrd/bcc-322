#include "unit_model.h"

void unit_Model_constructor(void) {
    Model* m1 = new ModelConcrete();
    assert(m1->getName() == "NULL");
    assert(m1->getFlowSize() == 0);
    assert(m1->getSystemSize() == 0);

    vector<Flow*> vectorFlow;
    Flow* flow = new FlowExponential();
    vectorFlow.push_back(flow);

    vector<System*> vectorSystem;
    System* s1 = new SystemConcrete();
    vectorSystem.push_back(s1);

    Model* m2 = new ModelConcrete("test", vectorFlow, vectorSystem);
    assert(m2->getName() == "test");
    assert(m2->getFlowSize() == 1);
    assert(m2->getSystemSize() == 1);

    delete m1;
    delete m2;
    delete flow;
    delete s1;
    vectorFlow.clear();
    vectorSystem.clear();
}

void unit_Model_destructor(void) {};

void unit_Model_getName(void) {
    Model* model = new ModelConcrete();
    assert(model->getName() == "NULL");

    delete model;
}

void unit_Model_setName(void) {
    Model* model = new ModelConcrete();
    model->setName("test");
    assert(model->getName() == "test");

    delete model;
}

void unit_Model_add(void) {
    Model* model = new ModelConcrete();
    System* s1 = new SystemConcrete("s1");
    System* s2 = new SystemConcrete("s2");    
    Flow* flow = new FlowExponential("flowExp", s1, s2);

    model->add(s1);
    model->add(s2);

    assert(model->getSystemSize() == 2);

    for(auto it = model->getSystemBegin(); it != model->getSystemEnd(); it++){
        if((*it)->getName() == s1->getName())
            assert((*it)->getName() == s1->getName());
    }

    model->add(flow);

    assert(model->getFlowSize() == 1);

    for(auto it = model->getFlowBegin(); it != model->getFlowEnd(); it++){
        if((*it)->getName() == flow->getName())
            assert((*it)->getName() == flow->getName());
    }

    model->clear();

    delete model;
    delete s1;
    delete s2;
    delete flow;
}

void unit_Model_remove(void) {
    Model* model = new ModelConcrete();
    System* s1 = new SystemConcrete("s1");

    model->add(s1);

    assert(model->getSystemSize() == 1);

    for(auto it = model->getSystemBegin(); it != model->getSystemEnd(); it++){
        if((*it)->getName() == s1->getName())
            assert((*it)->getName() == s1->getName());
    }

    model->remove(s1);

    assert(model->getSystemSize() == 0);

    model->clear();

    delete model;
    delete s1;
}

void unit_Model_clear(void) {
    Model* model = new ModelConcrete();
    System* s1 = new SystemConcrete("s1");
    System* s2 = new SystemConcrete("s2");    
    Flow* flow = new FlowExponential("flowExp", s1, s2);

    model->add(s1);
    model->add(s2);
    assert(model->getSystemSize() == 2);

    model->add(flow);
    assert(model->getFlowSize() == 1);

    model->clear();

    assert(model->getSystemSize() == 0);
    assert(model->getFlowSize() == 0);

    delete model;
    delete s1;
    delete s2;
    delete flow;
}

void unit_Model_run(void) {
    System* s1 = new SystemConcrete(100.0);
    System* s2 = new SystemConcrete(0.0);
    Model* model = new ModelConcrete();

    // exponential
    Flow* flow = new FlowExponential("test", s1, s2);
    model->add(s1);
    model->add(s2);
    model->add(flow);

    model->run(0, 100, 1);

    assert(abs(s1->getValue() - 36.6032) <  0.0001f);
    assert(abs(s2->getValue() - 63.3968) <  0.0001f);

    model->clear();

    delete s1;
    delete s2;
    delete flow;
    delete model;
}

void run_unit_tests_Model(void) {
    unit_Model_constructor();
    unit_Model_destructor();
    unit_Model_getName();
    unit_Model_setName();
    unit_Model_add();
    unit_Model_remove();
    unit_Model_clear();
    unit_Model_run();
}