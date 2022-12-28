#pragma once
#include<iostream>
#include "SFML/Graphics.hpp"
#include "Teacher.h"
#include"../Features/Textbox.h"


#define signop 6
class TeachSignup
{
private:
	int opselected;
	sf::Font font1;
	sf::Text option[signop];

public:
	Teacher Tobj;
	
	
	Textbox tb[signop];
	TeachSignup(float width, float height);
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	void signT(sf::RenderWindow& window);

	int OptionPressed() {
		return opselected;
	}


	void SignUpTeacher(sf::RenderWindow& wind);
};



