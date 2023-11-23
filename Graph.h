#include <iostream>
#include "MinPQ.h"
using namespace std;

class Graph
{

private:
    // private member variables //
    LinkedList* adjacency_list;
    //int* node_list;
    double infinity;
    int num_vertices_graph;

    int vertex_a;
    int vertex_b;
    double distance;
    double speed_limit;
    double adjustment_factor;
    double current_time;
    int vertex_a_hold;
    int vertex_b_hold;

public:
    // publice member functions //
    Graph();
    ~Graph();

    bool insert(int vertex_a, int vertex_b, double distance, double speed_limit, double adjustment_factor);
    bool print(int vertex_a);
    bool delete_a_vertex(int vertex_a);
    bool traffic(int vertex_a, int vertex_b, double adjustment_factor);

    LinkedList* Relax(int u, int v);
    bool Dijkstras(int s, int find_b);
    
    
    double find_time(double distance, double speed_limit, double adjustment_factor);


/// an array of linked lists. and the link lists store nodes which store all of the data.

    // publice member variables //

};