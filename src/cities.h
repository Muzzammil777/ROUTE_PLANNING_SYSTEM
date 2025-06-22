// cities.h
// List of cities in Tamil Nadu with coordinates (for visualization)
#ifndef CITIES_H
#define CITIES_H

#define MAX_CITIES 20

typedef struct {
    char name[32];
    int x, y; // coordinates for visualization
} City;

extern City cities[MAX_CITIES];
extern int num_cities;
void load_cities();

#endif
