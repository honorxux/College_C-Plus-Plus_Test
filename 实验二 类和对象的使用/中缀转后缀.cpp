#include<iostream>
#include<stdlib.h>
#include<string.h>
const int maxsize = 100;
using namespace std;
class Stack {
private:
	char *s;
	int top;
public:
	Stack()
	{
		s = new char[maxsize];
		top = 0;
	}
	~Stack()
	{
		delete[]s;
	}
	void push(char e)
	{
		if (top > maxsize - 1)
			cout << "overflow!" << endl;
		else
			s[top++] = e;
	}
	int pop()
	{
		return s[--top];
	}
	bool isEmpty()
	{
		if (top == 0)
			return true;
		else
			return false;
	}
    char gettop()
	{
	    return s[top-1];
	}

	void Check(char *s)
	{
		Stack bStack;//�����ж�����ƥ�� 
		int m, len;
		len = strlen(s);
		for (m = 0; m < len; )
		{
			if (s[0] == ')' || s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/')//����ĵ�һ���ַ������ǲ�����
			{
				cout << "������󣬵�һ���ַ�����Ϊ��������������" << endl;
				break;
			}
			else
			{
				if ((s[m] >= 40 && s[m] <= 57) && s[m] != 44 && s[m] != 46)//�ж�������ַ��Ƿ�����   +-*/ 0123456789  (  ) 
				{
					if ((s[m]=='+'||s[m]=='-'||s[m]=='*'||s[m]=='/')&&(s[m+1]=='+'||s[m+1]=='-'||s[m+1]=='*'||s[m+1]=='/'))//�ж������������Ƿ���
					{
						cout << "�������,�������������ܰ���" << endl;
						break;
					}
					else if ((s[m] >= '0' && s[m] <= '9') && (s[m + 1] >= '0' && s[m + 1] <= '9'))//�ж����������Ƿ���
					{
						cout << "��������������ֲ��ܰ���" << endl;
						break;
					}
					else  //�ж������Ƿ�ƥ�� 
					{
						if (s[m] == '(')
						{
							bStack.push(s[m]);
						}
						if (s[m] == ')')
						{
							if(bStack.isEmpty())
							{
								printf("����������Ų�ƥ��"); 
							}
							bStack.pop();
						}
						if (m == len - 1)//������ϣ�ջӦΪ�� 
						{
							if (!bStack.isEmpty())
							{
								cout << "����������Ų�ƥ��" << endl;
								break;
							}
							else
							{
								Transform(s);//���ú�������׺���ʽת��Ϊ��׺���ʽ 
								break;
							}
						}
						else
							m++;
					}
				}
				else
				{
					cout << "��������ַ�������ѡ��Χ" << endl;
					break;
				}
			}
		}
	}

	void Transform(char *s)
	{
		Stack mystack;
		char index[20];
		char ch; 
		int q = 0;
		int len = strlen(s);
		cout << "����ת��Ϊ��׺���ʽ��Ľ��Ϊ:";
		for (int p = 0; p < len; p++)
		{
			if (s[p] >= '0' && s[p] <= '9') //���������������ֱ�ӽ������ 
			{
				cout << s[p];
			}
			if (s[p] == '(') //������������ţ�ֱ�ӽ�����ջ 
			{
				mystack.push(s[p]);
			} 
			if (s[p] == '+' || s[p] == '-' || s[p] == '*' || s[p] == '/')//������������� 
			{
				if(mystack.isEmpty()|| mystack.gettop()=='(')
				{//���ջΪ�ջ���ջ��Ϊ�����ţ�����ջ 
					mystack.push(s[p]);
				} 
				else if((s[p] == '*' && ( mystack.gettop()== '-' || mystack.gettop()== '+' )) || (s[p] == '/' && ( mystack.gettop()== '-' || mystack.gettop()== '+' )))
				{//��������ж����ַ������ȼ���ջ��Ԫ�����ȼ��ߣ�����ջ
					mystack.push(s[p]);
				}
				else
				{//������ȼ��ͣ���ջ��Ԫ�س�ջ�����ж� 
					do
					{
						char ch = mystack.pop();
						cout << ch;
					} while(!(mystack.isEmpty()|| mystack.gettop()=='('||(s[p] == '*' && ( mystack.gettop()== '-' || mystack.gettop()== '+' )) || (s[p] == '/' && ( mystack.gettop()== '-' || mystack.gettop()== '+' )))) ;
				    mystack.push(s[p]);
				}
			}
			if (s[p] == ')')//������������ʱ,����ջ���ַ���ֱ������ ������Ϊֹ�������Ų������ 
			{
				while (1)
				{
					char ch = mystack.pop();//ȡ��ջ��Ԫ��
					if (ch == '(')
					{
						q--;
                        break;
					}
					else
					{
						cout << ch;
						q--;
					}
				}
			}
		}
		if (!mystack.isEmpty())//���������й���������Ժ��ж�ջ�Ƿ�Ϊ�գ������Ϊ�գ���ջ��ʣ���Ԫ��ȫ��ȡ��
		{
			while (!mystack.isEmpty())
			{
				ch = mystack.pop();
				cout << ch;
			}
		}
		cout << endl;
	}
};

int main()//������
{
	Stack myStack;
	char t[maxsize];
	int i;
	for (i = 0;; i++)
	{
		cout << "��������׺���ʽ:";
		cin >> t;
		myStack.Check(t);
	}
	system("pause");
	return 0;
}