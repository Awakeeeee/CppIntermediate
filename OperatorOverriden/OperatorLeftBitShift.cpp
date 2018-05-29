#include <iostream>
#include <string>

using namespace std;

class Item
{
public:
	int id;
	string name;
public:
	Item() {};
	Item(int id, string name) :id(id), name(name) {};
	void printItem()
	{
		cout << to_string(id) << " : " << name << endl;
	}
	//为cout << Item类型的<<定义overriden operator
	//第一个传参为<<左边项, 第二个传参为<<右边项
	
	//为什么必须要加friend
	//因为friend标记的方法[不是]类的成员
	//类的成员方法，向python一样，实际上有一个隐藏的第一个传参 --> 类的实例自己this
	//而<<的第一个传参需要的是ostream的输出流
	//这里只是选择在类里面把friend方法给实现了
	friend ostream& operator<<(ostream& output, const Item& other)
	{
		output << other.id << " : " << other.name << endl;
		return output;
	}

	//类比=
	//=运算符需要的第一个参数就是本身this，所以可以不标记为friend
	const Item& operator=(const Item& other)
	{
		this->id = other.id;
		this->name = other.name;
		return *this;
	}
};

int main33()
{
	Item t1 = Item(0, "Sword of ash");
	Item t2 = Item(1, "Helmet of fire");

	//<<和+的区别: <<是从左向右执行的,而+是从右向左
	//<<和+的共同点: 都是接收两个因素的运算符1+2需要有1和2, cout << "something"需要有ostream cout和内容string
	int a = 1 + (2 + 3);
	//cout是一个ostream类型,首先第一个string传入ostream返回一个新的ostream,然后第二个string在传入,最后是\r\n
	cout << "first into cout ostream" << "second into output ostream" << endl;

	cout << t1 << t2 << endl;

	system("PAUSE");
	return 0;
}