#include "ComplexNumber.h"

namespace qiqicppintermediate
{
	ComplexNumber::ComplexNumber()
	{}

	ComplexNumber::ComplexNumber(double real, double imaginary) :real(real), imaginary(imaginary)
	{}

	ComplexNumber::ComplexNumber(const ComplexNumber& other)
	{
		this->real = other.real;
		this->imaginary = other.imaginary;
	}

	const ComplexNumber& ComplexNumber::operator=(const ComplexNumber& other)
	{
		this->real = other.real;
		this->imaginary = other.imaginary;
		return *this;
	}

	bool ComplexNumber::operator==(const ComplexNumber& other)
	{
		return this->real == other.real && this->imaginary == other.imaginary;
	}

	bool ComplexNumber::operator!=(const ComplexNumber& other)
	{
		return !ComplexNumber::operator==(other);
	}

	ComplexNumber ComplexNumber::operator*()
	{
		return ComplexNumber(this->real, -this->imaginary);
	}

	ComplexNumber operator+(const ComplexNumber& a, const ComplexNumber& b)
	{
		ComplexNumber add;
		add.real = a.real + b.real;
		add.imaginary = a.imaginary + b.imaginary;
		return add;
	}
	ComplexNumber operator+(const ComplexNumber& c, double d)
	{
		return ComplexNumber(c.real + d, c.imaginary);
	}
	ComplexNumber operator+(double d, const ComplexNumber& c)
	{
		return ComplexNumber(c.real + d, c.imaginary);
	}

	ostream& operator<<(ostream& output, const ComplexNumber& other)
	{
		output << "(" << other.real << "," << other.imaginary << ")" << flush;
		return output;
	}
}