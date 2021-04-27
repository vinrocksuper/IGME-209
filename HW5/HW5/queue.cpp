#include "queue.h"
/**
/// <summary>
/// Constructor 1 space for queue
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T>
queue<T>::queue()
{
	list = new T * [1];
	size = 0;
}

/// <summary>
/// Takes a copy of a queue that already exists and copies it into this one
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="copy"> queue to copy from</param>
template <typename T>
queue<T>::queue(const queue& copy)
{
	size = copy.size;
	list = new T * [size];
	for (int i = 0; i < copy.size; i++)
	{
		list[i] = copy[i];
	}
}

/// <summary>
/// Deallocates all memory from queue
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T>
queue<T>::~queue()
{
	for(int i=0;i<size;i++)
	{
		delete list[i];
	}
	delete list;
	cout << "Queue class yeet" << endl;
}

/// <summary>
/// Adds an item* into the queue the last slot
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="item">item to add</param>
template <typename T>
void queue<T>::Push(T* item)
{
	list[size] = item;
	size++;
	cout << &item << " was added. There are now " << size << " elements." << endl;
}

/// <summary>
/// Removes the first element of the queue
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T>
void queue<T>::Pop()
{
	if(size > 1)
	{
		cout << &list[0] << " was removed. " << endl;
		list[0] = nullptr;
		
		for(int i=1;i<size;i++)
		{
			list[i - 1] = list[i];
		}
		size--;
		cout << &list[0] << " is now the first element." << endl;
	}

}

/// <summary>
/// Prints out all elements in the list
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T>
void queue<T>::Print()
{
	for(int i=0;i<size;i++)
	{
		cout << list[i] << endl;
	}
}

/// <summary>
/// Returns amount of elements in the queue
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template <typename T>
int queue<T>::GetSize()
{
	int cnt = 0;
	for(int i=0;i<size;i++)
	{
		if(list[i] != nullptr)
		{
			cnt++;
		}
	}
	return cnt;
}

/// <summary>
/// Returns whether or not the list is empty
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template <typename T>
bool queue<T>::IsEmpty() const
{
	return (size == 0);
}



/// <summary>
/// Operator assignment
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="other"> queue to assign from </param>
/// <returns> reassigned queue </returns>
template <typename T>
queue<T>& queue<T>::operator=(const queue other)
{
	size = other.size;
	for (int i = 0; i < size; i++)
	{
		delete list[i];
	}
	delete list;
	list = new T * [size];
	for (int i = 0; i < other.size; i++)
	{
		list[i] = other[i];
	}
	return this;
}

**/