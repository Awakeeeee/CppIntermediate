#include <iostream>
#include <map>
#include <string>
using namespace std;

int main7()
{
	multimap<int, string> mmap;
	//mmap[1] = "doggy"; //this is not valid in multi map
	mmap.insert(make_pair(3, "doggy"));
	mmap.insert(make_pair(3, "big doggy"));
	mmap.insert(make_pair(1, "cat"));
	mmap.insert(make_pair(2, "lion"));
	mmap.insert(make_pair(4, "big tiger"));
	mmap.insert(make_pair(4, "tiger"));

	//common loop, it is OK to have same keys
	for (multimap<int, string>::iterator it = mmap.begin(); it != mmap.end(); it++)
	{
		cout << it->first << " : " << it->second << endl;
	}

	cout << endl;

	for (multimap<int, string>::iterator it = mmap.find(3); it != mmap.end(); it++)
	{
		cout << it->first << " : " << it->second << endl;
	}

	cout << endl;

	//pair.first = the first 3 in mmap, pair.second = the last 3 in mmap
	pair<multimap<int, string>::iterator, multimap<int, string>::iterator> pit = mmap.equal_range(3);
	for (multimap<int, string>::iterator it = pit.first; it != pit.second; it++)
	{
		cout << it->first << " : " << it->second << endl;
	}

	system("PAUSE");
	return 0;
}