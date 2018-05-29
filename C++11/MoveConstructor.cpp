#include <iostream>
#include <string>
#include <vector>

using namespace std;


class SomeClass
{
private:
	static const int SIZE = 100;
	int *arr{nullptr};
public:
	//SomeClass() = default;
	SomeClass()
	{
		arr = new int[SIZE];
	}

	//copy constructor
	//传入值是一个用const lvalue reference绑定的rvalue, 这种情况下没有办法改变other
	//于是只能重新分配一块内存给this->arr
	SomeClass(const SomeClass& other)
	{
		cout << "copy constrcutor" << endl;
		arr = new int[SIZE];
		memcpy(arr, other.arr, sizeof(int) * SIZE);
	}

	//move constructor
	//传入值是C++11新特性: 右值引用, 赋予瞬时传入值一个引用, 并且可以改变他的内容
	//于是可以更改other.arr的内容
	SomeClass(SomeClass&& other)
	{
		cout << "move constructor" << endl;
		arr = other.arr; //arr指向copy的arr
		other.arr = nullptr; //因为other是个临时值, 不会再去用, 废弃他的arr, 避免和当前arr重复
		//整个过程就像这个item偷走了传入的item的内容, 并销毁了传入item, 本身取代了他
	}

	void operator=(const SomeClass& other)
	{
		cout << "normal operator =" << endl;
		arr = new int[SIZE];
		memcpy(arr, other.arr, sizeof(int) * SIZE);
	}

	void operator=(SomeClass&& other)
	{
		cout << "move operator =" << endl;
		//operator = is not initialization, in case the memory has already been allocated
		delete[] arr;
		arr = other.arr;
		other.arr = nullptr;
	}

	~SomeClass()
	{
		delete[] arr;
	}
};




int main33()
{
	SomeClass i1;
	SomeClass i2 = i1; // copy constructor

	i2 = SomeClass();

	//这个为什么没有调用move constructor ----- L62 因为compiler的优化
	SomeClass i3{ SomeClass() };

	vector<SomeClass> v;
	//如果定义了move construtor就会调用, 否则就会调用copy constructor
	v.push_back(SomeClass());

	system("PAUSE");
	return 0;
}