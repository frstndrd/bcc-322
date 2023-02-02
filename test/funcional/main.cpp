#ifndef MAIN_FUNCIONAL_TESTS
#define MAIN_FUNCIONAL_TESTS

#include "funcional_tests.h"
#include "..\..\src\model.h"
#include "..\..\src\system.h"
#include "..\..\src\flow.h"

int main() {
    exponentialFuncionalTest();
    logisticalFuncionalTest();
    complexFuncionalTest();
    cout << "\t[+] Passou pelos testes funcionais!\n" << endl;
    return true;
}

#endif