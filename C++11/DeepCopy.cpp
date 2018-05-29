#include <iostream>
#include <string>

using namespace std;

class Item
{
private:
	static const int SIZE = 50;
	int *arr;
public:
	Item() 
	{ 
		//use new to allocate memory
		arr = new int[SIZE];
		//use memset to set each byte memory in an bloak of memory
		memset(arr, 0, sizeof(int) * SIZE);
	};
	Item(const Item& other) 
	{ 
		//when copy, a new block of memory should be allocated, rather than two same pointers
		arr = new int[SIZE];
		//use memcpy to copy values
		memcpy(arr, other.arr, sizeof(int) * SIZE);
	};
	~Item() 
	{ 
		delete[] arr;
	};
	void setall(int val)
	{
		for (int i = 0; i < SIZE; i++)
		{
			arr[i] = val;
		}
	}
	void get(int idx)
	{
		cout << arr[idx] << endl;
	}
};


int main8()
{
	Item i1;
	i1.setall(5);
	i1.get(10);

	//this is wrong - this calls defulat constructor then = operator, no copy constructor
	//Item i3;
	//i3 = i1;

	//this is correctly using copy constructor
	Item i2 = i1;
	i2.get(10);

	system("PAUSE");
	return 0;
}