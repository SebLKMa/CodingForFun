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

1. cppEchoServer starts listening on localhost port 3000 (port cab be passed in as command line args).
2. On accepting connection from client, an independent thread will be started for the client socket.
3. The client thread will receive message and broadcast the message to all connected clients via the Sessions singleton.
4. Sessions is a threadsafe singleton holding a map of IDs and Client Sockets.
5. 
LIMITATIONS:
1. Server Shutdown currently using CTRL-C to kill this process. 
Graceful shutdown should be a client to send a shutdown signal to server or via Windows Services control.
2. Upon detection, Server should remove invalid socket entries from Sessions.
3. Message format now limited to "<LicenceID> <Message>", in theory server should validate client LicenceID.
4. No synchronization of states between servers. 

1. Client cppEchoClient has not been refactored to individual classes.
2. Client limited to 2 connections strings for now.
3. Client only establishes real connection on first send.
4. Client only detects lost connection on receive.
