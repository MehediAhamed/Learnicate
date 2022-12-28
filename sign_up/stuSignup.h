#pragma once
#include<iostream>
#include "SFML/Graphics.hpp"
#include "../sign_up/Student.h"
#include"../Features/Textbox.h"

using namespace std;
#define signop 6
class stuSignup
{
private:
	int opselected;
	sf::Font font1;
	sf::Text option[signop];
	Student Sobj;
public:

	Textbox tb[signop];
	stuSignup(float width, float height);
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();

	int OptionPressed() {
		return opselected;
	}
	void SignUpStudent(sf::RenderWindow& wind);
};

