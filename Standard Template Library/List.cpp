#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main123()
{
	//vector<int> v;
	//v.push_back(1);
	//v.push_back(2);
	//cout << (&v[0] + 1) << endl;
	//cout << &v[1] << endl;

	//C++中list是linked list
	//list元素有顺序， 会按照构建顺序排列，而不是像map一样自动从新按照key进行排序
	//元素内存不连续，不能通过[idx]来取元素
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_front(0);

	list<int>::iterator bit = l.begin();
	bit++; //在[1]位置插入一个元素，原[1]位置元素挤到后一个去
	//l.insert(bit, 5);
	//cout << *bit << endl; //输出1，bit仍然指向insert之前的内存地址，也就是1的地址

	list<int>::iterator eit = l.begin();
	eit++;
	//l.erase(eit); //删除[1]，list变为02，而eit仍然指向1的内存
	eit = l.erase(eit); //删除[1]，list变为02，而eit更新为新的[1] = 2
	cout << *eit << endl; //undefined result

	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << endl;
	}

	system("PAUSE");
	return 0;
}