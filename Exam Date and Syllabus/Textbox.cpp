#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

#include "Textbox.h"

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


void Textbox::create(std::string str)
{
	std::ofstream myfile("course.csv", std::ofstream::app);
	if (myfile.is_open())
	{
		myfile << str;


		myfile.close();
		std::cout << "Data has been recorded" << std::endl;
	}
	else std::cout << "Unable to open file";
}

//Read part
void Textbox::read(std::string str)
{
	int flag = 0;
	FILE* fp = fopen("course.csv", "r");

	if (!fp)
		printf("Can't open file\n");

	else {

		char buffer[1024];

		int row = 0;
		int column = 0;

		while (fgets(buffer, 1024, fp)) {


			column = 0;
			row++;

			char* value = strtok(buffer, ", ");

			while (value) {



				// Column 1
				if (column == 0) {

					if (strcmp(value, teacher_name) == 0)
					{
						flag = 1;
						printf("Teacher Name :");
					}

				}

				// Column
				if (column == 1 && flag == 1) {

					printf("\tCourse :");


				}

				// Column 3
				if (column == 2 && flag == 1) {
					printf("\tExam Date :");
				}
				if (column == 3 && flag == 1) {
					printf("\tSyllabus :");
				}

				if (flag == 1 && flag == 1)
				{
					printf(" %s", value);
				}



				value = strtok(NULL, ", ");
				column++;


			}

			printf("\n");
		}
		if(flag==0)
		std::cout << "Data not found" << std::endl;
		fclose(fp);
	}


}
