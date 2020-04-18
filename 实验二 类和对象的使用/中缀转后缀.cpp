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
		Stack bStack;//用于判断括号匹配 
		int m, len;
		len = strlen(s);
		for (m = 0; m < len; )
		{
			if (s[0] == ')' || s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/')//输入的第一个字符不能是操作符
			{
				cout << "输入错误，第一个字符不能为操作符和右括号" << endl;
				break;
			}
			else
			{
				if ((s[m] >= 40 && s[m] <= 57) && s[m] != 44 && s[m] != 46)//判断输入的字符是否属于   +-*/ 0123456789  (  ) 
				{
					if ((s[m]=='+'||s[m]=='-'||s[m]=='*'||s[m]=='/')&&(s[m+1]=='+'||s[m+1]=='-'||s[m+1]=='*'||s[m+1]=='/'))//判断两个操作符是否挨着
					{
						cout << "输入错误,两个操作数不能挨着" << endl;
						break;
					}
					else if ((s[m] >= '0' && s[m] <= '9') && (s[m + 1] >= '0' && s[m + 1] <= '9'))//判断两个数字是否挨着
					{
						cout << "输入错误，两个数字不能挨着" << endl;
						break;
					}
					else  //判断括号是否匹配 
					{
						if (s[m] == '(')
						{
							bStack.push(s[m]);
						}
						if (s[m] == ')')
						{
							if(bStack.isEmpty())
							{
								printf("输入错误，括号不匹配"); 
							}
							bStack.pop();
						}
						if (m == len - 1)//遍历完毕，栈应为空 
						{
							if (!bStack.isEmpty())
							{
								cout << "输入错误，括号不匹配" << endl;
								break;
							}
							else
							{
								Transform(s);//调用函数将中缀表达式转换为后缀表达式 
								break;
							}
						}
						else
							m++;
					}
				}
				else
				{
					cout << "输入错误，字符超出可选范围" << endl;
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
		cout << "将其转化为后缀表达式后的结果为:";
		for (int p = 0; p < len; p++)
		{
			if (s[p] >= '0' && s[p] <= '9') //如果遇到操作数，直接将其输出 
			{
				cout << s[p];
			}
			if (s[p] == '(') //如果遇到左括号，直接将其入栈 
			{
				mystack.push(s[p]);
			} 
			if (s[p] == '+' || s[p] == '-' || s[p] == '*' || s[p] == '/')//如果遇到操作符 
			{
				if(mystack.isEmpty()|| mystack.gettop()=='(')
				{//如果栈为空或者栈顶为左括号，则入栈 
					mystack.push(s[p]);
				} 
				else if((s[p] == '*' && ( mystack.gettop()== '-' || mystack.gettop()== '+' )) || (s[p] == '/' && ( mystack.gettop()== '-' || mystack.gettop()== '+' )))
				{//如果进行判定的字符的优先级比栈顶元素优先级高，则入栈
					mystack.push(s[p]);
				}
				else
				{//如果优先级低，则栈顶元素出栈，再判断 
					do
					{
						char ch = mystack.pop();
						cout << ch;
					} while(!(mystack.isEmpty()|| mystack.gettop()=='('||(s[p] == '*' && ( mystack.gettop()== '-' || mystack.gettop()== '+' )) || (s[p] == '/' && ( mystack.gettop()== '-' || mystack.gettop()== '+' )))) ;
				    mystack.push(s[p]);
				}
			}
			if (s[p] == ')')//当遇到右括号时,弹出栈内字符，直到遇到 左括号为止（左括号不输出） 
			{
				while (1)
				{
					char ch = mystack.pop();//取出栈顶元素
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
		if (!mystack.isEmpty())//当以上所有工作都完成以后，判断栈是否为空，如果不为空，则将栈中剩余的元素全部取出
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

int main()//主函数
{
	Stack myStack;
	char t[maxsize];
	int i;
	for (i = 0;; i++)
	{
		cout << "请输入中缀表达式:";
		cin >> t;
		myStack.Check(t);
	}
	system("pause");
	return 0;
}