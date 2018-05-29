#include <iostream>
#include <string>
#include <functional>

using namespace std;

int fAdd(int a, int b)
{
	return a + b;
}

void useSTF(function<int(int, int)> callable, int param1, int param2)
{
	cout << callable(param1,param2) << endl;
}

//Standard Function Type, 指任何'callable', 包括lambda, function pointer, functor
//Syntax, function<返回类型(传入值)> -- function<int(string, int)>
int main5()
{
	//Standard Function Type
	function<int(int, int)> stf;
	//可以是一个方法
	stf = fAdd;
	cout << stf(1, 2) << endl;
	//可以是方法指针
	int(*pf)(int, int) = fAdd;
	stf = pf;
	cout << stf(1, 2) << endl;
	//可以是lambda表达式
	stf = [](int a, int b) {return a + b; };
	cout << stf(1, 2) << endl;
	//可以是Functor
	class functor
	{
	public:
		int operator()(int a, int b)
		{
			return a + b;
		}
	} ftr;
	stf = ftr;
	cout << stf(1, 2) << endl;



	//那么如果一个方法的传入值定义的是需要一个standard function type, 那么以上所有类型都可以正确传入
	useSTF(pf, 1, 2);
	useSTF([](int a, int b) {return a + b; }, 1, 2);
	useSTF(ftr, 1, 2);

	getchar();
	return 0;
}