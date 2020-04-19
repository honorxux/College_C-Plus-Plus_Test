#include<iostream>
#include<string>
#include"Complex.h"
#include"Stack.h"
using namespace std;

void Convert(string resultstr[], string str);		//�����ʽת��Ϊ��׺���ʽ
Complex Operate(Complex x, string op, Complex y);	//���������
Complex Compute(string str[], int length);			//�����׺���ʽ


//�����ʽת��Ϊ��׺���ʽ
void Convert(string resultstr[], string str) {
	Stack<string> str_stack(str.length());   // ջ������Ϊ string
	int j = 0;
	for (int i = 0; i < str.length(); i++) {      //���� 
		if (str[i] == '(') {                     //����������� ��ջ
			str_stack.Push(string(1, str[i]));  //  string(1,s[i])��ʾ����һ�� s[i]�ַ����ַ���   ��Ϊջ������Ϊ string
			continue;
		}
		else if (str[i] == ')') {           //�����������
			string s;
			while (true) {
				str_stack.Pop(s);           //ջ�����ݳ�ջ��ֱ������������ 
				if (s == "(")
					break;
				resultstr[j++] = s;
			}
			continue;
		}
		else if (str[i] == '*' || str[i] == '/') {    //�����  *  /
			string s;
			while (true) {
				if (!str_stack.StackTop(s)) {    //���ջΪ�գ�����ջ
					str_stack.Push(string(1, str[i]));
					break;
				}
				else {
					if (s == "*" || s == "/") {   //���ջ��Ϊ * / �� ջ��Ԫ�س�ջ
						str_stack.Pop(s);
						resultstr[j++] = s;
					}
					else {                         //������� ����ջ
						str_stack.Push(string(1, str[i]));
						break;
					}
				}
			}
			continue;
		}
		else if (str[i] == '+' || str[i] == '-') {  //����� + -
			string s;
			while (true) {
				if (!str_stack.StackTop(s)) {   //ջΪ�� ��ջ
					str_stack.Push(string(1, str[i]));
					break;
				}
				else {
					if (s == "(") {                  //ջ��Ϊ ������  ��ջ
						str_stack.Push(string(1, str[i]));
						break;
					}
					else {                         //�������ջ��Ԫ�س�ջ
						str_stack.Pop(s);
						resultstr[j++] = s;
					}
				}
			}
			continue;
		}
		else {             //������� �� ��Ϊ +-*/ ����  ��     ���ֻ��� i
			string s;
			while (i != str.length() && str[i] != '+'&&str[i] != '-'&&str[i] != '*'&&str[i] != '/'&&str[i] != ')') {
				s.append(string(1, str[i++]));   //  appendƴ���ַ���     ��i�����鲿���棩
			}
			resultstr[j++] = s;
			i--;
			continue;
		}
	}

	while (!str_stack.StackEmpty()) {       //������ϣ����ջ���գ�����Ԫ�����γ�ջ
		string s;
		str_stack.Pop(s);
		resultstr[j++] = s;
	}
	if (j != str.length()) {     //���Ų����˺�׺���ʽ��    ������������ţ�ת��Ϊ��׺֮�����Ż�ȥ�����ַ�����������
		resultstr[j] = "end";    //end ����ʶ �����Ż����ַ�ƴ�ӵ�����£���׺���ʽ�Ľ���
	}
}

//���������
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

//�����׺���ʽ
Complex Compute(string str[], int length) {
	Stack<Complex> s(length);	//��ģ��  �ݴ������
	string op;	//�ݴ������
	Complex x, y;	//����������
	for (int i = 0; i < length; i++) {  //����
		if (str[i] != "+"&&str[i] != "-"&&str[i] != "*"&&str[i] != "/") {   //�����Ϊ ������
			Complex cnum;
			toComplex(cnum, str[i]);      //���ַ���ת��Ϊ��������   2+3i ����>  ��2+0i)+(0+3i)     ÿ��string���൱��һ�������� 2+3i�൱����������
			s.Push(cnum);
		}
		else   //Ϊ������   ������֮ǰ����������������ջ��                 ��׺���ʽ�ļ���
		{
			op = str[i];

			Complex x, y;
			s.Pop(y);	//ȡ������2
			s.Pop(x);	//ȡ������1
			s.Push(Operate(x, op, y));	//����ǰ��������ջ
		}
	}
	Complex result;		//���ܼ�����
	s.Pop(result);     //��׺���ʽ���һλ�϶�Ϊ�������� �������֮��ջ��ֻ��һ��Ԫ�أ���Ԫ�ؾ������ս��
	return result;
}

int main() {
	string str;
	cout << "�����������ʽ��";
	cin >> str;
	cout << "ת��Ϊ��׺���ʽΪ��";

	string* resultstr = new string[str.length()];     //��̬�����СΪ str.length()�Ŀռ� �� resultstr ָ��
	Convert(resultstr, str);    //ת��Ϊ��׺���ʽ
	int i;
	for (i = 0; i < str.length() && resultstr[i] != "end"; i++) {  //������������ţ�ת��Ϊ��׺֮�����Ż�ȥ�����ַ�����������
		cout << resultstr[i];   //�����׺���ʽ
	}

	Complex result;   //result���ڽ��ո�������������
	result = Compute(resultstr, i);     //iΪ��׺���ʽ�ַ�������  
	cout << endl << "������Ϊ��";
	result.PrintComplex();

	system("pause");
	return 0;

}
