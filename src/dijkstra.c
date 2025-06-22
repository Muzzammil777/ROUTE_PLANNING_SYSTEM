// dijkstra.c
// Route planning system for Tamil Nadu using Dijkstra's algorithm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CITIES 20
#define INF 1000000

// Structure to hold city information
typedef struct {
    char name[32];
    int x, y; // coordinates for visualization
} City;

// Graph as adjacency matrix
int graph[MAX_CITIES][MAX_CITIES];
extern City cities[MAX_CITIES];
extern int num_cities;

// Function prototypes
int get_city_index(const char *name);
void dijkstra(int src, int dest);
void load_cities();
void load_graph();
int to_lower_str(char *dst, const char *src);
int get_city_index_case_insensitive(const char *name);
void print_city_list();

int main() {
    char src_name[32], dest_name[32];
    load_cities();
    load_graph();
    print_city_list();
    int src = -1, dest = -1;
    while (src == -1) {
        printf("Enter source city: ");
        scanf("%s", src_name);
        src = get_city_index_case_insensitive(src_name);
        if (src == -1) printf("Invalid city name. Try again.\n");
    }
    while (dest == -1) {
        printf("Enter destination city: ");
        scanf("%s", dest_name);
        dest = get_city_index_case_insensitive(dest_name);
        if (dest == -1) printf("Invalid city name. Try again.\n");
    }
    dijkstra(src, dest);
    return 0;
}

int to_lower_str(char *dst, const char *src) {
    int i = 0;
    while (src[i]) {
        dst[i] = (src[i] >= 'A' && src[i] <= 'Z') ? src[i] + 32 : src[i];
        i++;
    }
    dst[i] = '\0';
    return i;
}

int get_city_index_case_insensitive(const char *name) {
    char input_lower[32], city_lower[32];
    to_lower_str(input_lower, name);
    for (int i = 0; i < num_cities; i++) {
        to_lower_str(city_lower, cities[i].name);
        if (strcmp(city_lower, input_lower) == 0)
            return i;
    }
    return -1;
}

void print_city_list() {
    printf("Available cities:\n");
    for (int i = 0; i < num_cities; i++) {
        printf("- %s\n", cities[i].name);
    }
}
