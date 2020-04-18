#include<iostream>
#include<string>
#include"Complex.h"
#include"Stack.h"
using namespace std;

void Convert(string resultstr[], string str);		//将表达式转换为后缀表达式
Complex Operate(Complex x, string op, Complex y);	//运算符计算
Complex Compute(string str[], int length);			//计算后缀表达式


//将表达式转换为后缀表达式
void Convert(string resultstr[], string str) {
	Stack<string> str_stack(str.length());   // 栈的类型为 string
	int j = 0;
	for (int i = 0; i < str.length(); i++) {      //遍历 
		if (str[i] == '(') {                     //如果是左括号 入栈
			str_stack.Push(string(1, str[i]));  //  string(1,s[i])表示生成一个 s[i]字符的字符串   因为栈的类型为 string
			continue;
		}
		else if (str[i] == ')') {           //如果是右括号
			string s;
			while (true) {
				str_stack.Pop(s);           //栈内数据出栈，直到遇到左括号 
				if (s == "(")
					break;
				resultstr[j++] = s;
			}
			continue;
		}
		else if (str[i] == '*' || str[i] == '/') {    //如果是  *  /
			string s;
			while (true) {
				if (!str_stack.StackTop(s)) {    //如果栈为空，则入栈
					str_stack.Push(string(1, str[i]));
					break;
				}
				else {
					if (s == "*" || s == "/") {   //如果栈顶为 * / 则 栈顶元素出栈
						str_stack.Pop(s);
						resultstr[j++] = s;
					}
					else {                         //其他情况 ，入栈
						str_stack.Push(string(1, str[i]));
						break;
					}
				}
			}
			continue;
		}
		else if (str[i] == '+' || str[i] == '-') {  //如果是 + -
			string s;
			while (true) {
				if (!str_stack.StackTop(s)) {   //栈为空 入栈
					str_stack.Push(string(1, str[i]));
					break;
				}
				else {
					if (s == "(") {                  //栈顶为 左括号  入栈
						str_stack.Push(string(1, str[i]));
						break;
					}
					else {                         //其他情况栈顶元素出栈
						str_stack.Pop(s);
						resultstr[j++] = s;
					}
				}
			}
			continue;
		}
		else {             //其他情况 （ 不为 +-*/ 括号  ）     数字或者 i
			string s;
			while (i != str.length() && str[i] != '+'&&str[i] != '-'&&str[i] != '*'&&str[i] != '/'&&str[i] != ')') {
				s.append(string(1, str[i++]));   //  append拼接字符串     （i跟在虚部后面）
			}
			resultstr[j++] = s;
			i--;
			continue;
		}
	}

	while (!str_stack.StackEmpty()) {       //遍历完毕，如果栈不空，所有元素依次出栈
		string s;
		str_stack.Pop(s);
		resultstr[j++] = s;
	}
	if (j != str.length()) {     //括号不放人后缀表达式。    如果输入有括号，转换为后缀之后，括号会去掉，字符串个数减少
		resultstr[j] = "end";    //end 来标识 有括号或者字符拼接的情况下，后缀表达式的结束
	}
}

//运算符计算
Complex Operate(Complex x, string op, Complex y) {
	if (op == "+")
		return x + y;
	else if (op == "-")
		return x - y;
	else if (op == "*")
		return x * y;
	else if (op == "/")
		return x / y;
}

//计算后缀表达式
Complex Compute(string str[], int length) {
	Stack<Complex> s(length);	//类模板  暂存操作数
	string op;	//暂存操作符
	Complex x, y;	//两个操作数
	for (int i = 0; i < length; i++) {  //遍历
		if (str[i] != "+"&&str[i] != "-"&&str[i] != "*"&&str[i] != "/") {   //如果不为 操作符
			Complex cnum;
			toComplex(cnum, str[i]);      //将字符串转化为复数类型   2+3i ——>  （2+0i)+(0+3i)     每个string都相当于一个复数， 2+3i相当于两个复数
			s.Push(cnum);
		}
		else   //为操作符   操作符之前至少有两个复数在栈中                 后缀表达式的计算
		{
			op = str[i];

			Complex x, y;
			s.Pop(y);	//取操作数2
			s.Pop(x);	//取操作数1
			s.Push(Operate(x, op, y));	//将当前计算结果入栈
		}
	}
	Complex result;		//接受计算结果
	s.Pop(result);     //后缀表达式最后一位肯定为操作符； 遍历完毕之后，栈中只有一个元素，该元素就是最终结果
	return result;
}

int main() {
	string str;
	cout << "请输入计算表达式：";
	cin >> str;
	cout << "转换为后缀表达式为：";

	string* resultstr = new string[str.length()];     //动态分配大小为 str.length()的空间 给 resultstr 指针
	Convert(resultstr, str);    //转换为后缀表达式
	int i;
	for (i = 0; i < str.length() && resultstr[i] != "end"; i++) {  //如果输入有括号，转换为后缀之后，括号会去掉，字符串个数减少
		cout << resultstr[i];   //输出后缀表达式
	}

	Complex result;   //result用于接收复数四则运算结果
	result = Compute(resultstr, i);     //i为后缀表达式字符串个数  
	cout << endl << "计算结果为：";
	result.PrintComplex();

	system("pause");
	return 0;

}
