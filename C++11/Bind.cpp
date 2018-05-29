#include <iostream>
#include <string>
#include <functional>

using namespace std;
using namespace placeholders;

int add(int a, int b, int c)
{
	cout << a << "," << b << "," << c << endl;
	return a + b + c;
}

void use(function<int(int, int, int)> stdfunc)
{
	stdfunc(11,22,33);
}

int main545()
{
	//对Bind的粗略认识
	//1. 用来使用更多手段操作传入参数
	//2. 一般方法中不能定义方法, 但用bind可以模拟类似的过程

	//使用placeholders namespace以后, 可以用_代表这是一个placeholder参数
	//数字的意义, _2表示, 第1个传参是实际传参的第2个值 --> 88
	auto bindfunc = bind(add, _2, _3, _1);
	bindfunc(77, 88, 99);

	//第2个参数总是50, 第1个和第3个看实际传参
	auto bindfunc2 = bind(add, _3, 50, _1);
	bindfunc2(33, 44, 55);

	//3. bind结果也是一个callable, 因此可以用在类型符合的standard fucntion处
	use(bindfunc);

	system("PAUSE");
	return 0;
}