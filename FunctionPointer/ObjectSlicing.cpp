#include <iostream>
#include <string>
using namespace std;

class parent
{
public:
	parent() { cout << "parent constructor" << endl; };
	parent(const parent& other) { cout << "parent copy construtor" << endl; };
	virtual void print()
	{
		cout << "parent" << endl;
	}
};

class child : public parent
{
private:
	int num;
public:
	child() {};
	child(int num) :num(num) { cout << "child constructor" << endl; };
	child(const child& other) 
	{ 
		cout << "child copy constructor" << endl;
		this->num = other.num;
	}
	void print()
	{
		cout << num << "child" << endl;
	}
};

int main()
{
	//�������:
	//child��constructor�����ã����е�һ���ǵ���Ĭ��parent��constructor���ѳ�Ա������ΪĬ��ֵ
	//Ȼ��child constructorʵ���Լ��ĳ�ʼ������num��Ϊ5��child construct����
	//����p1=c1����parent��copy constrcutor����Ϊ���Զ���cc�����Ե����Ǹ�cc/
	//����parent��cc��ֻ֪������parent�еĳ�Ա�������child�ж����num�ᱻ����

	//*****(��Object Slicing: parentʵ����child����ֵʱ, child��private�Ĳ��ֱ����Ե����), ����û�����ö�̬����******
	child c1(5);
	parent p1 = c1; //object slicing
	p1.print();	//parent

	//����ͨ������¶Զ�̬������: һϵ��parent�ǲ�ͬchild���Ͳ��Ҹ���ִ��child�жԷ�����override
	//һ��ʹ������&��ָ��*����̬���Ծͻ����(?)
	//�������Ȼp2, p3��parent���ͣ�����print��child�İ汾��print��ʹ��child��private memberҲ����

	//**********û��Object Slicing, ����ȷ������***********
	parent &p2 = c1;	//no log of 'child copy constructor'
	p2.print();	//child

	//�������Ļ�p3��һ��ָ��parent��ָ��, ������ָ��Ķ���һ����parent����Ҳ����������, �������������
	parent *p3 = &c1;
	p3->print(); //child

	system("PAUSE");
	return 0;
}