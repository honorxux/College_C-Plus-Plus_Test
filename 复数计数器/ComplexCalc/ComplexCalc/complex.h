#include<string>
using namespace std;

class Complex {
private:
	double real_;
	double image_;
public:
	Complex();
	Complex(double real, double image);
	void ChangeComplex(double real, double image);		//�ı临��
	void PrintComplex();	//��ӡ����
	friend void toComplex(Complex &x, string s);		//���ַ���ת��ΪComplex����
	friend Complex operator+(Complex &x, Complex &y);	//"+"���������
	friend Complex operator-(Complex &x, Complex &y);	//"-"���������
	friend Complex operator*(Complex &x, Complex &y);	//"*"���������
	friend Complex operator/(Complex &x, Complex &y);	//"/"���������
};
