#pragma once

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

#include<string>
#include <fstream>

#pragma warning(disable:4996)
#pragma comment(lib, "ws2_32.lib")
// Define keys:
#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Textbox {
public:
	Textbox(int size, sf::Color color, bool sel);

	// Make sure font is passed by reference:
	void setFont(sf::Font& fonts);

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
	void create(std::string str);
	void read(std::string str);
private:
	sf::Text textbox;

	std::ostringstream text;
	bool isSelected = false;
	bool hasLimit = false;
	int limit = 0;

	// Delete the last character of the text:
	void deleteLastChar() {
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
	void inputLogic(int charTyped) {
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
			text << "\n";
			
		}
		// Set the textbox text:
		textbox.setString(text.str() + "_");
	}
};



