/* Author: Blaine Wilson 
*  Generic Class for Graphs
*/
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

template <class T>
class Graph
{
    private:
        struct Vertex
        {
            int name;
            T data;
            std::vector<Vertex*> edges;
        };

        std::vector<Vertex*>* Vertices;


    public:
        /* Function: constructor
        * Parameters: None
        * Return: Nothing
        * Initializes a new vector to store Vertices in the Graph
        */
        Graph()
        {
            this->Vertices = new std::vector<Vertex*>;
        }



        /* Function: destructor
        * Parameters: None
        * Return: Nothing
        * Deletes all Vertices in the Graph
        */
        ~Graph()
        {
            for(int i = 0; i < this->Vertices->size(); i++)
            {
                delete this->Vertices->at(i);
            }

            delete this->Vertices;
        }



        /* Function: addVertex
        * Parameters: Template Data
        * Return: Nothing
        * Initializes a new Vertex and adds it to the list of Vertices
        */
        void addVertex(T data)
        {
            // initialize a new Vertex
            Vertex* newVertex = new Vertex;
            newVertex->name = this->Vertices->size();
            newVertex->data = data;

            // add Vertex to list of Vertices
            this->Vertices->push_back(newVertex);
        }



        /* Function: print
        * Parameters: None
        * Return: Nothing
        * Prints each Vertex in the Graph
        */
        void printVertices()
        {
            for(int i = 0; i < this->Vertices->size(); i++)
            {
                std::cout << this->Vertices->at(i)->data << std::endl;
            }
        }



        /* Function: addEdge
        * Parameters: base Vertex, destination Vertex
        * Return: Nothing
        * Adds a new edge between Vertices in the Graph
        */
        void addEdge(int base, int destination)
        {
            // verify Vertices
            if( (base < 0 || destination < 0) || (base > this->Vertices->size() - 1 || destination > this->Vertices->size() - 1) )
            {
                std::cout << "Out of Bounds!" << std::endl;
                return;
            }
            
            // add edge
            this->Vertices->at(base)->edges.push_back(this->Vertices->at(destination));  
        }



        /* Function: printList
        * Parameters: None
        * Return: Nothing
        * Prints the Graph in the form of a list
        */
        void printList()
        {
            // iterate Vertices
            for(int i = 0; i < this->Vertices->size(); i++)
            {
                std::cout << "Vertex: " << this->Vertices->at(i)->name << std::endl;
                std::cout << "Data: " << this->Vertices->at(i)->data << std::endl;
                std::cout << "Edges: ";

                // iterate Edges
                for(int j = 0; j < this->Vertices->at(i)->edges.size(); j++)
                {
                    std::cout << this->Vertices->at(i)->edges.at(j)->name;
                    if(j + 1 < this->Vertices->at(i)->edges.size())
                    {
                        std::cout << ", ";
                    }
                }
                std::cout << std::endl << std::endl;
            }
        }



        /* Function: printMatrix
        * Parameters: None
        * Return: Nothing
        * Prints the Graph in the form of an Adjacency Matrix
        */
        void printMatrix()
        {
            // dynamically allocate a new 2d array
            int** matrix = new int*[this->Vertices->size()];
            for(int i = 0; i < this->Vertices->size(); i++)
            {
                matrix[i] = new int[this->Vertices->size()];
            }

            // initialize matrix with values of 0
            for(int i = 0; i < this->Vertices->size(); i++)
            {
                for(int j = 0; j < this->Vertices->size(); j++)
                {
                    matrix[i][j] = 0;
                }
            }

            // populate matrix
            for(int i = 0; i < this->Vertices->size(); i++)
            {
                for(int j = 0; j < this->Vertices->size(); j++)
                {
                    for(int k = 0; k < this->Vertices->at(i)->edges.size(); k++)
                    {
                        if(this->Vertices->at(i)->edges.at(k)->name == this->Vertices->at(j)->name)
                        {
                            matrix[i][j] = 1;
                        }
                    }
                }
            }

            // print matrix
            std::cout << "-- Matrix --" << std::endl;
            // iterate row
            for(int i = 0; i < this->Vertices->size(); i++)
            {
                std::cout << "\t[" << this->Vertices->at(i)->name << "]";
            }
            std::cout << std::endl;
            // iterate columns
            for(int i = 0; i < this->Vertices->size(); i++)
            {
                std::cout << "[" << this->Vertices->at(i)->name << "]\t";
                for(int j = 0; j < this->Vertices->size(); j++)
                {
                    std::cout << " " << matrix[i][j] << "\t";
                }
                std::cout << std::endl;
            }

            // delete matrix
            for(int i = 0; i < this->Vertices->size(); i++)
            {
                delete [] matrix[i];
            }
            delete [] matrix;
        }

};

#endif