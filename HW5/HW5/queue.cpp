#include "queue.h"

template <typename T>
queue<T>::queue()
{
}

template <typename T>
queue<T>::queue(T first)
{
}

template <typename T>
queue<T>::queue(T** copy)
{
}

template <typename T>
queue<T>::~queue()
{
}

template <typename T>
void queue<T>::Push()
{
	size++;
}

template <typename T>
void queue<T>::Pop()
{
	size--;
}

template <typename T>
void queue<T>::Print()
{
}

template <typename T>
int queue<T>::GetSize()
{
	return size;
}

template <typename T>
bool queue<T>::IsEmpty()
{
	return size == 0;
}
