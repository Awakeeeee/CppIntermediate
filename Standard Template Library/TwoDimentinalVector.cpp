#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main2()
{

	int arr[3][4];
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			arr[row][col] = 1;
			cout << arr[row][col];
		}
		cout << endl;
	}

	cout << endl;

	//vector constructor: vector(number of elements, element init value)
	vector< vector<int> > grid(3, vector<int>(4, 0));

	//copy
	vector<int> c = grid[0];
	c.insert(c.begin(), 2);
	//reference
	vector<int> *v = &grid[0];
	v->insert(v->begin(), 1);

	for (int row = 0; row < grid.size(); row++)
	{
		for (int col = 0; col < grid[row].size(); col++)
		{
			cout << grid[row][col];
		}
		cout << endl;
	}

	system("PAUSE");
	return 0;
}