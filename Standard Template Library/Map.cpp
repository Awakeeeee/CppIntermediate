#include <iostream>
#include <map>
#include <string>
#include <iomanip>//precision
#include <sstream>//string stream
using namespace std;

class ItemInfo
{
public:
	string name;
	float price;
	ItemInfo()
	{}
	ItemInfo(string name, float price)
	{
		this->name = name;
		this->price = price;
	}
	string display()
	{
		stringstream f2s;
		f2s << fixed << setprecision(2) << price;
		return name + "(" + f2s.str() + " coins)";
	}
};

int main4()
{
	map<int, ItemInfo> itemDatabase;

	//map元素的顺序:map中的元素不是按照insert的先后顺序的,而是根据key排序,比如按下面的顺序插入,loop打印是的顺序是key 123
	//insert 1
	itemDatabase[3] = ItemInfo("Sowrd of Ash", 1000);
	//insert 2
	pair<int, ItemInfo> item2(2, ItemInfo("Helmet of Fire", 500));
	itemDatabase.insert(item2);
	//insert 3
	itemDatabase.insert(make_pair(1, ItemInfo("Boot of Flash", 600)));

	string cmd_end = "-exit";
	string cmd_list = "-ls";
	cout << "Input number to search an item, -exit to quit, -ls to show current database." << endl << endl;

	string input = "";
	while (true)
	{
		getline(cin, input);

		if (input == cmd_end)
			break;
		else if (input == cmd_list)
		{
			cout << "=======================" << endl;
			for (map<int, ItemInfo>::iterator it = itemDatabase.begin(); it != itemDatabase.end(); it++)
			{
				pair<int, ItemInfo> p = *it;
				cout << "Item ID " << p.first << ":" << p.second.display() << endl;
			}
			cout << "=======================" << endl;
		}
		else
		{
			int id = atoi(input.c_str());
			if (id == 0)
			{
				cout << "Invalid item ID" << endl;
			}
			else 
			{
				map<int, ItemInfo>::iterator find = itemDatabase.find(id);
				if (find == itemDatabase.end())
					cout << "Item of ID " << input << " is not in database" << endl;
				else
					cout << "Item ID " << find->first << ":" << find->second.display() << endl;
			}
		}
	}
	
	return 0;
}