#include <iostream>
#include <string>

using namespace std;

int test1()
{
	return 3;
}

int rref(int && rref)
{
	return rref;
}

//һ������:
//lvalue: A value that resides in memory(heap or stack) and addressable.
//rvalue : A value that's not lvalue.
//һ��û�е�ַ��value����ô����?
//�ҵ����: rvalue����û�е�ַ, ������ʱ��������int a = test1()���ʽ���������Ͼ���ʧ��, ��������һ�о���ʧ��, ����ȥ������
//��ַ��������, stack�ϵı�����ʱҲ��Ϊ��ʱ����, ���ô�����������֮��ű�����, ������֮�����ĵ�ַ�����������

//����ȡLvalue��reference
//������ȡRvalue��reference

//��ʱ��������Rvalue
//rvalue��ֵ��һ����ʱ����,���û�б��󶨵�����,�ڱ��ʽ����ʱ�ͻᱻ����
int main88()
{
	int a = 1;
	int b = a; //lvalue���Ե���rvalue��ʹ��, ��������������õ���lvalue��ֵ



	int val = 5; //val is a LValue
	int *pint = &val; //OK
	//int *pint = &5; //ERROR: &Expression must be a lvalue


	/*
	// ǰ׺��ʽ��
	int& int::operator++()
	{
		*this += 1;
		return *this;
	}

	//��׺��ʽ:
	const int int::operator++(int)
	{
		int oldValue = *this;
		++(*this);
		return oldValue;
	}
	*/
	pint = &(++val); //ǰ׺++����һ��lvalue, ����ֵ+1�Ժ��val
	//pint = &(val++); //��׺++��ʹ��һ����ʱ�����ԭֵ, ����rvalue, ����ȡ����ref



	//pint = &test1(); //��������ֵ����ʱ����, ����rvalue, ����ֱ�ӻ��ref


	//int &pt = test1();
	//����һ��temp rvalue֮һ:
	//����ͨ���������ǰ���������һ��lvalue��
	int t = test1();


	//����һ��temp rvalue֮��:
	//����㱣֤��ʱֵ����(const), ��ô���԰���������lvalue reference��
	//��а�һ��rvalue��const lvalue reference
	//Ӧ��:��ͨcopy constructor
	const int &pt = 5;


	//Lvalue reference����������reference
	int save_temp = test1();
	int &ref_l = save_temp;
	//����һ��temp rvalue֮��:
	//Rvalue reference��C++11��������¸���, ����&&
	//Ӧ��:Move Constructor
	int &&ref_r = 3;
	cout << &ref_r << endl;
	//��ֵ�����ҵ����:
	//������rref�����ķ���, �Ϳ��Ա�Ƿ�����Ҫһ����ֵ����, �����ֵ�Ϳ���ֱ����, ��������copy��ʱ����ֵ, ��������ʱ����ֵ�Ĺ���
	rref(test1());

	system("PAUSE");
	return 0;
}