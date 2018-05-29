#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include <map>
using namespace std;

//----------rang based loop : C++ foreach-----------------------
void loop()
{
	//previous
	const char* a[] = { "one", "two", "three" };
	int length = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < length; i++)
	{
		cout << a[i] << endl;
	}
	//now
	auto aa = { "one", "two", "three" };
	for (auto a : aa)
		cout << a << endl;

	//previous
	vector<int> b;
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	b.push_back(4);
	for (vector<int>::iterator t = b.begin(); t != b.end(); t++)
	{
		cout << *t << endl;
	}
	//now
	for (auto i : b)
		cout << i << endl;

	//previous
	string c = "HELLO";
	const char* cc = c.c_str();
	for (int i = 0; i < 6; i++)
	{
		cout << cc[i] << endl;
	}
	//now
	for (auto i : c)
		cout << i << endl;
}

//-----------------custom iterator: nested classes--------------------
template<class T>
class ring
{
private:
	vector<T> buffer;
	int count;
	int capacity;
public:
	ring() :count(0), capacity(3)
	{
		buffer.resize(3);
	};
	void add(T in)
	{
		int idx = count % capacity;
		buffer[idx] = in;
		count++;
	}
	void print()
	{
		for (auto i : buffer)
			cout << i << endl;
	}
	T& get(int pos)
	{
		if (pos < 0 || pos >= capacity)
			return buffer[0];
		return buffer[pos];
	}

	class iterator; //some kind of reference obj that points to an element of the class(buffer)
	iterator begin()	//think vector.begin()
	{
		return iterator(0, this);
	}
	iterator end()	//vector.end()
	{
		return iterator(capacity, this);
	}

	~ring() {
		buffer.clear();
	}
};
//defien nested class outside the wrapper so it is easier to read
template<class T>
class ring<T>::iterator
{
private:
	int pos;
	ring<T>* wrapper;
public:
	iterator() {};
	iterator(int pos, ring<T>* wrapper) : pos(pos), wrapper(wrapper)
	{};
	bool operator==(const iterator& other) //t != end()
	{
		return this->pos == other.pos;
	}
	bool operator!=(const iterator& other)
	{
		return !(*this == other);
	}
	iterator& operator++(int)	//t++
	{
		this->pos++;
		return *this;
	}
	iterator& operator++()
	{
		this->pos++;
		return *this;
	}
	T& operator*()	//cout<<*t<<endl
	{
		return wrapper->get(pos);
	}
};

int main2()
{
	//loop();

	ring<string> r;
	r.add("one");
	r.add("two");
	r.add("three");
	r.add("four");
	r.print();

	//use nested class to implement custom iterator
	for (ring<string>::iterator t = r.begin(); t != r.end(); t++)
	{
		cout << *t << endl;
	}
	//关于自定义iterator的相关方法都实现以后,就可以用ranged base loop来循环了
	for (auto i : r)
		cout << i << endl;

	system("PAUSE");
	return 0;
}