#include<SFML/Graphics.hpp>
#include<Windows.h>
#include<iostream>
#include<thread>
#include"SocketHandle.h"

int main()
{
	SocketHandle s = { false, 8000 };
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "A&B text render");


	sf::Text text; 
	sf::Font font; 
	text.setFont(font);
	text.setCharacterSize(72);
	text.setFillColor(sf::Color::White);
	text.setPosition(window.getSize().x / 2, window.getSize().y /2);

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
		
		text.setString(s.GetMessages());
		
		//Centre justify string
		if (text.getString().getSize() >= 1)
		{
			float offsetX = text.getLocalBounds().width;
			float offsetY = text.getLocalBounds().height;
			text.setPosition((window.getSize().x / 2) - (offsetX/2), (window.getSize().y / 2) - (offsetY / 2));
		}

		//Draw window and contents
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(text);
		window.display();
		//sleep a while
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(0.05s);
	}

	return 0;
}