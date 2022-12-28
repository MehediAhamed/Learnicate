#pragma once
#include "Main_Menu.h"
#include"chatbox.h"
#include"video_cam.h"
#include "../sign_up/Student.h"
#define s_opt 8

//Inheritance from Main Menu
class student_menu : public  Main_Menu
{
private:


	int s_menuIndex;

	sf::Text s_menu[s_opt];
	chatbox s;
	Student Sobj;



public:

	student_menu();
	student_menu(float width, float height);
	~student_menu();
	void draw2(sf::RenderWindow& window1);
	void MoveUp();
	void MoveDown();
	int getPressed();
	void currStu(Student& s);

	void s_display(sf::RenderWindow& window);
	void stu_chat(sf::RenderWindow& window);
	void Details(sf::RenderWindow& wind);

	void stu_video_chat();

	void  readMaterialFile(sf::RenderWindow& e_window);

	void syllabus_display(sf::RenderWindow& e_window);
	void notice_display(sf::RenderWindow& e_window);


};



