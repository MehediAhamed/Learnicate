#include "../sign_up/stuSignup.h"
#include "../sign_up/ssub_menu.h"
#include "../Application/student_menu.h"
#define fontcolor sf::Color::White
#define boxcolor sf::Color::Cyan

stuSignup::stuSignup(float width, float height) {
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


void stuSignup::SignUpStudent(sf::RenderWindow& wind) {

	stuSignup smenu(wind.getSize().x, wind.getSize().y);
	ssub_menu s_syb(wind.getSize().x, wind.getSize().y);
	student_menu sm(wind.getSize().x, wind.getSize().y);

	bool sflag[signop];
	fill_n(sflag, signop, false);

	/*cout << "Sign Up Student" << endl;*/
	sf::RenderWindow& SignS = wind;
	/*sf::RenderWindow SignS(sf::VideoMode(960, 720), "Sign Up Student");*/
	while (SignS.isOpen())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			if (sflag[0] == true) {
				smenu.tb[0].setSelected(true);
				smenu.tb[1].setSelected(false);
				smenu.tb[2].setSelected(false);
				smenu.tb[3].setSelected(false);
			}
			if (sflag[1] == true) {
				smenu.tb[1].setSelected(true);
				smenu.tb[0].setSelected(false);
				smenu.tb[2].setSelected(false);
				smenu.tb[3].setSelected(false);
			}
			if (sflag[2] == true) {
				smenu.tb[2].setSelected(true);
				smenu.tb[1].setSelected(false);
				smenu.tb[0].setSelected(false);
				smenu.tb[3].setSelected(false);
			}
			if (sflag[3] == true) {
				smenu.tb[3].setSelected(true);
				smenu.tb[1].setSelected(false);
				smenu.tb[2].setSelected(false);
				smenu.tb[0].setSelected(false);
			}

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)) {
			fill_n(sflag, signop, false);
			smenu.tb[0].setSelected(false);
			smenu.tb[1].setSelected(false);
			smenu.tb[2].setSelected(false);
			smenu.tb[3].setSelected(false);
		}


		sf::Event ssevent;
		while (SignS.pollEvent(ssevent))
		{
			if (ssevent.type == sf::Event::Closed) {
				SignS.close();
			}

			if (ssevent.type == sf::Event::TextEntered) {
				if (sflag[0] == true) {
					smenu.tb[0].typedOn(ssevent);
				}
				if (sflag[1] == true) {
					smenu.tb[1].typedOn(ssevent);
				}
				if (sflag[2] == true) {
					smenu.tb[2].typedOn(ssevent);
				}
				if (sflag[3] == true) {
					smenu.tb[3].typedOn(ssevent);
				}
			}

			if (ssevent.type == sf::Event::KeyPressed) {
				if (ssevent.key.code == sf::Keyboard::Escape) {
					SignS.close();
				}
				if (ssevent.key.code == sf::Keyboard::Up) {
					smenu.MoveUp();
					break;
				}
				if (ssevent.key.code == sf::Keyboard::Down) {
					smenu.MoveDown();
					break;
				}
				if (ssevent.key.code == sf::Keyboard::Return) {
					int y = smenu.OptionPressed();
					//Name:
					if (y == 0) {
						fill_n(sflag, signop, false);
						sflag[0] = true;
					}
					//Email:
					if (y == 1) {
						fill_n(sflag, signop, false);
						sflag[1] = true;

					}
					//ID:
					if (y == 2) {
						fill_n(sflag, signop, false);
						sflag[2] = true;
					}
					//Pass:
					if (y == 3) {
						fill_n(sflag, signop, false);
						sflag[3] = true;
					}
					//Proceed:
					if (y == 4) {
						std::fill_n(sflag, signop, false);
						smenu.tb[0].setSelected(false);
						smenu.tb[1].setSelected(false);
						smenu.tb[2].setSelected(false);
						smenu.tb[3].setSelected(false);
						sm.s_display(wind);
					}

					//Back:
					if (y == 5) {
						//should store the values
						fill_n(sflag, signop, false);
						smenu.tb[0].setSelected(false);
						smenu.tb[1].setSelected(false);
						smenu.tb[2].setSelected(false);
						smenu.tb[3].setSelected(false);
						s_syb.ssub_display(wind);
						
					}

				}
			}
		}

		SignS.clear();
		smenu.draw(SignS);
		for (int i = 0; i < signop - 1; i++) {
			smenu.tb[i].drawTo(SignS);
		}
		SignS.display();
	}
}