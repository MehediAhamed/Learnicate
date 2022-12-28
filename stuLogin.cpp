#pragma once
#include "sign_up/stuLogin.h"
#include "sign_up/ssub_menu.h"
#include "Application/student_menu.h"

#define fontcolor sf::Color::White


stuLogin::stuLogin(float width, float height) {
	if (!font1.loadFromFile("resources\\ttf\\Chrusty.ttf")) {
		cout << "No font selected" << endl;
	}






	option[0].setFont(font1);
	option[0].setFillColor(fontcolor);
	option[0].setString("Enter Email: ");
	option[0].setCharacterSize(20);
	option[0].setPosition(300, 200);

	tb[0].setSize(20);
	tb[0].setColor(sf::Color::White);
	tb[0].setSelected(false);
	tb[0].setFont(font1);
	tb[0].setPosition({ 500,200 });
	tb[0].setLimit(true, 30);

	option[1].setFont(font1);
	option[1].setFillColor(fontcolor);
	option[1].setString("Enter Password: ");
	option[1].setCharacterSize(20);
	option[1].setPosition(300, 300);

	tb[1].setSize(20);
	tb[1].setColor(sf::Color::White);
	tb[1].setSelected(false);
	tb[1].setFont(font1);
	tb[1].setPosition({ 500,300 });
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


void stuLogin::LogInStudent(sf::RenderWindow& wind) {

	sf::Text head;
	sf::Font font;
	if (!font.loadFromFile("resources\\ttf\\Chrusty.ttf"))
	{
		std::cout << "Fond didn't Load" << std::endl;
	}

	head.setFont(font);
	head.setFillColor(sf::Color::Color(155, 0, 0, 255));
	head.setString("Student Login");
	head.setCharacterSize(60);
	head.setPosition(sf::Vector2f((wind.getSize().x / 2) - 300, wind.getSize().y / (logop + 1) * 0.6));
	head.setStyle(sf::Text::Bold);
	head.setStyle(sf::Text::Italic);

	sf::RectangleShape e_background1;
	e_background1.setSize(sf::Vector2f(1500, 750));
	sf::Texture MainTexture1;
	MainTexture1.loadFromFile("resources\\images\\green.jpg");
	e_background1.setTexture(&MainTexture1);

	stuLogin slmenu(wind.getSize().x, wind.getSize().y);
	ssub_menu s_syb(wind.getSize().x, wind.getSize().y);
	student_menu sm(wind.getSize().x, wind.getSize().y);
	bool slflag[logop];
	fill_n(slflag, logop, false);

		sf::RenderWindow& LogS = wind;
	while (LogS.isOpen())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			if (slflag[0] == true) {
				slmenu.tb[0].setSelected(true);
				slmenu.tb[1].setSelected(false);

			}
			if (slflag[1] == true) {
				slmenu.tb[0].setSelected(false);
				slmenu.tb[1].setSelected(true);

			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)) {
			fill_n(slflag, logop, false);
			slmenu.tb[0].setSelected(false);
			slmenu.tb[1].setSelected(false);

		}


		sf::Event lsevent;
		while (LogS.pollEvent(lsevent))
		{
			if (lsevent.type == sf::Event::Closed) {
				LogS.close();
			}

			if (lsevent.type == sf::Event::TextEntered) {
				if (slflag[0] == true) {
					slmenu.tb[0].typedOn(lsevent);
				}
				if (slflag[1] == true) {
					slmenu.tb[1].typedOn(lsevent);
				}

			}

			if (lsevent.type == sf::Event::KeyPressed) {
				if (lsevent.key.code == sf::Keyboard::Escape) {
					LogS.close();
				}
				if (lsevent.key.code == sf::Keyboard::Up) {
					slmenu.MoveUp();
					break;
				}
				if (lsevent.key.code == sf::Keyboard::Down) {
					slmenu.MoveDown();
					break;
				}
				if (lsevent.key.code == sf::Keyboard::Return) {
					int y = slmenu.OptionPressed();
					//Email:
					if (y == 0) {
						fill_n(slflag, logop, false);
						slflag[0] = true;
					}
					//Password:
					if (y == 1) {
						fill_n(slflag, logop, false);
						slflag[1] = true;
					}
					//Proceed:
					if (y == 2) {
						Student s;
						bool f = 0;
						fill_n(slflag, logop, false);
						slmenu.tb[0].setSelected(false);
						slmenu.tb[1].setSelected(false);

						f = slmenu.tb[0].student_read(slmenu.tb[0].getText(), slmenu.tb[1].getText());
						if (f == true) {
							slmenu.tb[0].student_read(slmenu.tb[0].getText(), slmenu.tb[1].getText(), s);
							sm.currStu(s);
							sm.s_display(wind);
						}

						else
						{
							fill_n(slflag, logop, false);
							slmenu.tb[0].setSelected(false);
							slmenu.tb[1].setSelected(false);
							s_syb.ssub_display(wind);

						}
					}
					//Back:
					if (y == 3) {
						//should store the values	
						fill_n(slflag, logop, false);
						slmenu.tb[0].setSelected(false);
						slmenu.tb[1].setSelected(false);
						s_syb.ssub_display(wind);

					}
				}
			}
		}

		LogS.clear();
		LogS.draw(e_background1);
		LogS.draw(head);
		slmenu.draw(LogS);
		for (int i = 0; i < logop - 1; i++) {
			slmenu.tb[i].drawTo(LogS);
		}
		LogS.display();

	}
}