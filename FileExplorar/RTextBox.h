#pragma once
#include "Control.h"

class RTextBox : public Control
{
private:
	std::string path;
	std::string input;
	bool isTakingInput;

	sf::Clock cursorInterval;

	static sf::Font textBoxfont;
	static sf::Texture textCursor;
	void loadResources();
	static bool isResourcesLoaded;
public:
	void draw(sf::RenderTarget & target, sf::RenderStates states)const override;

	RTextBox();
	void setPath(std::string str);
	std::string getPath() const;

	bool getIsTakingInput();
	void setIsInputInProgress(bool i);
	void setInputString(std::string s);
	std::string getInputString();

	virtual ~RTextBox();
	virtual sf::FloatRect getGlobalBounds() const;
	virtual Control * handleEvent(sf::Event event, sf::Vector2f mousePos);
	virtual Control * clone() const;
};
