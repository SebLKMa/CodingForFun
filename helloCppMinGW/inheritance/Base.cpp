/*
 * Base.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: LMA
 */
#include <iostream>
#include "Base.h"

using namespace std;

Base::Base(void)
{
	cout << "Base::Base()" << endl;
	sayHi(); // calls self
}

Base::~Base(void)
{
	cout << "Base::~Base()" << endl;
}

void Base::sayHi()
{
	cout << "Base::sayHi()" << endl;
}





