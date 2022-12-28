#pragma once

#include<iostream>
#include<SFML/System.hpp>
#include"../Features/Button.h"
#include"../Features/Textbox.h"
#include<SFML/Graphics.hpp>

#include<string>
#include <fstream>


#define Main_Menu_Opt 3
class Main_Menu
{
protected:
	int menuIndex;
	sf::Font font, font2;
	sf::Text menu[Main_Menu_Opt];
	sf::Text headline;

	int MenuSelected;
	
	


public:


	Main_Menu();
	Main_Menu(float width, float height);
	~Main_Menu();

	virtual void draw(sf::RenderWindow& window);
	virtual void MoveUp();
	virtual void MoveDown();
	int getPressed();
	virtual void syllabus(sf::RenderWindow& window);
	virtual void notice(sf::RenderWindow& window);

	void mainmenu(sf::RenderWindow& window);



	virtual int MenuPressed();
	void operator = (sf::RenderWindow& window);
};


