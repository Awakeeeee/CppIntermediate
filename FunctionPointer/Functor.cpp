#include <iostream>
#include <string>
using namespace std;

//Functor��һ����, ͨ������ඨ����()���operator, ʹ��ʹ��ʱ���������񷽷��ĵ���, ������ӵ���������, ����̳�

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
	//ʵ��һ��functor
	TesterA ta;
	//���������񷽷��ĵ���
	cout << ta("doggy") << endl;

	//�򷽷��д���һ��testerʵ��, ���򷽷��д���һ��function pointer���������
	//C#����delegateʵ��, C++�п��Դ�functor
	check("kkk", ta);

	system("PAUSE");
	return 0;
}