#pragma once
#include<SFML/Network.hpp>

class SocketHandle
{
public:
	SocketHandle(bool setBlocking, const int port);
	std::string GetMessages();
	~SocketHandle();

private:
	sf::UdpSocket socket;
	static constexpr int buffSize = 256;
	char data[buffSize] = { 0 };
	std::size_t received;
	sf::IpAddress sender;
	unsigned short port;
	std::string msg = data;
};

