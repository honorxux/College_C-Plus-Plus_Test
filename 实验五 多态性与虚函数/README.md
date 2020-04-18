实验内容：
已知抽象队列类的定义如下：
template <class T>
class Queue{
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
请通过继承抽象类，重写纯虚函数 ，完成数组队列ArrayQueue的实现。
