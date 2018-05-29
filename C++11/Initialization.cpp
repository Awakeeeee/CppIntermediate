#include <iostream>
#include <string>
#include <vector>
using namespace std;

//自定义class中使用Initializer list
class Item
{
public:
	int num1{1};	//定义时赋值也是C++11的特性
	int num2 = 2;
	int num3{3};
public:

	Item() = default;//explicitly specify default constructor here
	Item(const Item& other) = delete; //explicitly specify there is not even a default copy constructor, the instance of this class has no way to assign

	Item(initializer_list<int> il)
	{};
	Item(int i)
	{
		num1 = i;
	}
	//普通方法中也可以使用initialize list, 相当于C# params
	void print(initializer_list<int> params)
	{
		for (auto i : params)
			cout << i << endl;
	}
};

int main3()
{
	//C++98
	//在使用时临时定义一个struct or class
	struct {
		int id;
		string name;
	} s1 = { 1, "bbb" }, s2 = { 2, "ccc" };
	cout << s1.name << endl;

	vector<int> v98;
	v98.push_back(1);
	string ss98 = "init";
	char cc98[] = { "fsdfds" };
	string *pss98 = &ss98;
	string *pssn98 = NULL;
	cout << pssn98 << endl;

	//C++11
	//对任何类型使用{}进行初始化, 不需要写=
	vector<int> v11{ 1,2,3 };
	string ss{ "init" };
	char cc[]{ "fsdfds" };
	string *pss{ &ss };
	string *pssn{ nullptr }; //nullptr is a new keyword introduced in C++11, which points to memeber position 0
	string *pssn2{};
	cout << pssn << endl;
	cout << pssn2 << endl;

	Item ii{ 1,2,3,4 };
	ii.print({3,4,5,6});//params
	Item ii2(10000);
	cout << ii2.num1 << endl;
	cout << ii2.num2 << endl;

	getchar();
	return 0;
}