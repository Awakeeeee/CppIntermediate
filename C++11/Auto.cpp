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

//����auto
//������'trailing type'
auto method(int i) -> int
{
	return i;
}

//����template method, trailing type������decltype��ʾ
//decltype�п��Դ�����ʽ
template<class T, class S>
auto templatemethod(T t, S s) -> decltype(t + s)
{
	return t + s;
}


int main1()
{
	//typeid(obj)���obj������, �е�����C# typeof()
	string s;
	//C++ Name Mangling: ��ΪOO�з������ص�����, ��ʱtypeif����ֻ����һ���򵥵�type��, ��int, ����Ҫ�������������Ϣ��ȷ�����
	//obj���ĸ�����ĸ��汾, ���������Name Mangling
	//��һ����: ����compiler��linker�ṩ������Ϣ������׼ȷ������
	cout << typeid(s).name() << endl;
	
	//decltype()
	double d;
	decltype(d) dd; //ͨ��ʵ��dȡ������,���ҿ����ڲ�д����������������ʹ��������� ---> ����decltype(d)�͵�ͬ��˵double
	cout << typeid(dd).name() << endl;
	
	//auto�Զ�ʶ������
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