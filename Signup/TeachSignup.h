#pragma once
#include<iostream>
#include "SFML/Graphics.hpp"
#include "Textbox.h"
#include "Teacher.h"
using namespace std;
#define signop 5
class TeachSignup
{
private:
	int opselected;
	sf::Font font1;
	sf::Text option[signop];
public:
	Teacher teach;
	Textbox tb[signop];
	TeachSignup(float width, float height);
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();

	int OptionPressed() {
		return opselected;
	}
};

