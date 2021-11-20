#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList<int> myList;
    
    myList.append(5);
    myList.append(4);
    myList.append(3);
    myList.append(2);
    myList.append(1);
    
    myList.print();

    return 0;
}