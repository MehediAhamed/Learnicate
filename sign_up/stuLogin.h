#pragma once
#include<iostream>
#include "SFML/Graphics.hpp"
#include "../Features/Textbox.h"

using namespace std;
#define logop 4
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
	void LogInStudent(sf::RenderWindow& wind);
};

