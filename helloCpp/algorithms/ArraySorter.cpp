#include "ArraySorter.h"
#include <iostream>
#include <iomanip>

using namespace std;

void ArraySorter::SortAscending(std::vector<double>& numbers)
{
	cout << "ArraySorter::SortAscending" << endl;
	
	double temp{}; // temp store
	bool swapped {false}; // true when numbers are not in order
	while (true)
	{
		for (vector<double>::size_type i{}; i < numbers.size() - 1; ++i) // exclude last null element
		{
			if (numbers.at(i) > numbers.at(i + 1))
			{
				// not in order, swap them
				temp = numbers.at(i);
				numbers.at(i) = numbers.at(i + 1);
				numbers.at(i + 1) = temp;
				swapped = true; // some numbers are swapped
			}
		}
		if (!swapped)
		{
			break; // if nothing swapped, numbers are in order
		}
		swapped = false; // to re-order numbers again if not all are in order
	}

	cout << "Numbers are sorted in ascending sequence:\n"
		<< std::fixed << std::setprecision(1);
	const size_t maxNperLine{10}; // no. of output per line
	size_t n{}; // no. on current line
	for (vector<double>::size_type i{}; i < numbers.size(); ++i)
	{
		cout << std::setw(8) << numbers[i];
		if (++n == maxNperLine)
		{
			cout << endl;
			n = 0;
		}
	}
	cout << endl;
}