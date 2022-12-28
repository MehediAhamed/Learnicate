#pragma once
#include "Main_Menu.h"
#include"chatbox.h"
#include"video_cam.h"
#include"../sign_up/Teacher.h"
#define t_opt 8

//Inheritance from Main Menu
class teacher_menu : public  Main_Menu
{
private:


	int t_menuIndex;

	sf::Text t_menu[t_opt];




public:
	Teacher Tobj;
	teacher_menu();
	teacher_menu(float width, float height);
	~teacher_menu();
	void draw2(sf::RenderWindow& window1);
	void MoveUp();
	void MoveDown();
	int getPressed();
	void currTeach(Teacher& t);
	void Details(sf::RenderWindow& wind);

	void t_display(sf::RenderWindow& window);


	void tchr_chat(sf::RenderWindow& window);

	void tchr_video_chat(sf::RenderWindow& window);

	virtual void syllabus(sf::RenderWindow& window);
	virtual void notice(sf::RenderWindow& window);


	



};


