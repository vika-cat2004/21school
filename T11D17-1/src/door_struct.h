#ifndef DOOR_STRUCT_H
#define DOOR_STRUCT_H

struct door {
    int id;
    int status;
};

void initialize_doors(struct door* doors);
void quick_sort(struct door* doors);
void close(struct door* doors);
void output(struct door* doors);

#endif