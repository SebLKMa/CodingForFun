libCppSocket.dll must be in runtime path
E.g.:
set PATH=%PATH%;C:\lma\git\codingforfun\cppSockets\Debug

1. cppEchoServer starts listening on localhost port 3000 (port cab be passed in as command line args).
2. On accepting connection from client, an independent thread will be started for the client socket.
3. The client thread will receive message and broadcast the message to all connected clients via the Sessions singleton.
4. Sessions is a threadsafe singleton holding a map of IDs and Client Sockets.
5. 
 
