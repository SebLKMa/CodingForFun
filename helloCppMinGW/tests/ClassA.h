/*
 * ClassA.h
 *
 *  Created on: 31 Jan 2017
 *      Author: likke
 */

#ifndef TESTS_CLASSA_H_
#define TESTS_CLASSA_H_
#include <iostream>
#include <memory>
using namespace std;

class A
{
public:
	A() { cout << "A()" << endl;}
	~A() { cout << "~A()" << endl; }
	void hello() { cout << "Beauty is only skin deep" << endl; }

	static void test1()
	{
		unique_ptr<A> pA(new A);
		// pA will be deleted when out of scope
	}

	static void test2()
	{
		unique_ptr<A> pA(new A);
		test2a(std::move(pA)); // must give release and give ownership to another unique_ptr
	}

	static void test2a(unique_ptr<A> p)
	{
		p->hello();
	}

	static void test3()
	{
		shared_ptr<A> pA(new A);
		test3a(pA); // another shared_ptr can point to the same object
	}

	static void test3a(shared_ptr<A> p)
	{
		p->hello();
	}

	static void doSimpleTest()
	{
		cout << "!!!Hello C++11/14 World!!!" << endl;

		A::test1();
		A::test2();
		A::test3();
	}
};


#endif /* TESTS_CLASSA_H_ */
