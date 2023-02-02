#include "funcional_tests.h"

void exponentialFuncionalTest() {
    Model* model = new Model();
    System* s1 = new System("pop1", 100.0);
    System* s2 = new System("pop2", 0.0);
    Flow* flow = new FlowExponential("Exponencial", s1, s2);
    
    model->setName("Sistema exponencial");
    model->add(s1);
    model->add(s2);
    model->add(flow);

    model->run(0, 100, 1);

    model->show();

    //assert(fabs(s1->getValue() - 36.6032) < 0.0001); // old version
    //printf("\n%lf\n", s1->getValue() - 36.6032); // = -0.000067
    //printf("\n%lf\n", round(s1->getValue() - 36.6033)); // = -0.000000

    assert(round(fabs(s1->getValue() - 36.6032) * 10000) == 0);
    assert(round(fabs(s2->getValue() - 63.3968) * 10000) == 0);

    model->clear();

    delete model;
    delete s1;
    delete s2;
    delete flow;
}

void logisticalFuncionalTest(){
    Model* model = new Model();
    System* s1 = new System("p1", 100.0);
    System* s2 = new System("p2", 10.0);
    Flow* flow = new FlowLogistical("Logistico", s1, s2);
    
    model->setName("Sistema logistico");

    model->add(s1);
    model->add(s2);
    model->add(flow);

    model->run(0, 100, 1);

    model->show();

    assert(round(fabs(s1->getValue() - 88.2167) * 10000) == 0);
    assert(round(fabs(s2->getValue() - 21.7833) * 10000) == 0);

    model->clear();

    delete model;
    delete s1;
    delete s2;
    delete flow;
}

void complexFuncionalTest(){
    Model* model = new Model();
    System* s1 = new System("Q1", 100.0);
    System* s2 = new System("Q2", 0.0);
    System* s3 = new System("Q3", 100.0);
    System* s4 = new System("Q4", 0.0);
    System* s5 = new System("Q5", 0.0);
    Flow* f = new FlowExponential("f", s1, s2);
    Flow* t = new FlowExponential("t", s2, s3);
    Flow* u = new FlowExponential("u", s3, s4);
    Flow* v = new FlowExponential("v", s4, s1);
    Flow* g = new FlowExponential("g", s1, s3);
    Flow* r = new FlowExponential("r", s2, s5);
    
    model->setName("Sistema complexo");

    model->add(s1);
    model->add(s2);
    model->add(s3);
    model->add(s4);
    model->add(s5);
    model->add(f);
    model->add(t);
    model->add(u);
    model->add(v);
    model->add(g);
    model->add(r);  

    model->run(0, 100, 1);
    model->show();

    assert(round(fabs(s1->getValue() - 31.8513) * 10000) == 0);
    assert(round(fabs(s2->getValue() - 18.4003) * 10000) == 0);
    assert(round(fabs(s3->getValue() - 77.1143) * 10000) == 0);
    assert(round(fabs(s4->getValue() - 56.1728) * 10000) == 0);
    assert(round(fabs(s5->getValue() - 16.4612) * 10000) == 0);

    model->clear();

    delete model;
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
    delete f;
    delete t;
    delete u;
    delete v;
    delete g;
    delete r;
}