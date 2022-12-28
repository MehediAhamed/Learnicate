#include "RibbonButton.h"


sf::Texture RibbonButton::textures[9];
bool RibbonButton::isResourcesLoaded = false;
RibbonButton::RibbonButton(ButtonType t)
{
	type = t;
	if (!isResourcesLoaded)
	{
		loadResources();
		isResourcesLoaded = true;
	}
	setBackgroundColor(sf::Color::Transparent);
	setSize(sf::Vector2f(70, 70));
}
void RibbonButton::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	sf::Vector2f thisPos = getPosition();

	Control::draw(target,states);

	sf::Sprite icon;
	icon.setTexture(textures[type]);
	icon.setPosition(thisPos.x, thisPos.y);
	target.draw(icon);

}
void RibbonButton::loadResources()
{

	textures[BACK].loadFromFile("resources\\images\\backButton.png");
	textures[FORTH].loadFromFile("resources\\images\\forthButton.png");
}

RibbonButton::ButtonType RibbonButton::getType()
{
	return type;
}

RibbonButton::~RibbonButton()
{
}

sf::FloatRect RibbonButton::getGlobalBounds() const
{
	return sf::FloatRect(getPosition(),getSize());
}

Control * RibbonButton::handleEvent(sf::Event event, sf::Vector2f mousePos)
{
	return this;
}

Control * RibbonButton::clone() const
{
	return new RibbonButton(*this);
}
