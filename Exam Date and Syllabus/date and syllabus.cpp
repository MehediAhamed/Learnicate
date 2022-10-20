
#include <SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>
#include "Button.h"
#include"Textbox.h"

#include<string>
#include <fstream>

#pragma warning(disable:4996)
#pragma comment(lib, "ws2_32.lib")





int m()
{
	


	sf::RenderWindow e_window(sf::VideoMode(1100, 750), "Main Menu");
	sf::Font arial;
	if(!arial.loadFromFile("ArialTh.ttf"))
	{
	   std::cout << "Font didn't loaded";
	}

	e_window.setKeyRepeatEnabled(true);

	sf::Text e_menu[3];
	e_menu[1].setFont(arial);
	e_menu[1].setCharacterSize(35);
	e_menu[1].setStyle(sf::Text::Bold);
	e_menu[1].setFillColor(sf::Color::White);
	e_menu[1].setString("Date (DD/MM/YY)");
	e_menu[1].setPosition(sf::Vector2f(100,40));

	e_menu[2].setFont(arial);
	e_menu[2].setCharacterSize(35);
	e_menu[2].setStyle(sf::Text::Bold);
	e_menu[2].setFillColor(sf::Color::White);
	e_menu[2].setString("Syllabus");
	e_menu[2].setPosition(sf::Vector2f(100, 270));



	//for exam background
	sf::RectangleShape e_background1, e_background2;
	e_background1.setSize(sf::Vector2f(832, 1500));
	sf::Texture e_MainTexture1, e_MainTexture2;
	e_MainTexture1.loadFromFile("chat6.png");
	e_background1.setTexture(&e_MainTexture1);


	
	e_background2.setSize(sf::Vector2f(1100,2000));
	e_MainTexture2.loadFromFile("dark.jpg");
	e_background2.setTexture(&e_MainTexture2);

	// Name Textbox:
	Textbox e_text1(40, sf::Color::White, true);
	e_text1.setPosition({100, 90 });
	e_text1.setLimit(true, 8);
	e_text1.setFont(arial);

	Textbox e_text2(40, sf::Color::White, true);
	e_text2.setPosition({ 100, 320 });
	e_text2.setLimit(true, 40);
	e_text2.setFont(arial);

	//Center textbox:
	//e_text1.setPosition(sf::Vector2f(900 / 2.0f - 170, 900 / 2.0f - 50));

	//Button
	Button e_btn1("Enter Date", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);

	e_btn1.setPosition({ 870,200 });
	e_btn1.setFont(arial);


	Button e_btn2("Syllabus", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);
	e_btn2.setPosition({ 870,300 });
	e_btn2.setFont(arial);



	Button e_btn3(" Save", { 100,50 }, 20, sf::Color::Green, sf::Color::Black);

	e_btn3.setPosition({ 980,500 });
	e_btn3.setFont(arial);

	Button e_btn4(" Back", { 100,50 }, 20, sf::Color::Green, sf::Color::Black);

	e_btn4.setPosition({ 865,500 });
	e_btn4.setFont(arial);


	



	



	
	int e_flag1 = 0, e_flag2=0;
	

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
					e_text1.typedOn1(Event,e_window);
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
				else if(!e_btn1.isMouseOver(e_window))
				{
					e_btn1.setBackColor(sf::Color::Green);
				}
				else if (e_btn2.isMouseOver(e_window))
				{
					e_btn1.setBackColor(sf::Color::White);
				}
				else if (!e_btn2.isMouseOver(e_window))
				{
					e_btn1.setBackColor(sf::Color::Green);
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
					std::cout << "Button 3 Pressed" << std::endl;
					std::string e_str = e_text1.getText();
					e_str += ",";
					e_str += e_text2.getText();
					e_str += "\n";
					std::cout << e_str << std::endl;


					e_text1.create(e_str);

					

				}
				
				
				break;

				
		}

			e_window.clear();
			e_window.draw(e_background2);
			e_window.draw(e_background1);
			e_window.draw(e_menu[1]);
			e_window.draw(e_menu[2]);
			e_text1.drawTo(e_window);
			e_text2.drawTo(e_window);
			e_btn1.drawTo(e_window);
			e_btn2.drawTo(e_window);
			e_btn3.drawTo(e_window);
			e_btn4.drawTo(e_window);
			//e_window.draw(linestrip, 4, sf::Lines);
		
			e_window.display();
		}

	}
	return 0;


	//store();
}













































