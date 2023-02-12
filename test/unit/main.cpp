#ifndef MAIN_UNIT_TESTS
#define MAIN_UNIT_TESTS

#include "unit_system.h"
#include "unit_model.h"
#include "unit_flow.h"

#define GRN     "\x1B[32m"
#define RESET   "\033[m"

int main() {
    run_unit_tests_System();
    cout << "\n[+] System unit tests: " << GRN << "OK!" << RESET << endl;
    run_unit_tests_Flow();
    cout << "[+] Flow unit tests: " << GRN << "OK!" << RESET << endl;
    run_unit_tests_Model();
    cout << "[+] Model unit tests: " << GRN << "OK!\n" << RESET << endl;
    return 0;
}

#endif