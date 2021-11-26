#include <iostream>
#include "Graph.h"


int main()
{
    Graph<int> myGraph;

    myGraph.addVertex(100);     // vertex 0
    myGraph.addVertex(200);     // vertex 1
    myGraph.addVertex(300);     // vertex 2
    myGraph.addVertex(400);     // vertex 3

    
    myGraph.addEdge(0, 1);
    myGraph.addEdge(0, 2);
    myGraph.addEdge(0, 3);

    myGraph.addEdge(1, 2);
    myGraph.addEdge(1, 3);

    myGraph.addEdge(3, 0);

    myGraph.printList();
    myGraph.printMatrix();

    if(myGraph.hasCycle(0))
    {
        std::cout << "Vertex 0 has a cycle " << std::endl;
    }

    return 0;
}