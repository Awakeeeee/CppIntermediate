#pragma once

template<T>
class outer
{
private:
	int somemember;
public:
	class inner;
};

template<T>
class outer<T>::inner
{
public:
	void innerfunction()
	{
		//do something
	}
};