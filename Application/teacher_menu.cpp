#pragma once
#include "teacher_menu.h"
#include"chatbox.h"

#include<thread>
#include"../FileExplorar/FileExplorer.h"
#define fontcolor sf::Color::White


teacher_menu::teacher_menu() :Main_Menu()
{

}

void teacher_menu::currTeach(Teacher &t) {
	Tobj = t;
	
}

teacher_menu::teacher_menu(float width, float height) :Main_Menu()
{
	if (!font.loadFromFile("resources\\ttf\\Typo.ttf"))
	{
		std::cout << "Fond didn't Load" << std::endl;
	}
	t_menu[0].setFont(font);
	t_menu[0].setCharacterSize(35);
	t_menu[0].setFillColor(sf::Color::Red);
	t_menu[0].setString("Exam  Plan");
	t_menu[0].setPosition(sf::Vector2f((width / 2) - 30, height / (t_opt + 1) * 2.5));


	t_menu[1].setFont(font);
	t_menu[1].setCharacterSize(35);
	t_menu[1].setFillColor(sf::Color::White);
	t_menu[1].setString("Notice");
	t_menu[1].setPosition(sf::Vector2f((width / 2) + 250, height / (t_opt + 1) * 2.5));

	t_menu[2].setFont(font);
	t_menu[2].setCharacterSize(35);
	t_menu[2].setFillColor(sf::Color::White);
	t_menu[2].setString("Course  Material");
	t_menu[2].setPosition(sf::Vector2f((width / 2) - 30, height / (t_opt + 1) * 3.5));


	//t_menu[3].setFont(font);
	//t_menu[3].setCharacterSize(35);
	//t_menu[3].setFillColor(sf::Color::White);
	//t_menu[3].setString("My Details");
	//t_menu[3].setPosition(sf::Vector2f((width / 2) + 250, height / (t_opt + 1) * 3.5));


	t_menu[4].setFont(font);
	t_menu[4].setCharacterSize(35);
	t_menu[4].setFillColor(sf::Color::White);
	t_menu[4].setString("Texting");
	t_menu[4].setPosition(sf::Vector2f((width / 2) - 30, height / (t_opt + 1) * 4.5));


	t_menu[5].setFont(font);
	t_menu[5].setCharacterSize(35);
	t_menu[5].setFillColor(sf::Color::White);
	t_menu[5].setString("Video Chat");
	t_menu[5].setPosition(sf::Vector2f((width / 2) + 250, height / (t_opt + 1) * 4.5));

	t_menu[6].setFont(font);
	t_menu[6].setCharacterSize(35);
	t_menu[6].setFillColor(sf::Color::Cyan);
	t_menu[6].setString("Back");
	t_menu[6].setPosition(sf::Vector2f((width / 2) - 10, height / (t_opt + 1) * 6));


	t_menu[7].setFont(font);
	t_menu[7].setCharacterSize(35);
	t_menu[7].setFillColor(sf::Color::Cyan);
	t_menu[7].setString("Quit");
	t_menu[7].setPosition(sf::Vector2f((width / 2) + 290, height / (t_opt + 1) * 6));

	t_menuIndex = 0;

}




void teacher_menu::draw2(sf::RenderWindow& window)
{
	for (int i = 0; i < t_opt; i++)
	{
		window.draw(t_menu[i]);
	}
}

void teacher_menu::MoveUp()
{
	if ((t_menuIndex - 1) >= 0)
	{
		t_menu[t_menuIndex].setFillColor(sf::Color::White);
		t_menuIndex--;
		t_menu[t_menuIndex].setFillColor(sf::Color::Red);





	}
}
//function overriding
void teacher_menu::MoveDown()
{
	if ((t_menuIndex + 1) < t_opt)
	{
		t_menu[t_menuIndex].setFillColor(sf::Color::White);
		t_menuIndex++;
		t_menu[t_menuIndex].setFillColor(sf::Color::Red);



	}
}
//function overriding
int teacher_menu::getPressed()
{
	return t_menuIndex;
}




teacher_menu::~teacher_menu()
{

}




void teacher_menu::tchr_chat(sf::RenderWindow& window)
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

	teacher_menu t(window.getSize().x, window.getSize().y);


	chatbox r;
	
	std::string str;






	sf::Text reply;


   //network
	video_cam k;

	r.localSocket2.connect(k.ip, r.teacher_chat_portB);
	char out[1024];
	r.localSocket2.send(out, sizeof(out));


	r.localSocket1.connect(k.ip, r.teacher_chat_portA);
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

					t.t_display(window);
					

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

					n_text2 =n_text ;
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




void teacher_menu::tchr_video_chat(sf::RenderWindow &window)
{


	video_cam r;
	

	std::thread t1(std::thread([&] { r.teacher_camera_video(); })), t2(std::thread([&] { r.teacher_show_video(); })),
		ta(std::thread([&] { r.t_a_receiveClient(); })), tb(std::thread([&] { r.t_a_sendClient(); }));
	




	ta.join();
	tb.join();

	t1.join();
	t2.join();

	


	return;


}

void teacher_menu::Details(sf::RenderWindow &window) {



	sf::Font font1;
	if (!font1.loadFromFile("resources\\ttf\\Chrusty.ttf"))
	{
		std::cout << "Font didn't loaded";
	}





	//for  background
	sf::RectangleShape background1;
	background1.setSize(sf::Vector2f(1100, 750));
	sf::Texture MainTexture1 ;
	MainTexture1.loadFromFile("resources\\images\\green.jpg");
	background1.setTexture(&MainTexture1);

	sf::Text option[3];

	option[0].setFont(font1);
	option[0].setFillColor(fontcolor);
	option[0].setString("Name :   "+ Tobj.getName());
	option[0].setCharacterSize(20);
	option[0].setPosition(300, 200);


	option[1].setFont(font1);
	option[1].setFillColor(fontcolor);
	option[1].setString("Email :   "+Tobj.getMail());
	option[1].setCharacterSize(20);
	option[1].setPosition(300, 300);


	option[2].setFont(font1);
	option[2].setFillColor(fontcolor);
	option[2].setString("ID :     "+Tobj.get_tid());
	option[2].setCharacterSize(20);
	option[2].setPosition(300, 400);








	

	Button n_btn4(" Back", { 200,50 }, 20, sf::Color::White, sf::Color::Black);

	n_btn4.setPosition({ 880,500 });
	n_btn4.setFont(font1);







	teacher_menu t(window.getSize().x, window.getSize().y);






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
					t.t_display(window);

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


void teacher_menu::t_display(sf::RenderWindow& window)
{


	//for student menu
	sf::RectangleShape t_background1, t_background2;

	t_background2.setSize(sf::Vector2f(1300, 800));


	sf::Texture t_MainTexture, t_MainTexture2;


	t_MainTexture2.loadFromFile("resources\\images\\teacher4.png");


	t_background2.setTexture(&t_MainTexture2);


	teacher_menu teach(window.getSize().x, window.getSize().y);
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

						teach.syllabus(window);

						break;

					case 1:

						teach.notice(window);


						break;




					case 2:
						explorar.run();
						
						break;

					case 3:

						//Details(window);
						break;




					case 4:

						
						teach.tchr_chat(window);
						break;




					case 5:

							teach.tchr_video_chat(window);

						break;

					case 6:

						teach.mainmenu(window);
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
		window.draw(t_background2);
		//window.draw(t_background1);


		draw2(window);
		window.display();

	}
}



void teacher_menu::syllabus(sf::RenderWindow& e_window)
{

	if (!font2.loadFromFile("resources\\ttf\\arial.ttf"))
	{
		std::cout << "Fond didn't Load" << std::endl;
	}

	menu[0].setFont(font2);
	menu[0].setCharacterSize(35);
	menu[0].setStyle(sf::Text::Bold);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("Subject");
	menu[0].setPosition(sf::Vector2f(73, 40));


	menu[1].setFont(font2);
	menu[1].setCharacterSize(35);
	menu[1].setStyle(sf::Text::Bold);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Date (DD-MM-YY)");
	menu[1].setPosition(sf::Vector2f(73, 200));

	menu[2].setFont(font2);
	menu[2].setCharacterSize(35);
	menu[2].setStyle(sf::Text::Bold);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Syllabus");
	menu[2].setPosition(sf::Vector2f(73, 360));



	//for exam background
	sf::RectangleShape e_background1, e_background2;
	e_background1.setSize(sf::Vector2f(1100, 750));
	sf::Texture MainTexture1, MainTexture2;
	MainTexture1.loadFromFile("resources\\images\\red.png");
	e_background1.setTexture(&MainTexture1);



	// Name Textbox:
	Textbox e_text0(40, sf::Color::White, true);
	e_text0.setPosition({ 73, 90 });
	e_text0.setLimit(true, 8);
	e_text0.setFont(font2);

	Textbox e_text1(40, sf::Color::White, true);
	e_text1.setPosition({ 73, 250 });
	e_text1.setLimit(true, 8);
	e_text1.setFont(font2);

	Textbox e_text2(40, sf::Color::White, true);
	e_text2.setPosition({ 73, 410 });
	e_text2.setLimit(true, 34);
	e_text2.setFont(font2);


	//Button
	Button e_btn("Subject", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);

	e_btn.setPosition({ 878,200 });
	e_btn.setFont(font2);

	Button e_btn1("Enter Date", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);

	e_btn1.setPosition({ 878,300 });
	e_btn1.setFont(font2);


	Button e_btn2("Syllabus ", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);
	e_btn2.setPosition({ 878,400 });
	e_btn2.setFont(font2);



	Button e_btn3(" Save", { 100,50 }, 20, sf::Color::Green, sf::Color::Black);

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


	int e_flag0 = 0,e_flag1 = 0, e_flag2 = 0;

	teacher_menu t(e_window.getSize().x, e_window.getSize().y);

	while (e_window.isOpen())
	{
		sf::Event Event;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			e_text0.setSelected(true);
			e_text1.setSelected(true);
			e_text2.setSelected(true);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			e_text0.setSelected(false);
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
				if (e_flag0 == 1)
				{
					e_text0.typedOn1(Event, e_window);
				}

				if (e_flag1 == 1)
				{
					e_text1.typedOn1(Event, e_window);
				}

				if (e_flag2 == 1)
				{
					e_text2.typedOn(Event);
				}


			case sf::Event::MouseMoved:

				if (e_btn.isMouseOver(e_window))
				{
					e_btn.setBackColor(sf::Color::White);
				}
				else if (!e_btn.isMouseOver(e_window))
				{
					e_btn.setBackColor(sf::Color::Green);
				}
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
				if (e_btn.isMouseOver(e_window))
				{
					e_flag1 = 0;
					e_flag2 = 0;
					std::cout << "Button 1 Pressed" << std::endl;
					e_flag0 = 1;

				}
				else if (e_btn1.isMouseOver(e_window))
				{
					e_flag0 = 0;
					e_flag2 = 0;
					std::cout << "Button 1 Pressed" << std::endl;
					e_flag1 = 1;

				}
				else if (e_btn2.isMouseOver(e_window))
				{
					e_flag0 = 0;
					e_flag1 = 0;
					std::cout << "Button 2 Pressed" << std::endl;
					e_flag2 = 1;

				}
				else if (e_btn4.isMouseOver(e_window))
				{
					e_flag0 = 0;
					e_flag1 = 0;
					e_flag2 = 0;

					t.t_display(e_window);
					std::cout << "Button 4 Pressed" << std::endl;


				}
				else if (e_btn3.isMouseOver(e_window))
				{
					e_flag0 = 0;
					e_flag1 = 0;
					e_flag2 = 0;
					std::cout << "Button 3 Pressed" << std::endl;
					std::string e_str = e_text0.getText() + ',' ;
					e_str += e_text1.getText();
					e_str += ",";
					e_str += e_text2.getText();
					e_str += "\n";
					std::cout << e_str << std::endl;


					for (int i = 1; i < e_str.length(); i++)
					{
						if (e_str[i] == '\n' || e_str[i] == '\r')
						{
							e_str[i] = ',';
						}
					}
					e_str += '\n';


					e_text1.create_syllabus_file(e_str);

					//chatbox r;
					//r.file_network_send("syllabus.csv", "syllabus.csv", "csv", r.syllabus_file_port_csv);

				}


				break;


			}

			e_window.clear();
			e_window.draw(e_background2);
			e_window.draw(e_background1);
			e_window.draw(menu[0]);
			e_window.draw(menu[1]);
			e_window.draw(menu[2]);
			e_text0.drawTo(e_window);
			e_text1.drawTo(e_window);
			e_text2.drawTo(e_window);
			e_btn.drawTo(e_window);
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



void teacher_menu::notice(sf::RenderWindow& window)
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

	


	teacher_menu t(window.getSize().x, window.getSize().y);






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
				break;

			case sf::Event::MouseButtonPressed:
				if (n_btn4.isMouseOver(window))
				{
					t.t_display(window);
					
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
							str2[i] = ',';
						}
					}


					std::cout << str2 << std::endl;


					n_text2.create_notice_file(str2);


					//chatbox r;
					//r.file_network_send("notice.csv", "notice.csv", "csv", r.notice_file_port_csv);



				}


				break;


			}

			window.clear();

			window.draw(background1);
			window.draw(n_menu[1]);
			window.draw(n_menu[2]);

			n_text2.drawTo(window);

			//n_btn2.drawTo(window);
			n_btn3.drawTo(window);
			n_btn4.drawTo(window);

			window.draw(n_sprite1);
			window.draw(n_sprite2);
			window.display();
		}

	}

}

