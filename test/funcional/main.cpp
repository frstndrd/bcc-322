#ifndef MAIN_FUNCIONAL_TESTS
#define MAIN_FUNCIONAL_TESTS

#include "funcional_tests.h"
#include "..\..\src\model.h"
#include "..\..\src\system.h"
#include "..\..\src\flow.h"

#define GRN     "\x1B[32m"
#define RESET   "\033[m"

int main() {
    exponentialFuncionalTest();
    cout << "[+] Exponential Test: " << GRN << "OK!" << RESET;
    logisticalFuncionalTest();
    cout << "[+] Logistical Test: " << GRN << "OK!" << RESET;
    complexFuncionalTest();
    cout << "[+] Complex Test: " << GRN << "OK!\n\n" << RESET;
    return true;
}

#endif