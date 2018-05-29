#pragma once
#include <iostream>
using namespace std;

namespace qiqicppintermediate
{
	//通常一个类用header file做原型, 从另一个cpp中实现, 编译时header file不被编译, .cpp编译成.o
	//而Template的实现和原型需要在一起, template class不是一个实际的class, 编译时要根据实际指定的类型, 自动生成一个对应的class
	template<class T, class K>
	class PropertyBase
	{
	private:
		T objt;
		K objk;
	public:
		PropertyBase()
		{}
		PropertyBase(T objt, K objk)
		{
			this->objt = objt;
			this->objk = objk;
		}
		void print()
		{
			cout << objt << endl;
			cout << objk << endl;
		}
	};
}