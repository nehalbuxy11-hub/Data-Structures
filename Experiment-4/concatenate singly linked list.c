#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node* NODE;

// CREATE NODE
NODE createNode(int x) {
    NODE newNode = (NODE)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = x;
    newNode->next = NULL;

    return newNode;
}

// ADD NODE (at end)
NODE addNode(NODE first, int x) {
    NODE newNode = createNode(x);

    if (first == NULL) {
        return newNode;
    }

    NODE temp = first;

    while (temp->next) {   // different style condition
        temp = temp->next;
    }

    temp->next = newNode;

    return first;
}

// CONCATENATE
NODE concatenate(NODE t1, NODE t2) {
    if (t1 == NULL) return t2;
    if (t2 == NULL) return t1;

    NODE temp = t1;

    // go to last node of list1
    while (temp->next) {
        temp = temp->next;
    }

    temp->next = t2;

    return t1;
}

// DISPLAY
void displayList(NODE first) {
    if (first == NULL) {
        printf("NULL\n");
        return;
    }

    NODE temp = first;

    while (temp) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}
