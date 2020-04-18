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
	ArrayQueue() //���캯��
	{
		element = new T[maxSize];
		rear = 0;
		Front = 0;
	}
	~ArrayQueue()//��������
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
			cout << "��" << endl;
		else
		{
			element[rear++] = num;
		}
	}
	void dequeue()
	{
		if (isEmpty())
			cout << "��" << endl;
		else
		{
			cout << element[Front] << endl;
			Front++;
		}
	}
	T front()
	{
		if (isEmpty())
			cout << "��" << endl;
		else
		{
			return element[Front];
		}
	}
};



#endif
