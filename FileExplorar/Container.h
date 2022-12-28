#ifndef CONTAINER_H
#define CONTAINER_H


#include"ScrollBar.h"
#include"Control.h"

class Container : public sf::Drawable
{
private:
	sf::View controlView;
	sf::View containerView;
	sf::FloatRect bounds;
	Control & control;
	ScrollBar  scroll;

	static const int scrollBarSize = 15;
public:
	Container(const sf::FloatRect & rectangle, Control & ctrl, const sf::Vector2f & windowSize);
	void resize(const sf::FloatRect & rectangle, const sf::Vector2f & windowSize);
	bool contains(const sf::Vector2f & point);
	Control * handleEvent(sf::RenderWindow & window, sf::Event event, sf::Vector2i mousePos);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void updateControlSize(const sf::Vector2f & size);
};


#endif // !CONTAINER_H
