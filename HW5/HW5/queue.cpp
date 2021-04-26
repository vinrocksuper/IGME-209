#include "queue.h"

/// <summary>
/// Constructor 1 space for queue
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T>
queue<T>::queue()
{
	list = new T * [1];
}


template <typename T>
queue<T>::queue(T** copy)
{

}

template <typename T>
queue<T>::queue(const queue& copy)
{
}


template <typename T>
queue<T>::~queue()
{
	for(int i=0;i<size;i++)
	{
		delete list[i];
	}
	delete list;
}

template <typename T>
void queue<T>::Push(T* item)
{
	list[size] = item;
	size++;
	
}

template <typename T>
void queue<T>::Pop()
{
	if(size > 1)
	{
		list[size - 1] = nullptr;
		size--;
	}

}

template <typename T>
void queue<T>::Print()
{
	for(int i=0;i<size;i++)
	{
		cout << list[i] << endl;
	}
}

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

template <typename T>
bool queue<T>::IsEmpty() const
{
	return (size == 0);
}
template <typename T>
queue<T>& queue<T>::operator=(const queue)
{
}