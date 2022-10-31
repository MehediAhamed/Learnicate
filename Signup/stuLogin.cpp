#include "stuLogin.h"


#define fontcolor sf::Color::White
#define boxcolor sf::Color::Cyan

stuLogin::stuLogin(float width, float height) {
	if (!font1.loadFromFile("arial.ttf")) {
		cout << "No font selected" << endl;
	}



	/*option[0].setFont(font1);
	option[0].setFillColor(fontcolor);
	option[0].setString("Sign up As Teacher");
	option[0].setCharacterSize(20);
	option[0].setPosition(400, 200);*/


	option[0].setFont(font1);
	option[0].setFillColor(fontcolor);
	option[0].setString("Enter Email: ");
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
	option[1].setString("Enter Password: ");
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
	option[2].setString("Back");
	option[2].setCharacterSize(20);
	option[2].setPosition(300, 400);




	opselected = -1;
}
void stuLogin::draw(sf::RenderWindow& window) {


	for (int i = 0; i < logop; i++)
	{
		window.draw(option[i]);
	}

}
void stuLogin::MoveUp() {
	if (opselected - 1 >= -1) {
		option[opselected].setFillColor(fontcolor);

		opselected--;
		if (opselected == -1) {
			opselected = logop - 1;
		}

		option[opselected].setFillColor(sf::Color::Red);
	}
}
void stuLogin::MoveDown() {
	if (opselected + 1 <= logop) {
		option[opselected].setFillColor(fontcolor);

		opselected++;
		if (opselected == logop) {
			opselected = 0;
		}

		option[opselected].setFillColor(sf::Color::Red);
	}
}