/*
 * Socket.h
 *
 *  Created on: 15 Feb 2017
 *      Author: seblkma
 */

#ifndef SOCKET_H_
#define SOCKET_H_
#include <string>
#include <winsock2.h> // The dll libws2_32.a is found in (remove the prefix "lib" and ".o" in Libraries setting
#include <WS2tcpip.h> // C:\msys64\mingw64\x86_64-w64-mingw32\lib

/**
 * This class provides the essential Socket functions.
 * E.g. Accept, listen, bind, send, recv.
 *
 */
class Socket
{
public:
	/**
	 * @port The port to listen on or connect to.
	 */
	Socket(std::string& port);

	/**
	 * @webAddress The hostname address to listen on or connect to.
	 * @port The port to listen on or connect to.
	 */
	Socket(std::string& webAddress, std::string& port);

	/**
	 * @webAddress The hostname address to listen on or connect to.
	 * @port The port to listen on or connect to.
	 * @hints The connection information e.g. protocol
	 */
	Socket(std::string& webAddress, std::string& port, addrinfo& hints);

	/**
	 * Closes the socket and frees socket resources.
	 */
	~Socket();

	Socket(const Socket& other) = delete; // does not support copy
	Socket(Socket&& other); // supports move

	/**
	 * The socket can become invalid when connection is lost.
	 * Checks if the socket is valid.
	 */
	bool IsValid();

	/**
	 * Starts connection.
	 */
	int Connect();

	/**
	 * Binds connection to listening socket
	 */
	int Bind();

	/**
	 * Starts listening on socket.
	 */
	int Listen(int queueSize);

	/**
	 * Starts accepting connection from peers.
	 */
	Socket Accept();

	/**
	 * Sends data to connected peer.
	 */
	SSIZE_T Send(std::stringstream data);

	/**
	 * Receives data from connection peer.
	 */
	std::stringstream Receive();
	void Close();

	/**
	 * Returns the the accepted socket handle. ID is only unique per process.
	 * @return The accepted socket handle.
	 */
	SOCKET GetSocketHandleID();

private:
	Socket(SOCKET newSocket, sockaddr_storage&& socketStorage);
	void CreateSocket(std::string& webAddress, std::string port, addrinfo& hints);

	bool ShutdownSend();
	int SetBlockingMode(u_long mode);

	addrinfo* m_pServerInfo{nullptr};
	SOCKET m_Socket{ static_cast<SOCKET>(0xFFFFFFFF) };
	sockaddr_storage m_AcceptedSocketStorage{};
	socklen_t m_AcceptedSocketSize{ sizeof(m_AcceptedSocketStorage) };
};


#endif /* SOCKET_H_ */
