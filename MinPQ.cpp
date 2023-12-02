#include <iostream>
#include <string>
#include <limits>
#include "MinPQ.h"
using namespace std;

MinPQ::MinPQ() {};

MinPQ::MinPQ(LinkedList** array, int size)
{
    this->heap = array;
    this->size = size;
    smallest = 0;
    min = 0;
    parent_index = 0;
    hold = 0;
    index = 0;
}

MinPQ::~MinPQ()
{
    //delete heap;
    cout << "deleted heap" << endl;
}

void MinPQ::build_heap(LinkedList* adjacency_list)
{
    for(int i = 0; i < this->size; i++)
    {
        cout << heap[i]->Dijkstras_distance << " (heap index = " << adjacency_list[heap[i]->current_vertex].heap_index << ") ";
    }
    cout << endl;
    for (int i = floor(this->size)-1; i >= 0; i --)
    {
        //cout << "times run: " << i << endl;
        heapify(i, adjacency_list);
        for(int i = 0; i < this->size; i++)
        {
            cout << heap[i]->Dijkstras_distance << " (heap index = " << adjacency_list[heap[i]->current_vertex].heap_index << ") ";
        }
        cout << endl;
    }

    for(int i = 0; i < this->size; i++)
    {
        cout << heap[i]->Dijkstras_distance << " (heap index = " << adjacency_list[heap[i]->current_vertex].heap_index << ") ";
    }
    cout << endl;

}

void MinPQ::heapify(int i, LinkedList* adjacency_list)
{
    //cout << "heapify called" << endl;
    int l = left(i);
    int r = right(i);
    smallest = i;

    if (l <= size-1 && heap[l]->Dijkstras_distance < heap[i]->Dijkstras_distance)
    {
        smallest = l;
        //cout << "smallest: " << *heap[smallest] << endl;
    }
    else
    {
        smallest = i;
        //cout << "smallest (i): " << *heap[smallest] << endl;
    }
    if (r <= size-1 && heap[r]->Dijkstras_distance < heap[smallest]->Dijkstras_distance)
    {
        smallest = r;
        //cout << "smallest: " << *heap[smallest] << endl;
    }
    if (smallest != i)
    {
        cout << "swapping " << heap[i]->Dijkstras_distance << " with " << heap[smallest]->Dijkstras_distance << endl;
        hold = heap[i];
        index = adjacency_list[heap[i]->current_vertex].heap_index;
        adjacency_list[heap[i]->current_vertex].heap_index = adjacency_list[heap[smallest]->current_vertex].heap_index;
        heap[i] = heap[smallest];
        adjacency_list[heap[smallest]->current_vertex].heap_index = index;
        heap[smallest] = hold;

        // swaps left and right child if left child is bigger
        if (isEven(i) && i != 0)
        {
            cout << "not left" << endl;
            swap(i-1, i, adjacency_list);
        }

        heapify(smallest, adjacency_list);
    }
}

int MinPQ::floor(int n)
{
    if (n%2 != 0)
    {
        n -= 1;
        n = n/2;
        return n;
    }
    else
    {
        n = n/2;
        return n;
    }
}

int MinPQ::left(int i)
{
    i = (i * 2) + 1;
    return i;
}

int MinPQ::right(int i)
{
    i = (2 * i) + 2;
    return i;
}

int MinPQ::parent(int i) 
{ 
    i = (i - 1) / 2;
    return i; 
}

void MinPQ::extractMin(int i, LinkedList* adjacency_list)
{
    min = heap[i]->current_vertex;
    adjacency_list[heap[i]->current_vertex].is_done = true;
    //cout << "min node extracted from the Queue: " << min << " adjacent vertices = " << heap[i]->num_vertices << endl;
    int* adjacent_array = heap[i]->adjacent();
    
    for (int j = 0; j < heap[i]->num_vertices; j++)
    {
        cout << "adjacent points to: " << min << " --> " << adjacent_array[j] << " ";       
    }
    cout << endl;

    for (int k = 0; k < heap[i]->num_vertices; k++)
    {
        // we want to go through every vertex in the adjacency array and check if it is done in the heap
        //if (!adjacency_list[adjacent_array[k]].is_done)
        //{
            //cout << "NOT in the done list!" << endl;
            push(Relax(min, adjacent_array[k], adjacency_list), adjacency_list[adjacent_array[k]].heap_index, adjacency_list);
            heapify(adjacency_list[adjacent_array[k]].heap_index, adjacency_list);
            
            
            
            for(int i = 0; i < size; i++)
            {
                cout << heap[i]->Dijkstras_distance << " ";
            }
            cout << endl;
        //}
        //else
        // {
        //     cout << "In the done list!" << endl;
        // }
    }
    delete[] adjacent_array;
}

LinkedList* MinPQ::Relax(int u, int v, LinkedList* adjacency_list)
{
    cout << "Relaxing: " << u << " " << v << " " << endl;
    if(adjacency_list[v].Dijkstras_distance > (adjacency_list[u].Dijkstras_distance + adjacency_list[u].get_weight(v)))
    {
        adjacency_list[v].setd(adjacency_list[u].Dijkstras_distance + adjacency_list[u].get_weight(v));
        cout << "RELAXING: "<< v << ": new Dijkstras distance: " << adjacency_list[v].Dijkstras_distance << " ";
        adjacency_list[v].Dijkstras_parent = u;//setparent(u);
        cout << "new parent: " << adjacency_list[v].Dijkstras_parent << endl;
        adjacency_list[v].did_relax = true;
        return &adjacency_list[v];
    }
    else
    {
        //adjacency_list[v].setd(adjacency_list[v].Dijkstras_distance);
        cout << "RELAXING: NO CHANGE: " << adjacency_list[v].Dijkstras_distance << endl;
        return &adjacency_list[v];
    }
    
}

void MinPQ::push(LinkedList* temp_linklist, int start, LinkedList* adjacency_list) // push the new Dijkstra's distance onto the start of the heap
{
    if (temp_linklist->did_relax == false)
    {
        return;
    }
    cout << "pushing onto index:" << start << endl;
    heap[start]->Dijkstras_distance = temp_linklist->Dijkstras_distance;
    heap[start]->Dijkstras_parent = temp_linklist->Dijkstras_parent;
    cout << heap[start]->Dijkstras_distance << " " << heap[start]->Dijkstras_parent << endl;
    cout << "checking if parent is valid: ";

    int starting_index = start;
    while(true)
    {
        parent_index = parent(starting_index);
        if (heap[start]->Dijkstras_distance < heap[parent_index]->Dijkstras_distance)
        {
            cout << "not valid" << endl;
            cout << "swapping " << heap[start]->Dijkstras_distance << " with " << heap[parent_index]->Dijkstras_distance << endl;
            hold = heap[start];
            index = adjacency_list[heap[start]->current_vertex].heap_index;
            adjacency_list[heap[start]->current_vertex].heap_index = adjacency_list[heap[parent_index]->current_vertex].heap_index;
            heap[start] = heap[parent_index];
            adjacency_list[heap[parent_index]->current_vertex].heap_index = index;
            heap[parent_index] = hold;

            starting_index = parent_index;
            
            for(int i = 0; i < this->size; i++)
            {
                cout << heap[i]->Dijkstras_distance << " (heap index = " << adjacency_list[heap[i]->current_vertex].heap_index << ") ";
            }

            // // swaps left and right child if left child is bigger
            // if (parent_index != left(parent(parent_index)))
            // {
            //     cout << "not left" << endl;
            //     swap(parent_index-1, parent_index, adjacency_list);
            // }
        }
        else
        {
            cout << "valid" << endl;
            // swaps left and right child if left child is bigger
            if (isEven(starting_index) && starting_index != 0 && heap[starting_index]->Dijkstras_distance < heap[starting_index-1]->Dijkstras_distance)
            {
                cout << "not left" << endl;
                swap(starting_index-1, starting_index, adjacency_list);
            }
            return;
        }
    }
    //heapify(start, 0);
}

bool MinPQ::print_path(int a, int b, LinkedList* adjacency_list)
{
    if (adjacency_list[b].Dijkstras_distance == numeric_limits<double>::infinity())
    {
        return false;
    }
    else if (adjacency_list[b].Dijkstras_parent == a)
    {
        cout << endl;
        cout << "PATH = ";
        cout << adjacency_list[b].current_vertex << " " << adjacency_list[b].Dijkstras_parent << endl;
        cout << endl;
        return true;
    }
    else
    {
        cout << endl;
        cout << "PATH (more than one) = ";
        cout << adjacency_list[b].current_vertex << " ";
        int i  = b;
        while (adjacency_list[i].Dijkstras_parent != a)
        {
            cout << adjacency_list[i].Dijkstras_parent << " ";
            i = adjacency_list[i].Dijkstras_parent;//adjacency_list[adjacency_list[i].Dijkstras_parent].current_vertex; // fix this shit
            //cout << endl << "new index = heap[parent]->index " << i << endl;
        }
        cout << adjacency_list[adjacency_list[i].Dijkstras_parent].current_vertex << endl;
        cout << endl;
        return true; 
    }
    

    // int i = 0;
    // while (heap[i]->current_vertex != b)
    // {
    //     //cout << " could implement in relax to make a new list of the shortest path" << endl;
    //     //for (int j = 0; j < this->size; j++)
    //     //{
    //         if (heap[i]->Dijkstras_parent = heap[i]->current_vertex)
    //         {
    //         }
    //     //}
    //     i++;
    // cout << "PATH = ";
    // for (int i = 0; i < this->size; i++)
    // {
    //     cout <<  heap[i]->current_vertex << " ";
    // }
}

bool MinPQ::lowest(int b)
{
    cout << "PARENT:" << heap[b]->Dijkstras_parent;
    cout << endl << endl;
    if (heap[b]->Dijkstras_distance == numeric_limits<double>::infinity())
    {
        return false;
    }
    else
    {
        cout << heap[b]->Dijkstras_distance << endl << endl;
        return true;
    }    
}

void MinPQ::swap(int start, int parent_index, LinkedList* adjacency_list)
{
    cout << "swapping " << heap[start]->Dijkstras_distance << " with " << heap[parent_index]->Dijkstras_distance << endl;
    hold = heap[start];
    index = adjacency_list[heap[start]->current_vertex].heap_index;
    adjacency_list[heap[start]->current_vertex].heap_index = adjacency_list[heap[parent_index]->current_vertex].heap_index;
    heap[start] = heap[parent_index];
    adjacency_list[heap[parent_index]->current_vertex].heap_index = index;
    heap[parent_index] = hold;
}

bool MinPQ::isEven(int i)
{
    return i%2==0;
}