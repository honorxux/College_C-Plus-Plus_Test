#ifndef __ARRAYQUEUE_H__
#define __ARRAYQUEUE_H__

#include "Queue.h"
#include <iostream>
using namespace std;

#define maxSize 50


template <class T>
class ArrayQueue : public Queue<T>
{
protected:
	T *element;
	int Front, rear;

public:
	ArrayQueue() //构造函数
	{
		element = new T[maxSize];
		rear = 0;
		Front = 0;
	}
	~ArrayQueue()//析构函数
	{
		delete[] element;
	}
	int size()
	{
		return (rear - Front);
	}
	bool isEmpty()
	{
		return (rear == Front) ? true : false;
	}
	void print()
	{
		cout << "ArrayQueue: ";
		int i = Front;
		for (i; i < rear; i++)
		{
			cout << element[i] << " ";
		}
	}
	void enqueue(T num)
	{
		if (rear - Front == maxSize)
			cout << "满" << endl;
		else
		{
			element[rear++] = num;
		}
	}
	void dequeue()
	{
		if (isEmpty())
			cout << "空" << endl;
		else
		{
			cout << element[Front] << endl;
			Front++;
		}
	}
	T front()
	{
		if (isEmpty())
			cout << "空" << endl;
		else
		{
			return element[Front];
		}
	}
};



#endif
