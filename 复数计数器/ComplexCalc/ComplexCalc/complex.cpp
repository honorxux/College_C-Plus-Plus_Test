#include<iostream>
#include<string>
#include"Complex.h"
using namespace std;

Complex::Complex() :real_(0), image_(0) {};

Complex::Complex(double real, double image) :real_(real), image_(image) {};

//�ı临��
void Complex::ChangeComplex(double real, double image) {
	real_ = real;
	image_ = image;
}

//��ӡ����
void Complex::PrintComplex() {
	if (real_ == 0 && image_ != 0) {     //ʵ��Ϊ0  �鲿��Ϊ0
		if (image_ == 1)                       //�鲿Ϊ1
			cout << "i" << endl;
		else if (image_ == -1)                //�鲿Ϊ -1
			cout << "-i" << endl;
		else                                 //������� ���   �鲿i
			cout << image_ << "i" << endl;
	}
	else if (real_ != 0 && image_ == 0)        //ʵ����Ϊ0   �鲿Ϊ0
		cout << real_ << endl;
	else if (real_ == 0 && image_ == 0)       //ʵ��Ϊ0    �鲿Ϊ0
		cout << "0" << endl;
	else {                                   //ʵ���鲿����Ϊ0
		if (image_ == 1)                         //�鲿Ϊ1
			cout << real_ << "+i" << endl;
		else if (image_ == -1)                  //�鲿Ϊ-1
			cout << real_ << "-i" << endl;
		else
			cout << real_ << showpos << image_ << "i" << endl;  //showpos Ϊ��ʾ����  ����ǰ����ʾ ��+��
	}

}

//���ַ���ת��ΪComplex����
void toComplex(Complex &x, string s) {
	string temp;
	if (s == "i")          //����ַ���Ϊ i
		x.ChangeComplex(0, 1);  //��ʵ��Ϊ 0  �鲿Ϊ  1
	else {
		int i;
		for (i = 0; i < s.length(); i++) {
			if (s[i] != 'i')                        //������ƴ�ӳ��ַ���   (����i  ������i��
				temp.append(string(1, s[i]));
		}

		double num;
		num = atof(temp.c_str());       //atof  ��ASCII�ַ���ת��Ϊ������    c_str ��ȡ�ַ����׵�ַ
		if (s[i - 1] != 'i')
			x.ChangeComplex(num, 0);   //������i   ��ʵ��Ϊnum  �鲿Ϊ0
		else
			x.ChangeComplex(0, num);    //����i  ��ʵ��Ϊ0 �鲿Ϊnum
	}
}

//"+"���������
Complex operator+(Complex &c1, Complex &c2) {
	return Complex(c1.real_ + c2.real_, c1.image_ + c2.image_);
}

//"-"���������
Complex operator-(Complex &c1, Complex &c2) {
	return Complex(c1.real_ - c2.real_, c1.image_ - c2.image_);
}

//"*"���������
Complex operator*(Complex &c1, Complex &c2) {
	//a+bi  c+di
	return Complex(c1.real_*c2.real_ - c1.image_*c2.image_, c1.image_*c2.real_ + c2.image_*c1.real_);
}

//"/"���������
Complex operator/(Complex &c1, Complex &c2) {
	return Complex((c1.real_*c2.real_ + c1.image_*c2.image_) / (c2.real_*c2.real_ + c2.image_*c2.image_), (c1.image_*c2.real_ - c1.real_*c2.image_) / (c2.real_*c2.real_ + c2.image_*c2.image_));
}
