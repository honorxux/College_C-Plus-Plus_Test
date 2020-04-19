#include<string>
using namespace std;

class Complex {
private:
	double real_;
	double image_;
public:
	Complex();
	Complex(double real, double image);
	void ChangeComplex(double real, double image);		//改变复数
	void PrintComplex();	//打印复数
	friend void toComplex(Complex &x, string s);		//将字符串转化为Complex类型
	friend Complex operator+(Complex &x, Complex &y);	//"+"运算符重载
	friend Complex operator-(Complex &x, Complex &y);	//"-"运算符重载
	friend Complex operator*(Complex &x, Complex &y);	//"*"运算符重载
	friend Complex operator/(Complex &x, Complex &y);	//"/"运算符重载
};
