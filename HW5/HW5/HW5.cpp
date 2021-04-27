// HW5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "queue.h";
int main()
{
	queue<int>  intQ;

	int x = 0;
	int y = 1;
	int z = 2;
	
	int* xptr = &x;
	int* yptr = &y;
	int* zptr = &z;

	
	intQ.Push(xptr);
	intQ.Push(yptr);
	intQ.Push(zptr);

//	intQ.Print();
//	cout << "There are " << intQ.GetSize() << " elements in the queue" << endl;

	
//	intQ.Pop();

//	intQ.Print();
	
    
}
