#include <iostream>
#include <string>

using namespace std;

class Item
{
public:
	Item() { cout << "Item constructor" << endl; };
	Item(const Item& other) { cout << "Item copy constructor" << endl; };
	~Item() { cout << "Item destructor" << endl; };
	Item& operator=(const Item& other)
	{
		cout << "Item = operator" << endl;
	}
};

Item returnObj()
{
	return Item();
}

void wrapper()
{
	Item i = returnObj();
}

int main7()
{
	//编译流程:
	//returnObj方法中实例化一个item, 调用item constructor
	//拷贝这个实例, 用于返回, 调用item copy constructor
	//原实例销毁, 调用item destructor
	//返回的拷贝赋值给i, 调用item copy constructor
	//拷贝被销毁, 调用item destructor
	//wrapper作用域超出, i被销毁, 调用item destructor
	//--------------------
	//但是实际没有中间冗余的部分, 这是compiler做的优化, 称为return type optimization/elision
	wrapper();

	system("PAUSE");
	return 0;
}