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

	//C++��list��linked list
	//listԪ����˳�� �ᰴ�չ���˳�����У���������mapһ���Զ����°���key��������
	//Ԫ���ڴ治����������ͨ��[idx]��ȡԪ��
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_front(0);

	list<int>::iterator bit = l.begin();
	bit++; //��[1]λ�ò���һ��Ԫ�أ�ԭ[1]λ��Ԫ�ؼ�����һ��ȥ
	//l.insert(bit, 5);
	//cout << *bit << endl; //���1��bit��Ȼָ��insert֮ǰ���ڴ��ַ��Ҳ����1�ĵ�ַ

	list<int>::iterator eit = l.begin();
	eit++;
	//l.erase(eit); //ɾ��[1]��list��Ϊ02����eit��Ȼָ��1���ڴ�
	eit = l.erase(eit); //ɾ��[1]��list��Ϊ02����eit����Ϊ�µ�[1] = 2
	cout << *eit << endl; //undefined result

	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << endl;
	}

	system("PAUSE");
	return 0;
}