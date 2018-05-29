#include <iostream>
#include <string>

using namespace std;

void use(void(*pf)())
{
	pf();
}

int main6()
{
	//lambda的基本语法
	[]() {};

	//将lambda用作定义匿名函数
	auto anonymous = []() {cout << "this is anonymous" << endl; };
	void(*pf)() = anonymous;
	use(pf);

	//实际作用: 当方法逻辑很简单是, 在传入方法的地方直接传入临时定义的lambda表达式更方便
	//通常lambda表达式的返回值会自动推断
	use([]() {cout << "I am lambda" << endl; });

	//如果lambda表达式的返回值自动推断失败, 使用trailing来显式指明
	[](double a, double b) -> double
	{
		cout << a + b << endl;
		return a + b; 
	}(3, 5);

	//在lambda中使用local variable
	int a = 1;
	int b = 2;
	int c = 123;
	//=指抓取所有local variable的值
	[=]() {cout << a << b << c << endl; }();
	//&指抓取所有local variable的引用
	[&]() {a = 5; }();
	cout << a << endl;
	//默认抓取所有值, 之后又把a改成引用
	[=, &a]() {a = 6; }();
	cout << a << endl;

	//如果一个抓取值是抓取的copy值, 那么默认情况下不能在lambda中给这个量赋值, 除非标记了mutable
	[a]() mutable {a = 10; }();

	getchar();
	return 0;
}