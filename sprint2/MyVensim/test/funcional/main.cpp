#ifndef  MAIN_FUNCIONAL_TESTS

#define MAIN_FUNCIONA_TESTS

#include "funcional_tests.h"

int main(int argc, char const *argv[])
{
    exponentialFuncionalTest();
    logisticalFuncionalTest();
    complexFuncionalTest();
    printf("Functional tests completed successfully\n");

    return 0;
}

#endif