/* Author: Blaine Wilson 
*  Generic Class for Queues implementing Linked Lists
*/
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template <class T>
class Queue
{
    private:
        int length;
        struct Node
        {
            T data;
            Node* next;
        };

        Node* bottom;
        Node* top;

    public:
        /* Function: constructor
        * Parameters: None
        * Return: Nothing
        * Initializes each attribute of the Queue
        */
        Queue()
        {
            this->length = 0;
            this->bottom = NULL;
            this->top = NULL;            
        }



        /* Function: destructor
        * Parameters: None
        * Return: Nothing
        * Deletes each Node in the Queue
        */
        ~Queue()
        {
            // empty check
            if(this->length == 0)
            {
                return;
            }

            // iteration + deletion
            Node* nodePtr = this->bottom;
            while(nodePtr != NULL)
            {
                this->bottom = this->bottom->next;
                delete nodePtr;
                this->length--;
                nodePtr = this->bottom;
            }
        }



        /* Function: push
        * Parameters: Template Data
        * Return: Nothing
        * Creates a new Node and then pushes it to the top of the Queue
        */
        void push(T data)
        {
            // initialize a new Node
            Node* newNode = new Node;
            newNode->data = data;
            newNode->next = NULL;

            // empty check + push
            if(this->bottom == NULL)
            {
                this->bottom = newNode;
                this->top = newNode;
                this->length++;
                return;
            }

            // iteration + push
            Node* nodePtr = this->bottom;
            while(nodePtr->next != NULL)
            {
                nodePtr = nodePtr->next;
            }

            nodePtr->next = newNode;
            this->top = newNode;
            this->length++;
        }



        /* Function: pop
        * Parameters: None
        * Return: Template Data
        * Deletes the Node at the bottom of the Queue and returns its data
        */
        T pop()
        {
            // empty check --> termination
            if(this->length == 0)
            {
                std::cout << "There are no Nodes in the Queue! Terminating..." << std::endl;
                exit(EXIT_FAILURE);
            }

            // pop
            T data = this->bottom->data;
            Node* nodePtr = this->bottom;
            this->bottom = this->bottom->next;
            delete nodePtr;
            this->length--;

            return data;
        }


        
        /* Function: peek
        * Parameters: None
        * Return: Template Data
        * Returns the Node data at the bottom of the Queue
        */
        T peek()
        {
            // empty check --> termination
            if(this->length == 0)
            {
                std::cout << "There are no Nodes in the Queue! Terminating..." << std::endl;
                exit(EXIT_FAILURE);
            }

            return this->bottom->data;
        }



        /* Function: print
        * Parameters: None
        * Return: Nothing
        * Iterates throughout the Queue and prints the data value of each Node
        */
        void print()
        {
            // empty check
            if(this->length == 0)
            {
                std::cout << "There are no Nodes in the Queue." << std::endl;
                return;
            }

            // iteration
            Node* nodePtr = this->bottom;
            while(nodePtr != NULL)
            {
                std::cout << nodePtr->data << " ";
                nodePtr = nodePtr->next;
            }
            std::cout << std::endl;
        }



        /* Function: getLength
        * Parameters: None
        * Return: length of the Queue
        * Returns the length attribute of the Queue
        */
        int getLength()
        {
            return this->length;
        }
};

#endif