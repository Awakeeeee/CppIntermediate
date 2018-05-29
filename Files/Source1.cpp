#include <iostream>
using namespace std;

//处于不知道什么原因，各个struct会进入一个stack，其中每个struct之间有一个boundary，默认是2 bytes空间
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