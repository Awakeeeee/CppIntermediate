#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace qiqicppintermediate
{
	class ComplexNumber
	{
	private:
		double real;
		double imaginary;
	public:
		ComplexNumber();
		ComplexNumber(double real, double imaginary);
		ComplexNumber(const ComplexNumber &other);
		
		const ComplexNumber& operator=(const ComplexNumber& other);
		bool operator==(const ComplexNumber& other);
		bool operator!=(const ComplexNumber& other);
		ComplexNumber operator*();
		friend ComplexNumber operator+(const ComplexNumber& a, const ComplexNumber& b);
		friend ComplexNumber operator+(const ComplexNumber& c, double d);
		friend ComplexNumber operator+(double d, const ComplexNumber& c);
		friend ostream& operator<<(ostream& output, const ComplexNumber& other);
	};
}