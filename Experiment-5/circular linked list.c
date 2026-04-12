#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node* NODE;

// CREATE NODE
NODE createNode(int x) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

// CREATE CLL
NODE createCLL(int n) {
    NODE first = NULL, last = NULL;
    int x;

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        NODE temp = createNode(x);

        if(first == NULL) {
            first = last = temp;
            last->next = first;
        } else {
            last->next = temp;
            last = temp;
            last->next = first;
        }
    }
    return first;
}

// DISPLAY
void displayCLL(NODE first) {
    if(first == NULL) {
        printf("CLL is empty\n");
        return;
    }

    NODE temp = first;
    printf("Elements in CLL are: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != first);

    printf("\n");
}

// INSERT
NODE insertCLL(NODE first, int pos, int x) {
    if(pos < 1) {
        printf("Position not found\n");
        return first;
    }

    NODE temp = createNode(x);

    // insert at beginning
    if(pos == 1) {
        if(first == NULL) {
            temp->next = temp;
            return temp;
        }

        NODE last = first;
        while(last->next != first)
            last = last->next;

        temp->next = first;
        last->next = temp;
        return temp;
    }

    NODE cur = first;
    for(int i = 1; i < pos - 1 && cur->next != first; i++)
        cur = cur->next;

    if(cur->next == first && pos > 2) {
        printf("Position not found\n");
        return first;
    }

    temp->next = cur->next;
    cur->next = temp;

    return first;
}

// DELETE
NODE deleteCLL(NODE first, int pos) {
    if(first == NULL) {
        printf("CLL is empty\n");
        return first;
    }

    if(pos < 1) {
        printf("Position not found\n");
        return first;
    }

    NODE temp, cur;

    // delete first node
    if(pos == 1) {
        if(first->next == first) {
            printf("Deleted element: %d\n", first->data);
            free(first);
            return NULL;
        }

        NODE last = first;
        while(last->next != first)
            last = last->next;

        temp = first;
        printf("Deleted element: %d\n", temp->data);

        first = first->next;
        last->next = first;

        free(temp);
        return first;
    }

    cur = first;
    for(int i = 1; i < pos - 1 && cur->next != first; i++)
        cur = cur->next;

    if(cur->next == first) {
        printf("Position not found\n");
        return first;
    }

    temp = cur->next;
    printf("Deleted element: %d\n", temp->data);

    cur->next = temp->next;
    free(temp);

    return first;
}

// REVERSE
NODE reverseCLL(NODE first) {
    if(first == NULL) return first;

    NODE prev = NULL, curr = first, next;
    NODE last = first;

    while(last->next != first)
        last = last->next;

    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while(curr != first);

    first->next = prev;
    return prev;
}

// CONCAT
NODE concatCLL(NODE first, NODE second) {
    if(first == NULL) return second;
    if(second == NULL) return first;

    NODE last1 = first;
    while(last1->next != first)
        last1 = last1->next;

    NODE last2 = second;
    while(last2->next != second)
        last2 = last2->next;

    last1->next = second;
    last2->next = first;

    return first;
}

// MAIN
int main() {
    NODE first = NULL, second = NULL;
    int choice, n, x, pos;

    while(1) {
        printf("1.Create 2.Insert 3.Delete 4.Display 5.Reverse 6.Concat 7.Exit\n");
        printf("choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("How many nodes? ");
                scanf("%d", &n);
                first = createCLL(n);
                break;

            case 2:
                printf("Position: ");
                scanf("%d", &pos);
                printf("Element: ");
                scanf("%d", &x);
                first = insertCLL(first, pos, x);
                break;

            case 3:
                printf("Position: ");
                scanf("%d", &pos);
                first = deleteCLL(first, pos);
                break;

            case 4:
                displayCLL(first);
                break;

            case 5:
                if(first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    first = reverseCLL(first);
                    printf("CLL reversed\n");
                    displayCLL(first);
                }
                break;

            case 6:
                printf("Creating second CLL to concatenate...\n");
                printf("How many nodes in second CLL? ");
                scanf("%d", &n);
                second = createCLL(n);
                first = concatCLL(first, second);
                printf("Concatenated CLL:\n");
                displayCLL(first);
                break;

            case 7:
                exit(0);
        }
    }
}
