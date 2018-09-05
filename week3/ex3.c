#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node * next;
};

struct Linked_list{
    struct Node * head;
};

struct Node * init_node(int value) {
    struct Node * node = malloc(sizeof(struct Node));
    node->value = value;
    node->next = NULL;
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
        list->head = init_node(value);
        return;
    }
    struct Node * node = list->head;
    while (node->next != NULL) {
        node = node->next;
    }
    node->next = init_node(value);
}

struct Node * delete_node(struct Linked_list * list) {
    if (list->head == NULL) {
        printf("Cannot delete from empty list!\n");
        return NULL;
    }
    struct Node * node = list->head->next;
    struct Node * prev = NULL;
    while (node->next != NULL) {
        prev = node;
        node = node->next;
    }
    if (prev == NULL) {
        list->head = NULL;
        return node;
    } else {
        prev->next = NULL;
        return node;
    }
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
    return 0;
}
