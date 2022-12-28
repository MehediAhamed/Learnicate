#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include "Main_Menu.h"
#include "student_menu.h"
#include "teacher_menu.h"
#include"../sign_up/ssub_menu.h"
#include"../sign_up/tsub_menu.h"




#pragma warning(disable:4996)
#pragma comment(lib, "ws2_32.lib")

int flag = 0;


int m()
{
	//Main Menu window size and object declaration

	sf::RenderWindow window(sf::VideoMode(1100, 750), "Main Menu");
	Main_Menu menu(window.getSize().x, window.getSize().y);

	//student object
	tsub_menu tm(window.getSize().x, window.getSize().y);
	ssub_menu sm(window.getSize().x, window.getSize().y);


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
						
						window.clear();
						window.close();
						flag = 1;
						exit(0);
				
						
						
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

//for receiving material.txt
void receive_material_text_file()
{
	if (flag == 1)
	{
		exit(0);
	}
	chatbox r;
	r.file_receive_text();
}

//for receiving course.csv

void receive_material_csv_file()
{
	chatbox r;
	r.file_receive_csv();
}


//for receiving notice
void receive_notice_csv_file()
{
	chatbox r;
	r.notice_receive_csv();
}

// for receiving syllabus
void receive_syllabus_csv_file()
{
	chatbox r;
	r.syllabus_receive_csv();
}




int main()
{
	



	m();

	//, t4(receive_notice_csv_file),t5(receive_syllabus_csv_file)


	/*std::thread t1(m), t2(receive_material_text_file), t3(receive_material_csv_file);
	t1.join();
	t2.join();
	t3.join();*/
	//t4.join();
	//t5.join();




}