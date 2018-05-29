#include <iostream>
#include <string>
#include "ComplexNumber.h"

using namespace std;
using namespace qiqicppintermediate;

int main()
{
	ComplexNumber num1(1, 2);
	ComplexNumber num2(num1);
	ComplexNumber num3;
	num3 = num1;

	//cout << num1 << "and" << num2 << endl;

	num3 = num1 + num2;
	cout << num3 << endl;

	num3 = 1.5 + num3 + 3.2;
	cout << num3 << endl;

	if (num3 == num1)
		cout << "Equal" << endl;
	else
		cout << "Not Equal" << endl;

	ComplexNumber *p = &num3;
	cout << p << endl;
	cout << *num3 << endl;

	system("PAUSE");
	return 0;
}