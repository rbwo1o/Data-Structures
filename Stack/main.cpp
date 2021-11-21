#include <iostream>
#include "Stack.h"

int main()
{

    Stack<int> myStack;

    myStack.push(5);
    myStack.push(4);
    myStack.push(3);
    myStack.push(2);
    myStack.push(1);
    
    myStack.print();

    myStack.pop();
    myStack.pop();
    
    std::cout << "Peeking: " << myStack.peek() << std::endl;

    while(myStack.getLength() > 0)
    {
        std::cout << "Popping " << myStack.pop() << std::endl;
    }

    myStack.print();

    return 0;
}