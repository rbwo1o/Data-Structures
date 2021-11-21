/* Author: Blaine Wilson 
*  Generic Class for Linked Lists
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <class T>
class LinkedList
{
    private:
        int length;
        struct Node
        {
            T data;
            Node* next;
        };

        Node* head;
        Node* tail;

    public:
        /* Function: constructor
        * Parameters: None
        * Return: Nothing
        * Initializes each attribute of the Linked List
        */
        LinkedList()
        {
            this->length = 0;
            this->head = NULL;
            this->tail = NULL;
        }


        /* Function: destructor
        * Parameters: None
        * Return: Nothing
        * Deletes each Node in the Linked List
        */
        ~LinkedList()
        {
            // empty check
            if(this->length == 0)
            {
                return;
            }

            // iteration + deletion
            Node* nodePtr = this->head;
            while(nodePtr != NULL)
            {
                this->head = this->head->next;
                delete nodePtr;
                this->length--;
                nodePtr = this->head;
            }
        }


        /* Function: append
        * Parameters: Template Data 
        * Return: Nothing
        * Creates a new Node and then appends it to the end of the Linked List
        */
        void append(T data)
        {
            // initialize a new Node
            Node* newNode = new Node;
            newNode->data = data;
            newNode->next = NULL;

            // empty check + append
            if(this->head == NULL)
            {
                this->head = newNode;
                this->tail = newNode;
                this->length++;
                return;
            }

            // iteration + append
            Node* nodePtr = this->head;
            while(nodePtr->next != NULL)
            {
                nodePtr = nodePtr->next;
            }

            nodePtr->next = newNode;
            this->tail = newNode;
            this->length++;
            return;
        }


        /* Function: print
        * Parameters: None
        * Return: Nothing
        * Iterates throughout the Linked List and prints the data value of each Node
        */
        void print()
        {
            // empty check
            if(this->length == 0)
            {
                std::cout << "The Linked List is empty." << std::endl;
                return;
            }
            
            // iteration
            Node* nodePtr = this->head;
            while(nodePtr != NULL)
            {
                std::cout << nodePtr->data << std::endl;
                nodePtr = nodePtr->next; 
            }
        }

};

#endif