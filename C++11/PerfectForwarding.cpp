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

//��������, ������鷽����ʹ�ô���ֵʱ, �ǰ���ֵ������ֵ�Դ���
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
	//���ʽ, ���¶���expression
	//a + b
	//a = 1
	//5
	//func(2, true)

	//===========statement==========
	//�ɷֺŸ�����ÿ�����, statement������expression����
	42;
	;
	int a;
	a = 5;
	if (a == 4)
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	//==========expression����Ϊ(C++11)============
	//lvalue
	//rvalue
	//xvalue
	//gvalue
	//prvalue

	//lvalue
	//lvalue�����õ���ַ
	//һ������lvalue reference�ķ����ĵ��ý����һ��lvalue
	Test t;
	Test *tp = &func_return_lr();

	//gvalue
	//����xvalue��lvalue

	//rvalue
	//����xvalue��prvalue

	//xvalue
	//xvlaueһ����һ��rvalue, ��˿��Ե���ֵ��, �Ҳ�����ֱ��ȡ��ַ
	//xvalue���ض�����ֵ���ʽ, ���緵����ֵ���õķ���
	func_return_rr();

	//prvalue
	//����ֵ, �������ط��������͵ķ���
	5;
	func_return_r();

	//=======reference collapse ���ñ���============
	//�񷽷��д����expression����, ��һ���Ƿ����жԴ����expression������
	//���뷽���Ĳ���������local varaibel�Դ�, ��˶���lvalue
	//����C++��һϵ�й���:

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

	//===========perfect forwarding ����ת��==================
	//���reference collapse����, �����������expression���;��Ƿ���ʹ��expression������, ��ô��������ת��
	//ʹ��forward<T>expression, ��ô���������ֵ, ʹ�õľ�����ֵ
	func_forward(Test());


	//TODO ��Щ������ɶ��??????????
	//The important thing to remember is that, if you have a function which receives an rvalue reference 
	//and calls another function which takes an rvalue reference, you need to put the function argument 
	//inside a call to std::forward() to make sure it is passed as an rvalue reference.

	system("PAUSE");
	return 0;
}