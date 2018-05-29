#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Test
{};

Test func_return_r()
{
	cout << "function returns a PRvalue" << endl;
	return Test();
}

Test& func_return_lr()
{
	cout << "The result of function that return a Lvalue reference is a Lvalue" << endl;
	Test t;
	return t;
}

Test&& func_return_rr()
{
	cout << "The result of function that return a Rvalue reference is a Rvalue" << endl;
	return Test();
}

template<typename T>
void func_rr(T&& t)
{
	check(t);
}

template<typename T>
void func_lr(T& t)
{
	check(t);
}

template<typename T>
void func_forward(T&& t)
{
	check(forward<T>(t));
}

//辅助方法, 用来检查方法内使用传入值时, 是按右值还是左值对待他
void check(Test& v)
{
	cout << "use expression as lvalue" << endl;
}
void check(Test&& v)
{
	cout << "use expression as rvalue" << endl;
}

int main3232()
{
	//============expression===========
	//表达式, 以下都是expression
	//a + b
	//a = 1
	//5
	//func(2, true)

	//===========statement==========
	//由分号隔开的每个语句, statement常常由expression构成
	42;
	;
	int a;
	a = 5;
	if (a == 4)
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	//==========expression分类为(C++11)============
	//lvalue
	//rvalue
	//xvalue
	//gvalue
	//prvalue

	//lvalue
	//lvalue可以拿到地址
	//一个返回lvalue reference的方法的调用结果是一个lvalue
	Test t;
	Test *tp = &func_return_lr();

	//gvalue
	//包括xvalue和lvalue

	//rvalue
	//包括xvalue和prvalue

	//xvalue
	//xvlaue一定是一个rvalue, 因此可以当右值用, 且不可以直接取地址
	//xvalue是特定的右值表达式, 比如返回右值引用的方法
	func_return_rr();

	//prvalue
	//纯右值, 包括返回非引用类型的方法
	5;
	func_return_r();

	//=======reference collapse 引用崩塌============
	//像方法中传入的expression类型, 不一定是方法中对待这个expression的类型
	//传入方法的参数被当成local varaibel对待, 因此都是lvalue
	//这是C++的一系列规则:

	//&& + & = &
	Test v;
	auto&& v1 = v;
	check(v1);
	//&& + && = &&
	Test&& v2 = Test();
	check(v2);
	//& + & = &
	Test& v3 = v;
	check(v2);
	//& + && = &
	Test& v4 = v2;
	check(v4);

	//===========perfect forwarding 完美转发==================
	//针对reference collapse问题, 如果方法传入expression类型就是方法使用expression的类型, 那么就是完美转发
	//使用forward<T>expression, 那么传入的是右值, 使用的就是右值
	func_forward(Test());


	//TODO 这些东西有啥用??????????
	//The important thing to remember is that, if you have a function which receives an rvalue reference 
	//and calls another function which takes an rvalue reference, you need to put the function argument 
	//inside a call to std::forward() to make sure it is passed as an rvalue reference.

	system("PAUSE");
	return 0;
}