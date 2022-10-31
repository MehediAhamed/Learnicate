#include "Menu.h"
#define fontcolor sf::Color::White
#define boxcolor sf::Color::Cyan

Menu::Menu(float width, float height) {
	if (!font1.loadFromFile("arial.ttf")) {
		cout << "No font selected" << endl;
	}
	//Sign Up As Teacher:

	menu[0].setFont(font1);
	menu[0].setFillColor(fontcolor);
	menu[0].setString("Sign up As Teacher");
	menu[0].setCharacterSize(20);
	menu[0].setPosition(400, 200);
	

	menbox[0].setPosition(390, 190);
	menbox[0].setFillColor(boxcolor);
	menbox[0].setSize(sf::Vector2f(200, 40));

	//Log in As Teacher:
	menu[1].setFont(font1);
	menu[1].setFillColor(fontcolor);
	menu[1].setString("Log in As Teacher");
	menu[1].setCharacterSize(20);
	menu[1].setPosition(400, 300);

	menbox[1].setPosition(390, 290);
	menbox[1].setFillColor(boxcolor);
	menbox[1].setSize(sf::Vector2f(200, 40));

    //Sign up as Student:
	menu[2].setFont(font1);
	menu[2].setFillColor(fontcolor);
	menu[2].setString("Sign Up As Student");
	menu[2].setCharacterSize(20);
	menu[2].setPosition(400, 400);

	menbox[2].setPosition(390, 390);
	menbox[2].setFillColor(boxcolor);
	menbox[2].setSize(sf::Vector2f(200, 40));

	//Log in as Student:
	menu[3].setFont(font1);
	menu[3].setFillColor(fontcolor);
	menu[3].setString("Log in As Student");
	menu[3].setCharacterSize(20);
	menu[3].setPosition(400, 500);

	menbox[3].setPosition(390, 490);
	menbox[3].setFillColor(boxcolor);
	menbox[3].setSize(sf::Vector2f(200, 40));

    //Back:
	menu[4].setFont(font1);
	menu[4].setFillColor(fontcolor);
	menu[4].setString("Back");
	menu[4].setCharacterSize(20);
	menu[4].setPosition(400, 600);

	menbox[4].setPosition(390, 590);
	menbox[4].setFillColor(boxcolor);
	menbox[4].setSize(sf::Vector2f(200, 40));


	MenuSelected = -1;
}
void Menu::draw(sf::RenderWindow& window) {
    
	for (int i = 0; i < menu_op; i++)
	{
		window.draw(menbox[i]);

	}
	
	for (int i = 0; i < menu_op; i++)
	{
		window.draw(menu[i]);
	}

}
void Menu::MoveUp() {
	if (MenuSelected - 1 >= -1) {
		menu[MenuSelected].setFillColor(fontcolor);

		MenuSelected--;
		if (MenuSelected == -1) {
			MenuSelected = menu_op-1;
		}

		menu[MenuSelected].setFillColor(sf::Color::Red);
	}
}
void Menu::MoveDown() {
	if (MenuSelected + 1 <= menu_op) {
		menu[MenuSelected].setFillColor(fontcolor);

		MenuSelected++;
		if (MenuSelected == menu_op) {
			MenuSelected = 0;
		}

		menu[MenuSelected].setFillColor(sf::Color::Red);
	}
}