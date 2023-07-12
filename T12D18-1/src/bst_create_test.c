#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void n() { printf("\n"); }

int cmp(int a, int b) { return a - b; }

void s21_btree_init() {
    int item = 2;
    t_btree *first = bstree_create_node(item);
    printf("Creating first node of binary tree with value %d: ", item);
    if (first->right == NULL && first->left == NULL && first->item == item) {
        printf("SUCCESS");
    } else {
        printf("FAILED");
    }

    n();

    item = -1;
    first = bstree_create_node(item);
    printf("Creating first node of binary tree with value %d: ", item);
    if (first->right == NULL && first->left == NULL && first->item == item) {
        printf("SUCCESS");
    } else {
        printf("FAILED");
    }

    free(first);
}

void s21_btree_insert() {
    int item = 2;
    t_btree *first = bstree_create_node(item);

    item = 3;
    printf("Adding node %d: ", item);
    bstree_insert(first, item, cmp);
    if (first->right->item == item) {
        printf("SUCCESS");
    } else {
        printf("FAILED");
    }

    n();

    item = 1;
    printf("Adding node %d: ", item);
    bstree_insert(first, item, cmp);
    if (first->left->item == item) {
        printf("SUCCESS");
    } else {
        printf("FAILED");
    }
}

int main() {
#ifdef Q3
    s21_btree_init();
#elif Q4
    s21_btree_insert();
#elif Q5
    s21_btree_infix();
    s21_btree_prefix();
    s21_btree_postfix();
#endif
    return 0;
}