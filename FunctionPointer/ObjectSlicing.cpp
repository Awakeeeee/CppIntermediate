#include <iostream>
#include <string>
using namespace std;

class parent
{
public:
	parent() { cout << "parent constructor" << endl; };
	parent(const parent& other) { cout << "parent copy construtor" << endl; };
	virtual void print()
	{
		cout << "parent" << endl;
	}
};

class child : public parent
{
private:
	int num;
public:
	child() {};
	child(int num) :num(num) { cout << "child constructor" << endl; };
	child(const child& other) 
	{ 
		cout << "child copy constructor" << endl;
		this->num = other.num;
	}
	void print()
	{
		cout << num << "child" << endl;
	}
};

int main()
{
	//编译过程:
	//child的constructor被调用，其中第一步是调用默认parent的constructor，把成员变量设为默认值
	//然后child constructor实现自己的初始化，把num设为5，child construct结束
	//接着p1=c1调用parent的copy constrcutor，因为有自定义cc，所以调用那个cc/
	//这是parent的cc，只知道复制parent中的成员，传入的child中多余的num会被忽略

	//*****(即Object Slicing: parent实例用child来赋值时, child中private的部分被忽略的情况), 这里没有利用多态特性******
	child c1(5);
	parent p1 = c1; //object slicing
	p1.print();	//parent

	//这是通常情况下对多态的利用: 一系列parent是不同child类型并且各自执行child中对方法的override
	//一旦使用引用&或指针*，多态特性就会介入(?)
	//这代表虽然p2, p3是parent类型，但是print是child的版本，print中使用child的private member也可以

	//**********没有Object Slicing, 是正确的做法***********
	parent &p2 = c1;	//no log of 'child copy constructor'
	p2.print();	//child

	//现在理解的话p3是一个指向parent的指针, 而真正指向的对象不一定是parent类型也可以是子类, 这里就是这个情况
	parent *p3 = &c1;
	p3->print(); //child

	system("PAUSE");
	return 0;
}