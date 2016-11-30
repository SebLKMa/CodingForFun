/*
 * DerivedC.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: LMA
 */
#include <iostream>
#include "DerivedC.h"

using namespace std;

DerivedC::DerivedC(void)
{
	cout << "DerivedC::~DeriveC()" << endl;
}

DerivedC::~DerivedC(void)
{
	cout << "DerivedC::~DerivedC()" << endl;
}

void DerivedC::sayHello()
{
	cout << "Hello from DerivedC" << endl;
}


