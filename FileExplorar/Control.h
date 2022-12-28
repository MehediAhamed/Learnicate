#ifndef CONTROL_H
#define CONTROL_H

#include"SFML\Graphics.hpp"
#include<iostream>
#include<vector>
#include<string>



class Control : public sf::Drawable
{
private:

	sf::RectangleShape bounds;
public:
	Control();
	Control(const sf::Vector2f & position, const sf::Vector2f & size);
	virtual ~Control() = 0;
	bool contains(const sf::Vector2f & point) const;

	virtual sf::Vector2f getPosition() const;
	virtual sf::Vector2f getSize() const;
	virtual sf::FloatRect getGlobalBounds() const = 0;

	virtual void setSize(const sf::Vector2f & size);
	virtual void setPosition(const sf::Vector2f & position);
	
	void setBackgroundColor(sf::Color bkColor);
	void setBorderColor(sf::Color borderColor);
	void setBorderThickness(float thickness);

	virtual Control * handleEvent(sf::Event event, sf::Vector2f mousePos) = 0;

	virtual Control * clone() const = 0;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // !CONTROL_H
