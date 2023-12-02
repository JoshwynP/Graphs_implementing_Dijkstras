#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

class MinPQ
{

    private:
    int size;
    LinkedList** heap;
    int smallest;
    int min;
    int parent_index;
    LinkedList* hold;
    int index;

    public:
    MinPQ();
    MinPQ(LinkedList** array, int size);
    ~MinPQ();

    void build_heap(LinkedList* adjacency_list);
    void heapify(int i, LinkedList* adjacency_list);
    int left(int i);
    int right(int i);
    int parent(int i);
    int floor(int n);
    void push(LinkedList* temp_linklist, int start, LinkedList* adjacency_list); // push the new Dijkstra's distance onto the start of the heap
    void swap(int start, int parent_index, LinkedList* adjacency_list);
    bool isEven(int i);

    void extractMin(int i, LinkedList* adjacency_list);
    LinkedList* Relax(int u, int v, LinkedList* adjacency_list);

    bool print_path(int a, int b, LinkedList* adjacency_list);
    bool lowest(int b);

};