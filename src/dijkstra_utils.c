#include <stdio.h>
#include <limits.h>
#include <string.h> // Added for strcmp
#include "cities.h"

extern int graph[MAX_CITIES][MAX_CITIES];

int get_city_index(const char *name) {
    for (int i = 0; i < num_cities; i++) {
        if (strcmp(cities[i].name, name) == 0)
            return i;
    }
    return -1;
}

void print_path(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%s", cities[j].name);
        return;
    }
    print_path(parent, parent[j]);
    printf(" -> %s", cities[j].name);
}

void dijkstra(int src, int dest) {
    int dist[MAX_CITIES];
    int visited[MAX_CITIES] = {0};
    int parent[MAX_CITIES];
    for (int i = 0; i < num_cities; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    dist[src] = 0;
    for (int count = 0; count < num_cities - 1; count++) {
        int min = INT_MAX, u = -1;
        for (int v = 0; v < num_cities; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                u = v;
            }
        }
        if (u == -1) break;
        visited[u] = 1;
        for (int v = 0; v < num_cities; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    printf("\nFastest route: ");
    print_path(parent, dest);
    printf("\nTime to reach: %d minutes\n", dist[dest]);
    // For visualization, output the path to a file
    FILE *f = fopen("route_path.txt", "w");
    int path[MAX_CITIES], idx = 0, temp = dest;
    while (temp != -1) {
        path[idx++] = temp;
        temp = parent[temp];
    }
    for (int i = idx - 1; i >= 0; i--) {
        fprintf(f, "%d ", path[i]);
    }
    fclose(f);
    printf("Route path saved to route_path.txt for visualization.\n");
}
