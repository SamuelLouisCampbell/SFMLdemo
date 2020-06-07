#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory>

class Stringhandling
{
public:
	Stringhandling(const std::string message,const sf::RenderWindow& window,const sf::Font font,const float size);
	void Draw(sf::RenderWindow& window) const;

private:
	std::vector<std::string> makeVecStrings(std::string& message);
	std::vector<std::unique_ptr<sf::Text>> makeVecText( const std::vector<std::string>& stringies,
														const sf::Font& font,
														const sf::RenderWindow& window,
														const float& size);
private:
	const sf::Window& window;
	const sf::Font& font;
	const float size;
	std::string message; 
	std::vector<std::string> stringies = makeVecStrings(message);
	std::vector<std::unique_ptr<sf::Text>> vec;

};

