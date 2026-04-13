#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue implementation
int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

// Topological Sort function
void topologicalSort(int adj[MAX][MAX], int n) {
    int indegree[MAX] = {0};
    int i, j;

    // Step 1: Calculate indegree of each vertex
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (adj[i][j] == 1)
                indegree[j]++;
        }
    }

    // Step 2: Enqueue vertices with indegree 0
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    int count = 0;
    printf("Topological Order: ");

    // Step 3: Process queue
    while (front <= rear) {
        int v = dequeue();
        printf("%d ", v);

        // Reduce indegree of adjacent vertices
        for (j = 0; j < n; j++) {
            if (adj[v][j] == 1) {
                indegree[j]--;
                if (indegree[j] == 0)
                    enqueue(j);
            }
        }

        count++;
    }

    // Step 4: Check for cycle
    if (count != n) {
        printf("\nGraph contains a cycle. Topological sort not possible.\n");
    }
}

// Main function
int main() {
    int n, i, j;
    int adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    topologicalSort(adj, n);

    return 0;
}