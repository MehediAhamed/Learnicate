#include "stuSignup.h"
#define fontcolor sf::Color::White
#define boxcolor sf::Color::Cyan

stuSignup::stuSignup(float width, float height) {
	if (!font1.loadFromFile("resources\\ttf\\arial.ttf")) {
		cout << "No font selected" << endl;
	}



	/*option[0].setFont(font1);
	option[0].setFillColor(fontcolor);
	option[0].setString("Sign up As Teacher");
	option[0].setCharacterSize(20);
	option[0].setPosition(400, 200);*/


	option[0].setFont(font1);
	option[0].setFillColor(fontcolor);
	option[0].setString("Enter Name: ");
	option[0].setCharacterSize(20);
	option[0].setPosition(300, 200);

	tb[0].setSize(20);
	tb[0].setColor(sf::Color::White);
	tb[0].setSelected(false);
	tb[0].setFont(font1);
	tb[0].setPosition({ 465,200 });
	tb[0].setLimit(true, 20);

	option[1].setFont(font1);
	option[1].setFillColor(fontcolor);
	option[1].setString("Enter Email: ");
	option[1].setCharacterSize(20);
	option[1].setPosition(300, 300);

	tb[1].setSize(20);
	tb[1].setColor(sf::Color::White);
	tb[1].setSelected(false);
	tb[1].setFont(font1);
	tb[1].setPosition({ 465,300 });
	tb[1].setLimit(true, 20);

	option[2].setFont(font1);
	option[2].setFillColor(fontcolor);
	option[2].setString("Enter Student ID: ");
	option[2].setCharacterSize(20);
	option[2].setPosition(300, 400);

	tb[2].setSize(20);
	tb[2].setColor(sf::Color::White);
	tb[2].setSelected(false);
	tb[2].setFont(font1);
	tb[2].setPosition({ 465,400 });
	tb[2].setLimit(true, 20);

	option[3].setFont(font1);
	option[3].setFillColor(fontcolor);
	option[3].setString("Enter Password: ");
	option[3].setCharacterSize(20);
	option[3].setPosition(300, 500);

	tb[3].setSize(20);
	tb[3].setColor(sf::Color::White);
	tb[3].setSelected(false);
	tb[3].setFont(font1);
	tb[3].setPosition({ 465,500 });
	tb[3].setLimit(true, 20);

	option[4].setFont(font1);
	option[4].setFillColor(fontcolor);
	option[4].setString("Back");
	option[4].setCharacterSize(20);
	option[4].setPosition(300, 600);




	opselected = -1;
}
void stuSignup::draw(sf::RenderWindow& window) {


	for (int i = 0; i < signop; i++)
	{
		window.draw(option[i]);
	}

}
void stuSignup::MoveUp() {
	if (opselected - 1 >= -1) {
		option[opselected].setFillColor(fontcolor);

		opselected--;
		if (opselected == -1) {
			opselected = signop - 1;
		}

		option[opselected].setFillColor(sf::Color::Red);
	}
}
void stuSignup::MoveDown() {
	if (opselected + 1 <= signop) {
		option[opselected].setFillColor(fontcolor);

		opselected++;
		if (opselected == signop) {
			opselected = 0;
		}

		option[opselected].setFillColor(sf::Color::Red);
	}
}