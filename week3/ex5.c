#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node * next;
    struct Node * prev;
};

struct Linked_list{
    struct Node * head;
    struct Node * tail;
};

struct Node * init_node(int value, struct Node * prev) {
    struct Node * node = malloc(sizeof(struct Node));
    node->value = value;
    node->next = NULL;
    node->prev = prev;
}

struct Linked_list * init_list() {
    struct Linked_list * list = malloc(sizeof(struct Linked_list));
    list->head = NULL;
}

void print_list(struct Linked_list * list){
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node * node = list->head;
    while (node->next != NULL) {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
}

void insert_node(struct Linked_list * list, int value) {
    if (list->head == NULL) {
        list->head = init_node(value, NULL);
        list->tail = list->head;
        return;
    }
    list->tail->next = init_node(value, list->tail);
    list->tail = list->tail->next;
}

struct Node * delete_node(struct Linked_list * list) {
    if (list->head == NULL) {
        printf("Cannot delete from empty list!\n");
        return NULL;
    }
    if (list->head == list->tail){
        struct Node * node = list->head;
        list->tail = NULL;
        list->head = NULL;
        return node;
    }
    struct Node * node = list->tail;
    list->tail = list->tail->prev;
    list->tail->next = NULL;
    return node;
}

int main() {
    struct Linked_list * list = init_list();
    print_list(list);
    insert_node(list, 1);
    print_list(list);
    insert_node(list, 2);
    print_list(list);
    insert_node(list, 3);
    print_list(list);
    insert_node(list, 4);
    print_list(list);
    insert_node(list, 5);
    print_list(list);
    delete_node(list);
    print_list(list);
    delete_node(list);
    print_list(list);
    delete_node(list);
    print_list(list);
    delete_node(list);
    print_list(list);
    delete_node(list);
    print_list(list);
    return 0;
}
