#pragma once
#include<iostream>
#include "SFML/Graphics.hpp"
#include "Textbox.h"

using namespace std;
#define logop 3
class stuLogin
{
private:
	int opselected;
	sf::Font font1;
	sf::Text option[logop];
public:
	
	Textbox tb[logop];
	stuLogin(float width, float height);
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();

	int OptionPressed() {
		return opselected;
	}
};

