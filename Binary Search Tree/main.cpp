#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree<int> myTree;

    myTree.insert(10);
    myTree.insert(2);
    myTree.insert(4);
    myTree.insert(1);
    myTree.insert(3);
    myTree.insert(6);
    myTree.insert(9);
    myTree.insert(8);
    myTree.insert(7);
    myTree.insert(5);

    myTree.displayInOrder();

    std::cout << std::endl;
    srand(time(NULL));

    int random = rand() % 20 + 1;

    if(myTree.search(random))
    {
        std::cout << random << " is in the Binary Search Tree!" << std::endl;
    }
    else
    {
        std::cout << random << " is NOT in the Binary Search Tree!" << std::endl;
    }

    return 0;
}