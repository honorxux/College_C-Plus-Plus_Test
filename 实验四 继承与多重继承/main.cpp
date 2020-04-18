#include <iostream>
using namespace std;

class vehicle
{
	protected:
		int maxSpeed;
		int weight;
    public:
		vehicle(int m, int w)
		{
			maxSpeed = m;
			weight = w;
		}
		~vehicle( ){}
		virtual void run()  //把基类的成员函数设为virtual，其派生类的相应的函数也会自动变为虚函数
		{
			cout << "Vehicle Run " << endl;
		}
		virtual void stop()
		{
			cout << "Vehicle Stop " << endl;
		}
};

class bicycle : virtual public vehicle
{
protected:
	int height;
public:
	bicycle(int m, int w, int h) :vehicle(m, w)
	{
		height = h;
	}
	~bicycle() {};
     void run()
	{
		cout << "Bicycle Run " << endl;
	}
	 void stop()
	{
		cout << "Bicycle Stop " << endl;
	}

};

class motorcar : virtual public vehicle
{
protected:
	int seatNum;
public:
	motorcar(int m, int w, int s) :vehicle(m, w)
	{
		seatNum = s;
	}
	~motorcar() {};
	void run()
	{
		cout << "MotorCar Run " << endl;
	}
	void stop()
	{
		cout << "MotorCar Stop " << endl;
	}

};

class motorcycle : public bicycle, public motorcar
{
public:
	motorcycle(int m, int w, int h, int s):vehicle(m,w),bicycle(m,w,h),motorcar(m,w,s){}  //只执行最后的派生类对虚基类的构造函数的调用，而忽略虚基类的其他派生类对虚基类的构造函数逇调用
	~motorcycle() {}
	void run()
	{
		cout << "maxSpeed: "<<maxSpeed << endl;
		cout << "weight: "<<weight << endl;
		cout << "height: " <<height<< endl;
		cout << "seatNum: " <<seatNum<< endl;
	}
	void stop()
	{
		cout << "Motorcylce Stop " << endl;
	}

};

int main()
{
	vehicle a(180, 50);
	bicycle b(80, 30, 2);
	motorcar c(150, 80, 4);
	motorcycle d(120, 60, 1, 2);

	vehicle *p1 = &a;  //指向基类的指针在操作它的多态类对象时，会根据不同的类对象，调用其相应的函数，这个函数就是虚函数
	vehicle *p2 = &b;
	vehicle *p3 = &c;
	vehicle *p4 = &d;

	p1->run();
	p1->stop();
	p2->run();
	p2->stop();
	p3->run();
	p3->stop();
	p4->run();
	p4->stop();
	 

	system("pause");
	return 0;
}