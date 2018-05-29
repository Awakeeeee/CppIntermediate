#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main1233()
{
	set<string> st;

	//set will sort the elements
	st.insert("dog");
	st.insert("cat");
	st.insert("dog");	//no duplicate element in set

	vector<int> vr = { 4,1,3,2 };
	vr.insert(vr.begin() + 2, 0);

	for (set<string>::iterator it = st.begin(); it != st.end(); it++)
	{
		cout << *it << endl;
	}

	cout << endl;

	for (int i = 0; i < vr.size(); i++)
	{
		cout << vr[i] << endl;
	}

	system("PAUSE");
	return 0;
}