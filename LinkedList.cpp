#include <iostream>
#include <limits>
#include "LinkedList.h"

////////////////////////// LinkedList Class Definitions /////////////////////////

//default constructor definition //
LinkedList::LinkedList(): list_head(nullptr) {}

LinkedList::LinkedList(int vertex): list_head(nullptr)
{
    current_vertex = vertex;
    Dijkstras_distance = numeric_limits<double>::infinity(); // infinity
    Dijkstras_parent = 0;
    num_vertices = 0;
    is_done = false;
}

// destructor definition //
LinkedList::~LinkedList()
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
        //if (temp_head->vertex != 0)
        //{
            cout << temp_head->vertex << " ";
            temp_head = temp_head->getnext();
        //}
        // else 
        // {
        //     temp_head = temp_head->getnext();
        // }
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
    Node* previous = current;
    int hold = 0;
    int vertex_empty = 0;
    while (current != nullptr)
    {
        hold = current->vertex;
        cout << "if: " << hold << " is equal to: " << vertex << endl;
        if (hold == vertex)
        {
            break;
        }
        else 
        {
            cout << "not equal" << endl;
            current = current->getnext();
            if (vertex_empty > 2)
            {
                previous = previous->getnext();
            }
            vertex_empty++;
        }
    }
    if (vertex_empty == 0)
    {
        list_head = nullptr;
    }

    
    Node* temp = current;
    current = current->getnext();
    previous = current;
    delete temp;
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
            cout << "new time is: " << current->time << " A is now = " << current->adjustment_factor << endl;
            return;
        }
        else
        {
            current = current->getnext();
        }
    }
}

void LinkedList::setd(int k)
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
    return 0;
}

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