#include "bst.h"

#include <stdlib.h>

t_btree *bstree_create_node(int item) {
    t_btree *node = malloc(sizeof(t_btree));
    node->item = item;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int)) {
    const int sub = cmpf(root->item, item);
    if (sub <= 0 && root->right == NULL) {
        root->right = bstree_create_node(item);
    } else if (root->right != NULL) {
        t_btree *next = root->right;
        while (next->right != NULL) {
            next = next->right;
        }
        next->right = bstree_create_node(item);
    }
    if (sub > 0 && root->left == NULL) {
        root->left = bstree_create_node(item);
    } else if (root->left != NULL) {
        t_btree *next = root->left;
        while (next->left != NULL) {
            next = next->left;
        }
        next->left = bstree_create_node(item);
    }
}

void bstree_apply_infix(t_btree *root, void (*func)(int)) {
    if (root == NULL) {
        return;
    }

    bstree_apply_infix(root->left, func);
    func(root->item);
    bstree_apply_infix(root->right, func);
}

void bstree_apply_prefix(t_btree *root, void (*func)(int)) {
    if (root == NULL) {
        return;
    }

    func(root->item);
    bstree_apply_prefix(root->left, func);
    bstree_apply_prefix(root->right, func);
}

void bstree_apply_postfix(t_btree *root, void (*func)(int)) {
    if (root == NULL) {
        return;
    }

    bstree_apply_postfix(root->left, func);
    bstree_apply_postfix(root->right, func);
    func(root->item);
}
