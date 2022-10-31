#pragma once
#include<iostream>
#include "SFML/Graphics.hpp"
#include "Textbox.h"

using namespace std;
#define signop 5
class stuSignup
{
private:
	int opselected;
	sf::Font font1;
	sf::Text option[signop];
public:
	
	Textbox tb[signop];
	stuSignup(float width, float height);
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();

	int OptionPressed() {
		return opselected;
	}
};

