#include <iostream>
#include <string>
#include <fstream>
#include "Graph.h"
#include "illegal_exception.h"
using namespace std;

void parse_file()
{
    Graph* city = new Graph();
    
    string command;
    Node* new_point;
    int vertex_a;
    int vertex_b;
    double distance;
    double speed_limit;
    double adjustment_factor;

    while (cin >> command) 
    {
        if (command == "LOAD") //Load command is entered//
        {
            string filename;
            cin >> filename;
            fstream fin(filename.c_str());

            //string toRead;
            while (fin >> vertex_a >> vertex_b >> distance >> speed_limit)
            {
                cout <<"opening file " << filename << endl;
                city->insert(vertex_a, vertex_b, distance, speed_limit, 1);
            }
            /////// End of the Load command ///////
        } 

        else if (command == "INSERT") //INSERT command is entered//
        {
            cin >> vertex_a >> vertex_b >> distance >> speed_limit;
            try
            {
                // can there be an edge from a to a?
                if (vertex_a == vertex_b || vertex_a < 1 || vertex_a > 500000 || vertex_b < 1 || vertex_b > 500000 || distance <= 0 || speed_limit <= 0)
                {
                    throw illegal_exception();
                }
                else
                {
                    if (city->insert(vertex_a, vertex_b, distance, speed_limit, 1))
                    {
                        cout << "success" << endl;
                    }
                }
            }
            catch (const illegal_exception& e) {
                cout << e.what() << endl;
            }
            /////// End of the INSERT command ///////
        } 
    
        else if (command == "PRINT") //PRINT command is entered//
        {     
            cin >> vertex_a;
            try
            {
                if (vertex_a < 1 || vertex_a > 500000)
                {
                    throw illegal_exception();
                }
                else 
                {
                    if (!(city->print(vertex_a)))
                    {
                        cout << "failure" << endl;
                    }
                    else 
                    {
                        cout << endl;
                    }
                }
            }
            catch (const illegal_exception& e) {
                cout << e.what() << endl;
            }
            /////// End of the PRINT command ///////

        } 

        else if (command == "DELETE") //DELETE command is entered//
        {
            cin >> vertex_a;
            try
            {
                if (vertex_a < 1 || vertex_a > 500000)
                {
                    throw illegal_exception();
                }
                else
                {
                    if (city->delete_a_vertex(vertex_a))
                    {
                        cout << "success" << endl;
                    }
                    else 
                    {
                        cout << "failure" << endl;
                    }
                }
            }
            catch (const illegal_exception& e) {
                cout << e.what() << endl;
            }
            /////// End of the DELETE command ///////

        } 
        
        else if (command == "PATH") //PATH command is entered//
        {
            cin >> vertex_a >> vertex_b;
            try
            {
                if (vertex_a < 1 || vertex_a > 500000 || vertex_b < 1 || vertex_b > 500000)
                {
                    throw illegal_exception();
                }
                else
                {
                    if (city->Dijkstras(vertex_a, vertex_b))
                    {
                        cout << "success" << endl;
                    }
                    else
                    {
                        cout << "failure" << endl;
                    }
                }
            }
            catch (const illegal_exception& e) {
                cout << e.what() << endl;
            }
                /////// End of the PATH command ///////
        }
        
        else if (command == "TRAFFIC") //TRAFFIC command is entered//
        { 
            cin >> vertex_a >> vertex_b >> adjustment_factor;
            try
            {
                if (vertex_a < 1 || vertex_a > 500000 || vertex_b < 1 || vertex_b > 500000)
                {
                    throw illegal_exception();
                }
                else
                {
                    if ((adjustment_factor >= 0 || adjustment_factor <= 1) && city->traffic(vertex_a, vertex_b, adjustment_factor))
                    {
                        cout << "success" << endl;
                    }
                    else
                    {
                        cout << "failure" << endl;
                    }
                }
            }
            catch (const illegal_exception& e) {
                cout << e.what() << endl;
            }
            /////// End of the TRAFFIC command ///////
        }

        else if (command == "UPDATE") //UPDATE command is entered//
        { 
            string filename;
            cin >> filename;
            fstream fin(filename.c_str());

            //string toRead;
            while (fin >> vertex_a >> vertex_b >> adjustment_factor)
            {
                cout << "opening file " << filename << endl;
                city->traffic(vertex_a, vertex_b, adjustment_factor);
            }
            /////// End of the UPDATE command ///////
        }

        else if (command == "LOWEST") //LOWEST command is entered//
        { 
           cin >> vertex_a >> vertex_b;
            try
            {
                if (vertex_a < 1 || vertex_a > 500000 || vertex_b < 1 || vertex_b > 500000)
                {
                    throw illegal_exception();
                }
            }
            catch (const illegal_exception& e) {
                cout << e.what() << endl;
            }
           
           cout << command << endl;
            /////// End of the LOWEST command ///////
        }

        else if (command == "END") //END command is entered//
        { 
            city->~Graph();
            break;
        }
    }
}

int main()
{
    parse_file();
}