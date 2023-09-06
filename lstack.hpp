/*
 * lstack.hpp
 * Written by : Jo Lynch (c3200655)
 * Modified : 25/08/2023
 *
 * This class represents the implementation for a templated Stack using a linked list as the underlying collection.
 * This file should be used in conjunction with Assignment 2 for SENG1120.
 */

template <typename T>
LStack<T>::LStack()
{
	list = new std::list<T>();
	count = 0;
}

template <typename T>
LStack<T>::~LStack()
{
	delete list;
	count = 0;
}

template <typename T>
void LStack<T>::push(const T &data)
{
	list->push_front(data);
	count++;
}

template <typename T>
T LStack<T>::pop()
{
	if (list->empty()) throw empty_collection_exception();
	T value = list->front();
	list->pop_front();
	count--;
	return value;
}

template <typename T>
T& LStack<T>::top()
{
	return list->front();
}

template <typename T>
int LStack<T>::size() const
{
	return list->size();
}

template <typename T>
bool LStack<T>::empty() const
{
	return list->empty();
}
