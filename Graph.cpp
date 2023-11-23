#include <iostream>
#include <limits>
#include "Graph.h"
using namespace std;

Graph::Graph()
{
    adjacency_list = new LinkedList[500000];
    //node_list = new int[500000];
    num_vertices_graph = 0;
    infinity = numeric_limits<double>::infinity();
}

Graph::~Graph()
{
    cout << "destructor ran" << endl;
}

bool Graph::insert(int vertex_a, int vertex_b, double distance, double speed_limit, double adjustment_factor)
{
    current_time = find_time(distance, speed_limit, adjustment_factor);

    vertex_a_hold = -1;
    vertex_b_hold = -1;

    //LinkedList a = adjacency_list[vertex_a-1];
    //LinkedList b = adjacency_list[vertex_b-1];
    
    // check if any of the vertices already in the graph match the given vertices
    cout << "a in the list: " << adjacency_list[vertex_a].current_vertex << " b in the list: " << adjacency_list[vertex_b].current_vertex << endl;
    // check if any of the vertices already in the graph match the given vertices
    if (adjacency_list[vertex_a].current_vertex == vertex_a)
    {
        vertex_a_hold = 1;
    }
    if (adjacency_list[vertex_b].current_vertex == vertex_b)
    {
        vertex_b_hold = 1;
    }
    

    if (vertex_a_hold == -1 && vertex_b_hold == -1) // both vertices are not in the graph
    {
        // new vertex a
        adjacency_list[vertex_a] = LinkedList(vertex_a);
        adjacency_list[vertex_a].insert_edge(vertex_b, current_time, adjustment_factor);
        adjacency_list[vertex_a].num_vertices++;
        num_vertices_graph++;

        // new vertex b
        adjacency_list[vertex_b] = LinkedList(vertex_b);
        adjacency_list[vertex_b].insert_edge(vertex_a, current_time, adjustment_factor);
        adjacency_list[vertex_b].num_vertices++;
        num_vertices_graph++;
    }
    else if (vertex_a_hold != -1 && vertex_b_hold == -1) // vertex b is not in the graph
    {
        // new edge for a
        adjacency_list[vertex_a].insert_edge(vertex_b, current_time, adjustment_factor);
        adjacency_list[vertex_a].num_vertices++;
        
        // new vertex and edge for b
        adjacency_list[vertex_b] = LinkedList(vertex_b);
        adjacency_list[vertex_b].insert_edge(vertex_a, current_time, adjustment_factor);
        adjacency_list[vertex_b].num_vertices++;
        num_vertices_graph++;
    }
    else if (vertex_a_hold == -1 && vertex_b_hold != -1) // vertex a is not in the graph
    {
        // new edge for b
        adjacency_list[vertex_b].insert_edge(vertex_a, current_time, adjustment_factor);
        adjacency_list[vertex_b].num_vertices++;
       
       // new vertex and edge for a
        adjacency_list[vertex_a] = LinkedList(vertex_a);
        adjacency_list[vertex_a].insert_edge(vertex_b, current_time, adjustment_factor);
        adjacency_list[vertex_a].num_vertices++;
        num_vertices_graph++;
    }
    else // both vertices are already in the graph
    {   
        // check if an edge already exists between the two vertices
        if (adjacency_list[vertex_a].search_vertex_edges(vertex_b) && adjacency_list[vertex_b].search_vertex_edges(vertex_a))
        {
            //just recalculate the time with distance and speed
            cout << "recalculating" << endl;
            adjacency_list[vertex_a].update_edge_time(current_time);
            adjacency_list[vertex_a].num_vertices++;
            adjacency_list[vertex_b].update_edge_time(current_time);
        }
        else
        {    
            cout << "adding new node" << endl;
            adjacency_list[vertex_a].insert_edge(vertex_b, current_time, adjustment_factor);
            adjacency_list[vertex_a].num_vertices++;
            adjacency_list[vertex_b].insert_edge(vertex_a, current_time, adjustment_factor);
            adjacency_list[vertex_b].num_vertices++;
        }
    }
    return true;
}

bool Graph::print(int vertex_a) /// needs a condition if an existing vertex loses all of its edges!
{
    if (!(adjacency_list[vertex_a].current_vertex == vertex_a))
    {
        return false;
    }

    adjacency_list[vertex_a].print_adjacent_vertices();
    return true;
}

bool Graph::delete_a_vertex(int vertex_a)
{
    if (adjacency_list[vertex_a].current_vertex == vertex_a)
    {
        adjacency_list[vertex_a].delete_parent_vertex(vertex_a);
        
        for (int i = 0; i < 500000; i++)
        {
            if (adjacency_list[i].current_vertex == 0)
            {
                continue;
            }
            else
            {
                cout << "deleting edge vertices" << endl;
                adjacency_list[i].delete_edge_vertex(vertex_a);
            }
        }
        return true;
    }
    else
    {
        cout << adjacency_list[vertex_a].current_vertex << endl;
        return false;
    }
}


bool Graph::traffic(int vertex_a, int vertex_b, double adjustment_factor)
{
    if (adjacency_list[vertex_a].current_vertex == vertex_a && adjacency_list[vertex_b].current_vertex == vertex_b && adjacency_list[vertex_a].search_vertex_edges(vertex_b) && adjacency_list[vertex_b].search_vertex_edges(vertex_a))
    {
        adjacency_list[vertex_a].update_adjustment_factor(vertex_b, adjustment_factor);
        adjacency_list[vertex_b].update_adjustment_factor(vertex_a, adjustment_factor);
        return true;
    }
    return false;
}


double Graph::find_time(double distance, double speed_limit, double adjustment_factor)
{
    int time = distance / (speed_limit * adjustment_factor);
    return time;
}


LinkedList* Graph::Relax(int u, int v)
{
    if(adjacency_list[v].Dijkstras_distance > (adjacency_list[u].Dijkstras_distance + adjacency_list[u].get_weight(v)))
    {
        adjacency_list[v].setd(adjacency_list[u].Dijkstras_distance + adjacency_list[u].get_weight(v));
        cout << "new Dijkstras distance: " << adjacency_list[v].Dijkstras_distance << " ";
        adjacency_list[v].setparent(u);
        cout << "new parent: " << adjacency_list[v].Dijkstras_parent << endl;

        return &adjacency_list[v];
    }
    return &adjacency_list[v];
}

bool Graph::Dijkstras(int s, int find_b)
{
    // MAKE HEAP OF INTEGERS
    // Done list
    // initialize the Priority Queue
    if (adjacency_list[s].current_vertex != s || adjacency_list[find_b].current_vertex != find_b)
    {
        return false;
    }
    
    MinPQ* Q;
    LinkedList* graph_vertices_array[num_vertices_graph];
    int i_graph = 0;
    // 
    // Q = new PriorityQueue(comparator);

    for (int i = 0; i < 500000; i++)
    {
        if (adjacency_list[i].current_vertex != 0)
        {
            if (adjacency_list[i].current_vertex == adjacency_list[s].current_vertex)
            {
                adjacency_list[s].setd(0);
                cout << "setting initial conditions for [s]: " << adjacency_list[s].current_vertex << endl;

            }
            else
            {
                adjacency_list[i].setd(infinity);
                adjacency_list[i].setparent(0);
                cout << "setting initial conditions for: " << adjacency_list[i].current_vertex << endl;
            }

            graph_vertices_array[i_graph] = new LinkedList(adjacency_list[i]);
            i_graph++;
            // Q.push(s_vertex);
        }
    }

    Q = new MinPQ(graph_vertices_array, num_vertices_graph);

    //adjacency_list[s].setd(0);
    //Q.modifyKey(s_vertex);

    // while (!(Q->isEmpty()))
    for (int i = 0; i < num_vertices_graph; i++)
    {
        int u = Q->extractMin(i);
        cout << "min node extracted from the Queue: " << u << endl;
        adjacency_list[u].is_done = true;

        int* adjacent_array = adjacency_list[u].adjacent();
        for (int i = 0; i < adjacency_list[u].num_vertices; i++)
        {
            cout << "adjacent points to: " << adjacency_list[u].current_vertex << "--> " << adjacent_array[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < adjacency_list[u].num_vertices; i++)
        {
            if (!adjacency_list[i].is_done)
            {
                // Now what is the index that we know that we will find this point at in the Queue?!
                Q->modifyKey(adjacent_array[i], Relax(adjacency_list[u].current_vertex, adjacent_array[i]));
            }
        }
        // delete[] adjacent_array;
    }
    
    return true;
}

