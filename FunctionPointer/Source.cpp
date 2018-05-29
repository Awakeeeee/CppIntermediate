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
	typedef int myInt; //����myInt��int���͵ı���
	myInt ii = 5;
	typedef bool(*fpAlias)(int, string); //����fpAlias���������ָ�����͵ı���
	fpAlias pf; //����൱������Ķ���
	//end of typedef notes

	//Ϊ�˱����д���ؿ�ָ��ķ���һ��, �����ű�������һ����pf�ķ���ָ��
	//(*pf) - function pointer name
	//bool - function return type
	//(int,string) - function params
	bool(*pf)(int, string);

	pf = solidmethod;
	//��ͬ��
	//pf = &solidmethod;

	pf(3, "sword");
	//�������ͨ����һ�����÷���ָ��, ��ͬ��
	//(*pf)(3, "sword");

	//Callback, ��C#�д�������delegateʵ��, ���ﴫ�˷���ָ��
	receivepf(pf);

	system("PAUSE");
	return 0;
}