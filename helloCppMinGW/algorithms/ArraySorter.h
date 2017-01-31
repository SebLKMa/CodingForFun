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
};
