// Definition of the ClientSocket class

#ifndef ClientSocket_class
#define ClientSocket_class


#include "SocketException.h"
#include <iostream>
#include "Socket.h"


class ClientSocket : private Socket
{
 public:

  ClientSocket ( std::string host, int port );
  virtual ~ClientSocket(){};

  const ClientSocket& operator << (const std::string& ) const;
  const ClientSocket& operator >> ( std::string& ) const;

};

// Implementation of the ClientSocket class




ClientSocket::ClientSocket ( std::string host, int port )
{
  if ( ! Socket::create() )
    {
      throw SocketException ( "Could not create client socket." );
    }

  if ( ! Socket::connect ( host, port ) )
    {
      throw SocketException ( "Could not bind to port." );
    }

  std::cout << "### CLIENT: Socket on " << host << " established on port " << port << std::endl;

}


const ClientSocket& ClientSocket::operator << (const std::string& s ) const
{
  if ( ! Socket::send ( s ) )
    {
      throw SocketException ( "Could not write to socket." );
    }

  return *this;

}


const ClientSocket& ClientSocket::operator >> ( std::string& s ) const
{
  if ( ! Socket::recv ( s ) )
    {
      throw SocketException ( "Could not read from socket." );
    }

  return *this;
}


#endif
