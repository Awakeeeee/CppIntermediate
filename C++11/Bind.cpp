#include <iostream>
#include <string>
#include <functional>

using namespace std;
using namespace placeholders;

int add(int a, int b, int c)
{
	cout << a << "," << b << "," << c << endl;
	return a + b + c;
}

void use(function<int(int, int, int)> stdfunc)
{
	stdfunc(11,22,33);
}

int main545()
{
	//��Bind�Ĵ�����ʶ
	//1. ����ʹ�ø����ֶβ����������
	//2. һ�㷽���в��ܶ��巽��, ����bind����ģ�����ƵĹ���

	//ʹ��placeholders namespace�Ժ�, ������_��������һ��placeholder����
	//���ֵ�����, _2��ʾ, ��1��������ʵ�ʴ��εĵ�2��ֵ --> 88
	auto bindfunc = bind(add, _2, _3, _1);
	bindfunc(77, 88, 99);

	//��2����������50, ��1���͵�3����ʵ�ʴ���
	auto bindfunc2 = bind(add, _3, 50, _1);
	bindfunc2(33, 44, 55);

	//3. bind���Ҳ��һ��callable, ��˿����������ͷ��ϵ�standard fucntion��
	use(bindfunc);

	system("PAUSE");
	return 0;
}