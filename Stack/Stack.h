/* Author: Blaine Wilson 
*  Generic Class for Stacks implementing Linked Lists
*/
#ifndef STACK_H
#define STACK_H

#include <iostream>

template <class T>
class Stack
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
        * Initializes each attribute of the Stack
        */
        Stack()
        {
            this->length = 0;
            this->bottom = NULL;
            this->top = NULL;
        }



        /* Function: destructor
        * Parameters: None
        * Return: Nothing
        * Deletes each Node in the Stack
        */
        ~Stack()
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
        * Creates a new Node and then pushes it to the top of the Stack
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
            this->length++;
            this->top = newNode;
        }



        /* Function: pop
        * Parameters: None
        * Return: Template Data
        * Deletes the Node at the top of the Stack and returns its data
        */
        T pop()
        {
            // empty check --> termination
            if(this->length == 0)
            {
                std::cout << "Stack Underflow Error! Terminating..." << std::endl;
                exit(EXIT_FAILURE);
            }

            // iteration + pop
            T data = this->top->data;
            Node* nodePtr = this->bottom;
            while(nodePtr->next != this->top && nodePtr->next != NULL)
            {
                nodePtr = nodePtr->next;
            }
            nodePtr->next = NULL;
            delete this->top;
            this->top = nodePtr;
            this->length--;

            return data;
        }



        /* Function: peek
        * Parameters: None
        * Return: Template Data
        * Returns the Node data at the top of the Stack
        */
        T peek()
        {
            // empty check --> termination
            if(this->length == 0)
            {
                std::cout << "No Nodes in the Stack! Terminating..." << std::endl;
                exit(EXIT_FAILURE);
            }

            return this->top->data;
        }



        /* Function: print
        * Parameters: None
        * Return: Nothing
        * Iterates throughout the Stack and prints the data value of each Node
        */
        void print()
        {
            // empty check
            if(this->length == 0)
            {
                std::cout << "There are no Nodes in the Stack." << std::endl;
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
        * Return: length of the Stack
        * Returns the length attribute of the Stack
        */
        int getLength()
        {
            return this->length;
        }

};

#endif