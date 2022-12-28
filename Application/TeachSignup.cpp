#include "../sign_up/teachSignup.h"
#include "../sign_up/tsub_menu.h"
#include "../Application/teacher_menu.h"
#define fontcolor sf::Color::White
#define boxcolor sf::Color::Cyan

TeachSignup::TeachSignup(float width, float height) {
	if (!font1.loadFromFile("resources\\ttf\\arial.ttf")) {
		std::cout << "No font selected" << std::endl;
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
	tb[0].setPosition({465,200});
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
	option[2].setString("Enter Teacher ID: ");
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
	option[4].setString("Proceed");
	option[4].setCharacterSize(20);
	option[4].setPosition(300, 600);

	option[5].setFont(font1);
	option[5].setFillColor(fontcolor);
	option[5].setString("Back");
	option[5].setCharacterSize(20);
	option[5].setPosition(300, 700);





	opselected = -1;
}
void TeachSignup::draw(sf::RenderWindow& window) {


	for (int i = 0; i < signop; i++)
	{
		window.draw(option[i]);
	}

}
void TeachSignup::MoveUp() {
	if (opselected - 1 >= -1) {
		option[opselected].setFillColor(fontcolor);

		opselected--;
		if (opselected == -1) {
			opselected = signop - 1;
		}

		option[opselected].setFillColor(sf::Color::Red);
	}
}
void TeachSignup::MoveDown() {
	if (opselected + 1 <= signop) {
		option[opselected].setFillColor(fontcolor);

		opselected++;
		if (opselected == signop) {
			opselected = 0;
		}

		option[opselected].setFillColor(sf::Color::Red);
	}
}

void TeachSignup::SignUpTeacher(sf::RenderWindow& wind) {

	TeachSignup tmenu(wind.getSize().x, wind.getSize().y);
	tsub_menu t_syb(wind.getSize().x, wind.getSize().y);
	teacher_menu tm(wind.getSize().x, wind.getSize().y);
	bool tflag[signop];
	std::fill_n(tflag, signop, false);

	/*cout << "Sign Up Teacher" << endl;*/
	sf::RenderWindow& SignT = wind;
	/*sf::RenderWindow SignT(sf::VideoMode(960, 720), "Sign Up Teacher");*/
	while (SignT.isOpen())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			if (tflag[0] == true) {
				tmenu.tb[0].setSelected(true);
				tmenu.tb[1].setSelected(false);
				tmenu.tb[2].setSelected(false);
				tmenu.tb[3].setSelected(false);
			}
			if (tflag[1] == true) {
				tmenu.tb[1].setSelected(true);
				tmenu.tb[0].setSelected(false);
				tmenu.tb[2].setSelected(false);
				tmenu.tb[3].setSelected(false);
			}
			if (tflag[2] == true) {
				tmenu.tb[2].setSelected(true);
				tmenu.tb[1].setSelected(false);
				tmenu.tb[0].setSelected(false);
				tmenu.tb[3].setSelected(false);
			}
			if (tflag[3] == true) {
				tmenu.tb[3].setSelected(true);
				tmenu.tb[1].setSelected(false);
				tmenu.tb[2].setSelected(false);
				tmenu.tb[0].setSelected(false);
			}

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)) {
			std::fill_n(tflag, signop, false);
			tmenu.tb[0].setSelected(false);
			tmenu.tb[1].setSelected(false);
			tmenu.tb[2].setSelected(false);
			tmenu.tb[3].setSelected(false);
		}
		sf::Event stevent;
		while (SignT.pollEvent(stevent))
		{
			if (stevent.type == sf::Event::Closed) {
				SignT.close();
			}
			if (stevent.type == sf::Event::TextEntered) {
				if (tflag[0] == true) {
					tmenu.tb[0].typedOn(stevent);
				}
				if (tflag[1] == true) {
					tmenu.tb[1].typedOn(stevent);
				}
				if (tflag[2] == true) {
					tmenu.tb[2].typedOn(stevent);
				}
				if (tflag[3] == true) {
					tmenu.tb[3].typedOn(stevent);
				}
			}
			if (stevent.type == sf::Event::KeyPressed) {
				if (stevent.key.code == sf::Keyboard::Escape) {
					SignT.close();
				}
				if (stevent.key.code == sf::Keyboard::Up) {
					tmenu.MoveUp();
					break;
				}
				if (stevent.key.code == sf::Keyboard::Down) {
					tmenu.MoveDown();
					break;
				}

				if (stevent.key.code == sf::Keyboard::Return) {
					int y = tmenu.OptionPressed();
					//Name:
					if (y == 0) {
						std::fill_n(tflag, signop, false);
						tflag[0] = true;
					}
					//Email:
					if (y == 1) {
						std::fill_n(tflag, signop, false);
						tflag[1] = true;

					}
					//ID:
					if (y == 2) {
						std::fill_n(tflag, signop, false);
						tflag[2] = true;
					}
					//Pass:
					if (y == 3) {
						std::fill_n(tflag, signop, false);
						tflag[3] = true;
					}
					//Proceed:
					if (y == 4) {
						std::fill_n(tflag, signop, false);
						tmenu.tb[0].setSelected(false);
						tmenu.tb[1].setSelected(false);
						tmenu.tb[2].setSelected(false);
						tmenu.tb[3].setSelected(false);
						tm.t_display(wind);
					}
					//Back:
					if (y == 5) {
						//should store the values	
						std::fill_n(tflag, signop, false);
						tmenu.tb[0].setSelected(false);
						tmenu.tb[1].setSelected(false);
						tmenu.tb[2].setSelected(false);
						tmenu.tb[3].setSelected(false);
						t_syb.tsub_display(wind);
						
						
					}

				}

			}
		}

		SignT.clear();
		tmenu.draw(SignT);
		for (int i = 0; i < signop - 1; i++) {
			tmenu.tb[i].drawTo(SignT);
		}
		SignT.display();


	}
}
