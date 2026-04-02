#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 6

// Function to find minimum distance vertex
int min_dist(int dist[], bool visited[]) {
    int minimum = INT_MAX;
    int index = -1;
    int i;

    for (i = 0; i < V; i++) {
        if (!visited[i] && dist[i] <= minimum) {
            minimum = dist[i];
            index = i;
        }
    }
    return index;
}

// Dijkstra Algorithm
void greedy_dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool visited[V];
    int i, count;

    // Initialize
    for (i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    // Main loop
    for (count = 0; count < V - 1; count++) {
        int m = min_dist(dist, visited);
        visited[m] = true;

        for (i = 0; i < V; i++) {
            if (!visited[i] && graph[m][i] &&
                dist[m] != INT_MAX &&
                dist[m] + graph[m][i] < dist[i]) {
                dist[i] = dist[m] + graph[m][i];
            }
        }
    }

    // Output
    printf("Vertex\tDistance from Source\n");
    for (i = 0; i < V; i++) {
        printf("%c\t%d\n", 'A' + i, dist[i]);
    }
}

int main() {
    int graph[V][V] = {
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}
    };

    greedy_dijkstra(graph, 0);  // ? correct

    return 0;
}
