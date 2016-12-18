//#include "stdafx.h"
#include <iostream>
#include "Loops.h"

using namespace std;

Loops::Loops()
{
}


Loops::~Loops()
{
}

void Loops::DoLoop1()
{
	int values[]{ 2,3,5,7,11,13,17,19,23,29 };
	size_t count = sizeof(values) / sizeof(values[0]);

	cout << "There are " << count << " elements." << endl;

	int sum{};
	for (size_t i{}; i < count; ++i)
	{
		sum += values[i];
	}
	cout << "The sum of elements is " << sum << "." << endl;
}
