template<class T>       //模板类            复数、字符串
class Stack {
private:
	T * elem_;
	int top_;
	int max_size_;
public:
	Stack(int max_size) {
		max_size_ = max_size;
		elem_ = new T[max_size];
		top_ = 0;
	}

	~Stack() {
		delete[] elem_;
	}

	//返回已有元素个数
	int StackLength() {
		return top_;
	}

	//判断栈是否为空
	bool StackEmpty() {
		if (StackLength() == 0)
			return true;
		else
			return false;
	}

	//判断栈是否已满
	bool StackFull() {
		if (StackLength() >= max_size_)
			return true;
		else
			return false;
	}

	//访问栈顶
	bool StackTop(T &elem) {
		if (StackEmpty())
			return false;

		elem = elem_[top_ - 1];
		return true;
	}

	//入栈
	bool Push(T elem) {
		if (StackFull())
			return false;

		elem_[top_] = elem;
		top_++;
		return true;
	}

	//出栈
	bool Pop(T &elem) {
		if (StackEmpty())
			return false;

		top_--;
		elem = elem_[top_];
		return true;
	}
};

