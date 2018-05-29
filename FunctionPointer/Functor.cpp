#include <iostream>
#include <string>
using namespace std;

//Functor是一个类, 通常这个类定义了()这个operator, 使得使用时看起来很像方法的调用, 但是又拥有类的特性, 比如继承

class TesterBase
{
public:
	//intent to be a Functor
	virtual bool operator()(string s) = 0;
	virtual ~TesterBase() {};
};

class TesterA : public TesterBase
{
public:
	bool operator()(string s)
	{
		return s == "doggy";
	}
};

class TesterB : public TesterBase
{
public:
	bool operator()(string s)
	{
		return s == "cat";
	}
};


void check(string s, TesterBase& tester)
{
	if (tester(s))
	{
		cout << "match!" << endl;
	}
	else 
	{
		cout << "not match!" << endl;
	}
}

int main3()
{
	//实例一个functor
	TesterA ta;
	//看起来很像方法的调用
	cout << ta("doggy") << endl;

	//向方法中传入一个tester实例, 是向方法中传入一个function pointer的替代做法
	//C#中以delegate实现, C++中可以传functor
	check("kkk", ta);

	system("PAUSE");
	return 0;
}