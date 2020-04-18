#include<iostream>
#include<string>
#include"Complex.h"
using namespace std;

Complex::Complex() :real_(0), image_(0) {};

Complex::Complex(double real, double image) :real_(real), image_(image) {};

//改变复数
void Complex::ChangeComplex(double real, double image) {
	real_ = real;
	image_ = image;
}

//打印复数
void Complex::PrintComplex() {
	if (real_ == 0 && image_ != 0) {     //实部为0  虚部不为0
		if (image_ == 1)                       //虚部为1
			cout << "i" << endl;
		else if (image_ == -1)                //虚部为 -1
			cout << "-i" << endl;
		else                                 //其他情况 输出   虚部i
			cout << image_ << "i" << endl;
	}
	else if (real_ != 0 && image_ == 0)        //实部不为0   虚部为0
		cout << real_ << endl;
	else if (real_ == 0 && image_ == 0)       //实部为0    虚部为0
		cout << "0" << endl;
	else {                                   //实部虚部都不为0
		if (image_ == 1)                         //虚部为1
			cout << real_ << "+i" << endl;
		else if (image_ == -1)                  //虚部为-1
			cout << real_ << "-i" << endl;
		else
			cout << real_ << showpos << image_ << "i" << endl;  //showpos 为显示符号  正数前面显示 ‘+’
	}

}

//将字符串转化为Complex类型
void toComplex(Complex &x, string s) {
	string temp;
	if (s == "i")          //如果字符串为 i
		x.ChangeComplex(0, 1);  //则实部为 0  虚部为  1
	else {
		int i;
		for (i = 0; i < s.length(); i++) {
			if (s[i] != 'i')                        //将数字拼接成字符串   (存在i  不存在i）
				temp.append(string(1, s[i]));
		}

		double num;
		num = atof(temp.c_str());       //atof  把ASCII字符串转化为浮点数    c_str 获取字符串首地址
		if (s[i - 1] != 'i')
			x.ChangeComplex(num, 0);   //不存在i   则实部为num  虚部为0
		else
			x.ChangeComplex(0, num);    //存在i  则实部为0 虚部为num
	}
}

//"+"运算符重载
Complex operator+(Complex &c1, Complex &c2) {
	return Complex(c1.real_ + c2.real_, c1.image_ + c2.image_);
}

//"-"运算符重载
Complex operator-(Complex &c1, Complex &c2) {
	return Complex(c1.real_ - c2.real_, c1.image_ - c2.image_);
}

//"*"运算符重载
Complex operator*(Complex &c1, Complex &c2) {
	//a+bi  c+di
	return Complex(c1.real_*c2.real_ - c1.image_*c2.image_, c1.image_*c2.real_ + c2.image_*c1.real_);
}

//"/"运算符重载
Complex operator/(Complex &c1, Complex &c2) {
	return Complex((c1.real_*c2.real_ + c1.image_*c2.image_) / (c2.real_*c2.real_ + c2.image_*c2.image_), (c1.image_*c2.real_ - c1.real_*c2.image_) / (c2.real_*c2.real_ + c2.image_*c2.image_));
}
