# include <iostream>
#include <string>
using namespace std;

/////////////////////// Nodes Class Declaration ///////////////////////////
class Node
{
    private:
        Node* next;
    public:
        Node(int vertex, double time, double adjustment_factor); // constructor declaration
        Node* getnext() const; // get next declaration
        void setnext(Node* new_node); // set next declaration

        /* Member variables */
        int vertex;
        double time;
        double adjustment_factor;
};