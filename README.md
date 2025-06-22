# Route Planning System for Tamil Nadu (C, Dijkstra's Algorithm)

## Features

- Find the fastest route between cities in Tamil Nadu using Dijkstra's algorithm
- Visualize the route on a map (SVG)

## How to Run

1. **Build the C programs**

```bash
cd src
gcc dijkstra.c dijkstra_utils.c cities.c graph.c -o route_planner
```

2. **Run the route planner**

```bash
./route_planner
```

Enter source and destination city names (e.g., Chennai, Madurai).

3. **Visualize the route**

```bash
gcc visualize_route.c cities.c -o visualize_route
./visualize_route
```

This generates `tamilnadu_route.svg` in the `src` folder. Open it in a browser or VS Code image viewer.

## Requirements

- GCC (C compiler)
- VS Code (with C/C++ extension for best experience)

## Cities Supported

- Chennai
- Coimbatore
- Madurai
- Tiruchirappalli
- Salem
- Tirunelveli
- Vellore
- Erode
- Thoothukudi
- Dindigul

You can add more cities and connections in `cities.c` and `graph.c`.
