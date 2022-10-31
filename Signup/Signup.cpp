// Signup.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include "SFML/Window.hpp"
#include "Menu.h"
#include "TeachSignup.h"
#include "TeachLogin.h"
#include "stuSignup.h"
#include "stuLogin.h"

int main()
{
	sf::RenderWindow wind(sf::VideoMode(960,720),"My window",sf::Style::Default);
	Menu supmenu(wind.getSize().x, wind.getSize().y);
	
	//Creating signup and login objects:
	TeachSignup tmenu(wind.getSize().x, wind.getSize().y);
	TeachLogin tlmenu(wind.getSize().x, wind.getSize().y);
	stuSignup smenu(wind.getSize().x, wind.getSize().y);
	stuLogin slmenu(wind.getSize().x, wind.getSize().y);
	
	//Flags:
	bool tflag[signop];
	fill_n(tflag, signop, false);

	bool tlflag[logop];
	fill_n(tlflag, logop, false);

	bool sflag[signop];
	fill_n(sflag, signop, false);

	bool slflag[logop];
	fill_n(slflag, logop, false);
	
	//Main window:
	while (wind.isOpen())
	{
		sf::Event e;

		while (wind.pollEvent(e))
		{
			if (e.type == sf::Event::Closed) 
				wind.close();
			if (e.type == sf::Event::KeyReleased) {
				if (e.key.code == sf::Keyboard::Up) {
					supmenu.MoveUp();
					break;
				}
				if (e.key.code == sf::Keyboard::Down) {
					supmenu.MoveDown();
					break;
				}
				if (e.key.code == sf::Keyboard::Return) {
					//Rendering all the windows separately

					int x = supmenu.MenuPressed();
					if (x == 0) {
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
								fill_n(tflag, signop, false);
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
											fill_n(tflag, signop, false);
											tflag[0] = true;
										}
										//Email:
										if (y == 1) {
											fill_n(tflag, signop, false);
											tflag[1] = true;
											
										}
										//ID:
										if (y == 2) {
											fill_n(tflag, signop, false);
											tflag[2] = true;
										}
										//Pass:
										if (y == 3) {
											fill_n(tflag, signop, false);
											tflag[3] = true;
										}
										//Back:
										if (y == 4) {
											//should store the values	
											tmenu.tb[0].setSelected(false);
											tmenu.tb[1].setSelected(false);
											tmenu.tb[2].setSelected(false);
											tmenu.tb[3].setSelected(false);
										}
										
									}

								}
							}
							
							SignT.clear();
							tmenu.draw(SignT);
							for (int i = 0; i < signop-1; i++) {
								tmenu.tb[i].drawTo(SignT);
							}
							SignT.display();
							
						
						}
					}
					if (x == 1) 
					{
						/*cout << "Log in Teacher" << endl;*/
						sf::RenderWindow& LogT = wind;
						/*sf::RenderWindow LogT(sf::VideoMode(960, 720), "Log In Teacher");*/
						while (LogT.isOpen())
						{
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
								if (tlflag[0] == true) {
									tlmenu.tb[0].setSelected(true);
									tlmenu.tb[1].setSelected(false);
									
								}
								if (tlflag[1] == true) {
									tlmenu.tb[0].setSelected(false);
									tlmenu.tb[1].setSelected(true);

								}

							}
							else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)) {
								fill_n(tlflag, logop, false);
								tlmenu.tb[0].setSelected(false);
								tlmenu.tb[1].setSelected(false);
								
							}
							sf::Event ltevent;
							while (LogT.pollEvent(ltevent))
							{
								if (ltevent.type == sf::Event::Closed) {
									LogT.close();
								}
								if (ltevent.type == sf::Event::TextEntered) {
									if (tlflag[0] == true) {
										tlmenu.tb[0].typedOn(ltevent);
									}
									if (tlflag[1] == true) {
										tlmenu.tb[1].typedOn(ltevent);
									}

								}


								if (ltevent.type == sf::Event::KeyPressed) {
									if (ltevent.key.code == sf::Keyboard::Escape) {
										LogT.close();
									}
									if (ltevent.key.code == sf::Keyboard::Up) {
										tlmenu.MoveUp();
										break;
									}
									if (ltevent.key.code == sf::Keyboard::Down) {
										tlmenu.MoveDown();
										break;
									}
									if (ltevent.key.code == sf::Keyboard::Return) {
										int y = tlmenu.OptionPressed();
										//Email:
										if (y == 0) {
											fill_n(tlflag, logop, false);
											tlflag[0] = true;
										}
										//Password:
										if (y == 1) {
											fill_n(tlflag, logop, false);
											tlflag[1] = true;
										}
										//Back:
										if (y == 2) {
											//should store the values	
											tlmenu.tb[0].setSelected(false);
											tlmenu.tb[1].setSelected(false);
											
										}
									}
								}
							}
							LogT.clear();
							tlmenu.draw(LogT);
							for (int i = 0; i < logop-1; i++) 
							{
								tlmenu.tb[i].drawTo(LogT);
							}
							
							LogT.display();
						}
					}
					if (x == 2) {
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
										//Back:
										if (y == 4) {
											//should store the values
											smenu.tb[0].setSelected(false);
											smenu.tb[1].setSelected(false);
											smenu.tb[2].setSelected(false);
											smenu.tb[3].setSelected(false);
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
					if (x == 3) 
					{
						/*cout << "Log in Student" << endl;*/
						/*sf::RenderWindow LogS(sf::VideoMode(960, 720), "Log In Student");*/
						sf::RenderWindow& LogS = wind;
						while (LogS.isOpen())
						{
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
								if (slflag[0] == true) {
									slmenu.tb[0].setSelected(true);
									slmenu.tb[1].setSelected(false);

								}
								if (slflag[1] == true) {
									slmenu.tb[0].setSelected(false);
									slmenu.tb[1].setSelected(true);

								}
							}
								else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)) {
									fill_n(slflag, logop, false);
									slmenu.tb[0].setSelected(false);
									slmenu.tb[1].setSelected(false);

								}
							

								sf::Event lsevent;
								while (LogS.pollEvent(lsevent))
								{
									if (lsevent.type == sf::Event::Closed) {
										LogS.close();
									}

									if (lsevent.type == sf::Event::TextEntered) {
										if (slflag[0] == true) {
											slmenu.tb[0].typedOn(lsevent);
										}
										if (slflag[1] == true) {
											slmenu.tb[1].typedOn(lsevent);
										}

									}

									if (lsevent.type == sf::Event::KeyPressed) {
										if (lsevent.key.code == sf::Keyboard::Escape) {
											LogS.close();
										}
										if (lsevent.key.code == sf::Keyboard::Up) {
											slmenu.MoveUp();
											break;
										}
										if (lsevent.key.code == sf::Keyboard::Down) {
											slmenu.MoveDown();
											break;
										}
										if (lsevent.key.code == sf::Keyboard::Return) {
											int y = slmenu.OptionPressed();
											//Email:
											if (y == 0) {
												fill_n(slflag, logop, false);
												slflag[0] = true;
											}
											//Password:
											if (y == 1) {
												fill_n(slflag, logop, false);
												slflag[1] = true;
											}
											//Back:
											if (y == 2) {
												//should store the values	
												slmenu.tb[0].setSelected(false);
												slmenu.tb[1].setSelected(false);

											}
										}
									}
								}

								LogS.clear();
								slmenu.draw(LogS);
								for (int i = 0; i < logop - 1; i++) {
									slmenu.tb[i].drawTo(LogS);
								}
								LogS.display();
							
						}
					}
					if (x == 4) {
						
						std::cout << "Go Back" << endl;
					}

					break;
				}
			}
		}
		wind.clear();
		supmenu.draw(wind);
		wind.display();

	}
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
