#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

class Item
{
public:
	int id;
	string name;
public:
	Item();
	Item(int id, string name) :id(id), name(name) {}
	Item(const Item &other)
	{
		this->id = other.id;
		this->name = other.name;
		cout << "Item copy constructor called" << endl;
	}
	~Item()
	{
		cout << "Item destructor called" << endl;
	}
};

int main321()
{
	stack<Item> stc;

	//push����һ��Itemʵ�壬���Ȼ�copyһ��ʵ�岢����stack��Ȼ�����ٴ����Itemʵ��
	stc.push(Item(3, "Sworld of Ash"));
	//push����һ�����ã���Ȼ��copyһ�ݴ��������ʵ�壬�������������ã����������ʵ�岻�ᱻ����
	Item &i = Item(2, "Helmet of Fire");
	stc.push(i);
	//Ӧ��ֱ�Ӵ�ʵ��������stack
	stc.push(Item(4, "Boot of Teleport"));
	stc.push(Item(1, "Boot of Shark"));
	stc.push(Item(0, "Boot of Wood"));

	cout << "----------------" << endl;

	//top����һ��ʵ�壬�����ֵ����һ��ʵ��out����ô����һ��shallow copy
	//out��topû�й�ϵ��ֻ��һ��copy
	//��ʱ��ȷ������
	Item p = stc.top();
	stc.pop(); //pop������Ԫ�أ�ֻ�����ٶ���Ԫ��
	cout << p.name << endl; //��Ϊout��top��copy���������ã���ʹtop�������ˣ�Ҳ���������ķ���out

	cout << "-------------" << endl;

	//while (stc.size() > 0)
	//{
	//	cout << stc.top().name << endl;
	//	stc.pop();
	//}

	cout << endl;
	cout << endl;

	//���������stack������ĳһ��Ԫ�أ���ô������stack�ṹ�����Ǵ��
	//����Ȼ�з�����
	stack<Item> stcCopy = stc;
	while (stcCopy.size() > 0)
	{
		if (stcCopy.top().id == 3)
		{
			cout << "Item ID 3: " << stcCopy.top().name << " is in the stack" << endl;
			break;
		}
		else {
			stcCopy.pop();
		}
	}

	cout << endl;
	while (stc.size() > 0)
	{
		cout << stc.top().name << endl;
		stc.pop();
	}

	system("PAUSE");
	return 0;
}