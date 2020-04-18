#pragma once
#ifdef FaceLIBDLL
#define ACEAPI _declspec(dllexport)
#else
#define FACEAPI _declspec(dllimport)
#endif

class Stack {
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