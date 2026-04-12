#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
    int size;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct LinkedList* initializeList() {
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

// INSERT
void insert(struct LinkedList* list, int data, int pos) {
    if (pos < 0 || pos > list->size) {
        printf("Invalid position\n");
        return;
    }

    struct Node* newNode = createNode(data);

    struct Node** ptr = &list->head;

    for (int i = 0; i < pos; i++) {
        ptr = &((*ptr)->next);
    }

    newNode->next = *ptr;
    *ptr = newNode;

    list->size++;
    printf("Element %d inserted at position %d\n", data, pos);
}

// DELETE
void deleteNode(struct LinkedList* list, int pos) {
    if (pos < 0 || pos >= list->size) {
        printf("Invalid position\n");
        return;
    }

    struct Node** ptr = &list->head;

    for (int i = 0; i < pos; i++) {
        ptr = &((*ptr)->next);
    }

    struct Node* temp = *ptr;
    *ptr = temp->next;

    free(temp);
    list->size--;

    printf("Element at position %d deleted\n", pos);
}

// REVERSE
void reverse(struct LinkedList* list) {
    struct Node *prev = NULL, *curr = list->head;

    while (curr) {
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    list->head = prev;
}

// DISPLAY
void display(struct LinkedList* list) {
    struct Node* temp = list->head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayReversed(struct LinkedList* list) {
    display(list);
}

// MAIN
int main() {
    int n, data, pos, choice;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    struct LinkedList* list = initializeList();

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insert(list, data, i);
    }

    while (1) {
        printf("Linked List Operations:\n");
        printf("1. Insert\n2. Delete\n3. Reverse\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                insert(list, data, pos);
                break;

            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteNode(list, pos);
                break;

            case 3:
                reverse(list);
                printf("Reversed List: ");
                displayReversed(list);
                reverse(list); // restore
                break;

            case 4:
                printf("Linked List: ");
                display(list);
                break;

            case 5:
                printf("Exiting program\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
