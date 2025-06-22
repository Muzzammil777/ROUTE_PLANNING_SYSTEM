// cities.c
#include "cities.h"
#include <string.h>

City cities[MAX_CITIES];
int num_cities = 10;

void load_cities() {
    // Example cities with made-up coordinates (x, y for visualization)
    strcpy(cities[0].name, "Chennai");    cities[0].x = 600; cities[0].y = 100;
    strcpy(cities[1].name, "Coimbatore"); cities[1].x = 100; cities[1].y = 400;
    strcpy(cities[2].name, "Madurai");    cities[2].x = 300; cities[2].y = 600;
    strcpy(cities[3].name, "Tiruchirappalli"); cities[3].x = 350; cities[3].y = 450;
    strcpy(cities[4].name, "Salem");       cities[4].x = 200; cities[4].y = 300;
    strcpy(cities[5].name, "Tirunelveli"); cities[5].x = 250; cities[5].y = 700;
    strcpy(cities[6].name, "Vellore");     cities[6].x = 400; cities[6].y = 200;
    strcpy(cities[7].name, "Erode");       cities[7].x = 150; cities[7].y = 350;
    strcpy(cities[8].name, "Thoothukudi"); cities[8].x = 350; cities[8].y = 750;
    strcpy(cities[9].name, "Dindigul");    cities[9].x = 320; cities[9].y = 500;
}
