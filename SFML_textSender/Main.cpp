#include<SFML/Network.hpp>
#include<Windows.h>
#include<conio.h>
#include<iostream>
#include<sstream>
#include<chrono>
#include<thread>
#include<random>

int main()
{
	bool quitter = false; 
	sf::UdpSocket s;
	if (s.bind(7000) != sf::Socket::Done)
	{
		std::cout << "socket creation failed" << std::endl;
	}
	else
	{
		std::cout << "socket creation success!" << std::endl;
	}
	std::string message = "\0";
	sf::IpAddress recipient = "127.0.0.1";
	unsigned short port = 8000;
	std::cout << "Recipient address : " << recipient << std::endl << "Recipient port : " << port << std::endl; 
	while (!quitter)
	{
		char c = _getch();
		
		if (c == '\b')
		{
			if (message.size() > 0)
			{
				message.pop_back();
			}
		}
		else if (c == '\r')
		{
			message += "\n";
		}
		else
		{
			message += c; 
		}
		
		if (s.send(message.c_str(), 255, recipient, port) != sf::Socket::Done)
		{
			std::cout << "data send fail" << std::endl;
		}
		else
		{
			std::cout << "sending >>" << message << std::endl;
		}
	}
	s.unbind();
	std::cin.get();
	return 0; 
}