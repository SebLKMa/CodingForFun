//============================================================================
// Name        : HelloMingwCpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
using namespace std;

class A
{
public:
	A() { cout << "A()" << endl;}
	~A() { cout << "~A()" << endl; }
	void hello() { cout << "Beauty is only skin deep" << endl; }
};

void test1()
{
	unique_ptr<A> pA(new A);
}

void test3(shared_ptr<A> p)
{
	p->hello();
}

void test2()
{
	shared_ptr<A> pA(new A);
	test3(pA);
}

int main()
{
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	test1();
	test2();

	return 0;
}
