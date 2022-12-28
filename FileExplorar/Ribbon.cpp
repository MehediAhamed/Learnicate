#include "Ribbon.h"
#include <iostream>



Ribbon::Ribbon(FolderView *fv, const sf::Vector2f & si)
{
	buttons.emplace_back(RibbonButton(RibbonButton::BACK));
	buttons.emplace_back(RibbonButton(RibbonButton::FORTH));
	setSize(si);
	positionButtons();
	folderView = fv;
	paths.push_back("");
	currentPathIndex = 0;
	lastOperation = RibbonButton::INVALID;
}

void Ribbon::positionButtons()
{
	sf::Vector2f pos(getPosition());
	for (int i = 0; i < 2; i++)
	{
		if (pos.x + buttons[i].getSize().x < getSize().x)
		{
			buttons[i].setPosition(pos);
			pos.x += buttons[i].getSize().x;
		}
		else
		{
			pos.x = getPosition().x;
			pos.y += buttons[i].getSize().y;

			buttons[i].setPosition(pos);
			pos.x += buttons[i].getSize().x;
		}
	}
	buttons[0].setPosition(sf::Vector2f(5, 75));
	buttons[1].setPosition(sf::Vector2f(25, 75));
	buttons[0].setSize(sf::Vector2f(15, 20));
	buttons[1].setSize(sf::Vector2f(15, 20));
	directoryTextBox.setPosition(sf::Vector2f(50, 75));
	directoryTextBox.setSize(sf::Vector2f(getSize().x - 60, 20));
}

void Ribbon::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto& x : buttons)
	{
		target.draw(x);
	}
	target.draw(directoryTextBox);
}

Control * Ribbon::handleEvent(sf::Event evnt, sf::Vector2f mousePos)
{
	switch (evnt.type)
	{
	case sf::Event::MouseButtonPressed:
	{
		directoryTextBox.handleEvent(evnt, mousePos);
		if (evnt.mouseButton.button == sf::Mouse::Button::Left)
		{
			onMouseLeftClick(evnt.mouseButton);
		}
		break;
	}
	case sf::Event::MouseMoved:
	{
		onMouseOver(evnt.mouseMove);
		break;
	}

	default:
		break;
	}
	return this;
}

void Ribbon::setPath(std::string path, bool truncateFollowing)
{
	if (truncateFollowing && currentPathIndex != paths.size() - 1 && paths.size() > 1)
	{
		paths.erase(paths.begin() + currentPathIndex + 1, paths.end());
		paths.push_back(path);
		currentPathIndex++;
		refresh();
		return;
	}
	if (path != paths[currentPathIndex])
	{
		paths.push_back(path);
		currentPathIndex++;
		refresh();
	}
	return;
}

void Ribbon::refresh()
{
	folderView->refreshDirectory();
	directoryTextBox.setPath(paths[currentPathIndex]);
}

Ribbon::~Ribbon()
{
}

sf::FloatRect Ribbon::getGlobalBounds() const
{
	return sf::FloatRect(getPosition(), getSize());
}

Control * Ribbon::clone() const
{
	return new Ribbon(*this);
}


void Ribbon::onMouseLeftClick(sf::Event::MouseButtonEvent & mouseButton)
{
	for (auto& x : buttons)
	{
		if (x.contains(sf::Vector2f(mouseButton.x, mouseButton.y)))
		{
			onButtonPress(x.getType());
			return;
		}
	}
	if (directoryTextBox.contains(sf::Vector2f(mouseButton.x, mouseButton.y)))
	{
		directoryTextBox.setIsInputInProgress(true);
		lastOperation = RibbonButton::INVALID;
		directoryTextBox.setInputString(folderView->getCurrentPath());
	}
}

void Ribbon::onMouseOver(sf::Event::MouseMoveEvent & mouse)
{
	for (auto& x : buttons)
	{
		if (x.contains(sf::Vector2f(mouse.x, mouse.y)))
		{
			x.setBackgroundColor(sf::Color(51, 190, 198, 150));
		}
		else
		{
			x.setBackgroundColor(sf::Color::Transparent);
		}
	}
}

void Ribbon::onButtonPress(RibbonButton::ButtonType t)
{
	switch (t)
	{
	
	

	case RibbonButton::BACK:
	{
		if (currentPathIndex > 0)
		{
			currentPathIndex--;
			folderView->loadDirectory(paths[currentPathIndex], false);
			refresh();
		}
		break;
	}
	case RibbonButton::FORTH:
	{
		if (currentPathIndex < paths.size() - 1)
		{
			currentPathIndex++;
			folderView->loadDirectory(paths[currentPathIndex], false);
			refresh();
		}
		break;
	}
	default:
		break;
	}
}
