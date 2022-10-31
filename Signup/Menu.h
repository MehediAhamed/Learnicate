#pragma once
#include "SFML/Graphics.hpp"
#include<iostream>
using namespace std;
#define menu_op 5
class Menu
{
private:
	int MenuSelected;
	sf::Font font1;
	sf::Text menu[menu_op];
	sf::Text headline;
	sf::RectangleShape menbox[menu_op];

public:
		Menu(float width, float height);
		void draw(sf::RenderWindow& window);
		void MoveUp();
		void MoveDown();

		int MenuPressed() {
			return MenuSelected;
		}

};

