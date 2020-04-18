#include "CycleQueue.h"


int main() {
	ArrayQueue<int> Queue1;
	CycleQueue<int> Queue2;


	Queue1.enqueue(1);
	Queue1.enqueue(2);
	Queue1.enqueue(3);
	Queue1.enqueue(4);
	Queue1.dequeue();
	cout << Queue1.front() << endl;
	cout << Queue1.size() << endl;
	cout << Queue1.isEmpty() << endl;
	Queue1.print();
	cout << endl;

	Queue2.enqueue(5);
	Queue2.enqueue(6);
	Queue2.enqueue(7);
	Queue2.enqueue(8);
	Queue2.dequeue();
	cout << Queue2.front() << endl;
	cout << Queue2.size() << endl;
	cout << Queue2.isEmpty() << endl;
	Queue2.print();
	cout << endl;


	ArrayQueue<int> *pt = &Queue1;
	pt->print();
	cout << endl;
	pt = &Queue2;
	pt->print();
	cout << endl;


	system("pause");
	return 0;
}