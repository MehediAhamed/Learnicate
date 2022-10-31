#include "Textbox.h"
void Textbox::inputL(int charTyped)
{
	if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY)
	{
		text << static_cast<char>(charTyped);
	}
	if (charTyped == DELETE_KEY)
	{
		if (text.str().length() > 0)
		{
			deleteLastChar();
		}
	}
	textb.setString(text.str() + "_");
}

void Textbox::deleteLastChar() {
	std::string t = text.str();
	std::string newT = "";
	for (int i = 0; i < t.length() - 1; i++)
	{
		newT += t[i];
	}
	text.str("");
	text << newT;

	textb.setString(text.str());
}
	
Textbox::Textbox(int size, sf::Color color, bool sel) {
		textb.setCharacterSize(size);
		textb.setFillColor(color);
		isSelected = sel;
		if (sel) {
			textb.setString("_");
		}
		else textb.setString("");
	}
void Textbox::setSize(int size) {
	textb.setCharacterSize(size);
}
void Textbox::setColor(sf::Color color) {
	textb.setFillColor(color);
}
void Textbox::setFont(sf::Font& font) {
		textb.setFont(font);
	}

void Textbox::setPosition(sf::Vector2f pos) {
		textb.setPosition(pos);
	}

	void Textbox::setLimit(bool Tof) {
		hasLimit = Tof;
	}

	void Textbox::setLimit(bool Tof, int lim) {
		hasLimit = Tof;
		limit = lim - 1;
	}

	void Textbox::setSelected(bool sel) {
		isSelected = sel;
		if (!sel) {
			std::string t = text.str();
			std::string newT = "";
			for (int i = 0; i < t.length(); i++)
			{
				newT += t[i];
			}
			textb.setString(newT);
		}
	}

	std::string Textbox::getText() {
		return text.str();
	}

	void Textbox::drawTo(sf::RenderWindow& window) {
		window.draw(textb);
	}

	void Textbox::typedOn(sf::Event input) {
		if (isSelected) {
			int charTyped = input.text.unicode;
			if (charTyped < 128) {
				if (hasLimit) {
					if (text.str().length() <= limit) {
						inputL(charTyped);
					}
					else if (text.str().length() > limit && charTyped == DELETE_KEY) {
						deleteLastChar();
					}
				}
				else {
					inputL(charTyped);
				}
			}
		}
	}
