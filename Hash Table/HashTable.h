/* Author: Blaine Wilson 
*  Generic Class for Hash Tables implementing Linked Lists to avoid collisions
*/
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <time.h>
#include <stdlib.h>


template <class T>
class HashTable
{
    private:
        struct Bucket
        {
            int key;
            T data;
            Bucket* next;
        };

        Bucket** table;
        int size;
        int length;

    public:
        /* Function: constructor
        * Parameters: Default Parameter to 10 elements
        * Return: Nothing
        * Initializes each attribute of the Hash Table
        */
        HashTable(int size = 10)
        {
            this->size = size;
            this->table = new Bucket*[this->size];
            this->length = 0;

            // initialize the random seed used for Hashing
            srand(time(NULL));

            // initialize each Bucket in the Hash Table
            for(int i = 0; i < this->size; i++)
            {
                this->table[i] = NULL;
            }
        }


        
        /* Function: destructor
        * Parameters: None
        * Return: Nothing
        * Deletes each Bucket in the Hash Table
        */
        ~HashTable()
        {
            // iterate array
            for(int i = 0; i < this->size; i++)
            {
                if(this->table[i] != NULL)
                {
                    // iterate Linked List + deletion
                    Bucket* bucketPtr = this->table[i];
                    Bucket* bucketPtrNext = bucketPtr;
                    while(bucketPtr != NULL)
                    {
                        bucketPtrNext = bucketPtr->next;
                        delete bucketPtr;
                        bucketPtr = bucketPtrNext;
                    }
                }
            }

            delete [] this->table;
        }



        /* Function: hash
        * Parameters: Template Data
        * Return: Integer
        * Returns a simple hash value representing the Bucket's key index of the Hash Table
        */
        int hash(T data)
        {
            int random = rand() % this->size + 0;
            int hash = (random + sizeof(data)) % this->size;
            
            return hash;
        }



        /* Function: insert
        * Parameters: Template Data
        * Return: Nothing
        * Inserts a new Bucket in the Hash Table. It avoids collision by using a Linked List.
        */
        void insert(T data)
        {
            // Key Index
            int key = hash(data);
            
            // initialize a new Bucket
            Bucket* newBucket = new Bucket;
            newBucket->key = key;
            newBucket->data = data;
            newBucket->next = NULL;

            // empty check + insertion
            if(this->table[key] == NULL)
            {
                this->table[key] = newBucket;
                this->length++;
                return;
            }
            
            // iteration of Linked List + insertion
            Bucket* bucketPtr = this->table[key];
            while(bucketPtr->next != NULL)
            {
                bucketPtr = bucketPtr->next;
            }

            bucketPtr->next = newBucket;
            this->length++;
        }



        /* Function: print
        * Parameters: None
        * Return: Nothing
        * Iterates throughout the Hash Table and prints the data value of each Bucket
        */
        void print()
        {
            // iterate array
            for(int i = 0; i < this->size; i++)
            {
                if(this->table[i] == NULL)
                {
                    std::cout << "[n]" << std::endl;
                }
                else
                {
                    // iterate Linked List
                    Bucket* bucketPtr = this->table[i];
                    while(bucketPtr != NULL)
                    {
                        std::cout << "[" << bucketPtr->data << "] --> ";
                        bucketPtr = bucketPtr->next;
                    }
                    std::cout << "[n]" << std::endl;
                }
            }
        }

        
};


#endif