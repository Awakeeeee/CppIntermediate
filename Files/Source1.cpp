#include <iostream>
using namespace std;

//���ڲ�֪��ʲôԭ�򣬸���struct�����һ��stack������ÿ��struct֮����һ��boundary��Ĭ����2 bytes�ռ�
#pragma pack(push, 1)	//???
struct Data
{
	char name[50]; //50 bytes
	int age;	//4 bytes
	float ability;	//4 bytes
};
#pragma pack(pop)

int main1()
{
	cout << sizeof(Data) << endl; //60 bytes - 2 bytes for padding

	system("PAUSE");
	return 0;
}