#include "SocketHandle.h"
#include <iostream>

SocketHandle::SocketHandle(bool setBlocking, const int port)
{
	if (socket.bind(port) != sf::Socket::Done)
	{
		std::cout << "socket failed" << std::endl;
	}
	socket.setBlocking(setBlocking);

}

std::string SocketHandle::GetMessages()
{
	if (socket.receive(data, buffSize, received, sender, port) != sf::Socket::Done)
	{
		std::cout << "no message detected" << std::endl;
	}
	std::cout << "Received " << received << " bytes from " << sender << " on port " << port << std::endl;
	std::cout << data << std::endl;
	std::string message = data; 
	return message; 
}

SocketHandle::~SocketHandle()
{
	socket.unbind();
}
