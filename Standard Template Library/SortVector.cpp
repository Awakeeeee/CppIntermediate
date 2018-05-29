#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Item
{
private:
	int id;
	string name;
public:
	Item() {};
	Item(int id, string name) :id(id), name(name) {};
	string print()
	{
		return to_string(id) + " : " + name;
	}

	bool operator<(const Item& other) const
	{
		return this->id < other.id;
	}

	//friend - ���������������涨�壬���ҿ��Է��ʸ����˽������
	friend bool compare(Item &a, Item &b);
};

bool compare(Item &a, Item &b)
{
	return a.id < b.id;
}

int main()
{
	//��Ϊvector��Ԫ���ǰ�����˳�����ģ���˴���sort������
	vector<Item> items;
	items.push_back(Item(3, "Sword of Ash"));
	items.push_back(Item(1, "Helmet of Fire"));
	items.push_back(Item(2, "Boot of Flash"));

	//������delegateһ���ķ���ָ��
	sort(items.begin(), items.end(), compare);

	for (vector<Item>::iterator it = items.begin(); it != items.end(); it++)
	{
		cout << it->print() << endl;
	}

	system("PAUSE");
	return 0;
}