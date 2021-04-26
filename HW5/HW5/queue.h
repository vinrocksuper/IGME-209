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
	queue(const queue &copy);
	~queue();
	void Push(T* item);
	void Pop();
	void Print();
	int GetSize();
	bool IsEmpty() const;

	queue& operator = (const queue other);
};

