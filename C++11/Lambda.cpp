#include <iostream>
#include <string>

using namespace std;

void use(void(*pf)())
{
	pf();
}

int main6()
{
	//lambda�Ļ����﷨
	[]() {};

	//��lambda����������������
	auto anonymous = []() {cout << "this is anonymous" << endl; };
	void(*pf)() = anonymous;
	use(pf);

	//ʵ������: �������߼��ܼ���, �ڴ��뷽���ĵط�ֱ�Ӵ�����ʱ�����lambda���ʽ������
	//ͨ��lambda���ʽ�ķ���ֵ���Զ��ƶ�
	use([]() {cout << "I am lambda" << endl; });

	//���lambda���ʽ�ķ���ֵ�Զ��ƶ�ʧ��, ʹ��trailing����ʽָ��
	[](double a, double b) -> double
	{
		cout << a + b << endl;
		return a + b; 
	}(3, 5);

	//��lambda��ʹ��local variable
	int a = 1;
	int b = 2;
	int c = 123;
	//=ָץȡ����local variable��ֵ
	[=]() {cout << a << b << c << endl; }();
	//&ָץȡ����local variable������
	[&]() {a = 5; }();
	cout << a << endl;
	//Ĭ��ץȡ����ֵ, ֮���ְ�a�ĳ�����
	[=, &a]() {a = 6; }();
	cout << a << endl;

	//���һ��ץȡֵ��ץȡ��copyֵ, ��ôĬ������²�����lambda�и��������ֵ, ���Ǳ����mutable
	[a]() mutable {a = 10; }();

	getchar();
	return 0;
}