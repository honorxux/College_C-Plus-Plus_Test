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
	cout << "������Ҫ�����жϵ��ַ���(��20-200���ַ�֮�䣩:" << endl;
	cin >> str;
	while (strlen(str) < 20 || strlen(str) > 200)
	{
		cout << "���벻����Ҫ�����������룺" << endl;
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
		cout << "��" << endl;
	}
	else
	{
		cout << "����" << endl;
	}

	STACK.DestroyStack(stack);
	return 0;
}


//------------------ջ�ĳ�ʼ������------------------
Status Stack::InitStack(SqStack &S) {
	S.base = (Elemtype *)malloc(STACK_INIT_SIZE * sizeof(Elemtype));
	if (!S.base) {
		return false;
	}
	S.stacksize = STACK_INIT_SIZE;
	S.top = S.base;
	return true;
}
//---------------------��ջ����---------------------
Status Stack::Push(SqStack &S, Elemtype e) {
	//�ж��Ƿ����
	if (S.top - S.base >= S.stacksize) {
		S.base = (Elemtype *)realloc(S.base, (S.stacksize + STACKINCREACE) * sizeof(Elemtype));
		if (!S.base) {
			return false;
		}
		S.top = S.base + S.stacksize;//ע����Ϊ�����ջ��ָ��ĸı䣬����ջ��ָ����֮�ı�
		S.stacksize += STACKINCREACE;
	}
	//ѹջ����
	*S.top = e;
	S.top++;
	return true;
}
//---------------------��ջ����---------------------
Status Stack::Pop(SqStack &S, Elemtype *e) {
	//�Ƿ��ж�
	if (S.base == S.top) {
		return false;
	}
	S.top--;    //ע��������Ϊtopָ��ջ�е�ǰԪ�ص���һ���ռ䣬����Ҫ�Ƚ���λ�ü�һ
	*e = *S.top;
	return true;
}
//------------------����ջԪ�ظ���------------------
int Stack::StackLength(SqStack S) {
	if (S.base == S.top) {
		return 0;
	}
	return S.top - S.base;
}

//--------------------����ջ------------------------
Status Stack::DestroyStack(SqStack &S) {
	free(S.base);
	free(S.top);
	S.base = NULL;
	return true;
}


