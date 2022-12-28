#pragma once
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include"../Application/chatbox.h"
#include "Textbox.h"
#include<fstream>




Textbox::Textbox(int size, sf::Color color, bool sel) {
	textbox.setCharacterSize(size);
	textbox.setFillColor(color);
	isSelected = sel;

	// Check if the textbox is selected upon creation and display it accordingly:
	if (isSelected)
		textbox.setString("_");
	else
		textbox.setString("");
}


void Textbox:: operator = (Textbox &t)
{



	
	textbox.setCharacterSize(40);
	textbox.setFillColor(sf::Color::White);
	isSelected = 1;
	setPosition({ 600, 120 });
	setLimit(true, 18);
	
		

	

	// Check if the textbox is selected upon creation and display it accordingly:
	if (isSelected)
		textbox.setString("_");
	else
		textbox.setString("");


	text.clear();
	text.str(" ");


	
	
}

// Delete the last character of the text:
void Textbox::deleteLastChar() {
	std::string t = text.str();
	std::string newT = "";
	for (int i = 0; i < t.length() - 1; i++) {
		newT += t[i];
	}
	text.str("");
	text << newT;
	textbox.setString(text.str() + "_");
}

// Get user input:
void Textbox::inputLogic(int charTyped) {
	// If the key pressed isn't delete, or the two selection keys, then append the text with the char:
	if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {
		text << static_cast<char>(charTyped);
	}
	// If the key is delete, then delete the char:
	else if (charTyped == DELETE_KEY) {
		if (text.str().length() > 0) {
			deleteLastChar();
		}
	}
	else if (charTyped == ENTER_KEY) {
		text << '\n';



	}
	// Set the textbox text:
	textbox.setString(text.str() + "_");

	
}


void Textbox::setSize(int size) {
	textbox.setCharacterSize(size);
}
void Textbox::setColor(sf::Color color) {
	textbox.setFillColor(color);
}
void Textbox::setFont(sf::Font& fonts) {
	textbox.setFont(fonts);

}





void Textbox::setPosition(sf::Vector2f point) {
	textbox.setPosition(point);
}

// Set char limits:
void Textbox::setLimit(bool ToF) {
	hasLimit = ToF;
}

void Textbox::setLimit(bool ToF, int lim) {
	hasLimit = ToF;
	limit = lim - 1;
}

// Change selected state:
void Textbox::setSelected(bool sel) {
	isSelected = sel;

	// If not selected, remove the '_' at the end:
	if (!sel) {
		std::string t = text.str();
		std::string newT = "";
		for (int i = 0; i < t.length(); i++) {
			newT += t[i];
		}
		textbox.setString(newT);
	}
}

std::string Textbox::getText() {
	return text.str();
}

void Textbox::drawTo(sf::RenderWindow& window) {
	window.draw(textbox);
}


bool Textbox::isMouseOver(sf::RenderWindow& window) {
	sf::Vector2i mouseCoords({ sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y });

	sf::Vector2f realCoords = window.mapPixelToCoords(mouseCoords);

	float mouseX = realCoords.x;
	float mouseY = realCoords.y;

	int btnPosX = textbox.getPosition().x;
	int btnPosY = textbox.getPosition().y;

	int btnxPosWidth =textbox.getPosition().x + textbox.getGlobalBounds().width;
	int btnyPosHeight = textbox.getPosition().y + textbox.getGlobalBounds().height;

	if (mouseX < btnxPosWidth + 20 && mouseX > btnPosX - 20 && mouseY < btnyPosHeight + 20 && mouseY > btnPosY - 20) {
		return true;
	}
	return false;
}

// Function for event loop:
void Textbox::typedOn(sf::Event input) {
	if (isSelected) {
		int charTyped = input.text.unicode;

		// Only allow normal inputs:
		if (charTyped < 128) {
			if (hasLimit) {
				// If there's a limit, don't go over it:
				if (text.str().length() <= limit*1) {
					
					if (text.str().length() == limit * 1)
					{
						inputLogic(ENTER_KEY);
					}
					else
					inputLogic(charTyped);
				
				}


				else if(text.str().length() >limit * 1 && text.str().length() <= limit*2)
				{
					if (text.str().length() == limit * 2)
					{
						inputLogic(ENTER_KEY);
					}
					else
						inputLogic(charTyped);
				}

				else if (text.str().length() > limit * 2 &&text.str().length() <= limit * 3)
				{
					if (text.str().length() == limit * 3)
					{
						inputLogic(ENTER_KEY);
					}
					else
						inputLogic(charTyped);
				}

				else if (text.str().length() > limit * 3 && text.str().length() <= limit * 4)
				{
					if (text.str().length() == limit * 4)
					{
						inputLogic(ENTER_KEY);
					}
					else
						inputLogic(charTyped);
				}
				
			}
			// If no limit exists, just run the function:
			else {
				inputLogic(charTyped);
			}
		}
	}
}


// Function for event loop:
void Textbox::typedOn1(sf::Event input,sf::RenderWindow &window) {
	if (isSelected) {
		int charTyped = input.text.unicode;

		// Only allow normal inputs:
		if (charTyped < 128) {
			if (hasLimit) {
				// If there's a limit, don't go over it:
				if (text.str().length() <= limit * 1) {
					if (charTyped != ENTER_KEY)
						inputLogic(charTyped);
					else
						return;

				}

				else if (text.str().length() > limit * 1) 
				{
					sf::Font arial;
				    if (!arial.loadFromFile("ArialTh.ttf"))
				    {
					std::cout << "Font didn't loaded";
				    }
					sf::Text menu;
					menu.setFont(arial);
					menu.setCharacterSize(35);
					menu.setStyle(sf::Text::Bold);
					menu.setFillColor(sf::Color::White);
					menu.setString("Date Format Error");
					menu.setPosition(sf::Vector2f(100, 120));
					window.draw(menu);

				}


			
			}
			// If no limit exists, just run the function:
			else {
				inputLogic(charTyped);
			}
		}
	}
}


void Textbox::create_notice_file(std::string str)
{
	
	std::ofstream myfile("notice.csv", std::ofstream::app);
	if (myfile.is_open())
	{
		myfile << str;


		myfile.close();
		std::cout << "Data has been recorded" << std::endl;
		
		
	}
	else std::cout << "Unable to open file";

	
}


void Textbox::create_syllabus_file(std::string str)
{

	std::ofstream myfile("syllabus.csv", std::ofstream::app);
	if (myfile.is_open())
	{
		myfile << str;


		myfile.close();
		std::cout << "Data has been recorded" << std::endl;


	}
	else std::cout << "Unable to open file";


}

void Textbox::teacher_details_file(std::string str)
{

	std::ofstream myfile("teacher.csv", std::ofstream::app);
	if (myfile.is_open())
	{
		myfile << str;


		myfile.close();
		std::cout << "Data has been recorded" << std::endl;


	}
	else std::cout << "Unable to open file";


}
bool Textbox::read(std::string email, std::string id, Teacher& t) {
	int flag = 0;

	std::ifstream fin;
	std::string line;
	// by default open mode = ios::in mode
	fin.open("teacher.csv");

	// Execute a loop until EOF (End of File)
	while (getline(fin, line)) {

		if (flag == 1)
		{
			break;
		}

		int i = 0;
		std::stringstream ss(line);
		std::string word[10];
		while (!ss.eof()) {
			getline(ss, word[i], ',');
			std::cout << word[i] << std::endl;
			i++;

			if (word[1] == email && word[3] == id)
			{
				t.setValues(word[2], word[0], word[1], word[3]);
				flag = 1;
				return 1;
			}
		}
	}

	// Close the file
	fin.close();
}

bool Textbox::check(std::string email)
{
	int flag = 0;

	std::ifstream fin;
	std::string line;
	// by default open mode = ios::in mode
	fin.open("teacher.csv");

	// Execute a loop until EOF (End of File)
	while (getline(fin, line)) {

		if (flag == 1)
		{
			break;
		}

		int i = 0;
		std::stringstream ss(line);
		std::string word[10];
		while (!ss.eof()) {
			getline(ss, word[i], ',');
			std::cout << word[i] << std::endl;
			i++;

			if (word[1] == email )
			{
				flag = 1;
				return 1;
			}
		}
		return 0;
	}

	// Close the file
	fin.close();


}



//Read part
bool Textbox::read(std::string email, std::string id)
{
	int flag = 0;

	std::ifstream fin;
	std::string line;
	// by default open mode = ios::in mode
	fin.open("teacher.csv");

	// Execute a loop until EOF (End of File)
	while (getline(fin, line)) {

		if (flag == 1)
		{
			break;
		}

		int i = 0;
		std::stringstream ss(line);
		std::string word[10];
		while (!ss.eof()) {
			getline(ss, word[i], ',');
			std::cout << word[i] << std::endl;
			i++;

			if (word[1]==email && word[3]==id)
			{
				flag = 1;
				return 1;
			}
		}
	}

	// Close the file
	fin.close();


}


void Textbox::student_details_file(std::string str)
{

	std::ofstream myfile("student.csv", std::ofstream::app);
	if (myfile.is_open())
	{
		myfile << str;


		myfile.close();
		std::cout << "Data has been recorded" << std::endl;


	}
	else std::cout << "Unable to open file";


}
bool Textbox::student_read(std::string email, std::string id,Student &stu) {
	
	int flag = 0;

	std::ifstream fin;
	std::string line;
	// by default open mode = ios::in mode
	fin.open("student.csv");

	// Execute a loop until EOF (End of File)
	while (getline(fin, line)) {

		if (flag == 1)
		{
			break;
		}

		int i = 0;
		std::stringstream ss(line);
		std::string word[10];
		while (!ss.eof()) {
			getline(ss, word[i], ',');
			std::cout << word[i] << std::endl;
			i++;

			if (word[1] == email && word[3] == id)
			{
				stu.setValues(word[2], word[0], word[1], word[3]);
				flag = 1;
				return 1;
			}
		}
	}

	// Close the file
	fin.close();
	
}

//Read part
bool Textbox::student_read(std::string email, std::string id)
{
	int flag = 0;

	std::ifstream fin;
	std::string line;
	// by default open mode = ios::in mode
	fin.open("student.csv");

	// Execute a loop until EOF (End of File)
	while (getline(fin, line)) {

		if (flag == 1)
		{
			break;
		}

		int i = 0;
		std::stringstream ss(line);
		std::string word[10];
		while (!ss.eof()) {
			getline(ss, word[i], ',');
			std::cout << word[i] << std::endl;
			i++;

			if (word[1] == email && word[3] == id)
			{
				flag = 1;
				return 1;
			}
		}
	}

	// Close the file
	fin.close();


}

