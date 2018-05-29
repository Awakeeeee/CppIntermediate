#include <iostream>

using namespace std;

class Something
{
private:
	int num;
	string word;
	int *arr = new int[10];
public:
	Something()
	{}
	Something(int num, string word) :num(num), word(word) {}
	
	//��������������࣬�򷽷�����ֵ���ݴ���һ���࣬��һ����ʵ����ֵ����һ��ʱ�����漰������������
	Something(const Something& other)
	{
		//Ĭ�Ͽ�������������ǳ�������Ѹ����ֶθ�ֵ
		num = other.num;
		word = other.num;
		//arr = other.arr; //XX - �����������ָ��(��������)����ôǳ������ֱ�Ӹ�ֵ���У�����ʵ�����ָ�뽫��ָ��ͬһ���ڴ�

		//�Լ����忽�����캯����ʵ����� - Ϊ�������Ϳ����¿ռ䣬���¿ռ����źͿ���ֵһ��������
		cout << "Custom copy constructor called" << endl;
		arr = new int[10];
		*arr = *(other.arr);
	}

	~Something() { delete[] arr; }

	void SetNum(int i)
	{
		num = i;
	}

	bool operator==(const Something& other) const
	{
		return this->num == other.num;
	}
};

int main6()
{
	Something s1(1, "ha");
	Something s2 = s1;
	s2.SetNum(3);
	if (s2 == s1)
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	system("PAUSE");
	return 0;
}