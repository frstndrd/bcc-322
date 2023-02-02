#ifndef MAIN_FUNCIONAL_TESTS
#define MAIN_FUNCIONAL_TESTS

#include "funcional_tests.h"
#include "..\..\src\model.h"
#include "..\..\src\system.h"
#include "..\..\src\flow.h"

int main() {
    exponentialFuncionalTest();
    cout << "\t[+] Passou pelo teste exponencial!\n" << endl;
    logisticalFuncionalTest();
    cout << "\t[+] Passou pelo teste logistico!\n" << endl;
    complexFuncionalTest();
    cout << "\t[+] Passou por todos testes funcionais!\n" << endl;
    return true;
}

#endif