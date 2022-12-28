#pragma once
#include "SFML/Graphics.hpp"
#include<iostream>

#define menu_op 3
class tsub_menu
{
private:
	int MenuSelected;
	sf::Font font1;
	sf::Text menu[menu_op];
	sf::Text headline;
	sf::RectangleShape menbox[menu_op];

public:

	tsub_menu(float width, float height);
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();

	int MenuPressed() {
		return MenuSelected;
	}
	void tsub_display(sf::RenderWindow& wind);


};

