#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
} node;

node* add(node **head, int data) {
    node *new = malloc(sizeof(node));
    if(!new) {
        return NULL;
    }

    new->data = data;

    if(*head) {
        new->prev = (*head)->prev;
        new->next = *head;
        (*head)->prev->next = new;
        (*head)->prev = new;
    } else {
        new->next = new;
        new->prev = new;
        *head = new;
    }

    return new;
}

void drop(node **head) {
    node *aux;
    if(!*head) {
        return;
    }

    (*head)->prev->next = NULL;
    while(*head) {
        aux = *head;
        *head = (*head)->next;
        free(aux);
    }
}

int main() {
    node *list = NULL;
    add(&list, 0);
    add(&list, 1);
    add(&list, 2);

    printf("%d ", list->data);
    printf("%d ", list->next->data);
    printf("%d ", list->prev->data);
    
    drop(&list);
}
