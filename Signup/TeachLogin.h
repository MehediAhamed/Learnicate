#pragma once
#include<iostream>
#include "SFML/Graphics.hpp"
#include "Textbox.h"
#include "Teacher.h"
using namespace std;
#define logop 3
class TeachLogin
{
private:
	int opselected;
	sf::Font font1;
	sf::Text option[logop];
public:
	Teacher teach;
	Textbox tb[logop];
	TeachLogin(float width, float height);
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();

	int OptionPressed() {
		return opselected;
	}
};

