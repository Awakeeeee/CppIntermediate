#pragma once
#include <iostream>
using namespace std;

namespace qiqicppintermediate
{
	//ͨ��һ������header file��ԭ��, ����һ��cpp��ʵ��, ����ʱheader file��������, .cpp�����.o
	//��Template��ʵ�ֺ�ԭ����Ҫ��һ��, template class����һ��ʵ�ʵ�class, ����ʱҪ����ʵ��ָ��������, �Զ�����һ����Ӧ��class
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