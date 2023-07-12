// #include "list.c"
#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#include "door_struct.h"

void add_door_test();
void remove_door_test();

int main() {
    add_door_test();
    remove_door_test();
    return 0;
}

void add_door_test() {
    struct door door1 = {1, 0};
    struct door door2 = {2, 1};
    struct door door3 = {3, 0};
    struct node* root = init(&door1);
    struct node* nodeDoor2 = add_door(root, &door2);
    if (root->next == nodeDoor2 && root->next->door->id == nodeDoor2->door->id) {
        printf("SUCCESS\n");
    } else {
        printf("FAULT\n");
    }
    add_door(nodeDoor2, &door3);
    if (nodeDoor2->next->door->id == 3 && root->next->next->door->id == 3) {
        printf("SUCCESS\n");
    } else {
        printf("FAULT\n");
    }
}

void remove_door_test() {
    struct door door1 = {1, 0};
    struct node* root = init(&door1);
    if (root->next < root->next->next) {
        remove_door(root->next->next, root->next);
        printf("SUCCESS\n");
    } else {
        printf("FAULT\n");
    }
}

struct node* remove = find_door(4, list);
    list = remove_door(remove, list);

    flag = 1;
    check_add = list;
    pos = 5;
    while (check_add) {
        if (removed_doors[pos].id != list->door_value.id &&
            removed_doors[pos].status != list->door_value.status) {
            flag = 0;
        }
        pos--;
        check_add = check_add->next;
    }
    if (flag == 1)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    destroy(list);
    destroy(check_add);
    return 0;
}
