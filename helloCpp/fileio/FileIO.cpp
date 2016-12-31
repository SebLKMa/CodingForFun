#include "FileIO.h"
#include <iostream>
#include <cctype>
#include <fstream>
#include <string>
#include <stdexcept>
using std::string;
using std::ios;

void FileIO::copy(const std::string& src, const std::string& dest)
{
	if (src == dest)
	{
		throw std::invalid_argument{ string("Cannot copy ") + src + " to itself.\n" };
	}

	try
	{
		if (!validateFiles(src, dest))
			return;

		// create file streams
		std::ifstream in{ src, ios::in | ios::binary };
		std::ofstream out{ dest, ios::out | ios::binary | ios::trunc };
		char ch;
		while (in.get(ch))
		{
			out.put(ch);
		}
		if (in.eof())
		{
			std::cout << src << " copied to " << dest << " successfully.\n";
		}
		else
		{
			std::cout << "Error copying file" << std::endl;
		}

	}
	catch (std::exception& ex)
	{
		std::cout << std::endl << typeid(ex).name() << ": " << ex.what();
	}
}

bool FileIO::validateFiles(const std::string& inFile, const std::string& outFile)
{
	// error if input file does not exist
	std::ifstream in{ inFile, ios::in | ios::binary };
	if (!in)
	{
		throw ios::failure{ string("Input file ") + inFile + " not found!" };
	}

	// confirm overwrite if output file exists
	std::ifstream temp{ outFile, ios::in | ios::binary };
	if (temp)
	{
		temp.close();
		std::cout << outFile << " exists, do you want to overwrite? (y/n): ";
		if (std::toupper(std::cin.get()) != 'Y')
		{
			std::cout << "Destination file not to be overwritten" << std::endl;
			return false;
		}
	}
	return true;
}