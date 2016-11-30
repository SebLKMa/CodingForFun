/*
 * hello.cpp
 *
 *  Created on: Sep 23, 2016
 *      Author: LMA
 */
#include <iostream>
#include <memory>
#include "Greet.h"
#include "HelloContainers.h"
#include "inheritance\DerivedC.h"

using namespace std;

void testInheritanceInStack()
{
	cout << "testInheritanceInStack" << endl;
	DerivedC myC;
}

void testInheritanceInHeap()
{
	cout << "testInheritanceInHeap" << endl;

	Base* pBase = new DerivedC();
	cout << "pBase created" << endl;
	if (nullptr != pBase)
	{
		//pBase->sayHello();
		delete pBase;
		cout << "pBase destroyed" << endl;
	}
}

void testCpp11()
{
	cout << "testCpp11" << endl;

	//auto text = unique_ptr<char[]>(new char[42]);

    unique_ptr<DerivedC> p1(new DerivedC);  // p1 owns DerivedC
    /*
    if (p1) p1->bar();
    {
        std::unique_ptr<Foo> p2(std::move(p1));  // now p2 owns Foo
        f(*p2);

        p1 = std::move(p2);  // ownership returns to p1
        std::cout << "destroying p2...\n";
    }

    if (p1) p1->bar();
    */

    // Foo instance is destroyed when p1 goes out of scope

}

int main() {

	Greet greeter;
	greeter.sayHello();

	HelloContainers myContainers;
	myContainers.helloVector();

	testInheritanceInStack();
	testInheritanceInHeap();
	testCpp11();

	return 0;
}



