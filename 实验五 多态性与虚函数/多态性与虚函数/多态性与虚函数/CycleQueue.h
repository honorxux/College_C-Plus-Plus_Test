#pragma once
#ifndef __CYCLEQUEUE_H__
#define __CYCLEQUEUE_H__

#include "ArrayQueue.h"
#include <iostream>
using namespace std;


template <class T>
class CycleQueue : public ArrayQueue<T>
{

public:
	CycleQueue() //���캯��
	{
		this->element = new T[maxSize];
		this->rear = 0;
		this->Front = 0;
	}
	~CycleQueue()//��������
	{
		delete[] this->element;
	}
	int size()
	{
		return (this->rear - this->Front + maxSize) % maxSize;
	}

	void print()
	{
		int i = this->Front;
		cout << "CycleQueue: ";
		for (; i != this->rear; i = (i + 1) % maxSize)
		{
			cout << this->element[i] << " ";
		}
		if (i == this->Front)
		{
			cout << "�ն���";
		}

	}
	void enqueue(T num)
	{
		if ((this->rear + 1) % maxSize == this->Front)
			cout << "��" << endl;
		else
		{
			this->element[this->rear] = num;
			this->rear = (this->rear + 1) % maxSize;
		}
	}
	void dequeue()
	{
		if (this->isEmpty())
			cout << "��" << endl;
		else
		{
			cout << this->element[this->Front] << endl;
			this->Front = (this->Front + 1) % maxSize;
		}
	}

};



#endif
