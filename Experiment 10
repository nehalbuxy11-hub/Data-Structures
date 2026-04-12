#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 100

// find minimum key vertex
int minVertex(int key[], bool visited[], int n) {
    int min = INT_MAX, index = -1;

    for (int i = 0; i < n; i++) {
        if (visited[i] == false && key[i] < min) {
            min = key[i];
            index = i;
        }
    }
    return index;
}

// prim's algorithm
void prim(int graph[V][V], int n) {
    int parent[V], key[V];
    bool visited[V];

    // initialize
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        visited[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < n - 1; i++) {
        int u = minVertex(key, visited, n);
        visited[u] = true;

        for (int j = 0; j < n; j++) {
            if (graph[u][j] != 0 && visited[j] == false && graph[u][j] < key[j]) {
                key[j] = graph[u][j];
                parent[j] = u;
            }
        }
    }

    // print MST
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    int n;
    int graph[V][V];

    printf("No of vertices: ");
    scanf("%d", &n);

    printf("Adjacency matrix elements (row wise):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    prim(graph, n);

    return 0;
}
