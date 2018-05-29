#include <iostream>
#include <string>

using namespace std;

class Creature
{
public:
	virtual void evolve()
	{
		cout << "creature evolve" << endl;
	}
	virtual void eat()
	{
		cout << "create eat" << endl;
	}
	~Creature() {}
};

class Animal
{
public:
	virtual void speak()
	{
		cout << "animal speal" << endl;
	}
	virtual void eat()
	{
		cout << "animal eat" << endl;
	}
	~Animal() {}
};


class Dog : public Creature, public Animal
{
public:
	~Dog(){}
};

int main()
{
	//��̳ж�����������
	//����������ͬ������ʱ, ������������
	//����������Ҫָ�����õ����ĸ�����, ����ʱ�ͱ�¶������Ĺ���

	Dog *pd = new Dog;

	pd->evolve();
	pd->speak();
	pd->Animal::eat();
	pd->Creature::eat();

	delete pd;

	system("PAUSE");
	return 0;
}