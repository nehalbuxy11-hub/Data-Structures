#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next, *prev;
};

struct Node *head = NULL;

// DISPLAY
void display() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    while(temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// INSERT AT END
void insert(int x) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = newNode->prev = NULL;

    if(head == NULL) {
        head = newNode;
    } else {
        struct Node *tail = head;
        while(tail->next)
            tail = tail->next;

        tail->next = newNode;
        newNode->prev = tail;
    }

    printf("Inserted successfully\n");
}

// DELETE BY VALUE
void deleteNode(int x) {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    while(temp && temp->data != x)
        temp = temp->next;

    if(temp == NULL) {
        printf("Number %d not found\n", x);
        return;
    }

    if(temp == head) {
        head = temp->next;
        if(head) head->prev = NULL;
    } else {
        temp->prev->next = temp->next;
        if(temp->next)
            temp->next->prev = temp->prev;
    }

    free(temp);

    printf("List after deletion: ");
    display();
}

// REVERSE
void reverse() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *curr = head, *temp = NULL;

    while(curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if(temp)
        head = temp->prev;

    display();
}

// CONCATENATE
void concatenate() {
    int n;
    scanf("%d", &n);

    if(n == 0) {
        printf("Second list is empty\n");
        return;
    }

    struct Node *second = NULL, *tail2 = NULL;

    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = newNode->prev = NULL;

        if(second == NULL) {
            second = tail2 = newNode;
        } else {
            tail2->next = newNode;
            newNode->prev = tail2;
            tail2 = newNode;
        }
    }

    if(head == NULL) {
        head = second;
    } else {
        struct Node *tail = head;
        while(tail->next)
            tail = tail->next;

        tail->next = second;
        second->prev = tail;
    }

    display();
}

// MAIN
int main() {
    int ch, x;

    while(1) {
        printf("Enter operation\n1: Insert\n2: Delete\n3: Display\n4: Reverse\n5: Concatenate\n6: Exit\n");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                scanf("%d", &x);
                insert(x);
                break;

            case 2:
                scanf("%d", &x);
                deleteNode(x);
                break;

            case 3:
                display();
                break;

            case 4:
                reverse();
                break;

            case 5:
                concatenate();
                break;

            case 6:
                printf("Exit\n");
                exit(0);
        }
    }
}
