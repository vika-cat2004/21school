#include "documentation_module.h"
#include "print_module.h"

int main() {
#ifdef Q1
    print_log(print_char, Module_load_success_message);
#endif
#ifdef Q2
    int *availability_mask = check_available_documentation_module(validate, Documents_count, Documents);
    output_availability(print_string, availability_mask, Documents_count, Documents);
#endif
    return 0;
}
