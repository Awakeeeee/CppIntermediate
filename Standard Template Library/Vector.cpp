#include <iostream>
#include <string>
#include <vector>
using namespace std;

void PrintVector(vector<string> *vlist)
{
	cout << "Size: " << (*vlist).size() << endl;
	cout << "Capacity: " << (*vlist).capacity() << endl;
}

int main1()
{
	vector<string> vlist;
	//List.Add()
	vlist.push_back("cat");
	vlist.push_back("dog");
	vlist.push_back("human");

	//sizeof string is 28 here, it is the size of string object, use string.length() to get the content size
	//cout << sizeof(vlist[0]) << endl;
	//cout << vlist[0].length() << endl;
	//cout << sizeof(vlist) << endl;
	cout << vlist.capacity() << endl;

	//string a ="fsdf";
	//string *p = &a;
	//cout << sizeof(p) << endl; //sizeof a pointer is 4

	//List.Count
	//for (int i = 0; i < vlist.size(); i++)
	//{
	//	cout << vlist[i] << endl;
	//}

	//for (vector<string>::const_iterator it = vlist.begin(); it != vlist.end(); it++)
	//{
	//	//*it = "yea?"; //const iterator not allowed
	//	cout << *it << endl;
	//}

	for (int i = 0; i < 100; i++)
	{
		vlist.push_back("add");
	}
	cout << vlist.capacity() << endl;

	cout << "Size是vector数组的实际内存占用" << endl;
	cout << "Capacity是预估的数组容量, 与size大小有关" << endl;

	vlist.clear();
	PrintVector(&vlist);
	cout << "Clear只清空size, 不修改capacity" << endl;

	vlist.resize(10);
	PrintVector(&vlist);
	cout << "Resize只修改size不修改capacity" << endl;

	vlist.reserve(1000);
	PrintVector(&vlist);
	cout << "Reserver是手动指定capacity大小" << endl;

	system("PAUSE");
	return 0;
}