/*
 * DerivedB.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: LMA
 */
#include <iostream>
#include "DerivedB.h"

using namespace std;

DerivedB::DerivedB(void)
{
	cout << "DerivedB::DerivedB()" << endl;
}

DerivedB::~DerivedB(void)
{
	cout << "DerivedB::~DerivedB()" << endl;
}

void DerivedB::sayHello()
{
	cout << "Hello from DerivedB" << endl;
}

