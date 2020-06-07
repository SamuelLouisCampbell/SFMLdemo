#include "Stringhandling.h"



Stringhandling::Stringhandling(const std::string message_in, const sf::RenderWindow& window, const sf::Font font, const float size)
	:
	message(message_in),
	window(window),
	size(size),
	font(font)
{
	makeVecStrings(message, stringies);
	makeVecText(vec);
}

void Stringhandling::Draw(sf::RenderWindow& window) const 
{
	for (int i = 0; i < stringies.size(); ++i)
	{
		window.draw(*vec[i]);
	}
}

void Stringhandling::makeVecStrings(const std::string& message_in, std::vector<std::string>& str)
{
	std::string message = message_in;
		if (message.size() >= 1)
	{
		while (message.find('\n') != std::string::npos)
		{
			std::string temp = message.substr(0, message.find('\n'));
			str.push_back(temp);
			message.erase(0, message.find('\n') + 1);

		}
		str.push_back(message);
	}
}

void Stringhandling::makeVecText(std::vector<std::unique_ptr<sf::Text>>& veccer)
{
	for (int i = 0; i < stringies.size(); ++i)
	{
		veccer.push_back(std::move(std::make_unique<sf::Text>()));
		veccer[i]->setFont(font);
		veccer[i]->setCharacterSize(size);
		veccer[i]->setFillColor(sf::Color::White);
		veccer[i]->setPosition(window.getSize().x / 2, window.getSize().y / 2);
		veccer[i]->setString(stringies[i]);

		//Centre current string
		if (veccer[i]->getString().getSize() >= 1)
		{

			float offsetX = veccer[i]->getLocalBounds().width;
			veccer[i]->setPosition((window.getSize().x / 2) - (offsetX / 2), window.getSize().y / 2);


		}
	}
	float totalSize = -(size * veccer.size()) / 2.0f;
	for (int i = 0; i < veccer.size(); ++i)
	{
		veccer[i]->move(0, totalSize);
		totalSize += size;
	}
}
