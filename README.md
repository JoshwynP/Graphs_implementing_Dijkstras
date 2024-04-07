# Graphs Implementing Dijkstra's Algorithm

This repository hosts a comprehensive C++ project aimed at mapping city-to-city connections and determining the shortest path between them leveraging Dijkstra's algorithm. Beyond its core functionality, the project stands out for its intricate use of various fundamental data structures, including graphs, minimum priority queues, linked lists, and nodes, to efficiently manage and navigate complex datasets.

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

```bash
g++ main.cpp Graph.cpp illegal_exception.cpp -o main
./main
