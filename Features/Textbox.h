#pragma once

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

#include<string>
#include <fstream>
#include "../sign_up/Teacher.h"
#include "../sign_up/Student.h"





#pragma warning(disable:4996)
#pragma comment(lib, "ws2_32.lib")
// Define keys:
#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Textbox {

private:
	sf::Text textbox;

	
	bool isSelected = false;
	bool hasLimit = false;
	int limit = 0;

	// Delete the last character of the text:
	void deleteLastChar();

	// Get user input:
	void inputLogic(int charTyped);
public:

	std::ostringstream text;



	Textbox() {


	}

	void operator = (Textbox &t);
	

	void setSize(int size);
	void setColor(sf::Color color);
	void setFont(sf::Font& font);
	Textbox(int size, sf::Color color, bool sel);

	// Make sure font is passed by reference:


	void setPosition(sf::Vector2f point);

	// Set char limits:
	void setLimit(bool ToF);

	void setLimit(bool ToF, int lim);

	// Change selected state:
	void setSelected(bool sel);

	std::string getText();

	void drawTo(sf::RenderWindow& window);

	// Function for event loop:
	void typedOn(sf::Event input);
	void typedOn1(sf::Event input, sf::RenderWindow& window);
	bool isMouseOver(sf::RenderWindow& window);
	void create_notice_file(std::string str);
	void create_syllabus_file(std::string str);
	bool read(std::string str, std::string id);

	void teacher_details_file(std::string str);

	void student_details_file(std::string str);

	bool read(std::string email, std::string id, Teacher& t);

	bool student_read(std::string email, std::string id);
	bool student_read(std::string email, std::string id,Student &stu);
	bool check(std::string email);
	
};



