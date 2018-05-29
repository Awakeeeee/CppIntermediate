#include <iostream>
#include <string>

using namespace std;

class Item
{
public:
	Item() { cout << "Item constructor" << endl; };
	Item(const Item& other) { cout << "Item copy constructor" << endl; };
	~Item() { cout << "Item destructor" << endl; };
	Item& operator=(const Item& other)
	{
		cout << "Item = operator" << endl;
	}
};

Item returnObj()
{
	return Item();
}

void wrapper()
{
	Item i = returnObj();
}

int main7()
{
	//��������:
	//returnObj������ʵ����һ��item, ����item constructor
	//�������ʵ��, ���ڷ���, ����item copy constructor
	//ԭʵ������, ����item destructor
	//���صĿ�����ֵ��i, ����item copy constructor
	//����������, ����item destructor
	//wrapper�����򳬳�, i������, ����item destructor
	//--------------------
	//����ʵ��û���м�����Ĳ���, ����compiler�����Ż�, ��Ϊreturn type optimization/elision
	wrapper();

	system("PAUSE");
	return 0;
}