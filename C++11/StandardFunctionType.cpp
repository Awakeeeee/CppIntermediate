#include <iostream>
#include <string>
#include <functional>

using namespace std;

int fAdd(int a, int b)
{
	return a + b;
}

void useSTF(function<int(int, int)> callable, int param1, int param2)
{
	cout << callable(param1,param2) << endl;
}

//Standard Function Type, ָ�κ�'callable', ����lambda, function pointer, functor
//Syntax, function<��������(����ֵ)> -- function<int(string, int)>
int main5()
{
	//Standard Function Type
	function<int(int, int)> stf;
	//������һ������
	stf = fAdd;
	cout << stf(1, 2) << endl;
	//�����Ƿ���ָ��
	int(*pf)(int, int) = fAdd;
	stf = pf;
	cout << stf(1, 2) << endl;
	//������lambda���ʽ
	stf = [](int a, int b) {return a + b; };
	cout << stf(1, 2) << endl;
	//������Functor
	class functor
	{
	public:
		int operator()(int a, int b)
		{
			return a + b;
		}
	} ftr;
	stf = ftr;
	cout << stf(1, 2) << endl;



	//��ô���һ�������Ĵ���ֵ���������Ҫһ��standard function type, ��ô�����������Ͷ�������ȷ����
	useSTF(pf, 1, 2);
	useSTF([](int a, int b) {return a + b; }, 1, 2);
	useSTF(ftr, 1, 2);

	getchar();
	return 0;
}