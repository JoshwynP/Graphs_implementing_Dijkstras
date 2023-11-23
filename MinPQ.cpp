#include <iostream>
#include <string>
#include "MinPQ.h"
using namespace std;

MinPQ::MinPQ() {};

MinPQ::MinPQ(LinkedList** array, int size)
{
    this->heap = array;
    this->size = size;

    for(int i = 0; i < size; i++)
    {
        cout << heap[i]->Dijkstras_distance << " ";
    }
    cout << endl;

    build_heap();
}

void MinPQ::build_heap()
{
    for (int i = floor(this->size)-1; i >= 0; i --)
    {
        cout << "times run: " << i << endl;
        heapify(i);
    }

    for(int i = 0; i < this->size; i++)
    {
        cout << heap[i]->Dijkstras_distance << " ";
    }
    cout << endl;

}

void MinPQ::heapify(int i)
{
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
        //cout << "swapping " << *heap[i] << " with " << *heap[smallest] << endl;
        LinkedList* hold = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = hold;

        heapify(smallest);
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

int MinPQ::extractMin(int i)
{
    int min = heap[i]->current_vertex;
    return min;
}