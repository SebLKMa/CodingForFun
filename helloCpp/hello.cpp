// helloCppConsole.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h" not using pre-compiled headers
#include <iostream>
#include <memory>
#include <utility>
#include <iomanip>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>
#include "Greet.h"
#include "HelloContainers.h"
#include "inheritance\DerivedC.h"
#include "copymove\MemoryPage.h"
#include "loops\Loops.h"
#include "algorithms\ArraySorter.h"
#include "templates\TArray.h"
#include "datastructures\TruckloadList.h"
#include "Box.h"

using namespace std;

void testLoops()
{
	Loops myLoops;
	myLoops.DoLoop1();
}

void testArraySorter()
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
}

void testInheritanceInStack()
{
	cout << "testInheritanceInStack" << endl;
	DerivedC myC;
	myC.sayHello();

	DerivedB myB = static_cast<DerivedB>(myC);
	myB.sayHello();
}

void testInheritanceInHeap()
{
	cout << "testInheritanceInHeap" << endl;

	Base* pBase = new DerivedC();
	cout << "pBase created" << endl;
	if (nullptr != pBase)
	{
		DerivedC* pDerivedC = dynamic_cast<DerivedC*>(pBase);
		if (pDerivedC)
		{
			pDerivedC->sayHello();
		}

		delete pBase;
		cout << "pBase destroyed" << endl;
	}
}

void testInheritanceInHeap2()
{
	cout << "testInheritanceInHeap2" << endl;

	Base* pBase = new DerivedA();
	cout << "pBase created" << endl;
	if (nullptr != pBase)
	{
		pBase->sayHi();

		delete pBase;
		cout << "pBase destroyed" << endl;
	}
}

void testCpp11unique_ptr()
{
	cout << "testCpp11unique_ptr()\n"
		<< "- same behavior as testInheritanceInHeap2()\n"
		<< "unique_ptr frees ownership when out of scope."
		<< endl;
	unique_ptr<Base> pA(new DerivedA);  // pA owns DerivedA
	pA->sayHi();
}

void testCpp11unique_ptr_Move()
{
	cout << "testCpp11unique_ptr_Move()\n"
		<< "- same behavior as testCpp11unique_ptr()\n"
		<< "std::move passes ownership of unique_ptr."
		<< endl;
	unique_ptr<DerivedA> pA(new DerivedA);   // pA owns DerivedA
	pA->sayHi();
	unique_ptr<DerivedA> pB = std::move(pA); // passes ownership to pB
	pB->sayHi();
}

void testCpp11shared_ptr2(shared_ptr<Base> pBase)
{
	cout << "testCpp11shared_ptr2() ref counted ptr" << endl;
	pBase->sayHi();
}

void testCpp11shared_ptr1()
{
	// ref counted ptr points to the same object, will be deleted when ref count becomes zero
	cout << "testCpp11shared_ptr1() ref counted ptr" << endl;
	shared_ptr<Base> pA(new DerivedA);   //
	pA->sayHi();
	testCpp11shared_ptr2(pA);
}

void testCpp11()
{
	cout << "testCpp11" << endl;

	//auto text = unique_ptr<char[]>(new char[42]);

	unique_ptr<DerivedC> p1(new DerivedC);  // p1 owns DerivedC
	/*
	if (p1) p1->bar();
	{
	std::unique_ptr<Foo> p2(std::move(p1));  // now p2 owns Foo
	f(*p2);

	p1 = std::move(p2);  // ownership returns to p1
	std::cout << "destroying p2...\n";
	}

	if (p1) p1->bar();
	*/

	// Foo instance is destroyed when p1 goes out of scope

}

void testCopy()
{
	cout << "testCopy" << endl;
	MemoryPage myPage(1024);
	MemoryPage myPage1 = myPage; // copy ctor
}

void testAssignment()
{
	cout << "testAssignment" << endl;
	MemoryPage myPage2(1024);
	MemoryPage myPage3(512);
	cout << "myPage2: " << myPage2.getSize() << endl;
	cout << "myPage3: " << myPage3.getSize() << endl;
	myPage2 = myPage3; // assignment ctor
	cout << "myPage2: " << myPage2.getSize() << endl;
}

void testMove()
{
	cout << "testMove" << endl;
	MemoryPage myPage(1024);
	MemoryPage myPage1 = std::move(myPage); // force move ctor
}

void testByteOrder()
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

void sayHello(int secs)
{
	cout << "Hello started" << endl;
	for (int i = 0; i<secs; ++i)
	{
		cout << i << endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	cout << "Hello completed " << endl;
}

void testThread()
{
	std::thread myThread;
	myThread = std::thread(sayHello, 3);
	//myThread.join();
	myThread.detach();
}

mutex myMutex;
void threadSafeCout(int i)
{
	lock_guard<mutex> myGuard(myMutex);
	cout << " " << i << "";
}

void doForLoop(int max)
{
	for (int i = 10 * (max - 1); i < 10 * max; i++)
	{
		threadSafeCout(i);
	}
}

void testThreads()
{
	cout << endl;
	cout << "testThreads()" << endl;
	thread t1(doForLoop, 1); //  0 - 9
	thread t2(doForLoop, 2); // 10 - 19
	thread t3(doForLoop, 3); // 20 - 29
	thread t4(doForLoop, 4); // 30 - 39
	thread t5(doForLoop, 5); // 40 - 49

	for (int i = 0; i > -50; i--)
	{
		threadSafeCout(i);   // 0, -49
	}

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();

	// NOTE that deadlock can also happen without locks.
	// Example:
	// thread 1 calls join on thread 2
	// thread 2 calls join on thread 1
	// Therefore, do not wait for another thread of there is a chance
	// the other thread is waiting for you.
}

mutex myMutex1, myMutex2;
void deadlockableCoutEven(int i)
{
	// attempt to acquire lock 1
	lock_guard<mutex> myGuard1(myMutex1);
	// ... do some operations here

	// attempt to acquire lock 2
	lock_guard<mutex> myGuard2(myMutex2);

	cout << " " << i << " ";
}

void deadlockableCoutOdd(int i)
{
	// attempt to acquire lock 2
	lock_guard<mutex> myGuard2(myMutex2);
	// ... do some operations here

	// attempt to acquire lock 1
	lock_guard<mutex> myGuard1(myMutex1);
	
	cout << " " << i << " ";
}

void doForLoopEvenOdd(int max)
{
	for (int i = 10 * (max - 1); i < 10 * max; i++)
	{
		if (i % 2 == 0)
		{
			deadlockableCoutEven(i);
		}
		else
		{
			deadlockableCoutOdd(i);
		}
	}
}

void testDeadlockThreads()
{
	cout << endl;
	cout << "testDeadlockThreads()" << endl;

	thread t1(doForLoopEvenOdd, 1); //  0 - 9
	thread t2(doForLoopEvenOdd, 2); // 10 - 19
	thread t3(doForLoopEvenOdd, 3); // 20 - 29
	thread t4(doForLoopEvenOdd, 4); // 30 - 39
	thread t5(doForLoopEvenOdd, 5); // 40 - 49

	for (int i = 0; i > -50; i--)
	{
		threadSafeCout(i);   // 0, -49
	}

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();

	// Prevent deadlock by acquiring locks in the same order.
}

void testTArray()
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

// gemerate a random integer 1 to count
inline size_t random(size_t count)
{
	return 1 + static_cast<size_t>(count * static_cast<double>(std::rand()) / RAND_MAX+1.0);
}

void testTruckloadList()
{
	const size_t dimLimit {99}; // upper limit on Box dimensions
	std::srand((unsigned)std::time(0)); // initialize random number generator

	TruckloadList list1;
	// add 12 random boxes to list
	const size_t boxCount {12};
	for (size_t i{}; i<boxCount; ++i)
	{
		list1.addBox(std::make_shared<Box>(random(dimLimit), random(dimLimit), random(dimLimit)));
	}
	cout << "The first list:\n";
	list1.listBoxes();

	// Find the largest Box in the list
	shared_ptr<Box> pBox {list1.getFirstBox()};
	shared_ptr<Box> pNextBox {};
	while (pNextBox = list1.getNextBox()) // assign then test to next Box
	{
		if (pBox->compare(*pNextBox) < 0)
			pBox = pNextBox;
	}
	cout << "\nThe largest box in the first list is:";
	pBox->listBox();
	cout << endl;
	// list1.deleteBox(pBox);
	// cout << "\nAfter deleting the largest box, the list contains:\n";
	// list1.listBoxes();

	const size_t NBOXES{20};
	vector<shared_ptr<Box>> boxes;
	for (size_t i{}; i<NBOXES; ++i)
	{
		boxes.push_back(make_shared<Box>(random(dimLimit), random(dimLimit), random(dimLimit)));
	}

	TruckloadList list2(boxes);
	cout << "\nThe second list:\n";
	list2.listBoxes();

	pBox = list2.getFirstBox();
	while (pNextBox = list2.getNextBox())
	{
		if (pBox->compare(*pNextBox) > 0)
		{
			pBox = pNextBox;
		}
	}

	cout << "\nThe smallest box in the first list is:";
	pBox->listBox();
	cout << endl;
}

int main() {

	//testLoops();
	//testArraySorter();

	//Greet greeter;
	//greeter.sayHello();

	//HelloContainers myContainers;
	//myContainers.helloVector();

	//testInheritanceInStack();
	//testInheritanceInHeap();
	//testCpp11();
	testInheritanceInHeap2();
	testCpp11unique_ptr();
	testCpp11unique_ptr_Move();
	testCpp11shared_ptr1();
	
	//testCopy();
	//testAssignment();
	//testMove();

	//testByteOrder();
	//testThread();

	//testThreads();
	//testDeadlockThreads();
	
	//testTArray();

	testTruckloadList();

	cout << endl;
	cout << "Q or q key to quit...";
	char chWait;
	cin >> chWait;

	return 0;
}
