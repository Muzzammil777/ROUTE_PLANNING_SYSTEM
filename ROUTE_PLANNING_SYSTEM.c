#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define MAX_NODES 6
// Structure to represent a graph edge
typedef struct Edge {
int destination;
long long int weight;
struct Edge* next;
} Edge;
// Structure to represent a graph node
typedef struct Node {
char name[100];
Edge* head; // Head of the edge list
} Node;
// Structure to represent a graph
typedef struct Graph {
int numNodes;
Node* array;
} Graph;
// Function to create a new edge
Edge* createEdge(int destination, long long int weight) {
Edge* newEdge = (Edge*)malloc(sizeof(Edge));
newEdge->destination = destination;
newEdge->weight = weight;
newEdge->next = NULL;
return newEdge;
}
// Function to create a graph with given number of nodes
Graph* createGraph(int numNodes) {
Graph* graph = (Graph*)malloc(sizeof(Graph));
graph->numNodes = numNodes;
graph->array = (Node*)malloc(numNodes * sizeof(Node));
int i;
for (i = 0; i < numNodes; i++) {
graph->array[i].head = NULL;
}
return graph;
}
// Function to add an edge to the graph
void addEdge(Graph* graph, int source, int destination, long long int weight) {
Edge* newEdge = createEdge(destination, weight);
newEdge->next = graph->array[source].head;
graph->array[source].head = newEdge;
// Add the reverse edge for an undirected graph
newEdge = createEdge(source, weight);
newEdge->next = graph->array[destination].head;
graph->array[destination].head = newEdge;
}
// Function to find the vertex with minimum distance value
int minDistance(long long int dist[], int sptSet[], int numNodes) {
long long int min = LLONG_MAX;
int minIndex = -1;
int v;
for (v = 0; v < numNodes; v++) {
if (sptSet[v] == 0 && dist[v] <= min) {
min = dist[v];
minIndex = v;
}
}
return minIndex;
}
// Function to implement Dijkstra's algorithm
void dijkstra(Graph* graph, int src, int dest) {
int numNodes = graph->numNodes;
long long int dist[numNodes]; // dist[i] will hold the shortest distance from src to i
int sptSet[numNodes]; // sptSet[i] will be 1 if vertex i is included in shortest path tree
int parent[numNodes]; // Parent array to store the shortest path tree
// Initialize all distances as INFINITE and sptSet[] as 0
int i;
for (i = 0; i < numNodes; i++) {
dist[i] = LLONG_MAX;
sptSet[i] = 0;
parent[i] = -1;
}
// Distance of source vertex from itself is always 0
dist[src] = 0;
// Find shortest path for all vertices
int count;
for (count = 0; count < numNodes - 1; count++) {
int u = minDistance(dist, sptSet, numNodes);
if (u == -1) break; // No more reachable vertices
sptSet[u] = 1;
// Update dist value of the adjacent vertices of the picked vertex
Edge* edge = graph->array[u].head;
while (edge != NULL) {
int v = edge->destination;
if (!sptSet[v] && dist[u] != LLONG_MAX && dist[u] + edge->weight <
dist[v]) {
dist[v] = dist[u] + edge->weight;
parent[v] = u;
}
edge = edge->next;
}
}
// Print the shortest path from src to dest
if (dist[dest] == LLONG_MAX) {
printf("No path exists from %s to %s\n", graph->array[src].name,
graph->array[dest].name);
} else {
printf("\n\nShortest path from %s to %s: ", graph->array[src].name,
graph->array[dest].name);
int current = dest;
printf("%s", graph->array[current].name);
while (parent[current] != -1) {
printf(" <- %s", graph->array[parent[current]].name);
current = parent[current];
}
printf("\nShortest distance: %lld km\n", dist[dest]);
}
}
int main() {
int numNodes = 6; // Number of cities in Tamil Nadu including Karur
Graph* graph = createGraph(numNodes);
printf("****-----ROUTE PLANNING SYSTEM-----****\n\n");
// Adding edges between cities in Tamil Nadu
addEdge(graph, 0, 1, 507); // Chennai to Coimbatore
addEdge(graph, 0, 2, 456); // Chennai to Madurai
addEdge(graph, 0, 3, 332); // Chennai to Trichy
addEdge(graph, 0, 4, 623); // Chennai to Tirunelveli
addEdge(graph, 0, 5, 384); // Chennai to Karur
addEdge(graph, 1, 2, 207); // Coimbatore to Madurai
addEdge(graph, 1, 3, 217); // Coimbatore to Trichy
addEdge(graph, 1, 4, 353); // Coimbatore to Tirunelveli
addEdge(graph, 1, 5, 131); // Coimbatore to Karur
addEdge(graph, 2, 3, 125); // Madurai to Trichy
addEdge(graph, 2, 4, 161); // Madurai to Tirunelveli
addEdge(graph, 2, 5, 143); // Madurai to Karur
addEdge(graph, 3, 4, 298); // Trichy to Tirunelveli
addEdge(graph, 3, 5, 83); // Trichy to Karur
addEdge(graph, 4, 5, 288); // Tirunelveli to Karur
// Setting city names
strcpy(graph->array[0].name, "Chennai");
strcpy(graph->array[1].name, "Coimbatore");
strcpy(graph->array[2].name, "Madurai");
strcpy(graph->array[3].name, "Trichy");
strcpy(graph->array[4].name, "Tirunelveli");
strcpy(graph->array[5].name, "Karur");
int src, dest;
printf("Enter your source city number:\n");
int i;
for (i = 0; i < numNodes; i++) {
printf("%d. %s\n", i + 1, graph->array[i].name);
}
printf("\nSource city---> ");
scanf("%d", &src);
src--; // Adjusting for 0-based index
printf("List of available cities to travel:\n");
for (i = 0; i < numNodes; i++) {
if (i != src) {
printf("%d. %s\n", i + 1, graph->array[i].name);
}
}
printf("Enter your destination city number: ");
scanf("%d", &dest);
dest--; // Adjusting for 0-based index
dijkstra(graph, src, dest);
// Free memory
for (i = 0; i < numNodes; i++) {
Edge* edge = graph->array[i].head;
while (edge != NULL) {
Edge* temp = edge;
edge = edge->next;
free(temp);
}
}
free(graph->array);
free(graph);
return 0;}