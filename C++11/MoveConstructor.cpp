#include <iostream>
#include <string>
#include <vector>

using namespace std;


class SomeClass
{
private:
	static const int SIZE = 100;
	int *arr{nullptr};
public:
	//SomeClass() = default;
	SomeClass()
	{
		arr = new int[SIZE];
	}

	//copy constructor
	//����ֵ��һ����const lvalue reference�󶨵�rvalue, ���������û�а취�ı�other
	//����ֻ�����·���һ���ڴ��this->arr
	SomeClass(const SomeClass& other)
	{
		cout << "copy constrcutor" << endl;
		arr = new int[SIZE];
		memcpy(arr, other.arr, sizeof(int) * SIZE);
	}

	//move constructor
	//����ֵ��C++11������: ��ֵ����, ����˲ʱ����ֵһ������, ���ҿ��Ըı���������
	//���ǿ��Ը���other.arr������
	SomeClass(SomeClass&& other)
	{
		cout << "move constructor" << endl;
		arr = other.arr; //arrָ��copy��arr
		other.arr = nullptr; //��Ϊother�Ǹ���ʱֵ, ������ȥ��, ��������arr, ����͵�ǰarr�ظ�
		//�������̾������item͵���˴����item������, �������˴���item, ����ȡ������
	}

	void operator=(const SomeClass& other)
	{
		cout << "normal operator =" << endl;
		arr = new int[SIZE];
		memcpy(arr, other.arr, sizeof(int) * SIZE);
	}

	void operator=(SomeClass&& other)
	{
		cout << "move operator =" << endl;
		//operator = is not initialization, in case the memory has already been allocated
		delete[] arr;
		arr = other.arr;
		other.arr = nullptr;
	}

	~SomeClass()
	{
		delete[] arr;
	}
};




int main33()
{
	SomeClass i1;
	SomeClass i2 = i1; // copy constructor

	i2 = SomeClass();

	//���Ϊʲôû�е���move constructor ----- L62 ��Ϊcompiler���Ż�
	SomeClass i3{ SomeClass() };

	vector<SomeClass> v;
	//���������move construtor�ͻ����, ����ͻ����copy constructor
	v.push_back(SomeClass());

	system("PAUSE");
	return 0;
}