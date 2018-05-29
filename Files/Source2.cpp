#include <iostream>
#include <fstream>

using namespace std;

#pragma pack(push, 1)
struct Item
{
	char name[50];
	int price;
	int id;
};

struct Container
{
	char thing[14];
};

#pragma pack(pop)

int main()
{
	Container c = { "what the fuck" };
	string file = "binary.mystery";
	ofstream ii;
	ii.open(file);
	if (ii.is_open())
	{
		//���̱����Դ�������Ƕ����Ƹ�ʽ
		//��д��ʱ������utf-8 char array
		//�ü��±��򿪣����±����������̵ײ㱣������� binary -> hex ->utf8�ַ�
		//����sublimeʱ��binary -> hex������ʾΪ����7768 6174 2074 6865 2066 7563 6b00 �Ķ���
		ii.write(reinterpret_cast<char*>(&c), sizeof(Container));
		ii.close();
	}

	//you can define a struct like this
	Item swordofdragon = { "Sword of Dragon", 10000, 1 };
	//by changing the extension, this becomes a binary file - open it with a txt editor you see lots of binary numbers
	string output = "itemdata.mystery";
	fstream ofs;
	ofs.open(output, ios::binary | ios::out);
	if (ofs.is_open())
	{
		//write a char* to the open file
		//how you cast a struct to char*
		ofs.write(reinterpret_cast<char*>(&swordofdragon), sizeof(Item));
		ofs.close();
	}
	else {
		cout << "Cannot write to file " << &output << endl;
	}

	//----read to another struct------
	Item itemslot = {};
	fstream ifs;
	ifs.open(output, ios::binary | ios::in);
	if (ifs.is_open())
	{
		//read from the openfile and the read content into a char*
		ifs.read(reinterpret_cast<char*>(&itemslot), sizeof(Item));
		ifs.close();
	}

	cout << itemslot.name << "," << itemslot.price << endl;

	system("PAUSE");
	return 0;
}