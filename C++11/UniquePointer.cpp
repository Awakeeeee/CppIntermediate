#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Something
{
public:
	Something() = default;
	void speak()
	{
		cout << "ayayaya" << endl;
	}

	~Something()
	{
		cout << "something destructor" << endl;
	}
};

//ͨ��, ��new keyword���ٵ��ڴ�, �ڹ���ʹ�������Ժ�Ҳ��������, �����ֶ�delete�ͷ��ڴ�, ����ͻ�����ڴ�й©
//C++11��unique_ptr�����þ���, ����new���ٵ��ڴ��ڹ���ʹ�����Ժ���Զ��ͷ�
//unique_ptr������ǰ��auto_ptr, auto_ptr is now OBSELETE
int main()
{
	{
		//�﷨: ����һ��something���ڴ�������uniqueָ��
		unique_ptr<Something> ps(new Something);
		//����ʹ��ָ��
		ps->speak();
	}
	//�����������Ժ�, �Զ��ͷ��ڴ�

	{
		unique_ptr<Something[]> psa(new Something[10]);
		//auto_ptr<Something[]> asa(new Something[10]); //auto pointer is obselete, it does not support arrays
		psa[0].speak();
	}


	cout << "--------------------------------------------------" << endl;
	//shaded_ptr��unique_ptr�Ļ�����
	//������б��ָ���������ǰָ��, ��ô��ǰָ�뼴ʹ�����Լ���������, Ҳ�����ͷ�, ֱ��û���κι����Ż��ͷ�, �е�����C# GC
	{
		shared_ptr<Something> sp_other(nullptr);

		{
			
			shared_ptr<Something> sp_self(new Something);
			sp_other = sp_self; //����other��������self
			cout << "self is out of scopr" << endl;
		}
		cout << "other is out of scope" << endl;
	}

	cout << "Main finishes" << endl;
	system("PAUSE");
	return 0;
}