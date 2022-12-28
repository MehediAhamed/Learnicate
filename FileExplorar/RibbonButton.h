#pragma once
#include "Control.h"
class RibbonButton:public Control
{
public:
	enum ButtonType { NEW_FILE=0, NEW_FOLDER, DELETEE, RENAME, COPY, MOVE, PASTE,BACK,FORTH,INVALID };
	RibbonButton(ButtonType t);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	ButtonType getType();
	virtual ~RibbonButton();
	virtual sf::FloatRect getGlobalBounds() const;
	virtual Control * handleEvent(sf::Event event, sf::Vector2f mousePos);

	virtual Control * clone() const;

	void loadResources();
private:
	ButtonType type;
	static sf::Texture textures[9];
	static bool isResourcesLoaded;

};