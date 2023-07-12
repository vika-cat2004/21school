#include "list.h"

#include <stdio.h>
#include <stdlib.h>

struct node* init(struct door* door) {
    struct node* root = (struct node*)malloc(sizeof(struct node));  // выделение памяти под корень списка
    root->door = door;
    root->next = NULL;  // это последний узел списка
    return (root);
};

struct node* add_door(struct node* elem, struct door* door) {
    struct node* last = init(door);  // сохранение указателя на следующий узел
    last->next = elem->next;  // сохранение поля данных добавляемого узла
    elem->next = last;  // созданный узел указывает на следующий элемент
    return last;
}

struct node* find_door(int door_id, struct node* root) {
    struct node* current = root;
    while (current != NULL && current->door->id != door_id) {
        current = current->next;
    }
    return current;
}

struct node* remove_door(struct node* elem, struct node* root) {
    struct node* temp = root;
    while (temp->next != elem) {  // просматриваем список начиная с корня
        temp = temp->next;
    }                         // пока не найдем узел, предшествующий
    temp->next = elem->next;  // переставляем указатель
    free(elem);               // освобождаем память удаляемого узла
    return (temp);
}

void destroy(struct node* root) {
    struct node* temp = NULL;
    while (root->next != NULL) {
        temp = root;
        root = root->next;
        free(temp);
    }
    free(root);
}
