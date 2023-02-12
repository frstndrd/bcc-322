#include "unit_system.h"
#include "..\..\src\system.h"

void unit_System_constructor(void) {
    System* s1 = new SystemConcrete();    
    assert(s1->getName() == "NULL");
    assert(s1->getValue() == 0);

    System* s2 = new SystemConcrete("test", 10);
    assert(s2->getName() == "test");
    assert(s2->getValue() == 10);

    delete s1;
    delete s2;
}

void unit_System_destructor(void) {};

void unit_System_getValue(void) {
    System* s = new SystemConcrete(10);
    assert(s->getValue() == 10);
}

void unit_System_setValue(void) {
    System* s = new SystemConcrete();
    s->setValue(100);
    assert(s->getValue() == 100);
}

void unit_System_getName(void) {
    System* s = new SystemConcrete("test");
    assert(s->getName() == "test");

    delete s;
}

void unit_System_setName(void) {
    System* s = new SystemConcrete();
    s->setName("test");
    assert(s->getName() == "test");

    delete s;
}

void run_unit_tests_System(void) {
    unit_System_constructor();
    unit_System_destructor();
    unit_System_getValue();
    unit_System_setValue();
    unit_System_getName();
    unit_System_setName();
}