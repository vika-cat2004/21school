#include "functions.h"

int checkId(FILE* ptr, int id) {
    int res = 0;
    if ((id >= 0) && (id <= getLastId(ptr))) res = 1;
    return res;
}

int getLastId(FILE* ptr) {
    int id = -1;
    if (ptr != NULL) {
        fseek(ptr, -sizeof(modules), SEEK_END);
        fread(&id, sizeof(int), 1, ptr);
        fseek(ptr, 0, SEEK_SET);
    }
    return id;
}
