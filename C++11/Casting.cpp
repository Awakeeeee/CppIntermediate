#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Item
{
public:
	Item() = default;
	virtual void print()
	{
		cout << typeid(*this).name() << endl;
	}
};

class Equipment : public Item
{
public:
	Equipment() = default;
	void print()
	{
		cout << typeid(*this).name() << endl;
	}
};

class Food : public Item
{
public:
	Food() = default;
	void print()
	{
		cout << typeid(*this).name() << endl;
	}
};




int main443()
{
	float f = 1.5;

	//-----�̳���C���Ե�casting-----
	//cast
	cout << (int)f << endl;

	//----- C++ -----
	//constrcut an int by this float value
	cout << int(f) << endl;

	//static cast, if type is wrong, there will be a compile time error
	cout << static_cast<int>(f) << endl;

	Item im;
	Equipment eq;
	Food fo;

	//����������ĳ�ʼ��һ������, ���Ƕ�̬������
	Item *pi = &eq;
	//�������ø����ʼ��һ�����಻����ֱ�ӽ���, ������Ҫcasting
	Equipment *pe = (Equipment*)&im;
	//static_cast�ô�: �ܸ���compile time error, ����д��һ���޷�ת��������
	//����: û��runtime�ı���, ��˺�Σ��, ���������equipment���еķ����ͻ����
	Equipment *pe2 = static_cast<Equipment*>(&im);

	//��static_cast����ֵ������ֵ����
	Item&& pr = Item();
	Item&& pr2 = static_cast<Item&&>(*pi);


	//dynamic_cast
	//��static�Ĳ�ͬ��, ����runtime�Ƿ�������, ���������, castʱ�᷵�ؿ�
	
	//��Ҫcompiler����RTTI runtime test infomation
	//Project Properties ---> C/C++ ---> Language ---> Enable Runtime Test Infomation
	Equipment *pe3 = dynamic_cast<Equipment*>(&im);
	if (pe3 == nullptr)
	{
		cout << "dynamic cast returns null pointer" << endl;
	}


	//reinterpret_cast
	//�����ٵļ��, �������ܳ���Ǳ������
	//��static_cast��dynamic_cast�������Ե�������п����õ�, ������Ʒǳ�����APIʱ�����õ�
	//һ�㲻���õ�
	Equipment *pe4 = reinterpret_cast<Equipment*>(&im);

	system("PAUSE");
	return 0;
}