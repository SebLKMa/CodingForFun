/*
 * Test02.cpp
 *
 *  Created on: Jan 4, 2017
 *      Author: LMA
 */
#include "Test02.h"
#include <iostream>
#include <memory>
#include <utility>
#include <iomanip>
#include <vector>
#include <string> // contains string, wstring, u16string, u32string
#include "..\inheritance\DerivedC.h"
#include "..\copymove\MemoryPage.h"


using namespace std;

void Test02::testInheritanceInStack()
{
	cout << "testInheritanceInStack" << endl;
	DerivedC myC;
	myC.sayHello();

	DerivedB myB = static_cast<DerivedB>(myC);
	myB.sayHello();
}

void Test02::testInheritanceInHeap()
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

void Test02::testInheritanceInHeap2()
{
	cout << "testInheritanceInHeap2" << endl;

	Base* pBase = new DerivedA();
	cout << "pBase created" << endl;
	if (nullptr != pBase)
	{
		pBase->sayHi();

		delete pBase;
		cout << "pBase destroyed" << endl;
	}
}

void Test02::testCpp11unique_ptr()
{
	cout << "testCpp11unique_ptr()\n"
		<< "- same behavior as testInheritanceInHeap2()\n"
		<< "unique_ptr frees ownership when out of scope."
		<< endl;
	unique_ptr<Base> pA(new DerivedA);  // pA owns DerivedA
	pA->sayHi();
}

void Test02::testCpp11unique_ptr_Move()
{
	cout << "testCpp11unique_ptr_Move()\n"
		<< "- same behavior as testCpp11unique_ptr()\n"
		<< "std::move passes ownership of unique_ptr."
		<< endl;
	unique_ptr<DerivedA> pA(new DerivedA);   // pA owns DerivedA
	pA->sayHi();
	unique_ptr<DerivedA> pB = std::move(pA); // passes ownership to pB
	pB->sayHi();
}

void Test02::testCpp11shared_ptr2(shared_ptr<Base> pBase)
{
	cout << "testCpp11shared_ptr2() ref counted ptr" << endl;
	pBase->sayHi();
}

void Test02::testCpp11shared_ptr1()
{
	// ref counted ptr points to the same object, will be deleted when ref count becomes zero
	cout << "testCpp11shared_ptr1() ref counted ptr" << endl;
	shared_ptr<Base> pA(new DerivedA);   //
	pA->sayHi();
	testCpp11shared_ptr2(pA);
}

void Test02::testCpp11()
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

void Test02::testCopy()
{
	cout << "testCopy" << endl;
	MemoryPage myPage(1024);
	MemoryPage myPage1 = myPage; // copy ctor
}

void Test02::testAssignment()
{
	cout << "testAssignment" << endl;
	MemoryPage myPage2(1024);
	MemoryPage myPage3(512);
	cout << "myPage2: " << myPage2.getSize() << endl;
	cout << "myPage3: " << myPage3.getSize() << endl;
	myPage2 = myPage3; // assignment ctor
	cout << "myPage2: " << myPage2.getSize() << endl;
}

void Test02::testMove()
{
	cout << "testMove" << endl;
	MemoryPage myPage(1024);
	MemoryPage myPage1 = std::move(myPage); // force move ctor
}





