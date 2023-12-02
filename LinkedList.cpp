#include <iostream>
#include <limits>
#include "LinkedList.h"

////////////////////////// LinkedList Class Definitions /////////////////////////

//default constructor definition //
LinkedList::LinkedList(): list_head(nullptr) 
{
    // add variables that are uninitialized
    current_vertex = 0;
    Dijkstras_distance = std::numeric_limits<double>::infinity(); // infinity
    Dijkstras_parent = 0;
    num_vertices = 0;
    heap_index = 0;
    is_done = false;
    is_Dij = false;
    did_relax = false;
}

LinkedList::LinkedList(int vertex): list_head(nullptr)
{
    //cout << "LinkedList special constructor" << endl;
    current_vertex = vertex;
    Dijkstras_distance = std::numeric_limits<double>::infinity(); // infinity
    Dijkstras_parent = 0;
    num_vertices = 0;
    heap_index = 0;
    is_done = false;
    is_Dij = false;
    did_relax = false;
}

// destructor definition //
LinkedList::~LinkedList()
{
    if (!is_Dij)
    {    
        Node* current = list_head;
        list_head = nullptr;

        while(current!= nullptr)
        {
            Node* temp = current;
            current = current->getnext();
            delete temp;
        }
    }
}

// insert_edge definition //
void LinkedList::insert_edge(int vertex, double current_time, double adjustment_factor)
{
    Node* new_edge = new Node(vertex, current_time, adjustment_factor);
    new_edge->setnext(list_head);
    list_head = new_edge;
}

// // search_vertex_edges definition //
bool LinkedList::search_vertex_edges(int vertex)
{
    Node* current = list_head;
    while (current != nullptr)
    {
        if (current->vertex == vertex)
        {
            return true;
        }
        else
        {
            current = current->getnext();
        }
    }
    return false;
}

void LinkedList::update_edge_time(double updated_time)
{
    list_head->time = updated_time;
}

void LinkedList::print_adjacent_vertices()
{
    Node* temp_head = list_head;

    while (temp_head != nullptr)
    {
        cout << temp_head->vertex << " ";
        temp_head = temp_head->getnext();
    }
}

void LinkedList::delete_parent_vertex(int vertex)
{
    Node* current = list_head;

    this->current_vertex = 0;
    list_head = nullptr;
    while(current != nullptr)
    {
        Node* temp = current;
        current = current->getnext();
        delete temp;
    }
}

void LinkedList::delete_edge_vertex(int vertex)
{
    Node* current = list_head;
    int hold = 0;
    while (current != nullptr)
    
    {
        hold = current->vertex;
        if (hold == vertex) // If the list head points to the current node
        {
            if (current == nullptr) // If the list head points to nothing
            {
                break;
            } 
            else if (list_head == current)
            {
                list_head = list_head->getnext(); // list head points to the next node
                delete current;
                num_vertices--;
                break;
            }

            else // If the list head does not point to the current node (node is in the middle/end of the list)
            {
                Node* prior_node = list_head;

                while(prior_node->getnext()!= current)
                {
                    prior_node = prior_node->getnext(); // Find the prior node to the current node
                }

                Node* hold = current->getnext();
                prior_node->setnext(hold); // Set the prior node to the next node
                delete current;
                num_vertices--;
                break;
            }
        } 
        else
        {
            current = current->getnext();
        }
        
    }
}

void LinkedList::update_adjustment_factor(int vertex, double adjustment_factor)
{
    Node* current = list_head;
    while (current != nullptr)
    {
        if (current->vertex == vertex)
        {
            current->time = (current->time * current->adjustment_factor) * (1 / adjustment_factor);
            current->adjustment_factor = adjustment_factor;
            //cout << "new time is: " << current->time << " A is now = " << current->adjustment_factor << endl;
            return;
        }
        else
        {
            current = current->getnext();
        }
    }
}

void LinkedList::setd(double k)
{
    Dijkstras_distance = k;
}

void LinkedList::setparent(int parent)
{
    Dijkstras_parent = parent;
}

double LinkedList::get_weight(int vertex)
{
    Node* temp_head = list_head;

    while (temp_head != nullptr)
    {
        if (temp_head->vertex == vertex)
        {
            return temp_head->time;
        }
        else
        {
            temp_head = temp_head->getnext();
        }
    }
    //cout << "not found" << endl;
    return 0;
}
// needs a delete
int* LinkedList::adjacent()
{
    Node* temp_head = list_head;
    int* adjacent_vertices = new int[num_vertices];
    int i = 0;

    while (temp_head != nullptr)
    {
        adjacent_vertices[i] = temp_head->vertex;
        //cout << "Adjacent list: " << adjacent_vertices[i];
        temp_head = temp_head->getnext();
        i++;
    } 
    //cout << "ran " << i << " times " << endl;
    return adjacent_vertices;
    // new int[num_vertices] needs to be deleted
}
