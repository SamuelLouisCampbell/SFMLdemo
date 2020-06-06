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
		/*using namespace std::chrono_literals;
		auto start = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(0.05s);
		auto end = std::chrono::high_resolution_clock::now();

		std::chrono::duration<float, std::milli> elapsed = end - start;*/
		//+ std::to_string(elapsed.count());

		char c = _getch();
		if (c == '\b')
		{
			if (message.size() > 0)
			{
				message.pop_back();
			}
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
	std::cin.get();
	return 0; 
}