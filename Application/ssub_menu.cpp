#include "../sign_up/ssub_menu.h"
#include "../sign_up/stuSignup.h"
#include "../sign_up/stuLogin.h"

#include "../Application/teacher_menu.h"

#define fontcolor sf::Color::White
#define boxcolor sf::Color::Cyan

ssub_menu::ssub_menu(float width, float height) {
	if (!font1.loadFromFile("resources\\ttf\\arial.ttf")) {
		std::cout << "No font selected" << std::endl;
	}
	//Sign Up As Teacher:

	menu[0].setFont(font1);
	menu[0].setFillColor(fontcolor);
	menu[0].setString("Sign up As Student");
	menu[0].setCharacterSize(20);
	menu[0].setPosition(400, 200);


	menbox[0].setPosition(390, 190);
	menbox[0].setFillColor(boxcolor);
	menbox[0].setSize(sf::Vector2f(200, 40));

	//Log in As Teacher:
	menu[1].setFont(font1);
	menu[1].setFillColor(fontcolor);
	menu[1].setString("Log in As Student");
	menu[1].setCharacterSize(20);
	menu[1].setPosition(400, 300);

	menbox[1].setPosition(390, 290);
	menbox[1].setFillColor(boxcolor);
	menbox[1].setSize(sf::Vector2f(200, 40));



	//Back:
	menu[2].setFont(font1);
	menu[2].setFillColor(fontcolor);
	menu[2].setString("Back");
	menu[2].setCharacterSize(20);
	menu[2].setPosition(400, 400);

	menbox[2].setPosition(390, 390);
	menbox[2].setFillColor(boxcolor);
	menbox[2].setSize(sf::Vector2f(200, 40));




	MenuSelected = -1;
}
void ssub_menu::draw(sf::RenderWindow& window) {

	for (int i = 0; i < menu_op; i++)
	{
		window.draw(menbox[i]);

	}

	for (int i = 0; i < menu_op; i++)
	{
		window.draw(menu[i]);
	}

}
void ssub_menu::MoveUp() {
	if (MenuSelected - 1 >= -1) {
		menu[MenuSelected].setFillColor(fontcolor);

		MenuSelected--;
		if (MenuSelected == -1) {
			MenuSelected = menu_op - 1;
		}

		menu[MenuSelected].setFillColor(sf::Color::Red);
	}
}
void ssub_menu::MoveDown() {
	if (MenuSelected + 1 <= menu_op) {
		menu[MenuSelected].setFillColor(fontcolor);

		MenuSelected++;
		if (MenuSelected == menu_op) {
			MenuSelected = 0;
		}

		menu[MenuSelected].setFillColor(sf::Color::Red);
	}
}


void ssub_menu::ssub_display(sf::RenderWindow& wind) {
	ssub_menu t_sub(wind.getSize().x, wind.getSize().y);

	stuSignup s_sign(wind.getSize().x, wind.getSize().y);
	stuLogin s_login(wind.getSize().x, wind.getSize().y);
	teacher_menu  m_menu(wind.getSize().x, wind.getSize().y);


	while (wind.isOpen()) {
		sf::Event tsubevent;
		while (wind.pollEvent(tsubevent))
		{
			if (tsubevent.type == sf::Event::Closed) {
				wind.close();
			}
			if (tsubevent.type == sf::Event::KeyReleased) {
				if (tsubevent.key.code == sf::Keyboard::Escape) {
					wind.close();
				}
				if (tsubevent.key.code == sf::Keyboard::Up) {
					t_sub.MoveUp();
					break;
				}
				if (tsubevent.key.code == sf::Keyboard::Down) {
					t_sub.MoveDown();
					break;
				}
				if (tsubevent.key.code == sf::Keyboard::Return) {
					int y = t_sub.MenuPressed();
					//SignUp:
					if (y == 0) {
						s_sign.SignUpStudent(wind);
					}
					//Login:
					if (y == 1) {
						s_login.LogInStudent(wind);

					}

					//Back:
					if (y == 2) {

						m_menu.mainmenu(wind);

					}
				}
			}
		}

		wind.clear();
		t_sub.draw(wind);
		wind.display();

	}
}
