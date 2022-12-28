#pragma once
#include "sign_up/ssub_menu.h"
#include "sign_up/stuSignup.h"
#include "sign_up/stuLogin.h"

#include "Application/teacher_menu.h"

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
	menu[0].setCharacterSize(40);
	menu[0].setPosition(sf::Vector2f((width / 2), height / (Main_Menu_Opt + 1) * 1.5));

	

	//Log in As Teacher:
	menu[1].setFont(font1);
	menu[1].setFillColor(fontcolor);
	menu[1].setString("Log in As Student");
	menu[1].setCharacterSize(40);
	menu[1].setPosition(sf::Vector2f((width / 2), height / (Main_Menu_Opt + 1) * 2.1));



	//Back:
	menu[2].setFont(font1);
	menu[2].setFillColor(fontcolor);
	menu[2].setString("Back");
	menu[2].setCharacterSize(40);
	menu[2].setPosition(sf::Vector2f((width / 2), height / (Main_Menu_Opt + 1) * 2.7));






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



	sf::Text head;
	sf::Font font;
	if (!font.loadFromFile("resources\\ttf\\Chrusty.ttf"))
	{
		std::cout << "Fond didn't Load" << std::endl;
	}

	head.setFont(font);
	head.setFillColor(sf::Color::Color(155, 0, 0, 255));
	head.setString("Welcome");
	head.setCharacterSize(60);
	head.setPosition(sf::Vector2f((wind.getSize().x / 2) + 30, wind.getSize().y / (Main_Menu_Opt + 1) * 0.6));
	head.setStyle(sf::Text::Bold);
	head.setStyle(sf::Text::Italic);




	ssub_menu t_sub(wind.getSize().x, wind.getSize().y);

	stuSignup s_sign(wind.getSize().x, wind.getSize().y);
	stuLogin s_login(wind.getSize().x, wind.getSize().y);
	teacher_menu  m_menu(wind.getSize().x, wind.getSize().y);

	sf::RectangleShape e_background1;
	e_background1.setSize(sf::Vector2f(1500, 750));
	sf::Texture MainTexture1;
	MainTexture1.loadFromFile("resources\\images\\back.jpg");
	e_background1.setTexture(&MainTexture1);

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
		wind.draw(e_background1);
		wind.draw(head);
		t_sub.draw(wind);

		wind.display();

	}
}
