#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* adj[MAX];
int visited[MAX];

// create new node
Node* create(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// add edge (undirected)
void addEdge(int u, int v) {
    Node* n1 = create(v);
    n1->next = adj[u];
    adj[u] = n1;

    Node* n2 = create(u);
    n2->next = adj[v];
    adj[v] = n2;
}

// simple DFS
void dfs(int start) {
    visited[start] = 1;
    printf("%d ", start);

    Node* p = adj[start];
    while (p != NULL) {
        if (visited[p->data] == 0) {
            dfs(p->data);
        }
        p = p->next;
    }
}

int main() {
    int V, E, u, v, start;

    scanf("%d %d", &V, &E);

    // initialize
    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    // input edges
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    scanf("%d", &start);

    dfs(start);

    return 0;
}
