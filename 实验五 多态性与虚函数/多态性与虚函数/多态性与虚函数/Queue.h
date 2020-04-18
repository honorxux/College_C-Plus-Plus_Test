#ifndef __QUEUE_H__
#define __QUEUE_H__

template <class T>
class Queue {
public:
	virtual int size() = 0;
	virtual bool isEmpty() = 0;
	virtual void print() = 0;
	//入队操作
	virtual void enqueue(T num) = 0;
	//出队操作
	virtual void dequeue() = 0;
	//获得队首元素
	virtual T front() = 0;
};

#endif
