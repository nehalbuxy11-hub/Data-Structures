#include <stdio.h>
#include <stdlib.h>

// Structure for a BST Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return newNode(data);
    
    // As per the note in the problem: elements >= root go to the right
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
        
    return root;
}

// Function to find and print nodes within the range [low, high]
void printRange(struct Node* root, int low, int high) {
    if (root == NULL) return;

    // Standard Inorder Traversal (Left, Root, Right) to keep output sorted
    
    // 1. Check left subtree if there's a chance it contains values >= low
    if (low < root->data)
        printRange(root->left, low, high);

    // 2. Check the current node
    if (low <= root->data && high >= root->data)
        printf("%d ", root->data);

    // 3. Check right subtree if there's a chance it contains values <= high
    if (high > root->data)
        printRange(root->right, low, high);
}

int main() {
    struct Node* root = NULL;
    int n, value, low, high;
printf(" Nehal Buxy, 25070521185, D1 "); 
    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    printf("Enter %d values: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Enter the range [low, high]: ");
    scanf("%d %d", &low, &high);

    printf("Output: ");
    printRange(root, low, high);
    printf("\n");

    return 0;
}
