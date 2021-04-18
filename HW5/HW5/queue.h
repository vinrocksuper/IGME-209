#pragma once
#include <iostream>
using namespace std;


template <typename T>
class queue
{
private:
	int size;
	T** list;

public:
	queue();
	queue(T first);
	queue(T** copy);
	~queue();
	void Push();
	void Pop();
	void Print();
	int GetSize();
	bool IsEmpty();
};

