#include "src/src/ServerSocket.h"
#include "src/src/SocketException.h"
#include <string>
#include <iostream>

int main (int argc, int argv[])
{
  std::cout << "### SERVER: status ON\n";

  try
    {
      // Create the socket
      ServerSocket server (30000);
	  std::cout << "### SERVER: listening...\n";

      while ( true )
	{

	  ServerSocket new_sock;
	  server.accept (new_sock);

	  try
	    {
	      while ( true )
		{
		  std::string data;
		  new_sock >> data;
		  int charNumber = data.size();
		  std::cout << "Received message:\n" << data << std::endl;
		  std::string response = std::to_string(charNumber);
		  new_sock << response;
		}
	    }
	  catch ( SocketException& ) {}

	}
    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }

  return 0;
}
