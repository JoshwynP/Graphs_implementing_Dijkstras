# Graphs Implementing Dijkstra's Algorithm

This repository contains a C++ project aimed at creating and managing a map of cities and determining the shortest path between them using Dijkstra's algorithm. The project is structured around a Graph class, implementing essential functionalities to manipulate and analyze graph data efficiently. For more details [click here to preview the design document.](https://drive.google.com/file/d/1yTUexbmdHcnrB8---NdD4tw23ADMoBDU/view?usp=sharing)

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

## Example Terminal Input

```cpp

```

## Example Terminal Output

```cpp
