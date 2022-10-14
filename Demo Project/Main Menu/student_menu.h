#pragma once
#include "Main_Menu.h"
#include"chatbox.h"
#include"video_cam.h"
#define s_opt 8

//Inheritance from Main Menu
class student_menu : public  Main_Menu
{
private:
	

	int s_menuIndex;

	sf::Text s_menu[s_opt];
	chatbox s;



public:

	student_menu();
	student_menu(float width, float height);
	~student_menu();
	void draw2(sf::RenderWindow& window1);
	void MoveUp();
	void MoveDown();
	int getPressed();

	void s_display(sf::RenderWindow& window);
	void stu_chat();


	void stu_video_chat();


};



