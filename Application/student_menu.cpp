#pragma once
#include "student_menu.h"
#include"../FileExplorar/FileExplorer.h"
#include <fstream>
#define fontcolor sf::Color::White

student_menu::student_menu() :Main_Menu()
{

}
void student_menu::currStu(Student& s) {
	Sobj = s;

}

student_menu::student_menu(float width, float height) : Main_Menu()
{
	if (!font.loadFromFile("resources\\ttf\\Typo.ttf"))
	{
		std::cout << "Fond didn't Load" << std::endl;
	}
	s_menu[0].setFont(font);
	s_menu[0].setCharacterSize(35);
	s_menu[0].setFillColor(sf::Color::Red);
	s_menu[0].setString("Exam Plan");
	s_menu[0].setPosition(sf::Vector2f((width / 2) - 30, height / (s_opt + 1) * 2.5));


	s_menu[1].setFont(font);
	s_menu[1].setCharacterSize(35);
	s_menu[1].setFillColor(sf::Color::White);
	s_menu[1].setString("Notice");
	s_menu[1].setPosition(sf::Vector2f((width / 2) + 250, height / (s_opt + 1) * 2.5));

	s_menu[2].setFont(font);
	s_menu[2].setCharacterSize(35);
	s_menu[2].setFillColor(sf::Color::White);
	s_menu[2].setString("Course Material");
	s_menu[2].setPosition(sf::Vector2f((width / 2) - 30, height / (s_opt + 1) * 3.5));


	/*s_menu[3].setFont(font);
	s_menu[3].setCharacterSize(35);
	s_menu[3].setFillColor(sf::Color::White);
	s_menu[3].setString("My Profile");
	s_menu[3].setPosition(sf::Vector2f((width / 2) + 250, height / (s_opt + 1) * 3.5));*/


	s_menu[4].setFont(font);
	s_menu[4].setCharacterSize(35);
	s_menu[4].setFillColor(sf::Color::White);
	s_menu[4].setString("Texting");
	s_menu[4].setPosition(sf::Vector2f((width / 2) - 30, height / (s_opt + 1) * 4.5));


	s_menu[5].setFont(font);
	s_menu[5].setCharacterSize(35);
	s_menu[5].setFillColor(sf::Color::White);
	s_menu[5].setString("Video Chat");
	s_menu[5].setPosition(sf::Vector2f((width / 2) + 250, height / (s_opt + 1) * 4.5));

	s_menu[6].setFont(font);
	s_menu[6].setCharacterSize(35);
	s_menu[6].setFillColor(sf::Color::Cyan);
	s_menu[6].setString("Back");
	s_menu[6].setPosition(sf::Vector2f((width / 2) - 10, height / (s_opt + 1) * 6));


	s_menu[7].setFont(font);
	s_menu[7].setCharacterSize(35);
	s_menu[7].setFillColor(sf::Color::Cyan);
	s_menu[7].setString("Quit");
	s_menu[7].setPosition(sf::Vector2f((width / 2) + 290, height / (s_opt + 1) * 6));

	s_menuIndex = 0;

}




void student_menu::draw2(sf::RenderWindow& window)
{
	for (int i = 0; i < s_opt; i++)
	{
		window.draw(s_menu[i]);
	}
}

void student_menu::MoveUp()
{
	if ((s_menuIndex - 1) >= 0)
	{
		s_menu[s_menuIndex].setFillColor(sf::Color::White);
		s_menuIndex--;
		s_menu[s_menuIndex].setFillColor(sf::Color::Red);





	}
}
//function overriding
void student_menu::MoveDown()
{
	if ((s_menuIndex + 1) < s_opt)
	{
		s_menu[s_menuIndex].setFillColor(sf::Color::White);
		s_menuIndex++;
		s_menu[s_menuIndex].setFillColor(sf::Color::Red);



	}
}
//function overriding
int student_menu::getPressed()
{
	return s_menuIndex;
}




student_menu::~student_menu()
{

}

void student_menu::stu_chat(sf::RenderWindow& window)
{
	sf::Font n_font;

	if (!n_font.loadFromFile("resources\\ttf\\arialbd.ttf"))
	{
		std::cout << "Font didn't loaded";
	}


	sf::Text n_menu[5];
	n_menu[1].setFont(n_font);
	n_menu[1].setCharacterSize(20);
	n_menu[1].setStyle(sf::Text::Bold);
	n_menu[1].setFillColor(sf::Color::Cyan);
	n_menu[1].setString("Limit(60 Letters)");
	n_menu[1].setPosition(sf::Vector2f(880, 70));

	n_menu[2].setFont(n_font);
	n_menu[2].setCharacterSize(42);
	n_menu[2].setStyle(sf::Text::Bold);
	n_menu[2].setFillColor(sf::Color::White);
	n_menu[2].setString("Chat Box");
	n_menu[2].setPosition(sf::Vector2f(430, 5));



	//for exam background
	sf::RectangleShape background1, background2;
	background1.setSize(sf::Vector2f(1100, 750));
	sf::Texture MainTexture1, MainTexture2;
	MainTexture1.loadFromFile("resources\\images\\red.png");
	background1.setTexture(&MainTexture1);




	Button n_btn3(" Exit", { 150,50 }, 20, sf::Color::Green, sf::Color::Black);

	n_btn3.setPosition({ 620,630 });
	n_btn3.setFont(n_font);

	Button n_btn4(" Back", { 150,50 }, 20, sf::Color::Green, sf::Color::Black);

	n_btn4.setPosition({ 300,630 });
	n_btn4.setFont(n_font);


	Button n_btn5(" Send", { 120,45 }, 20, sf::Color::Green, sf::Color::Black);

	n_btn5.setPosition({ 900,530 });
	n_btn5.setFont(n_font);





	sf::Texture n_texture;
	n_texture.loadFromFile("resources\\images\\white.jpg");

	// Create a sprite
	sf::Sprite n_sprite1, n_sprite2, n_sprite3, n_sprite4, n_sprite5;
	n_sprite1.setTexture(n_texture);
	n_sprite1.setTextureRect(sf::IntRect(0, 0, 8, 640));
	n_sprite1.setColor(sf::Color(255, 255, 255, 200));
	n_sprite1.setPosition(0, 52);

	n_sprite2.setTexture(n_texture);
	n_sprite2.setTextureRect(sf::IntRect(0, 0, 8, 640));
	n_sprite2.setColor(sf::Color(255, 255, 255, 200));
	n_sprite2.setPosition(540, 52);

	n_sprite3.setTexture(n_texture);
	n_sprite3.setTextureRect(sf::IntRect(0, 0, 8, 640));
	n_sprite3.setColor(sf::Color(255, 255, 255, 200));
	n_sprite3.setPosition(1092, 52);


	n_sprite4.setTexture(n_texture);
	n_sprite4.setTextureRect(sf::IntRect(0, 0, 1100, 10));
	n_sprite4.setColor(sf::Color(255, 255, 255, 200));
	n_sprite4.setPosition(0, 690);


	n_sprite5.setTexture(n_texture);
	n_sprite5.setTextureRect(sf::IntRect(0, 0, 1100, 10));
	n_sprite5.setColor(sf::Color(255, 255, 255, 200));
	n_sprite5.setPosition(0, 52);

	student_menu t(window.getSize().x, window.getSize().y);


	chatbox r;

	std::string str;






	sf::Text reply;


	//network
	video_cam k;
	r.localSocket2.connect(k.ip, r.student_chat_portB);
	char out[1024];
	r.localSocket2.send(out, sizeof(out));

	
	r.localSocket1.connect(k.ip, r.student_chat_portA);
	char buff[1024];
	std::size_t received;
	r.localSocket1.receive(buff, sizeof(buff), received);




	Textbox n_text2(40, sf::Color::White, true);
	n_text2.setPosition({ 600, 120 });
	n_text2.setLimit(true, 19);
	n_text2.setFont(n_font);







	while (window.isOpen())
	{




		sf::Event Event;



		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {

			n_text2.setSelected(true);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {

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

				if (n_btn5.isMouseOver(window))
				{
					n_btn5.setBackColor(sf::Color::White);
				}
				else if (!n_btn5.isMouseOver(window))
				{
					n_btn5.setBackColor(sf::Color::Green);
				}
				break;

			case sf::Event::MouseButtonPressed:
				if (n_btn4.isMouseOver(window))
				{

					r.localSocket1.disconnect();
					r.localSocket2.disconnect();

					t.s_display(window);


				}
				else if (n_btn3.isMouseOver(window))
				{

					r.localSocket1.disconnect();
					r.localSocket2.disconnect();

					exit(0);
				}

				else if (n_btn5.isMouseOver(window))
				{




					str = n_text2.getText();



					std::string str2;
					str2 = str;



					for (int i = 1; i < str2.length(); i++)
					{
						if (str2[i] == '\n' || str2[i] == '\r')
						{
							str2[i] = ' ';
						}
					}



					char out[1024];
					strcpy(out, str.c_str());



					if (r.localSocket2.send(out, sizeof(out)) != sf::Socket::Done)
					{

						std::cerr << "Failed to send end-of-stream packet" << std::endl;

					}


					Textbox n_text(40, sf::Color::White, true);

					n_text2 = n_text;
					n_text2.setFont(n_font);
					n_text2.setPosition({ 600, 120 });


				}







				char buff[1024];

				if (r.localSocket1.receive(buff, sizeof(buff), received) != sf::Socket::Done)
				{
					std::cout << "Message wasn't recieved" << std::endl;
					break;

				}
				else
				{


					reply.setFont(n_font);
					reply.setCharacterSize(41);
					reply.setStyle(sf::Text::Bold);
					reply.setFillColor(sf::Color::Yellow);
					reply.setString(buff);
					reply.setPosition(sf::Vector2f(20, 120));


				}


				break;


			}

			window.clear();

			window.draw(background1);
			window.draw(n_menu[1]);
			window.draw(n_menu[2]);
			window.draw(reply);

			n_text2.drawTo(window);


			n_btn3.drawTo(window);
			n_btn4.drawTo(window);
			n_btn5.drawTo(window);


			window.draw(n_sprite1);
			window.draw(n_sprite2);
			window.draw(n_sprite3);
			window.draw(n_sprite4);
			window.draw(n_sprite5);


			window.display();






		}

	}



}


void student_menu::stu_video_chat()
{



	video_cam r;


	std::thread t1(std::thread([&] { r.student_camera_video(); })), t2(std::thread([&] { r.student_show_video(); })),
		ta(std::thread([&] { r.s_a_receiveClient(); })), tb(std::thread([&] { r.s_a_sendClient(); }));





	ta.join();
	tb.join();
	t1.join();
	t2.join();
	




	return;


}


void student_menu::Details(sf::RenderWindow& window) {



	sf::Font font1;
	if (!font1.loadFromFile("resources\\ttf\\Chrusty.ttf"))
	{
		std::cout << "Font didn't loaded";
	}





	//for  background
	sf::RectangleShape background1;
	background1.setSize(sf::Vector2f(1100, 750));
	sf::Texture MainTexture1;
	MainTexture1.loadFromFile("resources\\images\\green.jpg");
	background1.setTexture(&MainTexture1);

	sf::Text option[3];

	option[0].setFont(font1);
	option[0].setFillColor(fontcolor);
	option[0].setString("Name :   " + Sobj.getName());
	option[0].setCharacterSize(20);
	option[0].setPosition(300, 200);


	option[1].setFont(font1);
	option[1].setFillColor(fontcolor);
	option[1].setString("Email :   " + Sobj.getMail());
	option[1].setCharacterSize(20);
	option[1].setPosition(300, 300);


	option[2].setFont(font1);
	option[2].setFillColor(fontcolor);
	option[2].setString("ID :     " + Sobj.get_sid());
	option[2].setCharacterSize(20);
	option[2].setPosition(300, 400);










	Button n_btn4(" Back", { 200,50 }, 20, sf::Color::White, sf::Color::Black);

	n_btn4.setPosition({ 880,500 });
	n_btn4.setFont(font1);







	student_menu t(window.getSize().x, window.getSize().y);






	while (window.isOpen())
	{
		sf::Event Event;



		while (window.pollEvent(Event))
		{

			switch (Event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;



			case sf::Event::MouseMoved:



				if (n_btn4.isMouseOver(window))
				{
					n_btn4.setBackColor(sf::Color::Red);
				}
				else if (!n_btn4.isMouseOver(window))
				{
					n_btn4.setBackColor(sf::Color::White);
				}
				break;

			case sf::Event::MouseButtonPressed:
				if (n_btn4.isMouseOver(window))
				{
					t.s_display(window);

				}


				break;


			}

			window.clear();

			window.draw(background1);


			for (int i = 0; i < 3; i++)
			{
				window.draw(option[i]);
			}

			n_btn4.drawTo(window);
			window.display();
		}

	}
}



void student_menu::s_display(sf::RenderWindow& window)
{

	//for student menu
	sf::RectangleShape s_background1, s_background2;
	s_background1.setSize(sf::Vector2f(400, 800));
	s_background2.setSize(sf::Vector2f(1300, 800));
	sf::Texture s_MainTexture, s_MainTexture2;

	s_MainTexture.loadFromFile("resources\\images\\school6.png");
	s_MainTexture2.loadFromFile("resources\\images\\green.jpg");

	s_background1.setTexture(&s_MainTexture);
	s_background2.setTexture(&s_MainTexture2);


	student_menu stu(window.getSize().x, window.getSize().y);
	FileExplorer explorar;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{

			switch (event.type)
			{
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					MoveUp();
					break;
				case sf::Keyboard::Down:
					MoveDown();
					break;
				case sf::Keyboard::Return:
					switch (getPressed())
					{
					case 0:

						stu.syllabus_display(window);

						break;

					case 1:

						
						stu.notice_display(window);
						break;




					case 2:

						stu.readMaterialFile(window);

						break;

					case 3:

						//Details(window);


						break;




					case 4:

					    stu.stu_chat(window);
						break;

					case 5:

						stu.stu_video_chat();

						break;

					case 6:

						stu.mainmenu(window);

						break;




					case 7:
						window.close();
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
		window.draw(s_background2);
		window.draw(s_background1);


		draw2(window);
		window.display();

	}
}



void student_menu::readMaterialFile(sf::RenderWindow& e_window)
{
	std::ifstream fin;
	std::string line;


	sf::Font font2;

	if (!font2.loadFromFile("resources\\ttf\\arial.ttf"))
	{
		std::cout << "Fond didn't Load" << std::endl;
	}



	sf::Text menu[20];

	int opt = 1;

	// by default open mode = ios::in mode
	fin.open("Material.txt");


	menu[0].setFont(font2);
	menu[0].setCharacterSize(30);
	menu[0].setStyle(sf::Text::Bold);
	menu[0].setFillColor(sf::Color::Cyan);
	menu[0].setString("All files are saved in drive");
	menu[0].setPosition(sf::Vector2f(200, 20));


	FileExplorer ex;
	// Execute a loop until EOF (End of File)
	while (getline(fin, line)) {

		// Print line (read from file) in Console
		std::cout << line << std::endl;



		menu[opt].setFont(font2);
		menu[opt].setCharacterSize(30);
		menu[opt].setStyle(sf::Text::Bold);
		menu[opt].setFillColor(sf::Color::White);
		menu[opt].setString(line);
		menu[opt].setPosition(sf::Vector2f(300, 80*opt));
		opt++;
	}

	// Close the file
	fin.close();





	//for exam background
	sf::RectangleShape e_background1, e_background2;
	e_background1.setSize(sf::Vector2f(1100, 750));
	sf::Texture MainTexture1, MainTexture2;
	MainTexture1.loadFromFile("resources\\images\\green.jpg");
	e_background1.setTexture(&MainTexture1);






	Button e_btn3(" Open", { 100,50 }, 20, sf::Color::Green, sf::Color::Black);

	e_btn3.setPosition({ 988,500 });
	e_btn3.setFont(font2);

	Button e_btn4(" Back", { 100,50 }, 20, sf::Color::Green, sf::Color::Black);

	e_btn4.setPosition({ 870,500 });
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

	student_menu s(e_window.getSize().x,e_window.getSize().y);


	while (e_window.isOpen())
	{
		sf::Event Event;


		while (e_window.pollEvent(Event))
		{

			switch (Event.type)
			{
			case sf::Event::Closed:
				e_window.close();
				break;

			case sf::Event::TextEntered:

			case sf::Event::MouseMoved:

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
				if (e_btn4.isMouseOver(e_window))
				{
					e_flag1 = 0;
					e_flag2 = 0;

					s.s_display(e_window);
					std::cout << "Button 4 Pressed" << std::endl;


				}
				else if (e_btn3.isMouseOver(e_window))
				{
					ex.run();
				}


				break;


			}

			e_window.clear();
			e_window.draw(e_background2);
			e_window.draw(e_background1);
			e_window.draw(menu[1]);
			e_window.draw(menu[2]);

			e_btn3.drawTo(e_window);
			e_btn4.drawTo(e_window);


			e_window.draw(n_sprite1);
			e_window.draw(n_sprite2);

			e_window.draw(menu[0]);

			for (int i = 1; i < opt; i++)
			{
				e_window.draw(menu[i]);
			}


			e_window.display();
		}

	}


}

void student_menu::syllabus_display(sf::RenderWindow& e_window)
{
	std::ifstream fin;
	std::string line;


	sf::Font font2;

	if (!font2.loadFromFile("resources\\ttf\\arial.ttf"))
	{
		std::cout << "Fond didn't Load" << std::endl;
	}



	sf::Text menu[20];

	int opt = 1;


	int flag = 0;
	FILE* fp = fopen("syllabus.csv", "r");

	if (!fp)
		printf("Can't open file\n");

	else
	{

		char buffer[1024];

		int row = 0;
		int column = 0;

		while (fgets(buffer, 1024, fp))
		{

			column = 0;
			row++;

			char* value = strtok(buffer, ", ");

			while (value)
			{

				
					printf(" %s", value);

					menu[opt].setFont(font2);
					menu[opt].setCharacterSize(30);
					menu[opt].setStyle(sf::Text::Bold);
					menu[opt].setFillColor(sf::Color::Yellow);
					menu[opt].setPosition(sf::Vector2f(150, 80 * opt));

					if (opt == 1)
					{
						std::string s;
						s = "Subject Name : ";
						s += value;
						menu[opt].setString(s);
					}
					else if (opt == 2)
					{
						std::string s;
						s = "Exam Date : ";
						s += value;
						menu[opt].setString(s);
					}

					else if (opt == 3)
					{
						std::string s;
						s = "Syllabus : ";
						s += value;
						menu[opt].setString(s);
					}
					else if (opt == 4)
					{
						std::string s;
						
						s += value;
						menu[opt].setString(s);
					}
					else if (opt == 5)
					{
						std::string s;
					
						s += value;
						menu[opt].setString(s);
					}
					else if (opt == 6)
					{
						std::string s;
						
						s += value;
						menu[opt].setString(s);
					}

					opt++;
				

			

				value = strtok(NULL, ", ");
				column++;
			}

			printf("\n");
		}

		if (flag == 0)
			std::cout << "Data not found" << std::endl;
		fclose(fp);
	}





	//for exam background
	sf::RectangleShape e_background1, e_background2;
	e_background1.setSize(sf::Vector2f(1100, 750));
	sf::Texture MainTexture1, MainTexture2;
	MainTexture1.loadFromFile("resources\\images\\green.jpg");
	e_background1.setTexture(&MainTexture1);





	Button e_btn4(" Back", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);

	e_btn4.setPosition({ 880,350 });
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

	student_menu s(e_window.getSize().x, e_window.getSize().y);


	while (e_window.isOpen())
	{
		sf::Event Event;


		while (e_window.pollEvent(Event))
		{

			switch (Event.type)
			{
			case sf::Event::Closed:
				e_window.close();
				break;

			case sf::Event::TextEntered:



			case sf::Event::MouseMoved:

				if (e_btn4.isMouseOver(e_window))
				{
					e_btn4.setBackColor(sf::Color::White);
				}
				else if (!e_btn4.isMouseOver(e_window))
				{
					e_btn4.setBackColor(sf::Color::Green);
				}
				break;

			case sf::Event::MouseButtonPressed:
				if (e_btn4.isMouseOver(e_window))
				{
					e_flag1 = 0;
					e_flag2 = 0;

					s.s_display(e_window);
					std::cout << "Button 4 Pressed" << std::endl;


				}
				

				break;


			}

			e_window.clear();
			e_window.draw(e_background2);
			e_window.draw(e_background1);
			e_window.draw(menu[1]);
			e_window.draw(menu[2]);

			
			e_btn4.drawTo(e_window);


			e_window.draw(n_sprite1);
			e_window.draw(n_sprite2);

			e_window.draw(menu[0]);

			for (int i = 1; i < opt; i++)
			{
				e_window.draw(menu[i]);
			}


			e_window.display();
		}

	}


}



void student_menu::notice_display(sf::RenderWindow& e_window)
{
	std::ifstream fin;
	std::string line;


	sf::Font font2;

	if (!font2.loadFromFile("resources\\ttf\\arial.ttf"))
	{
		std::cout << "Fond didn't Load" << std::endl;
	}



	sf::Text menu[20];


	int opt = 1;


	menu[0].setFont(font2);
	menu[0].setCharacterSize(50);
	menu[0].setStyle(sf::Text::Bold);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setPosition(sf::Vector2f(350, 40));
	menu[0].setString("Notice");
	// by default open mode = ios::in mode
	fin.open("notice.csv");


	// Execute a loop until EOF (End of File)
	while (getline(fin, line)) {



			int i = 0;
			std::stringstream ss(line);
			std::string word[1000];
			while (!ss.eof()) {



				menu[opt].setFont(font2);
				menu[opt].setCharacterSize(30);
				menu[opt].setStyle(sf::Text::Bold);
				menu[opt].setFillColor(sf::Color::Yellow);
				menu[opt].setPosition(sf::Vector2f(200, 120 * opt));

				getline(ss, word[i], ',');
				std::cout << word[i] << std::endl;
			
				menu[opt].setString(word[i]);

				i++;
				opt++;

			}
		}
	
	// Close the file
	fin.close();


	//for exam background
	sf::RectangleShape e_background1, e_background2;
	e_background1.setSize(sf::Vector2f(1100, 750));
	sf::Texture MainTexture1, MainTexture2;
	MainTexture1.loadFromFile("resources\\images\\green.jpg");
	e_background1.setTexture(&MainTexture1);





	Button e_btn4(" Back", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);

	e_btn4.setPosition({ 880,350 });
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

	student_menu s(e_window.getSize().x, e_window.getSize().y);


	while (e_window.isOpen())
	{
		sf::Event Event;


		while (e_window.pollEvent(Event))
		{

			switch (Event.type)
			{
			case sf::Event::Closed:
				e_window.close();
				break;

			case sf::Event::TextEntered:



			case sf::Event::MouseMoved:

				if (e_btn4.isMouseOver(e_window))
				{
					e_btn4.setBackColor(sf::Color::White);
				}
				else if (!e_btn4.isMouseOver(e_window))
				{
					e_btn4.setBackColor(sf::Color::Green);
				}
				break;

			case sf::Event::MouseButtonPressed:
				if (e_btn4.isMouseOver(e_window))
				{
					e_flag1 = 0;
					e_flag2 = 0;

					s.s_display(e_window);
					std::cout << "Button 4 Pressed" << std::endl;


				}


				break;


			}

			e_window.clear();
			e_window.draw(e_background2);
			e_window.draw(e_background1);
			
			e_btn4.drawTo(e_window);


			e_window.draw(n_sprite1);
			e_window.draw(n_sprite2);
			
			e_window.draw(menu[0]);

			for (int i = 1; i < opt; i++)
			{
				e_window.draw(menu[i]);
			}


			e_window.display();
		}

	}


}