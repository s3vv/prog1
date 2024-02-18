#ifndef NODE_
#define NODE_

template<class T>
class node
{
	T data;
	node<T> * next;
	node()
	{
		next = nullptr;
	}
	node(T item)
	{
		data = item;
		next = nullptr;
	}
};

#endif