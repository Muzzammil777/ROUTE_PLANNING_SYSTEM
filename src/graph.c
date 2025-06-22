// graph.c
#include "cities.h"
#include <stdio.h>

extern int graph[MAX_CITIES][MAX_CITIES];

void load_graph() {
    // Initialize all to INF
    for (int i = 0; i < num_cities; i++)
        for (int j = 0; j < num_cities; j++)
            graph[i][j] = (i == j) ? 0 : 1000000;
    // Example connections (distances in minutes)
    graph[0][6] = graph[6][0] = 120; // Chennai <-> Vellore
    graph[0][4] = graph[4][0] = 300; // Chennai <-> Salem
    graph[4][1] = graph[1][4] = 120; // Salem <-> Coimbatore
    graph[1][7] = graph[7][1] = 60;  // Coimbatore <-> Erode
    graph[7][4] = graph[4][7] = 80;  // Erode <-> Salem
    graph[4][3] = graph[3][4] = 90;  // Salem <-> Tiruchirappalli
    graph[3][2] = graph[2][3] = 100; // Tiruchirappalli <-> Madurai
    graph[2][5] = graph[5][2] = 120; // Madurai <-> Tirunelveli
    graph[5][8] = graph[8][5] = 60;  // Tirunelveli <-> Thoothukudi
    graph[2][9] = graph[9][2] = 60;  // Madurai <-> Dindigul
    graph[9][3] = graph[3][9] = 70;  // Dindigul <-> Tiruchirappalli
}
