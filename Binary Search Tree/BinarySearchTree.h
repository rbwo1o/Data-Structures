/* Author: Blaine Wilson 
*  Generic Class for Binary Search Trees
*/
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>


template <class T>
class BinarySearchTree
{
    private:
        /* attributes */
        int length;

        struct Node
        {
            T data;
            Node* left;
            Node* right;
        };

        Node* root;



        /* methods */


        /* Function: insert
        * Parameters: new Node, position of current sub tree
        * Return: Nothing
        * Recursively searches a sub tree for the appropriate place to insert the new Node.
        */
        void insert(Node* newNode, Node* pos)
        {
            // empty check
            if(this->root == NULL)
            {
                this->root = newNode;
                this->length++;
                return;
            }

            // leaf node
            if(pos == NULL)
            {
                pos = newNode;
                this->length++;
                return;
            }

            // recursive iteration + insert
            if(newNode->data < pos->data)
            {
                if(pos->left == NULL)
                {
                    pos->left = newNode;
                    this->length++;
                    return;
                }
                else
                {
                    insert(newNode, pos->left);
                }
            }
            else
            {
                if(pos->right == NULL)
                {
                    pos->right = newNode;
                    this->length++;
                    return;
                }
                else
                {
                    insert(newNode, pos->right);
                }
            }
        }



        /* Function: displayInOrder
        * Parameters: position of current sub tree
        * Return: Nothing
        * Recursively prints the values of each node of a sub tree from least to greatest
        */
        void displayInOrder(Node* pos)
        {
            if(pos)
            {
                // recursive left
                displayInOrder(pos->left);

                std::cout << pos->data << std::endl;
                
                // recursive right
                displayInOrder(pos->right);
            }
        }



        /* Function: insert
        * Parameters: position of current sub tree
        * Return: Nothing
        * Recursively deletes each Node of a sub tree
        */
        void destroySubTree(Node* pos)
        {
            // recursive left
            if(pos->left)
            {
                destroySubTree(pos->left);
            }

            // recursive right
            if(pos->right)
            {
                destroySubTree(pos->right);
            }

            delete pos;
        }



    public:
        /* Function: constructor
        * Parameters: None
        * Return: Nothing
        * Initializes each attribute of the Binary Search Tree
        */
        BinarySearchTree()
        {
            this->length = 0;
            this->root = NULL;
        }



        /* Function: destructor
        * Parameters: None
        * Return: Nothing
        * Deletes each Node in the Binary Search Tree by calling a private destroySubTree method
        */
        ~BinarySearchTree()
        {
            if(this->root)
            {
                destroySubTree(this->root);
            }
        }



        /* Function: insert
        * Parameters: Template Data
        * Return: Nothing
        * Inserts a new Node in the Binary Search Tree by calling a private insert method
        */
        void insert(T data)
        {
            // initialize a new Node
            Node* newNode = new Node;
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;

            insert(newNode, this->root);
        }



        /* Function: displayInOrder
        * Parameters: None
        * Return: Nothing
        * Displays the Binary Search Tree in order by calling a private displayInOrder method
        */
        void displayInOrder()
        {
            displayInOrder(this->root);
        }



        /* Function: Search
        * Parameters: Template Data
        * Return: Nothing
        * Searches the Binary Search Tree for the Template Data
        */
        bool search(T data)
        {
            Node* pos = this->root;
            while(pos != NULL)
            {
                if(pos->data == data)
                {
                    return true;
                }
                else if(pos->data > data)
                {
                    pos = pos->left;
                }
                else
                {
                    pos = pos->right;
                }
            }

            return false;
        }

};


#endif