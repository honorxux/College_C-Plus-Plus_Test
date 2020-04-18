#include<iostream>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
using namespace std;

#define STACK_INIT_SIZE 200
#define STACKINCREACE 10
typedef char Elemtype;
typedef int Status;
typedef struct {
	Elemtype *base;
	Elemtype *top;
	int stacksize;
}SqStack;
class Stack {

public:
	Status InitStack(SqStack &S);
	Status Push(SqStack &S, Elemtype e);
	Status Pop(SqStack &S, Elemtype *e);
	int StackLength(SqStack S);
	Status DestroyStack(SqStack &S);
};

int main()
{

	int i = 0, j = 0;
	int judge = 1, LENGTH;
	char str[100];
	char stackstr;
	Stack STACK;
	SqStack stack;
	STACK.InitStack(stack);
	cout << "请输入要进行判断的字符串(在20-200个字符之间）:" << endl;
	cin >> str;
	while (strlen(str) < 20 || strlen(str) > 200)
	{
		cout << "输入不符合要求请重新输入：" << endl;
		cin >> str;
	}
	while (str[i] != '\0')
	{
		STACK.Push(stack, str[i]);
		i++;
	}
	for (j = 0; j < i; j++)
	{

		STACK.Pop(stack, &stackstr);
		if (stackstr != str[j])
		{
			judge = 0;
		}
	}

	if (judge == 1)
	{
		cout << "是" << endl;
	}
	else
	{
		cout << "不是" << endl;
	}

	STACK.DestroyStack(stack);
	return 0;
}


//------------------栈的初始化函数------------------
Status Stack::InitStack(SqStack &S) {
	S.base = (Elemtype *)malloc(STACK_INIT_SIZE * sizeof(Elemtype));
	if (!S.base) {
		return false;
	}
	S.stacksize = STACK_INIT_SIZE;
	S.top = S.base;
	return true;
}
//---------------------入栈函数---------------------
Status Stack::Push(SqStack &S, Elemtype e) {
	//判断是否溢出
	if (S.top - S.base >= S.stacksize) {
		S.base = (Elemtype *)realloc(S.base, (S.stacksize + STACKINCREACE) * sizeof(Elemtype));
		if (!S.base) {
			return false;
		}
		S.top = S.base + S.stacksize;//注意因为这里的栈底指针的改变，导致栈顶指针随之改变
		S.stacksize += STACKINCREACE;
	}
	//压栈部分
	*S.top = e;
	S.top++;
	return true;
}
//---------------------出栈函数---------------------
Status Stack::Pop(SqStack &S, Elemtype *e) {
	//非法判断
	if (S.base == S.top) {
		return false;
	}
	S.top--;    //注意这里因为top指向栈中当前元素的上一个空间，所以要先将其位置减一
	*e = *S.top;
	return true;
}
//------------------返回栈元素个数------------------
int Stack::StackLength(SqStack S) {
	if (S.base == S.top) {
		return 0;
	}
	return S.top - S.base;
}

//--------------------销毁栈------------------------
Status Stack::DestroyStack(SqStack &S) {
	free(S.base);
	free(S.top);
	S.base = NULL;
	return true;
}


