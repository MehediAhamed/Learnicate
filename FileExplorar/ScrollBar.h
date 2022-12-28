
#ifndef SCROLL_BAR_H
#define SCROLL_BAR_H


#include"SFML\Graphics.hpp"
#include<iostream>
#include<fstream>
#include<vector>
#include<string>




class ScrollBar : public sf::Drawable
{
private:
	sf::RectangleShape scrollArea;
	sf::RectangleShape bar;
	sf::RectangleShape scrollUpButton;
	sf::RectangleShape scrollDownButton;
	sf::Sprite sUp;
	sf::Sprite sDown;
	int scrollValue;

	sf::Vector2f targetSize;
	sf::View & targetView;

	static sf::Texture caretUp;
	static sf::Texture caretDown;
	static bool isTextureLoaded;

	static void loadTextures();
public:
	ScrollBar(const sf::Vector2f & position, const sf::Vector2f & size, sf::View & view, const sf::Vector2f & targetViewSize);
	void setSettings(const sf::Vector2f & position, const sf::Vector2f & size);
	
	void updateTargetSize(const sf::Vector2f & targetViewSize);
	bool scrollUpButtonClick();
	bool scrollDownButtonClick();
	bool onScrollUpButton(const sf::Vector2f & point);
	bool onScrollDownButton(const sf::Vector2f & point);
	bool onBar(const sf::Vector2f & point);
	bool scroll(float value);

	bool contains(const sf::Vector2f & point);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // !SCROLL_BAR_H