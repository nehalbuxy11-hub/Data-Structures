#include <stdio.h>
#include <stdlib.h> 

typedef struct node {
    int vertex;
    struct node* next;
} *GNODE;

GNODE graph[100];

// delete vertex
void deleteVertex(int *N) {
    int v;
    printf("Enter vertex to delete : ");
    scanf("%d", &v);

    if (v < 1 || v > *N) {
        printf("Invalid vertex.\n");
        return;
    }

    // free list of that vertex
    GNODE temp = graph[v];
    while (temp != NULL) {
        GNODE t = temp;
        temp = temp->next;
        free(t);
    }

    // shift list up
    for (int i = v; i < *N; i++) {
        graph[i] = graph[i + 1];
    }

    // update vertex numbers
    for (int i = 1; i <= *N; i++) {
        GNODE p = graph[i];
        while (p != NULL) {
            if (p->vertex > v) {
                p->vertex = p->vertex - 1;
            }
            p = p->next;
        }
    }

    (*N)--;

    printf("After deleting vertex the adjacency list is : \n");
    print(N);
}

// delete edge
void deleteEdge(int *N) {
    int src, dest;

    printf("Enter the source vertex of the edge : ");
    scanf("%d", &src);

    printf("Enter the destination vertex of the edge : ");
    scanf("%d", &dest);

    if (src < 1 || src > *N || dest < 1 || dest > *N) {
        printf("Invalid vertex.\n");
        return;
    }

    GNODE p = graph[src];
    GNODE prev = NULL;

    while (p != NULL) {
        if (p->vertex == dest) {
            if (prev == NULL) {
                graph[src] = p->next;
            } else {
                prev->next = p->next;
            }
            free(p);
            break; // simple student logic
        }
        prev = p;
        p = p->next;
    }

    printf("After deleting edge the adjacency list is : \n");
    print(N);
}
