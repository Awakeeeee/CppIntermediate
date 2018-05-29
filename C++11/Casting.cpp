#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Item
{
public:
	Item() = default;
	virtual void print()
	{
		cout << typeid(*this).name() << endl;
	}
};

class Equipment : public Item
{
public:
	Equipment() = default;
	void print()
	{
		cout << typeid(*this).name() << endl;
	}
};

class Food : public Item
{
public:
	Food() = default;
	void print()
	{
		cout << typeid(*this).name() << endl;
	}
};




int main443()
{
	float f = 1.5;

	//-----继承自C语言的casting-----
	//cast
	cout << (int)f << endl;

	//----- C++ -----
	//constrcut an int by this float value
	cout << int(f) << endl;

	//static cast, if type is wrong, there will be a compile time error
	cout << static_cast<int>(f) << endl;

	Item im;
	Equipment eq;
	Food fo;

	//可以用子类的初始化一个父类, 这是多态的特性
	Item *pi = &eq;
	//反过来用父类初始化一个子类不可以直接进行, 这里需要casting
	Equipment *pe = (Equipment*)&im;
	//static_cast好处: 能给出compile time error, 比如写成一个无法转换的类型
	//坏处: 没有runtime的保护, 因此很危险, 如果调用了equipment特有的方法就会崩溃
	Equipment *pe2 = static_cast<Equipment*>(&im);

	//用static_cast将左值赋给右值引用
	Item&& pr = Item();
	Item&& pr2 = static_cast<Item&&>(*pi);


	//dynamic_cast
	//与static的不同是, 会检查runtime是否有问题, 如果有问题, cast时会返回空
	
	//需要compiler开启RTTI runtime test infomation
	//Project Properties ---> C/C++ ---> Language ---> Enable Runtime Test Infomation
	Equipment *pe3 = dynamic_cast<Equipment*>(&im);
	if (pe3 == nullptr)
	{
		cout << "dynamic cast returns null pointer" << endl;
	}


	//reinterpret_cast
	//做最少的检查, 有最大可能出现潜在问题
	//在static_cast和dynamic_cast都不可以的情况下有可能用到, 处理设计非常糟糕的API时可能用到
	//一般不会用到
	Equipment *pe4 = reinterpret_cast<Equipment*>(&im);

	system("PAUSE");
	return 0;
}