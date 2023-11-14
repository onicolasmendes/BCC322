#include "unit_Flow.h"
#include "unit_Model.h"
#include "unit_System.h"
#include "unit_tests.h"

int main(int argc, char const *argv[])
{
    run_unit_test_Flow();
    run_unit_test_System();
    run_unit_test_Model();
    printf("Unit tests completed successfully\n");
    return 0;
}
