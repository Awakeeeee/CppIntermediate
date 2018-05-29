#include <iostream>
#include <string>
using namespace std;

bool solidmethod(int i, string s)
{
	cout << i << ":" << s << endl;
	return true;
}

void receivepf(bool(*pf)(int ,string))
{
	int i = 5;
	string s = "test";
	if (pf(i, s))
	{
		cout << "successfully executed" << endl;
	}
	else 
	{
		cout << "execute fails" << endl;
	}
}

int main1()
{
	//typedef
	typedef int myInt; //现在myInt是int类型的别名
	myInt ii = 5;
	typedef bool(*fpAlias)(int, string); //现在fpAlias是这个方法指针类型的别名
	fpAlias pf; //这就相当于下面的定义
	//end of typedef notes

	//为了避免和写返回空指针的方法一样, 用括号表明这是一个叫pf的方法指针
	//(*pf) - function pointer name
	//bool - function return type
	//(int,string) - function params
	bool(*pf)(int, string);

	pf = solidmethod;
	//等同于
	//pf = &solidmethod;

	pf(3, "sword");
	//像调用普通方法一样调用方法指针, 等同于
	//(*pf)(3, "sword");

	//Callback, 在C#中传方法用delegate实现, 这里传了方法指针
	receivepf(pf);

	system("PAUSE");
	return 0;
}