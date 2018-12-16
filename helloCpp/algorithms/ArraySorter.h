#pragma once
#include <vector>
#include <string>

class ArraySorter
{
public:
	ArraySorter() {}
	~ArraySorter() {}

	void SortAscending(std::vector<double>& numbers);

	void SortAscending(std::vector<std::string>& strings);

	int floorSearch(int arr[], int low, int high, int x);
};
