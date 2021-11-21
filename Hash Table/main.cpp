#include <iostream>
#include "HashTable.h"


int main()
{
    HashTable<int> myTable(5);

    myTable.insert(1);
    myTable.insert(2);
    myTable.insert(3);
    myTable.insert(4);
    myTable.insert(5);
    myTable.insert(6);
    myTable.insert(7);
    myTable.insert(8);
    myTable.insert(9);
    myTable.insert(10);
    myTable.insert(11);
    myTable.insert(12);
    myTable.insert(13);
    myTable.insert(14);
    myTable.insert(15);
    myTable.insert(16);
    myTable.insert(17);
    myTable.insert(18);
    myTable.insert(19);
    myTable.insert(20);

    myTable.print();

    return 0;
}