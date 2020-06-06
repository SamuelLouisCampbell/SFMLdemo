#include<SFML/Graphics.hpp>
#include<Windows.h>
#include<iostream>
#include<thread>
#include"SocketHandle.h"
#include <memory>
#include <vector>

int main()
{
	const int port = 8000; 
	const std::string info = "A&B text render, bound to port: " + std::to_string(port); 
	SocketHandle s = { false, port };
	sf::RenderWindow window(sf::VideoMode(1920, 1080), info.c_str());


	sf::Font font; 


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
		std::vector<std::unique_ptr<sf::Text>> vec; 
		vec.push_back(std::move(std::make_unique<sf::Text>()));
		//sf::Text text; 

		vec[0]->setFont(font);
		vec[0]->setCharacterSize(72);
		vec[0]->setFillColor(sf::Color::White);
		vec[0]->setPosition(window.getSize().x / 2, window.getSize().y / 2);
		//Get messages from UDP socket.
		std::string message = s.GetMessages();

		vec[0]->setString(message);
		
		//Centre justify string
		if (vec[0]->getString().getSize() >= 1)
		{
			float offsetX = vec[0]->getLocalBounds().width;
			float offsetY = vec[0]->getLineSpacing();
			vec[0]->setPosition((window.getSize().x / 2) - (offsetX/2), (window.getSize().y / 2) - (offsetY / 2));
		}

		//Draw window and contents
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(*vec[0]);
		window.display();
		//sleep a while
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(0.05s);
	}

	return 0;
}