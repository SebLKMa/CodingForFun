//============================================================================
// Name        : cppEchoServer.cpp
// Author      : seblkma
// Version     :
// Copyright   : copyright(c) seblkma
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <Hello.h>

using namespace std;

int main() {
	//NOTE: remove the prefix "lib" if your DLL name starts with lib...
	//NOTE: the location of DLL has to be in your runtime search PATH
	//See:
	//http://eclipsesource.com/blogs/2010/03/03/shared-libraries-with-eclipse-cdt-and-cygwin-on-windows/
	//https://tayefeh.wordpress.com/2009/07/06/creating-and-using-a-c-shared-library-with-eclipse-cdt-galileo-and-gnu-c-compiler-and-linker/

    Hello myHello;
    const string me{"Seb"};
    string greetings = myHello.getHello(me);

	cout << greetings << endl;

	return 0;
}
