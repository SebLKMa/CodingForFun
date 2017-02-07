/*
 * Socket.cpp
 *
 *  Created on: 5 Feb 2017
 *      Author: likke
 */
#include <sstream>
#include <cassert>
#include <iostream>
#include "Socket.h"

using namespace std;

Socket::Socket(std::string& port)
{
	stringstream portStream{port};
	int portNumber;
	portStream >> portNumber;
	assert(portNumber > 1024); // ports under 1024 are reserved !

	addrinfo hints{};
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	string address{""};
	CreateSocket(address, port, hints);
}

Socket::Socket(std::string& webAddress, std::string& port)
{
	addrinfo hints{};
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	CreateSocket(webAddress, port, hints);
}

Socket::Socket(std::string& webAddress, std::string& port, addrinfo& hints)
{
	CreateSocket(webAddress, port, hints);
}

Socket::~Socket()
{
	Close();
}

Socket::Socket(Socket&& other)
	: m_pServerInfo(other.m_pServerInfo),
	  m_Socket(other.m_Socket),
	  m_AcceptedSocketStorage(other.m_AcceptedSocketStorage),
	  m_AcceptedSocketSize(other.m_AcceptedSocketSize)
{
	if (this != &other)
	{
		other.m_pServerInfo = nullptr;
		other.m_Socket = -1;
		other.m_AcceptedSocketStorage = sockaddr_storage();
		other.m_AcceptedSocketSize = sizeof(other.m_AcceptedSocketStorage);
	}
}

bool Socket::IsValid()
{
	return m_Socket != -1;
}

int Socket::Connect()
{
	int connectionResult{ connect(m_Socket, m_pServerInfo->ai_addr, m_pServerInfo->ai_addrlen) };
	if (connectionResult == -1)
	{
		cout << "Connection failed!" << endl;
	}
	else
	{
		cout << "Connection successful" << endl;
	}
	return connectionResult;
}

int Socket::Bind()
{
	int bindResult{ ::bind(m_Socket, m_pServerInfo->ai_addr, m_pServerInfo->ai_addrlen) };
	if (bindResult == -1)
	{
		cout << "Bind failed!" << endl;
	}
	else
	{
		cout << "Bind successful" << endl;
	}
	return bindResult;
}

int Socket::Listen(int queueSize)
{
	int listenResult{ listen(m_Socket, queueSize) };
	if (listenResult == -1)
	{
		cout << "Listen failed!" << endl;
	}
	else
	{
		cout << "Listen successful" << endl;
	}
	return listenResult;
}

Socket Socket::Accept()
{
	SOCKET newSocket{ accept(
						m_Socket,
						reinterpret_cast<sockaddr*>(&m_AcceptedSocketStorage),
						&m_AcceptedSocketSize) };
	if (newSocket == -1)
	{
		cout << "Accept failed!" << endl;
	}
	else
	{
		cout << "Accept successful" << endl;
	}

	m_AcceptedSocketSize = sizeof(m_AcceptedSocketStorage);
	return Socket(newSocket, move(m_AcceptedSocketStorage));
}

SSIZE_T Socket::Send(std::stringstream data)
{
	string packetData{ data.str() };
	SSIZE_T sendResult{ send(m_Socket, packetData.c_str(), packetData.length(), 0) };
	if (sendResult == -1)
	{
		cout << "Send failed! " << data.str() << endl;
	}
	else
	{
		cout << "Send successful " << data.str() <<  endl;
	}
	return sendResult;
}

std::stringstream Socket::Receive()
{
	cout << "Receive waiting..." << endl;

	const int dataSize{ 1024 };
	char dataReceived[dataSize];

	SSIZE_T receiveResult{ recv(m_Socket, dataReceived, dataSize, 0) };
	if (receiveResult == -1)
	{
		cout << "Receive failed!" << endl;
	}
	else if (receiveResult == 0)
	{
		cout << "Receive detected closed connection !" << endl;
	}
	else
	{
		cout << "Receive successful" << endl;
	}

	// http://stackoverflow.com/questions/14404202/receiving-strange-characters-symbols-in-winsock
	dataReceived[receiveResult] = 0;

	stringstream data{ dataReceived };
	return move(data);
}

void Socket::Close()
{
	closesocket(m_Socket);
	m_Socket = -1;
	freeaddrinfo(m_pServerInfo);
}


Socket::Socket(SOCKET newSocket, sockaddr_storage&& socketStorage)
	: m_Socket {newSocket}, m_AcceptedSocketStorage { move(socketStorage) }
{
}

void Socket::CreateSocket(std::string& webAddress, std::string port, addrinfo& hints)
{
	getaddrinfo(webAddress.c_str(), port.c_str(), &hints, &m_pServerInfo);
	m_Socket = socket(m_pServerInfo->ai_family, m_pServerInfo->ai_socktype, m_pServerInfo->ai_protocol);;
}

