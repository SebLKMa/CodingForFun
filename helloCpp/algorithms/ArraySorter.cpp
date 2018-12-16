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

void ArraySorter::SortAscending(std::vector<std::string>& strings)
{
	string temp;
	bool sorted{ false };
	while (!sorted)
	{
		sorted = true;  // re-start until all are sorted
		for (size_t i{1}; i < strings.size(); ++i)	// start loop from second index
		{
			if (strings[i - 1] > strings[i])		// start compare from first index
			{
				temp = strings[i];
				strings[i] = strings[i - 1];
				strings[i - 1] = temp;
				sorted = false;
			}
		}
	}

	cout << "Strings are sorted in ascending sequence:\n"
		<< std::fixed << std::setprecision(1);
	const size_t maxNperLine{ 10 }; // no. of output per line
	size_t n{}; // no. on current line
	for (vector<string>::size_type i{}; i < strings.size(); ++i)
	{
		cout << std::setw(8) << strings[i];
		if (++n == maxNperLine)
		{
			cout << endl;
			n = 0;
		}
	}
	cout << endl;
}

/*
 * https://www.geeksforgeeks.org/floor-in-a-sorted-array/
 * Function to get index of floor of x in arr[low..high]
 */
int ArraySorter::floorSearch(int arr[], int low, int high, int x)
{
    // If low and high cross each other
    if (low > high)
        return -1;

    // If last element is smaller than x
    if (x >= arr[high])
        return high;

    // Find the middle point
    int mid = (low+high)/2;

    // If middle point is floor.
    if (arr[mid] == x)
        return mid;

    // If x lies between mid-1 and mid
    if (mid > 0 && arr[mid-1] <= x && x < arr[mid])
        return mid-1;

    // If x is smaller than mid, floor must be in
    // left half.
    if (x < arr[mid])
        return floorSearch(arr, low, mid-1, x);

    // If mid-1 is not floor and x is greater than
    // arr[mid],
    return floorSearch(arr, mid+1, high, x);
}
