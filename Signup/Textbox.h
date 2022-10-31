#pragma once
#include<iostream>
#include "SFML/Graphics.hpp"
#include <sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27
class Textbox
{
private:
	sf::Text textb;
	std::ostringstream text;
	bool isSelected = false;
	bool hasLimit = false;
	int limit = 0;

	void inputL(int charTyped);
	void deleteLastChar();
public:
	Textbox() {
	}
	Textbox(int size, sf::Color color, bool sel);
	void setSize(int size);
	void setColor(sf::Color color);
	void setFont(sf::Font& font);
	void setPosition(sf::Vector2f pos);
	void setLimit(bool Tof);
	void setLimit(bool Tof, int lim);
	void setSelected(bool sel);
	std::string getText();
	void drawTo(sf::RenderWindow& window);
	void typedOn(sf::Event input);
};

