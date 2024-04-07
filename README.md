# Graphs Implementing Dijkstra's Algorithm

This repository contains a C++ project for creating a map from city to city and finding the shortest path between them using Dijkstra's algorithm. The main file, `main.cpp`, implements various functions to load data, insert vertices, print graphs, delete vertices, find paths, adjust traffic, update traffic data, and find the lowest cost path.

## Functionality Overview

### parse_file()

This function serves as the entry point of the program. It reads commands from the standard input and executes corresponding actions.

### Command Handling

1. **LOAD**: Loads data from a specified file into the graph.
2. **INSERT**: Inserts a new edge between two vertices with specified distance and speed limit.
3. **PRINT**: Prints information about a specific vertex in the graph.
4. **DELETE**: Deletes a vertex from the graph.
5. **PATH**: Finds the shortest path between two vertices.
6. **TRAFFIC**: Adjusts the traffic factor between two vertices.
7. **UPDATE**: Updates traffic data from a specified file.
8. **LOWEST**: Finds the lowest cost path between two vertices.
9. **END**: Terminates the program.

## Function Details

### parse_file()

- Purpose: Reads commands from standard input and executes corresponding actions.
- Parameters: None.
- Return Type: Void.

### main()

- Purpose: Entry point of the program, calls `parse_file()` to start processing commands.
- Parameters: None.
- Return Type: Integer.

### Command Handling Functions (LOAD, INSERT, PRINT, DELETE, PATH, TRAFFIC, UPDATE, LOWEST)

- Purpose: Execute respective commands with error handling.
- Parameters: Vary depending on the command.
- Return Type: Void.

## Running the Program

To run the program, compile `main.cpp` along with `Graph.cpp` and `illegal_exception.cpp` using your preferred compiler. Then execute the compiled binary. Ensure input files for commands like LOAD and UPDATE are present in the same directory or provide proper file paths.

Example:
```bash
g++ main.cpp Graph.cpp illegal_exception.cpp -o main
./main
