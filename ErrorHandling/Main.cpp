#include <iostream>
#include <string>
using namespace std;

//exception handle是有消耗，会降低速度的

void errorMethod()
{
	bool error1 = false;
	bool error2 = true;
	if (error1)
	{
		throw "some exception";
	}

	if (error2)
	{
		throw string("some exception of string msg");
	}
}

void wrapper()
{
	try {
		errorMethod();
	}
	catch (string e)
	{
		cout << "Handle error in wrapper" << endl;
	}
	cout << "log in wrapper" << endl;
}

int main_1()
{
	try
	{
		wrapper();
	}
	catch (const char* e)	//const char* => primitive string(string inside "")
	{
		cout << "Error msg:" << e << endl;
	}
	catch (string &e)
	{
		cout << "Error msg:" << e << endl;
	}

	cout << "If exception is caught, program goes out of the ERROR METHOD(not directly to the try-catch position), and keep on running" << endl;

	system("PAUSE");
	return 0;
}