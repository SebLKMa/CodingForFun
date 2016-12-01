/*
 * hello.cpp
 *
 *  Created on: Sep 23, 2016
 *      Author: LMA
 */
#include <iostream>
#include <memory>
#include <utility>
#include "Greet.h"
#include "HelloContainers.h"
#include "inheritance\DerivedC.h"
#include "copymove\MemoryPage.h"

using namespace std;

void testInheritanceInStack()
{
	cout << "testInheritanceInStack" << endl;
	DerivedC myC;
	myC.sayHello();

	DerivedB myB = static_cast<DerivedB>(myC);
	myB.sayHello();
}

void testInheritanceInHeap()
{
	cout << "testInheritanceInHeap" << endl;

	Base* pBase = new DerivedC();
	cout << "pBase created" << endl;
	if (nullptr != pBase)
	{
		DerivedC* pDerivedC = dynamic_cast<DerivedC*>(pBase);
		if (pDerivedC)
		{
			pDerivedC->sayHello();
		}
		
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

void testCopy()
{
	cout << "testCopy" << endl;
	MemoryPage myPage(1024);
	MemoryPage myPage1 = myPage; // copy ctor
}

void testAssignment()
{
	cout << "testAssignment" << endl;
	MemoryPage myPage2(1024);
	MemoryPage myPage3(512);
	cout << "myPage2: " << myPage2.getSize() << endl;
	cout << "myPage3: " << myPage3.getSize() << endl;
	myPage2 = myPage3; // assignment ctor
	cout << "myPage2: " << myPage2.getSize() << endl;
}

void testMove()
{
	cout << "testMove" << endl;
	MemoryPage myPage(1024);
	MemoryPage myPage1 = std::move(myPage); // force move ctor
}

int main() {

	//Greet greeter;
	//greeter.sayHello();

	//HelloContainers myContainers;
	//myContainers.helloVector();

	//testInheritanceInStack();
	//testInheritanceInHeap();
	//testCpp11();
	testCopy();
	testAssignment();
	testMove();

	return 0;
}



