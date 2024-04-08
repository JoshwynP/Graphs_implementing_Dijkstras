# Graphs Implementing Dijkstra's Algorithm

This repository hosts a comprehensive C++ project aimed at mapping city-to-city connections and determining the shortest path between them leveraging Dijkstra's algorithm. Beyond its core functionality, the project stands out for its intricate use of various fundamental data structures, including graphs, minimum priority queues, linked lists, and nodes, to efficiently manage and navigate complex datasets.
For more details, [click here to preview the design document.](https://drive.google.com/file/d/1yTUexbmdHcnrB8---NdD4tw23ADMoBDU/view?usp=sharing)

## Core Functionalities

### Data Structure Implementation

The project intricately implements several essential data structures to achieve efficient data management and algorithm execution:

- **Graphs**: Serve as the backbone of the project, enabling the representation of cities as vertices and the roads between them as edges, along with associated attributes like distance and speed limits.
- **Minimum Priority Queue**: Utilized within Dijkstra's algorithm to efficiently determine the next closest vertex to visit, ensuring optimal pathfinding with minimal computational overhead.
- **Linked Lists**: Facilitate dynamic data storage, allowing for efficient insertion and deletion of vertices and edges, which is critical for handling the graph's mutable structure.
- **Nodes**: Act as fundamental elements for linked lists and the graph, encapsulating data such as vertex identifiers, distances, and adjacency information.

### Functional Overview

#### `parse_file()`

Serves as the program's control center, interpreting and executing commands input through the standard input stream.

#### Command Operations

1. **LOAD**: Populates the graph with data from a file, building the initial map layout.
2. **INSERT**: Adds new edges to the graph, reflecting new or updated routes between cities.
3. **PRINT**: Displays information about edges connected to a specified vertex, showcasing the graph's current state.
4. **DELETE**: Removes vertices from the graph, along with their associated edges, adjusting the map as needed.
5. **PATH**: Employs Dijkstra's algorithm to find the shortest path between two cities.
6. **TRAFFIC**: Modifies edge weights to simulate traffic conditions, affecting pathfinding outcomes.
7. **UPDATE**: Batch updates traffic data from a file, reflecting widespread changes in traffic conditions.
8. **LOWEST**: Determines the lowest cost path considering both distance and traffic conditions.
9. **END**: Cleans up resources and terminates the program.

### Getting Started

#### Compilation and Execution

Compile `main.cpp` along with the required source files (`Graph.cpp`, `illegal_exception.cpp`) using a C++ compiler:







# Graphs Implementing Dijkstra's Algorithm

This repository contains a C++ project aimed at creating and managing a map of cities and determining the shortest path between them using Dijkstra's algorithm. The project is structured around a Graph class, implementing essential functionalities to manipulate and analyze graph data efficiently. For more details, [click here to preview the design document.](https://drive.google.com/file/d/1yTUexbmdHcnrB8---NdD4tw23ADMoBDU/view?usp=sharing)

## Overview

The Graph class provides functionalities to load city data from files, insert new connections between cities, print information about cities and their connections, delete cities from the map, find the shortest path between cities, simulate traffic conditions, update traffic data, and more.

## Core Functionalities

### Constructor

#### `Graph::Graph()`

- Default constructor for the Graph class.

### File Parsing

#### `void parse_file()`

- Reads commands from the standard input stream and performs corresponding operations on the graph data structure.

### Loading Data

#### `void Graph::load(string filename)`

- Loads city data from a specified file and inserts it into the graph.

### Insertion

#### `bool Graph::insert(int vertex_a, int vertex_b, double distance, double speed_limit)`

- Inserts a new connection between two cities into the graph.

### Printing Information

#### `bool Graph::print(int vertex_a)`

- Prints information about connections originating from a specified city.

### Deletion

#### `bool Graph::delete_a_vertex(int vertex_a)`

- Deletes a city and its associated connections from the graph.

### Shortest Path Calculation

#### `bool Graph::Dijkstras(int vertex_a, int vertex_b, string mode)`

- Finds the shortest path between two cities using Dijkstra's algorithm.

### Traffic Simulation

#### `bool Graph::traffic(int vertex_a, int vertex_b, double adjustment_factor)`

- Simulates traffic conditions between two cities by adjusting edge weights.

### Data Update

#### `void Graph::update(string filename)`

- Updates traffic data from a specified file.

## Getting Started

To use this Graph implementation in your C++ project, follow these steps:

1. Clone the repository to your local machine.
2. Include the necessary header files (`Graph.h`, `illegal_exception.h`) in your project.
3. Compile `main.cpp` along with the required source files using a C++ compiler.
4. Execute the compiled binary to run the program.

## Example Usage

```cpp
// Example usage of Graph implementation
#include <iostream>
#include "Graph.h"

int main() {
    parse_file();
    return 0;
}

