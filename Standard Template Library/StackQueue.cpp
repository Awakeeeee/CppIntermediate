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

	//push传入一个Item实体，首先会copy一个实体并加入stack，然后销毁传入的Item实体
	stc.push(Item(3, "Sworld of Ash"));
	//push传入一个引用，仍然会copy一份传入的引用实体，但是由于有引用，传入的引用实体不会被销毁
	Item &i = Item(2, "Helmet of Fire");
	stc.push(i);
	//应该直接传实体来构造stack
	stc.push(Item(4, "Boot of Teleport"));
	stc.push(Item(1, "Boot of Shark"));
	stc.push(Item(0, "Boot of Wood"));

	cout << "----------------" << endl;

	//top返回一个实体，如果赋值给另一个实体out，那么这是一个shallow copy
	//out和top没有关系，只是一个copy
	//这时正确的做法
	Item p = stc.top();
	stc.pop(); //pop不返回元素，只是销毁顶层元素
	cout << p.name << endl; //因为out是top的copy而不是引用，即使top被销毁了，也可以正常的访问out

	cout << "-------------" << endl;

	//while (stc.size() > 0)
	//{
	//	cout << stc.top().name << endl;
	//	stc.pop();
	//}

	cout << endl;
	cout << endl;

	//如果你想在stack中搜索某一个元素，那么当初用stack结构可能是错的
	//但仍然有方法：
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