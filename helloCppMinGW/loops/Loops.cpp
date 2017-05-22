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

int Loops::GetBinaryGap(const char values[])
{
	size_t size = sizeof(values) / sizeof(values[0]);
	cout << "There are " << size << " elements." << endl;

	// not interested in leading zeroes
	int startIndex = 0;
	for (size_t i=0; i<size; ++i)
	{
		if (values[i] == '1')
		{
			startIndex = i;
			break;
		}
	}

	int max = 0;
	int currCount = 0;
	for (size_t i=startIndex; i<size; ++i)
	{
		if (values[i]=='1' && currCount==0)
		{
			continue;
		}

		if (values[i]=='1' && currCount!=0)
		{
			if (currCount > max)
			{
				max = currCount;
			}
			currCount = 0;
			continue;
		}

		if (values[i]=='0')
		{
			++currCount;
		}
	}

	return max;
}
