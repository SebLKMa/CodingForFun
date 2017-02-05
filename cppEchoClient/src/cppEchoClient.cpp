//============================================================================
// Name        : cppEchoClient.cpp
// Author      : seblkma
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
#include "WinsockWrapper.h"
#include "Socket.h"
//#include <winsock2.h> // The dll libws2_32.a is found in (remove the prefix "lib" and ".o" in Libraries setting
//#include <WS2tcpip.h> // C:\msys64\mingw64\x86_64-w64-mingw32\lib

using namespace std;

void StartClient()
{
	WinsockWrapper myWinsockHelper;

	string address{"localhost"};
	string port{"3000"};
	Socket connectingSocket(address, port);
	connectingSocket.Connect();

	string messageSent{"Beauty is only skin deep."};
	stringstream dataSent;
	dataSent << messageSent;
	connectingSocket.Send(move(dataSent));

	cout << "Sent message." << endl;
}

using namespace std;

int main() {
	StartClient();
	return 0;
}
