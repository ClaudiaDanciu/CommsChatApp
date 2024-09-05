# C++ TCP Chat Application using OOP

This project implements a simple TCP-based chat application using object-oriented programming (OOP) principles in C++. 
The communication is established between two applications running as a **server** and a **client** on the same machine using sockets. 
The chat allows messages to be exchanged between the client and the server indefinitely until the client types "QUIT", which will terminate both applications.

## Features
- Object-oriented design with inheritance and polymorphism.
- `Comms` class contains shared networking functionality between the client and server.
- `Server` class manages the server-side operations: listening for connections and responding to client messages.
- `Client` class manages the client-side operations: connecting to the server and sending messages.
- Communication uses TCP sockets to send and receive messages.
- Graceful termination when the client sends "QUIT".

## Requirements
- C++ Compiler: Must support C++11 (or later).
- Operating System: Tested on macOS and Linux. Should work on Windows with minor adjustments.
- Networking Support: The program runs over TCP sockets and requires network support.

## How to Compile and Run

###Step 1: Clone the repository:
git clone https://github.com/ClaudiaDanciu/CommsChatApp

###Step 2: Compile the Code
To compile the project, use the following command to enable C++11:
g++ -std=c++11 Main.cpp -o CommsChatApp

###Step 3:Run the Server:
1. Open a Terminal window for the server.
2. Ensure that the preprocessor directive #define SERVER_MODE is uncommented in Main.cpp to run the server:
#define SERVER_MODE // Uncomment for server mode
3. Compile and run the server:
g++ -std=c++11 Main.cpp -o CommsChatApp
./CommsChatApp
4. The server will start and wait for a client connection:
Server initialized and waiting for connections...
###Step 4: Run the Client
1. Open another Terminal window for the client.
2. Ensure that the preprocessor directive #define SERVER_MODE is commented out in Main.cpp to run the client:
//#define SERVER_MODE // Comment for client mode
3. Compile and run the client:
g++ -std=c++11 Main.cpp -o CommsChatApp
./CommsChatApp
4. The client will connect to the server, and you can start exchanging messages.
###Step 5: Exchange Messages: 
- After running the client, type a message in the client terminal
- The server will receive the message and can respond
- This process will repeat until the client types "QUIT"
- Once "QUIT" is sent, both the server and client will terminate.

 


