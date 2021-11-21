#include <iostream>
#include "Queue.h"

int main()
{
    Queue<int> myQueue;
    
    myQueue.push(5);
    myQueue.push(4);
    myQueue.push(3);
    myQueue.push(2);
    myQueue.push(1);

    myQueue.print();

    myQueue.pop();
    myQueue.pop();

    std::cout << "Peeking: " << myQueue.peek() << std::endl;

    while(myQueue.getLength() > 0)
    {
        std::cout << "Popping " << myQueue.pop() << std::endl;
    }

    myQueue.print();

    return 0;
}