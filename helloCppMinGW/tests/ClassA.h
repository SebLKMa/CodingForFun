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
	}

	static void test3(shared_ptr<A> p)
	{
		p->hello();
	}

	static void test2()
	{
		shared_ptr<A> pA(new A);
		test3(pA);
	}

	static void doSimpleTest()
	{
		cout << "!!!Hello C++11/14 World!!!" << endl;

		A::test1();
		A::test2();
	}
};


#endif /* TESTS_CLASSA_H_ */
