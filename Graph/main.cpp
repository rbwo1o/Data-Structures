#include <iostream>
#include "Graph.h"


int main()
{
    Graph<int> myGraph;

    myGraph.addVertex(100);   // 0
    myGraph.addVertex(200);  // 1
    myGraph.addVertex(300);    // 2
    myGraph.addVertex(400);   // 3

    //myGraph.printVertices();
    
    myGraph.addEdge(0, 3);
    myGraph.addEdge(0, 1);
    myGraph.addEdge(1, 0);
    myGraph.addEdge(2, 0);
    myGraph.addEdge(2, 1);
    myGraph.addEdge(2, 3);
    myGraph.addEdge(2, 1);
    myGraph.addEdge(3, 3);


    myGraph.printList();
    myGraph.printMatrix();

    return 0;
}