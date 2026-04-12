#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice, value;
    Node *root = NULL;

    while (1) {
        printf("1. Insert Node\n");
        printf("2. In-Order Traversal\n");
        printf("3. Pre-Order Traversal\n");
        printf("4. Post-Order Traversal\n");
        printf("5. Delete Node\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Data: ");
            scanf("%d", &value);
            root = insertNode(root, value);
        }
        else if (choice == 2) {
            inorderTraversal(root);
            printf("\n");
        }
        else if (choice == 3) {
            preorderTraversal(root);
            printf("\n");
        }
        else if (choice == 4) {
            postorderTraversal(root);
            printf("\n");
        }
        else if (choice == 5) {
            printf("Delete: ");
            scanf("%d", &value);

            int flag = 0;
            root = deleteNode(root, value, &flag);

            if (flag == 0) {
                printf("Value not found\n");
            }
        } 
        else if (choice == 6) {
            freeTree(root);
            break;   // instead of exit()
        }
        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
