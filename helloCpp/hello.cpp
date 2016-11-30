/*
 * hello.cpp
 *
 *  Created on: Sep 23, 2016
 *      Author: LMA
 */
#include <iostream>
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
	if (0 != pBase)
	{
		//pBase->sayHello();
		delete pBase;
		cout << "pBase destroyed" << endl;
	}
}

int main() {

	Greet greeter;
	greeter.sayHello();

	HelloContainers myContainers;
	myContainers.helloVector();

	testInheritanceInStack();
	testInheritanceInHeap();

	return 0;
}



