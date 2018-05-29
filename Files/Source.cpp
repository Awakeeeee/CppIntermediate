#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void simpleWriteFile(string fileName)
{
	//specify this is a output steam(write into file), if file name not exist then create one
	//alternative: use ofstream to represent output file stream
	std::fstream fileStream;	//create a file read-write stream

	fileStream.open(fileName, std::ios::out);

	if (fileStream.is_open())
	{
		//write something
		for (int i = 0; i < 2; i++)
		{
			//this is like cout, and cout is 'ostream'
			switch (i)
			{
			case 0:
				fileStream << "Level(Sword of Ash) : Legend" << std::endl;
				break;
			case 1:
				fileStream << "Level(Boot of Flame) : Rare" << std::endl;
				break;
			default:
				break;
			}
		}
		fileStream.close();
	}
}

void simpleReadFile(string fileName)
{
	fstream fileStream;

	fileStream.open(fileName, ios::in);
	if (fileStream.is_open())
	{
		while (fileStream.eof() == false)
		{
			string line;
			getline(fileStream, line);
			cout << line << endl;
		}
		fileStream.close();
	}
	else {
		cout << "Cannot open file " << fileName << endl;
	}
}

void stripString(string *s)
{
	int l = (*s).length();
	//this is the char array of a string, BUT it is const
	const char *ori = (*s).c_str();
	for (int i = 0; i < (l + 1); i++)
	{
		if (ori[i] == ' ')
			(*s).erase(i, 1);
	}
}
//为什么char *arr中, &arr[1]输出的不是内存地址而是值?
void configReadFile(string fileName)
{
	fstream fileStream;

	fileStream.open(fileName, ios::in);
	if (fileStream.is_open())
	{
		while (fileStream.eof() == false)
		{
			//getline() can has a custom delimiter, stream.get() delimit by space
			string equipment;
			string rarity;

			getline(fileStream, equipment, ':');
			stripString(&equipment);
			getline(fileStream, rarity);
			stripString(&rarity);

			//at the end, there is still a \n\r left, that CRLF will be clear in next while loop
			if (!fileStream)
				break;

			cout << equipment << "----->" << rarity << endl;
		}
	}
}

int main2()
{
	std::string fileName = "test.txt";
	simpleWriteFile(fileName);
	configReadFile(fileName);

	system("PAUSE");
	return 0;
}