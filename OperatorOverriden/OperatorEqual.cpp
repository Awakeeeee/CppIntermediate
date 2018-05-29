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
	//override = operator
	const Item& operator=(const Item& other)
	{
		cout << "using overriden = operator" << endl;
		//this->id = other.id;
		this->name = other.name;
		return *this;
	}
	//override copy constructor
	Item(const Item& other)
	{
		cout << "using overriden copy constructor" << endl;
		this->id = other.id;
		this->name = other.name;
	}
	//THE RULE of 3 : operator=, copy constructor, destructor, all 3 should be implemented if you implement 1 of them
	~Item() {};
};

int main2()
{
	Item t1 = Item(0, "Sword of ash");
	Item t2 = Item(1, "Helmet of fire");

	//Equivalent
	//t2 = t1;
	t2.operator=(t1);
	t2.printItem();

	//this is another use of '=' sign, but it is not invoking operator=, it is invoking copy constructor
	Item t3 = t2;
	t3.printItem();

	system("PAUSE");
	return 0;
}