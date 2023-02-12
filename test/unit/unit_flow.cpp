#include "unit_flow.h"
#include "..\..\src\flow.h"

void unit_Flow_constructor(void) {
    System* s1 = new SystemConcrete();
    System* s2 = new SystemConcrete();

    // exponential
    Flow* flowExp1 = new FlowExponential();
    assert(flowExp1->getName() == "NULL");
    assert(flowExp1->getSource() == NULL);
    assert(flowExp1->getTarget() == NULL);

    Flow* flowExp2 = new FlowExponential("test", s1, s2);
    assert(flowExp2->getName() == "test");
    assert(flowExp2->getSource() == s1);
    assert(flowExp2->getTarget() == s2);

    // logistical
    Flow* flowLog1 = new FlowLogistical();
    assert(flowLog1->getName() == "NULL");
    assert(flowLog1->getSource() == NULL);
    assert(flowLog1->getTarget() == NULL);

    Flow* flowLog2 = new FlowLogistical("test", s1, s2);
    assert(flowLog2->getName() == "test");
    assert(flowLog2->getSource() == s1);
    assert(flowLog2->getTarget() == s2);

    delete s1;
    delete s2;
    delete flowExp1;
    delete flowExp2;
    delete flowLog1;
    delete flowLog2;
}

void unit_Flow_destructor(void) {};

void unit_Flow_getName(void) {
    System* s1 = new SystemConcrete();
    System* s2 = new SystemConcrete();

    // exponential
    Flow* flowExp1 = new FlowExponential("test", s1, s2);
    assert(flowExp1->getName() == "test");

    // logistical
    Flow* flowLog1 = new FlowLogistical("test", s1, s2);
    assert(flowLog1->getName() == "test");

    delete s1;
    delete s2;
    delete flowExp1;
    delete flowLog1;
}

void unit_Flow_setName(void) {
    // exponential
    Flow* flowExp1 = new FlowExponential();
    flowExp1->setName("test");
    assert(flowExp1->getName() == "test");

    // logistical
    Flow* flowLog1 = new FlowLogistical();
    flowLog1->setName("test");
    assert(flowLog1->getName() == "test"); 

    delete flowExp1;
    delete flowLog1;
}

void unit_Flow_getSource(void) {
    System* s1 = new SystemConcrete();
    System* s2 = new SystemConcrete();

    // exponential
    Flow* flowExp1 = new FlowExponential("test", s1, s2);
    assert(flowExp1->getSource() == s1);

    // logistical
    Flow* flowLog1 = new FlowLogistical("test", s1, s2);
    assert(flowLog1->getSource() == s1);

    delete s1;
    delete s2;
    delete flowExp1;
    delete flowLog1;
}

void unit_Flow_setSource(void) {
    System* s1 = new SystemConcrete();
    System* s2 = new SystemConcrete();
    System* s3 = new SystemConcrete();

    // exponential
    Flow* flowExp1 = new FlowExponential("test", s1, s2);
    flowExp1->setSource(s3);
    assert(flowExp1->getSource() == s3);

    // logistical
    Flow* flowLog1 = new FlowLogistical("test", s1, s2);
    flowLog1->setSource(s3);
    assert(flowLog1->getSource() == s3);

    delete s1;
    delete s2;
    delete s3;
    delete flowExp1;
    delete flowLog1;
}

void unit_Flow_getTarget(void) {
    System* s1 = new SystemConcrete();
    System* s2 = new SystemConcrete();

    // exponential
    Flow* flowExp1 = new FlowExponential("test", s1, s2);
    assert(flowExp1->getTarget() == s2);

    // logistical
    Flow* flowLog1 = new FlowLogistical("test", s1, s2);
    assert(flowLog1->getTarget() == s2);

    delete s1;
    delete s2;
    delete flowExp1;
    delete flowLog1;
}

void unit_Flow_setTarget(void) {
    System* s1 = new SystemConcrete();
    System* s2 = new SystemConcrete();
    System* s3 = new SystemConcrete();

    // exponential
    Flow* flowExp1 = new FlowExponential("test", s1, s2);
    flowExp1->setTarget(s3);
    assert(flowExp1->getTarget() == s3);

    // logistical
    Flow* flowLog1 = new FlowLogistical("test", s1, s2);
    flowLog1->setTarget(s3);
    assert(flowLog1->getTarget() == s3);

    delete s1;
    delete s2;
    delete s3;
    delete flowExp1;
    delete flowLog1;
}

void unit_Flow_execute(void) {
    System* s1 = new SystemConcrete(100.0);
    System* s2 = new SystemConcrete(0.0);
    Model* m = new ModelConcrete();

    // exponential
    Flow* flowExp1 = new FlowExponential("test", s1, s2);
    m->add(s1);
    m->add(s2);
    m->add(flowExp1);

    m->run(0, 100, 1);

    assert(abs(s1->getValue() - 36.6032) <  0.0001);
    assert(abs(s2->getValue() - 63.3968) <  0.0001);

    m->clear();

    // logistical
    s1->setValue(100.0);
    s2->setValue(10.0);
    Flow* flowLog1 = new FlowLogistical("test", s1, s2);
    m->add(s1);
    m->add(s2);
    m->add(flowLog1);

    m->run(0, 100, 1);

    assert(abs(s1->getValue() - 88.2167) <  0.0001f);
    assert(abs(s2->getValue() - 21.7834) <  0.0001f);

    m->clear();

    delete s1;
    delete s2;
    delete flowExp1;
    delete flowLog1;
    delete m;
}

void run_unit_tests_Flow(void){
    unit_Flow_constructor();
    unit_Flow_destructor();
    unit_Flow_getName();
    unit_Flow_setName();
    unit_Flow_getSource();
    unit_Flow_setSource();
    unit_Flow_getTarget();
    unit_Flow_setTarget();
    unit_Flow_execute();
}