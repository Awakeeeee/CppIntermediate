#include <iostream>
#include <string>

using namespace std;

int test1()
{
	return 3;
}

int rref(int && rref)
{
	return rref;
}

//一个解释:
//lvalue: A value that resides in memory(heap or stack) and addressable.
//rvalue : A value that's not lvalue.
//一个没有地址的value是怎么回事?
//我的理解: rvalue不是没有地址, 而是临时变量像在int a = test1()表达式结束后马上就消失了, 甚至在下一行就消失了, 所以去拿他的
//地址毫无意义, stack上的变量有时也称为临时变量, 但好歹是在作用域之后才被销毁, 作用于之内他的地址还是有意义的

//可以取Lvalue的reference
//不可以取Rvalue的reference

//临时变量属于Rvalue
//rvalue右值是一个临时对象,如果没有被绑定到引用,在表达式结束时就会被废弃
int main88()
{
	int a = 1;
	int b = a; //lvalue可以当作rvalue来使用, 并且这种情况下用的是lvalue的值



	int val = 5; //val is a LValue
	int *pint = &val; //OK
	//int *pint = &5; //ERROR: &Expression must be a lvalue


	/*
	// 前缀形式：
	int& int::operator++()
	{
		*this += 1;
		return *this;
	}

	//后缀形式:
	const int int::operator++(int)
	{
		int oldValue = *this;
		++(*this);
		return oldValue;
	}
	*/
	pint = &(++val); //前缀++返回一个lvalue, 就是值+1以后的val
	//pint = &(val++); //后缀++先使用一个临时保存的原值, 属于rvalue, 不能取他的ref



	//pint = &test1(); //方法返回值是临时变量, 属于rvalue, 不能直接获得ref


	//int &pt = test1();
	//保持一个temp rvalue之一:
	//最普通的做法就是把他保存在一个lvalue中
	int t = test1();


	//保持一个temp rvalue之二:
	//如果你保证临时值不变(const), 那么可以把他保存在lvalue reference中
	//这叫绑定一个rvalue到const lvalue reference
	//应用:普通copy constructor
	const int &pt = 5;


	//Lvalue reference就是正常的reference
	int save_temp = test1();
	int &ref_l = save_temp;
	//保持一个temp rvalue之三:
	//Rvalue reference是C++11中引入的新概念, 符号&&
	//应用:Move Constructor
	int &&ref_r = 3;
	cout << &ref_r << endl;
	//右值引用我的理解:
	//定义像rref这样的方法, 就可以标记方法需要一个右值引用, 传入的值就可以直接用, 而不经过copy临时传入值, 再销毁临时传入值的过程
	rref(test1());

	system("PAUSE");
	return 0;
}