#include <iostream>

using namespace std;

class Something
{
private:
	int num;
	string word;
	int *arr = new int[10];
public:
	Something()
	{}
	Something(int num, string word) :num(num), word(word) {}
	
	//当方法返回这个类，向方法中用值传递传入一个类，把一个类实例赋值给另一个时，会涉及到拷贝构造器
	Something(const Something& other)
	{
		//默认拷贝构造器属于浅拷贝，把各个字段赋值
		num = other.num;
		word = other.num;
		//arr = other.arr; //XX - 如果定义中有指针(引用类型)，那么浅拷贝的直接赋值不行，两个实例里的指针将会指向同一块内存

		//自己定义拷贝构造函数，实现深拷贝 - 为引用类型开辟新空间，在新空间里存放和拷贝值一样的内容
		cout << "Custom copy constructor called" << endl;
		arr = new int[10];
		*arr = *(other.arr);
	}

	~Something() { delete[] arr; }

	void SetNum(int i)
	{
		num = i;
	}

	bool operator==(const Something& other) const
	{
		return this->num == other.num;
	}
};

int main6()
{
	Something s1(1, "ha");
	Something s2 = s1;
	s2.SetNum(3);
	if (s2 == s1)
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	system("PAUSE");
	return 0;
}