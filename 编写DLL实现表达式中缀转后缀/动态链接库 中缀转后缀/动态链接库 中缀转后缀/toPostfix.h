#ifdef DLL_API
#else
#define DLL_API _declspec(dllimport)    //������
#endif

class DLL_API Stack {       //������
private:
	char *s;
	int top;
public:
	Stack();
	~Stack();
	void push(char e);
	int pop();
	bool isEmpty();
	char gettop();
	void Check(char *s);
	void Transform(char *s);
};


	