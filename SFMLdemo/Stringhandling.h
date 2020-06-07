#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory>

class Stringhandling
{
public:
	Stringhandling(const std::string message_in,const sf::RenderWindow& window,const sf::Font font,const float size);
	void Draw(sf::RenderWindow& window) const;

private:
	void makeVecStrings(const std::string& message_in, std::vector<std::string>& str);
	void makeVecText(std::vector<std::unique_ptr<sf::Text>>& veccer);
private:
	const sf::RenderWindow& window;
	const sf::Font& font;
	const float size;
	std::string message; 
	std::vector<std::string> stringies;
	std::vector<std::unique_ptr<sf::Text>> vec;

};

