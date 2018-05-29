#include <iostream>
#include <string>
#include "PropertyBase.h"

using namespace std;
using namespace qiqicppintermediate;

class Item
{
protected:
	int id;
	string name;
public:
	Item() {}
	Item(int id, string name) :id(id), name(name) {}
};




class Equipment : public Item //C# difference, need to mark public in order to use polymorphism
{
protected:
	float armor;
public:
	Equipment():Item() {}	//call base class constructor
	Equipment(int id, string name, float armor) :Item(id, name), armor(armor) {}
};



void templateMethod()
{
	cout << "Calling non template version of method" << endl;
}
template<class T>
void templateMethod(T passin)
{
	cout << "Calling template version of method" << endl;
	cout << passin << endl;
}

template<class T>
T mustSpecifyT()
{
	T ins = T();
	return ins;
}

int main()
{
	PropertyBase<string, int> pb("yesyes", 5);
	pb.print();

	PropertyBase<Item, Item> pbi(Item(1, "Sword of ash"), Equipment(2, "Helmet of fire", 100.0));
	////如果Item类的print方法有问题, 那么运行时才会报错
	//pbi.print();

	templateMethod();
	templateMethod<string>("overload it");

	//mustSpecifyT<>(); //必须指明类型, 不能只指明是template的overload
	string see = mustSpecifyT<string>();
	cout << see << "!" << endl;

	system("PAUSE");
	return 0;
}