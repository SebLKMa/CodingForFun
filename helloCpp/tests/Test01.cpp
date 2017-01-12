/*
 * Test01.cpp
 *
 *  Created on: Jan 4, 2017
 *      Author: LMA
 */
#include "Test01.h"
#include <iostream>
#include <utility>
#include <iomanip>
#include <vector>
#include <string> // contains string, wstring, u16string, u32string
#include "..\loops\Loops.h"
#include "..\algorithms\ArraySorter.h"
#include "..\algorithms\Quicksort.h"
#include "..\fileio\FileIO.h"
#include "..\templates\TArray.h"
#include "..\Box.h"
#include "..\strings\StringUtils.h"

using namespace std;

void Test01::testStringTypes()
{
	wstring myWstring{ L"Hello wstring" }; //wchar_t characters
	u16string myU16string{ u"Hello unicode 16" }; // char16_t characters
	u32string myU32string{ U"Hello unicode 32" }; // char32_t characters
	wcout << myWstring << endl;
}

void Test01::testStringUtils()
{
	string myStr{"olla hello"};
	cout << myStr;

	StringUtils utils;
	utils.reverse(myStr);
	cout << " reversed: " << myStr << endl;

	string myStr1{"OLLA"};
	string myStr2{"ABBA"};
	string myStr3{"1881"};

	cout << myStr1 << " is palindrome: " << std::boolalpha << utils.isPalindrome(myStr1) << endl;
	cout << myStr2 << " is palindrome: " << std::boolalpha << utils.isPalindrome(myStr2) << endl;
	cout << myStr3 << " is palindrome: " << std::boolalpha << utils.isPalindrome(myStr3) << endl;
}

void Test01::testPtrsBasics()
{
	long number{ 12345L };
	long* pNumber{ &number }; // address-of
	std::cout << "Number: " << *pNumber << endl; // de-reference to get the data

	// char* WRONG!!!
	//char* pPhrase{ "Beauty is only skin deep" };// WRONG! pPhrase only stores the addressof the
												// first char 'B'. The rest is an array of const char
	//*pPhrase = "Yes indeed."; // attempt to change contents of pPhrase results compile ERROR
	//*pPhrase = 'Y';			// Runtime CRASH!!! Not allowed to change string literal

	// const char* CORRECT!!!
	const char* pPhrase{ "Beauty is only skin deep" };  // CORRECT way, const ptr type
														// ptr points to a const object
	std::cout << pPhrase << endl;

	// ptr to a const object, const object cannot be changed
	pPhrase = { "Yes, indeed." };
	std::cout << pPhrase << endl;

	const int VALUE_1{ 42 };	   // const object 1
	const int VALUE_2{ 65 };	   // const object 2
	const int* pValue{ &VALUE_1 }; // ptr to address of const object
	std::cout << *pValue << endl;
	pValue = &VALUE_2;			   // change ptr to address of another const object
	std::cout << *pValue << endl;

	// array of ptrs to const, these pointers are pointing to const data
	const char* arrDimSum[]{ "Har Kow", "Siew Mai", "Cheong Fun", "Fung Jao", "Ma Lai Go" };
	size_t arrSize = sizeof(arrDimSum);    // 4 x 5 elements = 20
	size_t eleSize = sizeof(arrDimSum[0]); // each pointer address is 4 bytes
	size_t choice{};
	std::cout << "Pick your dim sum number between 1 and " << arrSize / eleSize << ": ";
	std::cin >> choice;
	if (choice >= 1 && choice <= arrSize / eleSize)
	{
		std::cout << "You dim sum is: " << arrDimSum[choice - 1] << endl;
	}
	else
	{
		std::cout << "No dim sum chosen." << endl;
	}

	// you can still change the ptr to point to another const data
	size_t index = arrSize / eleSize;
	arrDimSum[index - 1] = "Egg tart";
	std::cout << "Pick your dim sum number between 1 and " << index << ": ";
	std::cin >> choice;
	if (choice >= 1 && choice <= index)
	{
		std::cout << "You dim sum is: " << arrDimSum[choice - 1] << endl;
	}
	else
	{
		std::cout << "No dim sum chosen." << endl;
	}

	// array of const ptrs to const, these are const pointers are pointing to const data
	// once initialized, these const pointers cannot be changed to point to something else.
	const char* const arrDimSumFixed[]{ "Har Kow", "Siew Mai", "Cheong Fun", "Fung Jao", "Ma Lai Go" };
	size_t arrSize2 = sizeof(arrDimSumFixed);
	size_t eleSize2 = sizeof(arrDimSumFixed[0]);
	size_t index2 = arrSize2 / eleSize2;
	//arrDimSumFixed[index2 - 1] = "Egg tart"; // compile error!!! lvalue cannot be modified
}

void Test01::testRefsBasics()
{
	double price{ 3.5 };
	double& refPrice{ price };  // reference to price
	refPrice += 1.5;			// changing the value of price
	cout << price << endl;
	cout << refPrice << endl;

	const double& fixedPrice{ price };
	//fixedPrice += 3.3;		// cannot change const ref
	price += 3.3;
	cout << price << endl;
	cout << refPrice << endl;
	cout << fixedPrice << endl;

	const double FtoC{ 5.0 / 9.0 };
	double temperatures[]{ 45.5, 50.0, 48.2, 57.0, 63.8 };
	// t is a copy of the array element for each iteration
	// temperature array still storing Fahrenheits
	for (auto t : temperatures)
	{
		t = (t - 32.0) * FtoC;
	}
	for (const auto& t : temperatures) // not changing data, use const ref
	{
		cout << std::setw(6) << t;
	}
	cout << endl;
	// if results can be store in same temperature array,
	// it is more efficient to use references
	for (auto& t : temperatures)
	{
		t = (t - 32.0) * FtoC;
	}
	for (const auto& t : temperatures) // not changing data, use const ref
	{
		cout << std::setw(6) << t;
	}
	cout << endl;
}

void Test01::testLoops()
{
	Loops myLoops;
	myLoops.DoLoop1();
}

void Test01::testArraySorter()
{
	vector<double> numbers;
	double input {};
	while (true)
	{
		cout << "Enter non-zero number value, 0 to end: ";
		cin >> input;
		if (!input)
		{
			break;
		}
		numbers.push_back(input);
	}

	if (numbers.size() == 0)
	{
		return;
	}

	ArraySorter aSorter;
	aSorter.SortAscending(numbers);

	vector<string> myStrings;
	myStrings.push_back("deep");
	myStrings.push_back("skin");
	myStrings.push_back("beauty");
	myStrings.push_back("only");
	myStrings.push_back("is");
	aSorter.SortAscending(myStrings);
}

void Test01::testQuicksort()
{
	const string SEPS{" ,.!?\"\n"};
	string text;
	cout << "Enter a string terminated by *: " << endl;
	getline(cin, text, '*');

	Quicksort sorter(text, SEPS);
	sorter.sort();
	sorter.showWords();
}

void Test01::testFileIO()
{
	string infile{"C:\\temp\\C++ Primer - Sampler Chapter.pdf"};
	string outfile{"C:\\temp\\C++ Primer - Sampler Chapter copy.pdf"};
	FileIO myFileIO;
	myFileIO.copy(infile, outfile);
}

void Test01::testTArray1()
{
	const size_t NVALUE = 50;
	TArray<double> values(NVALUE); // template's class ctor and instance created
	try
	{
		for (size_t i = 0; i < NVALUE; ++i)
		{
			values[i] = i + 1;
		}
		cout << "Sum of pairs of elements:";
		size_t lines{};
		for (size_t i{ NVALUE - 1 }; i >= 0; i--)
		{
			cout << (lines++ % 5 == 0 ? "\n" : "")
				<< std::setw(5) << values[i] + values[i - 1];
		}
	}
	catch (const std::out_of_range& ex)
	{
		cerr << "\nout_of_range exception object caught! " << ex.what() << endl;
	}

	try
	{
		const size_t NBOXES = 10;
		TArray<Box> boxes(NBOXES); // template instance created

		// i <= NBOXES will exceed index, forcing operator[] to throw
		for (size_t i = 0; i <= NBOXES; ++i)
		{
			cout << "Box volume is " << boxes[i].volume() << endl;
		}
	}
	catch (const std::out_of_range& ex)
	{
		cerr << "\nout_of_range exception object caught! " << ex.what() << endl;
	}
}

void Test01::testTArray2()
{
	try
	{
		const size_t NBOXES = 10;
		TArray<Box> boxes(NBOXES); // template instance created
		for (size_t i = 0; i < NBOXES; ++i)
		{
			cout << "Box volume is " << boxes[i].volume() << endl;
		}

		TArray<Box> otherBoxes = boxes;
		for (size_t i = 0; i < NBOXES; ++i)
		{
			otherBoxes[i].setLength(i + 1);
			cout << "Other Box volume is " << otherBoxes[i].volume() << endl;
		}
	}
	catch (const std::out_of_range& ex)
	{
		cerr << "\nout_of_range exception object caught! " << ex.what() << endl;
	}
}

void Test01::testByteOrder()
{
	unsigned long lNumber;
	unsigned char* pChar;

	// 11 22 33 44 => big-endian
	// 44 33 22 11 => little-endian
	// lNumber = 0x1122334455667788UL for long 64-bit

	lNumber = 0x11223344UL;
	pChar = (unsigned char*)&lNumber;
	for (int i = 0; i<sizeof(long); i++)
	{
		//cout << std::hex << setw(4) << *pChar++;
		printf("%x ", *pChar++);
	}
	cout << endl;
	//printf("\n");
}

void Test01::testBitShift()
{
	// we are in 16-bit integer
	unsigned short number = 16387U;				  // binary ‭0100000000000011‬
	unsigned short numberLeftShift = number << 2; // binary 00000000000011‬00 == 12, bit are lost, otherwise = *2n where n is n shift
	unsigned short numberRightShift = number >> 2; // binary 00‭01000000000000 == 4096 == 16387/2n where n is n shift

	cout << number << " 2left shift:" << numberLeftShift << " 2right shift: " << numberRightShift << endl;
}

// e.g. unix file permission rwx
const unsigned short READ = 4;	// 0100  2^2
const unsigned short WRITE = 2;	// 0010  2^1
const unsigned short EXEC = 1;	// 0001  2^0
void Test01::testBitMasks()
{
	// user A permission is read, write
	// rwx
	// 110 = 6
	unsigned short userApermission = 6;
	checkUserPermission("UserA", userApermission);

	// user B permission is read, write, execute
	// rwx
	// 101 = 5
	unsigned short userBpermission = 5;
	checkUserPermission("UserB", userBpermission);

	// now set user A to have execute permission
	// rwx
	// 110
	// 001
	setUserPermission(userApermission, EXEC);
	checkUserPermission("UserA", userApermission);

	// now set user B to have write permission
	// rwx
	// 101
	// 010
	setUserPermission(userBpermission, WRITE);
	checkUserPermission("UserB", userBpermission);

	// now set user A not to have write permission
	// rwx
	// 111
	// 010 ~ 101 then & with 111
	unsetUserPermission(userApermission, WRITE);
	checkUserPermission("UserA", userApermission);

	// now set user B to have read permission
	// rwx
	// 111
	// 100 ~ 011 then & with 111
	unsetUserPermission(userBpermission, READ);
	checkUserPermission("UserB", userBpermission);
}

void Test01::checkUserPermission(const std::string& userId, const unsigned short& userPermission)
{
	cout << "=====================================" << endl;

	// using bitwise AND to extract the bit information
	// test if user A permitted to read
	if ((userPermission & READ) == READ)
		cout << userId <<  " has READ permission" << endl;
	else
		cout << userId << " has no READ permission" << endl;

	// test if user A permitted to write
	if ((userPermission & WRITE) == WRITE)
		cout << userId << " has WRITE permission" << endl;
	else
		cout << userId << " has no WRITE permission" << endl;

	// test if user A permitted to exececute
	if ((userPermission & EXEC) == EXEC)
		cout << userId << " has EXEC permission" << endl;
	else
		cout << userId << " has no EXEC permission" << endl;
}

void Test01::setUserPermission(unsigned short& userPermission, const unsigned short& setPermission)
{
	// using bitwise OR to turn bits on
	userPermission |= setPermission;
}

void Test01::unsetUserPermission(unsigned short& userPermission, const unsigned short& unsetPermission)
{
	// using bitwise AND complement to turn bits off
	userPermission &= ~unsetPermission;
}
