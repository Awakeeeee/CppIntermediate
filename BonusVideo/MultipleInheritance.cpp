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
	//多继承多个父类的内容
	//多个父类存在同名方法时, 会有歧义问题
	//歧义问题需要指明调用的是哪个父类, 但这时就暴露了子类的构成

	Dog *pd = new Dog;

	pd->evolve();
	pd->speak();
	pd->Animal::eat();
	pd->Creature::eat();

	delete pd;

	system("PAUSE");
	return 0;
}