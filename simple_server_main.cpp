
// Main function

#include <string>
#include <iostream>

#include "headers/ServerSocket.h"
#include "headers/SocketException.h"


int main ( int argc, int argv[] ) {
	
   std::cout << "running....\n";  // wainting for a client to send a message 

   try {
	   
// Create the socket
   
   ServerSocket server ( 30000 );

   while ( true )
   {

   ServerSocket new_sock;
   server.accept ( new_sock );

   try {
	   
   while ( true ) {
	   
   std::string data;
   new_sock >> data;
   std::cout << data ; //Display the Error sent from the client
   new_sock << data;
   }
	   }
   catch ( SocketException& ) {}
   }
   }
  
   catch ( SocketException& e ) {
	   
   std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
   }

   return 0;

}
