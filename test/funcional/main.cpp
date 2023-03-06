#ifndef MAIN_FUNCIONAL_TESTS
#define MAIN_FUNCIONAL_TESTS

#include "funcional_tests.h"

#define GRN     "\x1B[32m"
#define RESET   "\033[m"

int main() {
    exponentialFuncionalTest();
    cout << "[+] Exponential test: " << GRN << "OK!" << RESET << endl;
    logisticalFuncionalTest();
    cout << "[+] Logistical test: " << GRN << "OK!" << RESET << endl;
    complexFuncionalTest();
    cout << "[+] Complex test: " << GRN << "OK!\n\n" << RESET;
    return 0;
}

#endif