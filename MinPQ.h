#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

class MinPQ
{

    private:
    int size;
    LinkedList** heap;
    int smallest = 0;

    public:
    MinPQ();
    MinPQ(LinkedList** array, int size);

    void build_heap();
    void heapify(int i);
    int left(int i);
    int right(int i);
    
    int floor(int n);

    void push(double distance);
    int extractMin(int i);
    bool isEmpty();

};