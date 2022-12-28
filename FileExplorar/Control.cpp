#include"Control.h"

Control::Control()
{
}
Control::Control(const sf::Vector2f & position, const sf::Vector2f & size) : bounds(size)
{
	bounds.setPosition(position);
}

bool Control::contains(const sf::Vector2f & point) const
{
	return sf::FloatRect(bounds.getGlobalBounds()).contains(point);
}
sf::Vector2f Control::getPosition() const
{
	return bounds.getPosition();
}
sf::Vector2f Control::getSize() const
{
	return bounds.getSize();
}
void Control::setSize(const sf::Vector2f & size)
{
	bounds.setSize(size);
}
void Control::setPosition(const sf::Vector2f & position)
{
	bounds.setPosition(position);
}
void Control::setBackgroundColor(sf::Color bkColor)
{
	bounds.setFillColor(bkColor);
}
void Control::setBorderColor(sf::Color borderColor)
{
	bounds.setOutlineColor(borderColor);
}
void Control::setBorderThickness(float thickness)
{
	bounds.setOutlineThickness(thickness);
}
void Control::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(bounds, states);
}
Control::~Control()
{}
