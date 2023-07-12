#include "documentation_module.h"

#include <stdlib.h>

int validate(char *data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}
int *check_available_documentation_module(int (*validate)(char *), int document_count, ...) {
    int *availability_mask = malloc(document_count * sizeof(int));
    va_list docs;
    va_start(docs, document_count);
    for (int i = 0; i < document_count; ++i) {
        char *temp = va_arg(docs, char *);
        if (temp == NULL || strcmp(temp, "") == 0) break;
        availability_mask[i] = validate(temp);
    }
    va_end(docs);
    return availability_mask;
}
void output_availability(void (*print)(char *), const int *avail, int doc_count, ...) {
    va_list docs;
    va_start(docs, doc_count);
    char m[1000];
    for (int i = 0; i < doc_count; i++) {
        char *temp = va_arg(docs, char *);
        if (temp == NULL || strcmp(temp, "") == 0) break;
        if (i != 0) print("\n");
        sprintf(m, "%s: %s", temp, avail[i] ? "available" : "unavailable");
        print(m);
    }
    va_end(docs);
}
