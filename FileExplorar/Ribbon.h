#pragma once
class TreeView;
#include "FileSystem.h"
#include "FolderView.h"
#include "RTextBox.h"
#include "RibbonButton.h"

class Ribbon:public Control
{
public:
	Ribbon(FolderView * fv, const sf::Vector2f & si);
	void positionButtons();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	virtual Control * handleEvent(sf::Event event, sf::Vector2f mousePos);

	void setPath(std::string path, bool truncateFollowing = false);

	void refresh();

	virtual ~Ribbon();
	virtual sf::FloatRect getGlobalBounds() const;
	

	virtual Control * clone() const;

private:
	void onMouseLeftClick(sf::Event::MouseButtonEvent & mouseButton);
	void onMouseOver(sf::Event::MouseMoveEvent & mouse);
	void onButtonPress(RibbonButton::ButtonType t);

private:
	std::vector<RibbonButton> buttons;
	std::vector<std::string> paths;
	int currentPathIndex;

	FolderView * folderView;
	FileSystem fs;
	RTextBox directoryTextBox;

	std::string operationFrom;//for copy and move
	/*bool inputInProgress;
	string inputString;*/
	RibbonButton::ButtonType lastOperation;
};