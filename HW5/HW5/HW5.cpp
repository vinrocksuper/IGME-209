// HW5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "queue.h";
int main()
{
	queue<int*>  intQ;

	int x = 0;
	int y = 1;
	int z = 2;
	
	int* xptr = &x;
	int* yptr = &y;
	int* zptr = &z;

	//Testing Push() GetSize() Print()
	cout << "push 3 times." << endl;
	intQ.Push(xptr);
	intQ.Push(yptr);
	intQ.Push(zptr);
	intQ.Print();
	cout << "There are " << intQ.GetSize() << " elements in the queue" << endl;
	cout << endl;

	//Testing Pop();
	cout << "popped 1 time." << endl;
	intQ.Pop();
	intQ.Print();
	cout << "There are " << intQ.GetSize() << " elements in the queue" << endl;
	cout << endl;
	
	//Testing IsEmpty();
	cout << "popped 2 times." << endl;
	intQ.Pop();
	intQ.Pop();
	intQ.Print();
	cout << "There are " << intQ.GetSize() << " elements in the queue" << endl;
	if(intQ.IsEmpty())
	{
		cout << "The queue is currently empty" << endl;
	}
	else
	{
		cout << "The queue is not empty" << endl;
	}
	cout << endl;
	
	//Testing CopyConstructor
	intQ.Push(xptr);
	intQ.Push(yptr);
	queue<int*> intQCopy(intQ);
	cout << "original has " << intQ.GetSize() << " elements." << endl;
	cout << "copy has " << intQCopy.GetSize() << " elements." << endl;
	cout << endl;
	cout << "Push one into copy nothing into original" << endl;
	intQCopy.Push(zptr);
	cout << "copy printout: " << endl;
	intQCopy.Print();
	cout << "original printout: " << endl;
	intQ.Print();
	cout << endl;
	
	//Testing operator=
	cout << "Set original to copy via = operator" << endl;
	intQ = intQCopy;
	intQ.Print();
	
}
