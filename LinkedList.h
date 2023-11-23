# include <iostream>
#include <string>
#include "Node.h"
using namespace std;

/////////////////////// LinkedList Class Declaration ///////////////////////////
class LinkedList
{
    private:
        Node* list_head;

    public:
        LinkedList();
        LinkedList(int vertex);
        ~LinkedList();
        void insert_edge(int vertex, double current_time, double adjustment_factor);
        bool search_vertex_edges(int vertex);
        void update_edge_time(double updated_time);
        void print_adjacent_vertices();
        void delete_parent_vertex(int vertex);
        void delete_edge_vertex(int vertex);
        void update_adjustment_factor(int vertex, double adjustment_factor);

        void setd(int k);
        void setparent(int parent);
        double get_weight(int vertex);
        int* adjacent();


        int get_word(string word);
        void return_key(int index, int size);

        int current_vertex;
        double Dijkstras_distance;
        int  Dijkstras_parent;
        int num_vertices;
        bool is_done;

        
};