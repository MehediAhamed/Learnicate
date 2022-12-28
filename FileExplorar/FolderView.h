#pragma once
#include <vector>
#include <string>
#include "File.h"
#include "Drive.h"

class Ribbon;


class FolderView:public Control
{
public:
	FolderView(sf::Vector2f size);

	std::string getCurrentPath()const;
	std::string getSelectedFilePath()const;
	std::string getSelectedFileName() const;

	void loadDirectory(const std::string path, bool effectRibbon=true);

	virtual ~FolderView();
	virtual sf::FloatRect getGlobalBounds() const;
	virtual Control * handleEvent(sf::Event event, sf::Vector2f mousePos);

	virtual Control * clone() const;

	void attachRibbon(Ribbon * rb);

	void refreshDirectory();
	void refreshDrives();
	void refresh();

	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	
	void positionDrives();
	void positionFiles();
private:
	void loadDrives();

	//Graphical
	void onClickLeft(const sf::Event::MouseButtonEvent& mouseButton, sf::Vector2f mousePos);
	void onBackSpace();
	void onMouseMove(const sf::Event::MouseMoveEvent& mouse, sf::Vector2f mousePos);
private:
	sf::Clock lastClickTime;
	Ribbon* pRibbon;
	sf::FloatRect globalBounds;
	std::string currentPath="";
	std::vector<Drive> drives;
	std::vector<File> files;
	int selectedFile=-1;
	int selectedDrive=-1;

};