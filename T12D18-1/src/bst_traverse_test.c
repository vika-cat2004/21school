#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void smth(int value) { printf("%d ", value); }

int cmp(int a, int b) { return a - b; }

void n() { printf("\n"); }

void s21_btree_infix() {
    t_btree *root = bstree_create_node(50);
    bstree_insert(root, 25, cmp);
    bstree_insert(root, 75, cmp);
    bstree_insert(root, 29, cmp);
    bstree_insert(root, 78, cmp);
    bstree_insert(root, 66, cmp);
    bstree_insert(root, 100, cmp);
    printf("Infix:\n");
    bstree_apply_infix(root, smth);
    free(root);
}

void s21_btree_prefix() {
    t_btree *root = bstree_create_node(50);
    bstree_insert(root, 25, cmp);
    bstree_insert(root, 75, cmp);
    bstree_insert(root, 29, cmp);
    bstree_insert(root, 78, cmp);
    bstree_insert(root, 66, cmp);
    bstree_insert(root, 100, cmp);
    printf("Prefix:\n");
    bstree_apply_prefix(root, smth);
    free(root);
}

void s21_btree_postfix() {
    t_btree *root = bstree_create_node(50);
    bstree_insert(root, 25, cmp);
    bstree_insert(root, 75, cmp);
    bstree_insert(root, 29, cmp);
    bstree_insert(root, 78, cmp);
    bstree_insert(root, 66, cmp);
    bstree_insert(root, 100, cmp);
    printf("Postfix:\n");
    bstree_apply_postfix(root, smth);
    free(root);
}

int main() {
    s21_btree_infix();
    n();
    s21_btree_prefix();
    n();
    s21_btree_postfix();
}