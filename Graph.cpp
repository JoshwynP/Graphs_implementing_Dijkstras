#include <iostream>
#include <limits>
#include "Graph.h"
using namespace std;

Graph::Graph()
{
    adjacency_list = new LinkedList[500001];
    num_vertices_graph = 0;
    infinity = std::numeric_limits<double>::infinity();

    vertex_a = 0;
    vertex_b = 0;
    distance = 0;
    speed_limit = 0;
    adjustment_factor = 0;
    current_time = 0;
    vertex_a_hold = 0;
    vertex_b_hold = 0;
}

Graph::~Graph()
{
    delete[] adjacency_list;
    //cout << "destructor ran" << endl;
}

bool Graph::insert(int vertex_a, int vertex_b, double distance, double speed_limit, double adjustment_factor)
{
    current_time = find_time(distance, speed_limit, adjustment_factor);

    vertex_a_hold = -1;
    vertex_b_hold = -1;

    // check what vertices are in the graph
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
            //cout << "recalculating" << endl;
            adjacency_list[vertex_a].update_edge_time(current_time);
            adjacency_list[vertex_a].num_vertices++;
            adjacency_list[vertex_b].update_edge_time(current_time);
        }
        else
        {    
            //cout << "adding new node" << endl;
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
        
        for (int i = 1; i < 500001; i++)
        {
            if (adjacency_list[i].current_vertex == 0)
            {
                continue;
            }
            else
            {
                //cout << "deleting edge vertices" << endl;
                adjacency_list[i].delete_edge_vertex(vertex_a);
            }
        }
        num_vertices_graph--;
        return true;
    }
    else
    {
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
    double time = distance / (speed_limit * adjustment_factor);
    return time;
}

bool Graph::Dijkstras(int s, int find_b, string command)
{
    if (adjacency_list[s].current_vertex != s || adjacency_list[find_b].current_vertex != find_b || s == find_b)
    {
        return false;
    }
    
    // funny but if s is bigger than find_b then swap so it works LOL
    // if (s > find_b)
    // {
    //     int hold = s;
    //     s = find_b;
    //     find_b = hold;
    // }

    MinPQ* Q;
    LinkedList* graph_vertices_array[num_vertices_graph];
    int i_graph = 0;
    int temp_del = 0;
    for (int i = 1; i < 500001; i++)
    {
        if (adjacency_list[i].current_vertex != 0)
        {
            if (adjacency_list[i].current_vertex == adjacency_list[s].current_vertex)
            {
                adjacency_list[s].setd(0);
                //cout << "setting initial conditions for [s]: " << adjacency_list[s].current_vertex << endl;

            }
            else
            {
                adjacency_list[i].setd(infinity);
                adjacency_list[i].setparent(0);
                //cout << "setting initial conditions for: " << adjacency_list[i].current_vertex << endl;
            }
            graph_vertices_array[i_graph] = new LinkedList(adjacency_list[i]);
            temp_del++;

            graph_vertices_array[i_graph]->current_vertex = adjacency_list[i].current_vertex;
            graph_vertices_array[i_graph]->heap_index = i_graph;
            graph_vertices_array[i_graph]->num_vertices = adjacency_list[i].num_vertices;
            graph_vertices_array[i_graph]->is_Dij = true;

            adjacency_list[i].heap_index = i_graph;
            adjacency_list[i].is_done = false;
            i_graph++;
        }
    }
    //cout << "about to make heap of vertices" << endl;
    Q = new MinPQ(graph_vertices_array, num_vertices_graph);
    Q->build_heap(adjacency_list);
    
    for (int i = 0; i < num_vertices_graph; i++)
    {
        Q->extractMin(i, adjacency_list); // extract min
        //delete graph_vertices_array[i];
    }
    
    bool TorF;
    if (command == "PATH")
    {
        //int b = adjacency_list[find_b].heap_index;
        //cout << "running path" << endl;
        TorF = Q->print_path(s, find_b, adjacency_list);
    }
    else
    {
        int b = adjacency_list[find_b].heap_index;
        //cout << "extracting from index " << b << " in the heap!" << endl;
        TorF = Q->lowest(b); // CHANGE FOR LOWEST STUFF
    }
    
    //DELETE ALL THE ARRAYS AND STUFF
    for (int i = 0; i < temp_del; ++i) 
    {
        delete graph_vertices_array[i];
    }
    delete Q;

    if (TorF)
    {
        return true;
    }
    else
    {
        return false;
    }
}

