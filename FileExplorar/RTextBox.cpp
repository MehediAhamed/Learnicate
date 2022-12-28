#include "RTextBox.h"

bool RTextBox::isResourcesLoaded = false;
sf::Font RTextBox::textBoxfont;
sf::Texture RTextBox::textCursor;

void RTextBox::loadResources()
{
	textBoxfont.loadFromFile("resources\\fonts\\segoeuil.ttf");
	textCursor.loadFromFile("resources\\images\\textCursor.png");
}
void RTextBox::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	sf::Vector2f thisPos = getPosition();

	Control::draw(target, states);
	if (isTakingInput)
	{
		sf::RectangleShape cover(getSize());
		cover.setPosition(thisPos);
		cover.setFillColor(sf::Color(65,252,233,90));
		target.draw(cover);

		sf::Text txt(input, textBoxfont, 15);
		txt.setFillColor(sf::Color::Black);
		txt.setPosition(thisPos.x + 2, thisPos.y);
		target.draw(txt);

		if (cursorInterval.getElapsedTime().asMilliseconds() %2000 < 1000)
		{
			sf::Sprite s(textCursor);
			s.setPosition(thisPos.x + txt.getLocalBounds().width, thisPos.y);
			target.draw(s);
		}
	}
	else
	{
		sf::Text txt((path == "") ? "This PC" : path, textBoxfont, 15);
		txt.setFillColor(sf::Color::Black);
		txt.setPosition(thisPos.x + 2, thisPos.y);
		target.draw(txt);
	}
}
RTextBox::RTextBox()
{
	setSize(sf::Vector2f(100, 20));
	if (!isResourcesLoaded)
	{
		loadResources();
		isResourcesLoaded = true;
	}
	setBorderColor(sf::Color::Black);
	setBorderThickness(1);
	setBackgroundColor(sf::Color::White);
	path = "";
	input = "";
	isTakingInput = false;
}

void RTextBox::setPath(std::string str)
{
	path = str;
}

std::string RTextBox::getPath() const
{
	return path;
}

bool RTextBox::getIsTakingInput()
{
	return isTakingInput;
}

void RTextBox::setIsInputInProgress(bool i)
{
	isTakingInput = i;
}

void RTextBox::setInputString(std::string s)
{
	input = s;
}

std::string RTextBox::getInputString()
{
	return input;
}

RTextBox::~RTextBox()
{
}

sf::FloatRect RTextBox::getGlobalBounds() const
{
	return sf::FloatRect(getPosition(), getSize());
}

Control * RTextBox::handleEvent(sf::Event event, sf::Vector2f mousePos)
{
	if (event.type == sf::Event::EventType::TextEntered)
	{
		if (event.text.unicode != 13)
		{
			if (event.text.unicode == '\b' && input != "")
			{
				input.pop_back();
			}
			else if(event.text.unicode != '\b')
			{
				input.push_back(event.text.unicode);
			}
		}
		else
		{
			isTakingInput = false;
		}
	}
	else if (event.type == sf::Event::MouseButtonPressed)
	{
		if (!contains(mousePos))
		{
			isTakingInput = false;
			input = "";
		}
	}
	return this;
}

Control * RTextBox::clone() const
{
	return new RTextBox(*this);
}
