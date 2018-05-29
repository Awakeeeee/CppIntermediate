#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include <map>
using namespace std;

template<class T>
class Item
{
public:
	Item() {};
};

//返回auto
//附加了'trailing type'
auto method(int i) -> int
{
	return i;
}

//对于template method, trailing type可是用decltype表示
//decltype中可以传入表达式
template<class T, class S>
auto templatemethod(T t, S s) -> decltype(t + s)
{
	return t + s;
}


int main1()
{
	//typeid(obj)获得obj的类型, 有点类似C# typeof()
	string s;
	//C++ Name Mangling: 因为OO中方法重载等特性, 有时typeif并不只返回一个简单的type名, 如int, 而是要附带许多其他信息来确认这个
	//obj是哪个类的哪个版本, 这种情况叫Name Mangling
	//另一解释: 用于compiler向linker提供更多信息而传递准确的语义
	cout << typeid(s).name() << endl;
	
	//decltype()
	double d;
	decltype(d) dd; //通过实体d取得类型,并且可以在不写这个类型名的情况下使用这个类型 ---> 现在decltype(d)就等同于说double
	cout << typeid(dd).name() << endl;
	
	//auto自动识别类型
	map<int, string> m;
	m.insert(make_pair(1, "fsdf"));
	m.insert(make_pair(232, "xcvxcvc"));
	m.insert(make_pair(123, "qweqwe"));
	for (auto t = m.begin(); t != m.end(); t++)
		cout << t->first << t->second << endl;
	
	cout << method(1) << endl;
	cout << templatemethod(3, 5) << endl;

	system("PAUSE");
	return 0;
}