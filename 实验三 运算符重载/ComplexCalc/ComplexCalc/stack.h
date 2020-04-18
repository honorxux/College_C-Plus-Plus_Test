template<class T>       //ģ����            �������ַ���
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

	//��������Ԫ�ظ���
	int StackLength() {
		return top_;
	}

	//�ж�ջ�Ƿ�Ϊ��
	bool StackEmpty() {
		if (StackLength() == 0)
			return true;
		else
			return false;
	}

	//�ж�ջ�Ƿ�����
	bool StackFull() {
		if (StackLength() >= max_size_)
			return true;
		else
			return false;
	}

	//����ջ��
	bool StackTop(T &elem) {
		if (StackEmpty())
			return false;

		elem = elem_[top_ - 1];
		return true;
	}

	//��ջ
	bool Push(T elem) {
		if (StackFull())
			return false;

		elem_[top_] = elem;
		top_++;
		return true;
	}

	//��ջ
	bool Pop(T &elem) {
		if (StackEmpty())
			return false;

		top_--;
		elem = elem_[top_];
		return true;
	}
};

