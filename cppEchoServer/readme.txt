 This project is built using Eclipse C/C++ Development Tool (in particular MSYS64, MinGW GCC)
 
	NOTE:
	remove the prefix "lib" if your DLL name starts with lib...
	the location of DLL has to be in your runtime search PATH
	See:
	http://eclipsesource.com/blogs/2010/03/03/shared-libraries-with-eclipse-cdt-and-cygwin-on-windows/
	https://tayefeh.wordpress.com/2009/07/06/creating-and-using-a-c-shared-library-with-eclipse-cdt-galileo-and-gnu-c-compiler-and-linker/

libCppSocket.dll must be in runtime path
E.g.:
set PATH=%PATH%;C:\lma\git\codingforfun\cppSockets\Debug

//ProtocolTask task{ref(acceptingSocket)};
//async(launch::async, &BaseTask::Execute, &task); // http://stackoverflow.com/questions/22242719/what-is-the-difference-between-async-and-thread-detach

// See:
// https://www.codeproject.com/Articles/412511/Simple-client-server-network-using-Cplusplus-and-W
// http://stackoverflow.com/questions/15382316/where-does-winsock-store-ip-address-of-a-socket
// http://stackoverflow.com/questions/26454836/winsock2-c-multiple-sockets-stored-as-one
// https://www.codeproject.com/Articles/4016/Server-Client-Sockets
// https://www.codeproject.com/Articles/2477/Multi-threaded-Client-Server-Socket-Class
// http://www.dreamincode.net/forums/topic/228484-server-broadcasting-message-to-all-clients-vs-c/

RELEASE NOTES:
This project serves to demonstrate the concepts required in building process communications applications.
It has not yet reached a matured and stable release.

1. cppEchoServer starts listening on localhost. Port is be passed in as command line argument.
2. On accepting connection from client, an independent thread will be started for the client socket.
3. The client thread will receive message and broadcast the message to all connected clients via the Sessions singleton.
4. Sessions is a threadsafe singleton holding a map of IDs and Client Sockets.
5. 
LIMITATIONS:
1. Server current spawns one thread for each client connection. This should be improved for scalability.
2. Server Shutdown currently using CTRL-C to kill this process. 
Graceful shutdown should be a client to send a shutdown signal to server or via Windows Services control.
3. Upon detection, Server should remove invalid socket entries from Sessions.
4. Message format now limited to "<LicenceID> <Message>".
In theory, server should validate LicenceID from client, i.e. client is allowed to use the server operation.
5. No synchronization of states between servers. 

1. Client cppEchoClient has not been refactored to individual classes.
2. Client limited to 2 connections strings for now.
3. Client establishes real connection on first send.
4. Client detects lost connection on receive thread. Currently it does not notify lost connection to main sending thread.
5. Client would prompt user to re-send message on lost connection.

