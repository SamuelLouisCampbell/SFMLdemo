#include<SFML/Graphics.hpp>
#include<Windows.h>
#include<iostream>
#include<thread>
#include"SocketHandle.h"
#include <memory>
#include <vector>
#include "Stringhandling.h"

int main()
{
	const int port = 8000; 
	const std::string info = "Text To Screen, bound to port: " + std::to_string(port); 
	SocketHandle s = { false, port };
	sf::RenderWindow window(sf::VideoMode(1920, 1080), info.c_str());


	sf::Font font; 
	const float size = 72.0f;

	if (!font.loadFromFile("Helvetica.ttf"))
	{
		OutputDebugStringA("Cannot load font\n");
	}
	else
	{
		OutputDebugStringA("Loaded font file OK!\n");
	}
	while (window.isOpen())
	{

		//Get messages from UDP socket.
		std::string message = "Hello!\nYou!"; //s.GetMessages();
		Stringhandling sh = { message, window, font, size };
		//std::vector<std::string> stringies;

		//while (message.find('\n') != std::string::npos)
		//{
		//	std::string temp = message.substr(0, message.find('\n'));
		//	stringies.push_back(temp);
		//	message.erase(0, message.find('\n') + 1);
	
		//}
		//stringies.push_back(message);
	
		////vectors of text objects.
		//std::vector<std::unique_ptr<sf::Text>> vec; 
		//for (int i = 0; i < stringies.size(); ++i)
		//	{
		//		vec.push_back(std::move(std::make_unique<sf::Text>()));
		//		vec[i]->setFont(font);
		//		vec[i]->setCharacterSize(size);
		//		vec[i]->setFillColor(sf::Color::White);
		//		vec[i]->setPosition(window.getSize().x / 2, window.getSize().y / 2);
		//		vec[i]->setString(stringies[i]);

		//		//Centre current string
		//		if (vec[i]->getString().getSize() >= 1)
		//		{
		//			
		//			float offsetX = vec[i]->getLocalBounds().width;
		//			vec[i]->setPosition((window.getSize().x / 2) - (offsetX / 2), window.getSize().y / 2);
		//								
		//			
		//		}
		//	}
		//float totalSize = -(size * vec.size()) / 2.0f;
		//for (int i = 0; i < vec.size(); ++i)
		//{
		//	vec[i]->move(0, totalSize);
		//	totalSize += size;

		//}


		//Draw window and contents
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		/*for (int i = 0; i < stringies.size(); ++i)
		{
			window.draw(*vec[i]);
		}*/
		sh.Draw(window);
		window.display();

		//sleep a while
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(0.05s);
	}

	return 0;
}