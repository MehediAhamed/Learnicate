#include "../sign_up/TeachLogin.h"
#include "../sign_up/tsub_menu.h"
#include "../Application/teacher_menu.h"

#define fontcolor sf::Color::White
#define boxcolor sf::Color::Cyan

TeachLogin::TeachLogin(float width, float height) {
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
	option[2].setString("Proceed");
	option[2].setCharacterSize(20);
	option[2].setPosition(300, 400);
	
	option[3].setFont(font1);
	option[3].setFillColor(fontcolor);
	option[3].setString("Back");
	option[3].setCharacterSize(20);
	option[3].setPosition(300, 500);






	opselected = -1;
}
void TeachLogin::draw(sf::RenderWindow& window) {


	for (int i = 0; i < logop; i++)
	{
		window.draw(option[i]);
	}

}
void TeachLogin::MoveUp() {
	if (opselected - 1 >= -1) {
		option[opselected].setFillColor(fontcolor);

		opselected--;
		if (opselected == -1) {
			opselected = logop - 1;
		}

		option[opselected].setFillColor(sf::Color::Red);
	}
}
void TeachLogin::MoveDown() {
	if (opselected + 1 <= logop) {
		option[opselected].setFillColor(fontcolor);

		opselected++;
		if (opselected == logop) {
			opselected = 0;
		}

		option[opselected].setFillColor(sf::Color::Red);
	}
}


void TeachLogin::LogInTeacher(sf::RenderWindow& wind) {

	TeachLogin tlmenu(wind.getSize().x, wind.getSize().y);
	tsub_menu t_syb(wind.getSize().x, wind.getSize().y);
	teacher_menu tm(wind.getSize().x, wind.getSize().y);

	bool tlflag[logop];
	fill_n(tlflag, logop, false);

	/*cout << "Log in Teacher" << endl;*/
	sf::RenderWindow& LogT = wind;
	/*sf::RenderWindow LogT(sf::VideoMode(960, 720), "Log In Teacher");*/
	while (LogT.isOpen())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			if (tlflag[0] == true) {
				tlmenu.tb[0].setSelected(true);
				tlmenu.tb[1].setSelected(false);

			}
			if (tlflag[1] == true) {
				tlmenu.tb[0].setSelected(false);
				tlmenu.tb[1].setSelected(true);

			}

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)) {
			fill_n(tlflag, logop, false);
			tlmenu.tb[0].setSelected(false);
			tlmenu.tb[1].setSelected(false);

		}
		sf::Event ltevent;
		while (LogT.pollEvent(ltevent))
		{
			if (ltevent.type == sf::Event::Closed) {
				LogT.close();
			}
			if (ltevent.type == sf::Event::TextEntered) {
				if (tlflag[0] == true) {
					tlmenu.tb[0].typedOn(ltevent);
				}
				if (tlflag[1] == true) {
					tlmenu.tb[1].typedOn(ltevent);
				}

			}


			if (ltevent.type == sf::Event::KeyPressed) {
				if (ltevent.key.code == sf::Keyboard::Escape) {
					LogT.close();
				}
				if (ltevent.key.code == sf::Keyboard::Up) {
					tlmenu.MoveUp();
					break;
				}
				if (ltevent.key.code == sf::Keyboard::Down) {
					tlmenu.MoveDown();
					break;
				}
				if (ltevent.key.code == sf::Keyboard::Return) {
					int y = tlmenu.OptionPressed();
					//Email:
					if (y == 0) {
						fill_n(tlflag, logop, false);
						tlflag[0] = true;
					}
					//Password:
					if (y == 1) {
						fill_n(tlflag, logop, false);
						tlflag[1] = true;
					}
					//Proceed:
					if (y == 2) {
						fill_n(tlflag, logop, false);
						tlmenu.tb[0].setSelected(false);
						tlmenu.tb[1].setSelected(false);
						tm.t_display(wind);
					}
					//Back:
					if (y == 3) {
						//should store the values	
						fill_n(tlflag, logop, false);
						tlmenu.tb[0].setSelected(false);
						tlmenu.tb[1].setSelected(false);
						t_syb.tsub_display(wind);
					}
				}
			}
		}
		LogT.clear();
		tlmenu.draw(LogT);
		for (int i = 0; i < logop - 1; i++)
		{
			tlmenu.tb[i].drawTo(LogT);
		}

		LogT.display();
	}
}