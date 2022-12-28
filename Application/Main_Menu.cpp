#pragma once
#include"teacher_menu.h"
#include"student_menu.h"
#include"../sign_up/Person.h"
#include "../sign_up/TeachLogin.h"
#include "../sign_up/stuSignup.h"
#include "../sign_up/stuLogin.h"
#include "../sign_up/ssub_menu.h"
#include "../sign_up/tsub_menu.h"






void Main_Menu::mainmenu(sf::RenderWindow& window)
{
	
	Main_Menu menu(window.getSize().x, window.getSize().y);

	
	
	ssub_menu sm(window.getSize().x, window.getSize().y);


	tsub_menu tm(window.getSize().x, window.getSize().y);


	//for main menu
	sf::RectangleShape background;
	background.setSize(sf::Vector2f(1500, 750));
	sf::Texture MainTexture;
	MainTexture.loadFromFile("resources\\images\\back.jpg");
	background.setTexture(&MainTexture);






	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{

			switch (event.type)
			{
			case (sf::Event::KeyReleased):
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;
				case sf::Keyboard::Down:
					menu.MoveDown();
					break;
				case sf::Keyboard::Return:
					switch (menu.getPressed())
					{
					case 0:

					    tm.tsub_display(window);
						break;

					case 1:

						sm.ssub_display(window);

						break;

					case 2:
						window.close();
						break;
					}
					break;
				}



				break;

			case sf::Event::Closed:window.close();
				break;
			}

		}
		window.clear();
		window.draw(background);

		menu.draw(window);
		window.display();

	}
}



Main_Menu::Main_Menu(float width, float height)
{
	if (!font.loadFromFile("resources\\ttf\\Chrusty.ttf"))
	{
		std::cout << "Fond didn't Load" << std::endl;
	}

	if (!font2.loadFromFile("resources\\ttf\\Typo.ttf"))
	{
		std::cout << "Fond didn't Load" << std::endl;
	}


	headline.setFont(font);
	headline.setString("Learnicate");
	headline.setStyle(sf::Text::Bold);
	headline.setStyle(sf::Text::Italic);
	headline.setCharacterSize(70);
	headline.setFillColor(sf::Color::Color(155, 0, 0, 255));
	headline.setPosition(sf::Vector2f((width / 2) - 73, height / (Main_Menu_Opt + 1) * 0.5));


	menu[0].setFont(font2);
	menu[0].setCharacterSize(40);
	menu[0].setFillColor(sf::Color::Cyan);
	menu[0].setString("As Teacher");
	menu[0].setPosition(sf::Vector2f((width / 2) , height / (Main_Menu_Opt + 1) * 1.5));


	menu[1].setFont(font2);
	menu[1].setCharacterSize(40);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("As Student");
	menu[1].setPosition(sf::Vector2f((width / 2) , height / (Main_Menu_Opt + 1) * 2.2));


	menu[2].setFont(font2);
	menu[2].setCharacterSize(40);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f((width / 2) , height / (Main_Menu_Opt + 1) * 2.9));

	menuIndex = 0;


}

Main_Menu::Main_Menu()
{

}


Main_Menu::~Main_Menu()
{

}

void Main_Menu::draw(sf::RenderWindow& window)
{
	window.draw(headline);
	for (int i = 0; i < Main_Menu_Opt; i++)
	{
		window.draw(menu[i]);
	}
}

void Main_Menu::MoveUp()
{
	if ((menuIndex - 1) >= 0)
	{
		menu[menuIndex].setFillColor(sf::Color::White);
		menuIndex--;
		menu[menuIndex].setFillColor(sf::Color::Cyan);
	}
}

void Main_Menu::MoveDown()
{
	if ((menuIndex + 1) < Main_Menu_Opt)
	{
		menu[menuIndex].setFillColor(sf::Color::White);
		menuIndex++;
		menu[menuIndex].setFillColor(sf::Color::Cyan);
	}
}

int Main_Menu::getPressed()
{
	return menuIndex;
}

int Main_Menu::MenuPressed() {
	return MenuSelected;
}






void Main_Menu::syllabus(sf::RenderWindow& e_window)
{

	if (!font2.loadFromFile("resources\\ttf\\arial.ttf"))
	{
		std::cout << "Fond didn't Load" << std::endl;
	}




	menu[1].setFont(font2);
	menu[1].setCharacterSize(35);
	menu[1].setStyle(sf::Text::Bold);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Date (DD-MM-YY)");
	menu[1].setPosition(sf::Vector2f(73, 40));

	menu[2].setFont(font2);
	menu[2].setCharacterSize(35);
	menu[2].setStyle(sf::Text::Bold);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Syllabus");
	menu[2].setPosition(sf::Vector2f(73, 270));



	//for exam background
	sf::RectangleShape e_background1, e_background2;
	e_background1.setSize(sf::Vector2f(1100, 750));
	sf::Texture MainTexture1, MainTexture2;
	MainTexture1.loadFromFile("resources\\images\\red.png");
	e_background1.setTexture(&MainTexture1);



	// Name Textbox:
	Textbox e_text1(40, sf::Color::White, true);
	e_text1.setPosition({ 73, 90 });
	e_text1.setLimit(true, 8);
	e_text1.setFont(font2);

	Textbox e_text2(40, sf::Color::White, true);
	e_text2.setPosition({ 73, 320 });
	e_text2.setLimit(true, 34);
	e_text2.setFont(font2);


	//Button
	Button e_btn1("Enter Date", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);

	e_btn1.setPosition({ 878,200 });
	e_btn1.setFont(font2);


	Button e_btn2("Syllabus ", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);
	e_btn2.setPosition({ 878,300 });
	e_btn2.setFont(font2);



	Button e_btn3(" Save", { 100,50 }, 20, sf::Color::Green, sf::Color::Black);

	e_btn3.setPosition({ 980,500 });
	e_btn3.setFont(font2);

	Button e_btn4(" Back", { 100,50 }, 20, sf::Color::Green, sf::Color::Black);

	e_btn4.setPosition({ 865,500 });
	e_btn4.setFont(font2);




	sf::Texture n_texture;
	n_texture.loadFromFile("resources\\images\\white.jpg");
	// Create a sprite
	sf::Sprite n_sprite1, n_sprite2, n_sprite3;
	n_sprite1.setTexture(n_texture);
	n_sprite1.setTextureRect(sf::IntRect(0, 0, 10, 750));
	n_sprite1.setColor(sf::Color(255, 255, 255, 200));
	n_sprite1.setPosition(0, 0);

	n_sprite2.setTexture(n_texture);
	n_sprite2.setTextureRect(sf::IntRect(0, 0, 10, 750));
	n_sprite2.setColor(sf::Color(255, 255, 255, 200));
	n_sprite2.setPosition(850, 0);


	int e_flag1 = 0, e_flag2 = 0;


	while (e_window.isOpen())
	{
		sf::Event Event;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			e_text1.setSelected(true);
			e_text2.setSelected(true);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			e_text1.setSelected(false);
			e_text2.setSelected(false);
		}


		while (e_window.pollEvent(Event))
		{

			switch (Event.type)
			{
			case sf::Event::Closed:
				e_window.close();
				break;

			case sf::Event::TextEntered:
				if (e_flag1 == 1)
				{
					e_text1.typedOn1(Event, e_window);
				}

				if (e_flag2 == 1)
				{
					e_text2.typedOn(Event);
				}


			case sf::Event::MouseMoved:


				if (e_btn1.isMouseOver(e_window))
				{
					e_btn1.setBackColor(sf::Color::White);
				}
				else if (!e_btn1.isMouseOver(e_window))
				{
					e_btn1.setBackColor(sf::Color::Green);
				}
				if (e_btn2.isMouseOver(e_window))
				{
					e_btn2.setBackColor(sf::Color::White);
				}
				else if (!e_btn2.isMouseOver(e_window))
				{
					e_btn2.setBackColor(sf::Color::Green);
				}

				if (e_btn3.isMouseOver(e_window))
				{
					e_btn3.setBackColor(sf::Color::White);
				}
				else if (!e_btn3.isMouseOver(e_window))
				{
					e_btn3.setBackColor(sf::Color::Red);
				}
				if (e_btn4.isMouseOver(e_window))
				{
					e_btn4.setBackColor(sf::Color::White);
				}
				else if (!e_btn4.isMouseOver(e_window))
				{
					e_btn4.setBackColor(sf::Color::Red);
				}
				break;

			case sf::Event::MouseButtonPressed:
				if (e_btn1.isMouseOver(e_window))
				{
					e_flag2 = 0;
					std::cout << "Button 1 Pressed" << std::endl;
					e_flag1 = 1;

				}
				else if (e_btn2.isMouseOver(e_window))
				{
					e_flag1 = 0;
					std::cout << "Button 2 Pressed" << std::endl;
					e_flag2 = 1;

				}
				else if (e_btn4.isMouseOver(e_window))
				{
					e_flag1 = 0;
					e_flag2 = 0;
					std::cout << "Button 4 Pressed" << std::endl;


				}
				else if (e_btn3.isMouseOver(e_window))
				{
					e_flag1 = 0;
					e_flag2 = 0;

					std::string str = e_text1.getText();
					std::string str2;
					str2 = str;

					for (int i = 1; i < str2.length(); i++)
					{
						if (str2[i] == '\n' || str2[i] == '\r')
						{
							str2[i] = ';';
						}
					}

					e_text1.create_syllabus_file(str2);



				}


				break;


			}

			e_window.clear();
			e_window.draw(e_background2);
			e_window.draw(e_background1);
			e_window.draw(menu[1]);
			e_window.draw(menu[2]);
			e_text1.drawTo(e_window);
			e_text2.drawTo(e_window);
			e_btn1.drawTo(e_window);
			e_btn2.drawTo(e_window);
			e_btn3.drawTo(e_window);
			e_btn4.drawTo(e_window);

			e_window.draw(n_sprite1);
			e_window.draw(n_sprite2);


			e_window.display();
		}

	}



}



void Main_Menu::notice(sf::RenderWindow& window)
{




	sf::Font n_font;
	if (!n_font.loadFromFile("resources\\ttf\\arialbd.ttf"))
	{
		std::cout << "Font didn't loaded";
	}


	sf::Text n_menu[3];
	n_menu[1].setFont(n_font);
	n_menu[1].setCharacterSize(20);
	n_menu[1].setStyle(sf::Text::Bold);
	n_menu[1].setFillColor(sf::Color::Cyan);
	n_menu[1].setString("Limit(150 Letters)");
	n_menu[1].setPosition(sf::Vector2f(880, 200));

	n_menu[2].setFont(n_font);
	n_menu[2].setCharacterSize(42);
	n_menu[2].setStyle(sf::Text::Bold);
	n_menu[2].setFillColor(sf::Color::White);
	n_menu[2].setString("Notice");
	n_menu[2].setPosition(sf::Vector2f(350, 60));



	//for exam background
	sf::RectangleShape background1, background2;
	background1.setSize(sf::Vector2f(1100, 750));
	sf::Texture MainTexture1, MainTexture2;
	MainTexture1.loadFromFile("resources\\images\\red.png");
	background1.setTexture(&MainTexture1);




	Textbox n_text2(40, sf::Color::White, true);
	n_text2.setPosition({ 70, 110 });
	n_text2.setLimit(true, 35);
	n_text2.setFont(n_font);






	Button n_btn3(" Save", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);

	n_btn3.setPosition({ 880,350 });
	n_btn3.setFont(n_font);

	Button n_btn4(" Back", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);

	n_btn4.setPosition({ 880,500 });
	n_btn4.setFont(n_font);





	sf::Texture n_texture;
	n_texture.loadFromFile("resources\\images\\white.jpg");

	// Create a sprite
	sf::Sprite n_sprite1, n_sprite2, n_sprite3;
	n_sprite1.setTexture(n_texture);
	n_sprite1.setTextureRect(sf::IntRect(0, 0, 10, 750));
	n_sprite1.setColor(sf::Color(255, 255, 255, 200));
	n_sprite1.setPosition(0, 0);

	n_sprite2.setTexture(n_texture);
	n_sprite2.setTextureRect(sf::IntRect(0, 0, 10, 750));
	n_sprite2.setColor(sf::Color(255, 255, 255, 200));
	n_sprite2.setPosition(850, 0);



	teacher_menu t;






	while (window.isOpen())
	{
		sf::Event Event;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			//n_text1.setSelected(true);
			n_text2.setSelected(true);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			//n_text1.setSelected(false);
			n_text2.setSelected(false);
		}


		while (window.pollEvent(Event))
		{

			switch (Event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::TextEntered:

				n_text2.typedOn(Event);



			case sf::Event::MouseMoved:


				if (n_btn3.isMouseOver(window))
				{
					n_btn3.setBackColor(sf::Color::White);
				}
				else if (!n_btn3.isMouseOver(window))
				{
					n_btn3.setBackColor(sf::Color::Green);
				}
				if (n_btn4.isMouseOver(window))
				{
					n_btn4.setBackColor(sf::Color::White);
				}
				else if (!n_btn4.isMouseOver(window))
				{
					n_btn4.setBackColor(sf::Color::Green);
				}
				break;

			case sf::Event::MouseButtonPressed:
				if (n_btn4.isMouseOver(window))
				{

					std::cout << "Button 4 Pressed" << std::endl;
					window.clear();
					//t.t_display(window);
					t.mainmenu(window);

				}
				else if (n_btn3.isMouseOver(window))
				{

					std::cout << "Button 3 Pressed" << std::endl;

					std::string str = n_text2.getText();
					std::string str2;
					str2 = str;

					for (int i = 1; i < str2.length(); i++)
					{
						if (str2[i] == '\n' || str2[i] == '\r')
						{
							str2[i] = ';';
						}
					}

					std::cout << str2 << std::endl;


					n_text2.create_notice_file(str2);
					



				}


				break;


			}

			window.clear();

			window.draw(background1);
			window.draw(n_menu[1]);
			window.draw(n_menu[2]);

			n_text2.drawTo(window);

		
			n_btn3.drawTo(window);
			n_btn4.drawTo(window);

			window.draw(n_sprite1);
			window.draw(n_sprite2);
		
			window.display();
		}

	}


}






void Main_Menu::operator=(sf::RenderWindow& window)
{
	window.getDefaultView();
}