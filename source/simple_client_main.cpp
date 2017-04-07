
#include <iostream>
#include <string>

#include "../headers/ClientSocket.h"
#include "../headers/SocketException.h"

int main ( int argc, int argv[] ) {
	
   try
   {

   ClientSocket client_socket ( "localhost", 30000 );

   std::string reply;

   try {
	   
   client_socket << "Connection was successfully established";
   client_socket >> reply;
	}
     
   catch ( SocketException& ) {}

   std::cout << "We received this response from the server:\n\"" << reply << "\"\n";

    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\n";
    }

  return 0;
}
