#include "Stringhandling.h"



Stringhandling::Stringhandling(const std::string message, const sf::RenderWindow& window, const sf::Font font, const float size)
	:
	message(message),
	window(window),
	size(size),
	font(font)
{
}

void Stringhandling::Draw(sf::RenderWindow& window) const 
{
	for (int i = 0; i < stringies.size(); ++i)
	{
		window.draw(*vec[i]);
	}
}

std::vector<std::string> Stringhandling::makeVecStrings(std::string& message)
{
	std::vector<std::string> stringies;
	while (message.find('\n') != std::string::npos)
	{
		std::string temp = message.substr(0, message.find('\n'));
		stringies.push_back(temp);
		message.erase(0, message.find('\n') + 1);

	}
	stringies.push_back(message);
	return stringies;
}

std::vector<std::unique_ptr<sf::Text>> Stringhandling::makeVecText( const std::vector<std::string>& stringies, 
																	const sf::Font& font, 
																	const sf::RenderWindow&  window, 
																	const float& size)
{
	std::vector<std::unique_ptr<sf::Text>> vec;
	for (int i = 0; i < stringies.size(); ++i)
	{
		vec.push_back(std::move(std::make_unique<sf::Text>()));
		vec[i]->setFont(font);
		vec[i]->setCharacterSize(size);
		vec[i]->setFillColor(sf::Color::White);
		vec[i]->setPosition(window.getSize().x / 2, window.getSize().y / 2);
		vec[i]->setString(stringies[i]);

		//Centre current string
		if (vec[i]->getString().getSize() >= 1)
		{

			float offsetX = vec[i]->getLocalBounds().width;
			vec[i]->setPosition((window.getSize().x / 2) - (offsetX / 2), window.getSize().y / 2);


		}
	}
	float totalSize = -(size * vec.size()) / 2.0f;
	for (int i = 0; i < vec.size(); ++i)
	{
		vec[i]->move(0, totalSize);
		totalSize += size;
	}
	return vec; 
}
