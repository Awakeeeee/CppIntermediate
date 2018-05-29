#include <iostream>
#include <string>

using namespace std;

class Item
{
public:
	int id;
	string name;
public:
	Item() {};
	Item(int id, string name) :id(id), name(name) {};
	void printItem()
	{
		cout << to_string(id) << " : " << name << endl;
	}
	//Ϊcout << Item���͵�<<����overriden operator
	//��һ������Ϊ<<�����, �ڶ�������Ϊ<<�ұ���
	
	//Ϊʲô����Ҫ��friend
	//��Ϊfriend��ǵķ���[����]��ĳ�Ա
	//��ĳ�Ա��������pythonһ����ʵ������һ�����صĵ�һ������ --> ���ʵ���Լ�this
	//��<<�ĵ�һ��������Ҫ����ostream�������
	//����ֻ��ѡ�����������friend������ʵ����
	friend ostream& operator<<(ostream& output, const Item& other)
	{
		output << other.id << " : " << other.name << endl;
		return output;
	}

	//���=
	//=�������Ҫ�ĵ�һ���������Ǳ���this�����Կ��Բ����Ϊfriend
	const Item& operator=(const Item& other)
	{
		this->id = other.id;
		this->name = other.name;
		return *this;
	}
};

int main33()
{
	Item t1 = Item(0, "Sword of ash");
	Item t2 = Item(1, "Helmet of fire");

	//<<��+������: <<�Ǵ�������ִ�е�,��+�Ǵ�������
	//<<��+�Ĺ�ͬ��: ���ǽ����������ص������1+2��Ҫ��1��2, cout << "something"��Ҫ��ostream cout������string
	int a = 1 + (2 + 3);
	//cout��һ��ostream����,���ȵ�һ��string����ostream����һ���µ�ostream,Ȼ��ڶ���string�ڴ���,�����\r\n
	cout << "first into cout ostream" << "second into output ostream" << endl;

	cout << t1 << t2 << endl;

	system("PAUSE");
	return 0;
}