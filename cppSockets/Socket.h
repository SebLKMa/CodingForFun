/*
 * Socket.h
 *
 *  Created on: 5 Feb 2017
 *      Author: likke
 */

#ifndef SOCKET_H_
#define SOCKET_H_
#include <string>
#include <winsock2.h> // The dll libws2_32.a is found in (remove the prefix "lib" and ".o" in Libraries setting
#include <WS2tcpip.h> // C:\msys64\mingw64\x86_64-w64-mingw32\lib

class Socket
{
public:
	Socket(std::string& port);
	Socket(std::string& webAddress, std::string& port);
	Socket(std::string& webAddress, std::string& port, addrinfo& hints);
	~Socket();

	Socket(const Socket& other) = delete; // does not support copy
	Socket(Socket&& other); // supports move

	bool IsValid();
	int Connect();
	int Bind();
	int Listen(int queueSize);
	Socket Accept();
	SSIZE_T Send(std::stringstream data);
	std::stringstream Receive();
	void Close();

	int SetBlockingMode(u_long mode);

private:
	Socket(SOCKET newSocket, sockaddr_storage&& socketStorage);
	void CreateSocket(std::string& webAddress, std::string port, addrinfo& hints);

	addrinfo* m_pServerInfo{nullptr};
	SOCKET m_Socket{ static_cast<SOCKET>(0xFFFFFFFF) };
	sockaddr_storage m_AcceptedSocketStorage{};
	socklen_t m_AcceptedSocketSize{ sizeof(m_AcceptedSocketStorage) };
};


#endif /* SOCKET_H_ */
