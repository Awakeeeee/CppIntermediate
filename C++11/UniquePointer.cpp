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

//通常, 用new keyword开辟的内存, 在过了使用区域以后也不会销毁, 比如手动delete释放内存, 否则就会出现内存泄漏
//C++11中unique_ptr的作用就是, 这样new开辟的内存在过了使用域以后会自动释放
//unique_ptr代替以前的auto_ptr, auto_ptr is now OBSELETE
int main()
{
	{
		//语法: 开辟一个something的内存来构造unique指针
		unique_ptr<Something> ps(new Something);
		//正常使用指针
		ps->speak();
	}
	//超过作用域以后, 自动释放内存

	{
		unique_ptr<Something[]> psa(new Something[10]);
		//auto_ptr<Something[]> asa(new Something[10]); //auto pointer is obselete, it does not support arrays
		psa[0].speak();
	}


	cout << "--------------------------------------------------" << endl;
	//shaded_ptr在unique_ptr的基础上
	//如果还有别的指针关联到当前指针, 那么当前指针即使过了自己的作用域, 也不会释放, 直到没有任何关联才会释放, 有点类似C# GC
	{
		shared_ptr<Something> sp_other(nullptr);

		{
			
			shared_ptr<Something> sp_self(new Something);
			sp_other = sp_self; //现在other关联到了self
			cout << "self is out of scopr" << endl;
		}
		cout << "other is out of scope" << endl;
	}

	cout << "Main finishes" << endl;
	system("PAUSE");
	return 0;
}