
#include <SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>
#include "Button.h"
#include"Textbox.h"


#pragma warning(disable:4996)
#pragma comment(lib, "ws2_32.lib")





int main()
{



	sf::RenderWindow window(sf::VideoMode(1100, 750), "Main n_menu");
	sf::Font n_font;
	if (!n_font.loadFromFile("ArialTh.ttf"))
	{
		std::cout << "Font didn't loaded";
	}

	window.setKeyRepeatEnabled(true);

	sf::Text n_menu[3];
	n_menu[1].setFont(n_font);
	n_menu[1].setCharacterSize(35);
	n_menu[1].setStyle(sf::Text::Bold);
	n_menu[1].setFillColor(sf::Color::White);
	n_menu[1].setString("Material");
	n_menu[1].setPosition(sf::Vector2f(50, 20));

	n_menu[2].setFont(n_font);
	n_menu[2].setCharacterSize(35);
	n_menu[2].setStyle(sf::Text::Bold);
	n_menu[2].setFillColor(sf::Color::White);
	n_menu[2].setString("Notice");
	n_menu[2].setPosition(sf::Vector2f(50, 380));



	//for exam background
	sf::RectangleShape background1, background2;
	background1.setSize(sf::Vector2f(1100, 750));
	sf::Texture MainTexture1, MainTexture2;
	MainTexture1.loadFromFile("red.png");
	background1.setTexture(&MainTexture1);



	// Name Textbox:
	Textbox n_text1(40, sf::Color::White, true);
	n_text1.setPosition({ 50, 70 });
	n_text1.setLimit(true, 50);
	n_text1.setFont(n_font);

	Textbox n_text2(40, sf::Color::White, true);
	n_text2.setPosition({ 50, 420 });
	n_text2.setLimit(true, 50);
	n_text2.setFont(n_font);

	

	//Button
	Button n_btn1("Material", { 200,50 }, 20, sf::Color::Cyan, sf::Color::Black);

	n_btn1.setPosition({ 880,160 });
	n_btn1.setFont(n_font);


	Button n_btn2("Announce", { 200,50 }, 20, sf::Color::Cyan, sf::Color::Black);
	n_btn2.setPosition({ 880,300 });
	n_btn2.setFont(n_font);



	Button n_btn3(" Save", { 100,50 }, 20, sf::Color::Green, sf::Color::Black);

	n_btn3.setPosition({ 990,500 });
	n_btn3.setFont(n_font);

	Button n_btn4(" Back", { 100,50 }, 20, sf::Color::Green, sf::Color::Black);

	n_btn4.setPosition({ 870,500 });
	n_btn4.setFont(n_font);





	sf::Texture n_texture;
	n_texture.loadFromFile("white.jpg");

	// Create a sprite
	sf::Sprite n_sprite1,n_sprite2, n_sprite3;
	n_sprite1.setTexture(n_texture);
	n_sprite1.setTextureRect(sf::IntRect(0, 0, 10, 750));
	n_sprite1.setColor(sf::Color(255, 255, 255, 200));
	n_sprite1.setPosition(0, 0);

	n_sprite2.setTexture(n_texture);
	n_sprite2.setTextureRect(sf::IntRect(0, 0, 10, 750));
	n_sprite2.setColor(sf::Color(255, 255, 255, 200));
	n_sprite2.setPosition(850, 0);

	n_sprite3.setTexture(n_texture);
	n_sprite3.setTextureRect(sf::IntRect(350, 0, 840, 10));
	n_sprite3.setColor(sf::Color(255, 255, 255, 200));
	n_sprite3.setPosition(10, 370);

	






	int n_flag1 = 0, n_flag2 = 0;


	while (window.isOpen())
	{
		sf::Event Event;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			n_text1.setSelected(true);
			n_text2.setSelected(true);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			n_text1.setSelected(false);
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
				if (n_flag1 == 1)
				{
					n_text1.typedOn(Event);
				}

				if (n_flag2 == 1)
				{
					n_text2.typedOn(Event);
				}


			case sf::Event::MouseMoved:


				if (n_btn1.isMouseOver(window))
				{
					n_btn1.setBackColor(sf::Color::White);
				}
				else if (!n_btn1.isMouseOver(window))
				{
					n_btn1.setBackColor(sf::Color::Cyan);
				}
			    if (n_btn2.isMouseOver(window))
				{
					n_btn2.setBackColor(sf::Color::White);
				}
				else if (!n_btn2.isMouseOver(window))
				{
					n_btn2.setBackColor(sf::Color::Cyan);
				}

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
				if (n_btn1.isMouseOver(window))
				{
					n_flag2 = 0;
					std::cout << "Button 1 Pressed" << std::endl;
					n_flag1 = 1;

				}
				else if (n_btn2.isMouseOver(window))
				{
					n_flag1 = 0;
					std::cout << "Button 2 Pressed" << std::endl;
					n_flag2 = 1;

				}
				else if (n_btn4.isMouseOver(window))
				{
					n_flag1 = 0;
					n_flag2 = 0;
					std::cout << "Button 4 Pressed" << std::endl;


				}
				else if (n_btn3.isMouseOver(window))
				{
					n_flag1 = 0;
					n_flag2 = 0;
					std::cout << "Button 3 Pressed" << std::endl;
					std::string str = n_text1.getText();
					str += ",";
					str += n_text2.getText();
					str += "\n";
					std::cout << str << std::endl;


					n_text1.create(str);



				}


				break;


			}

			window.clear();
			
			window.draw(background1);
			window.draw(n_menu[1]);
			window.draw(n_menu[2]);
			n_text1.drawTo(window);
			n_text2.drawTo(window);
			n_btn1.drawTo(window);
			n_btn2.drawTo(window);
			n_btn3.drawTo(window);
			n_btn4.drawTo(window);
			
			window.draw(n_sprite1);
			window.draw(n_sprite2);
			window.draw(n_sprite3);
			window.display();
		}

	}

	return 0;

	//store();
}













































