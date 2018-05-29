#include <iostream>
#include <string> //std::string
#include <exception> //std::exception

using namespace std;

class my_exception : public exception
{
public:
	int mem = 1;
	//const after method : 'what() const' means this method will not change class member, there is [compile time check] of this - you cannot run the program
	//throw() : you promise that this method will not produce any exception, however there is [no compile time check] - if method raise exception anyway, the program gets runtime exception
	virtual const char* what() const throw()
	{
		//mem = 2; //const method will not do this
		return "my custom exception is raised";
	}
};

void exceptionmethod()
{
	my_exception e;
	throw e;
}

int main()
{
	try {
		exceptionmethod();
	}
	catch (my_exception &e)
	{
		cout << e.what() << endl;
	}
	catch (exception &e)
	{
		cout << "Always catch specific child exception before base class exception" << endl;
	}

	cout << "Still running" << endl;
	system("PAUSE");
	return 0;
}