/*
 * DerivedA.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: LMA
 */
#include <iostream>
#include "DerivedA.h"

using namespace std;

DerivedA::DerivedA(void)
{
	cout << "DerivedA::DerivedA()" << endl;
}

DerivedA::~DerivedA(void)
{
	cout << "DerivedA::~DerivedA()" << endl;
}

void DerivedA::sayHi()
{
	cout << "DerivedA::sayHi()" << endl;
}

