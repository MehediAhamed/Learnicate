#pragma once
#include <string>
#include <SFML\Graphics.hpp>

#include "Control.h"

class Drive:public Control
{
public:
	Drive(const std::string &driveLetter);
	
	void refresh();

	std::string getPath();
	std::string getLabel();
	std::string getFileSysName();
	unsigned long long getCapacity();
	unsigned long long getUsedSpace();
	unsigned long long getFreeSpace();

	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	virtual sf::FloatRect getGlobalBounds() const;
	virtual Control * handleEvent(sf::Event event, sf::Vector2f mousePos);

	virtual Control * clone() const;

	~Drive();
private:
	//Graphical

	void loadDriveResources();
	void refreshGraphicalVariables();

	//Non Graphical
	bool loadNames();//load label, drive letter etc
	void refreshStatistics();
private:
	//Graphical
	static bool isDriveResourcesLoaded;
	static sf::Texture driveIcon;
	static sf::Font driveFont;
	
	//Graphical Elements Variables
	std::string labelAndLetterTxt;
	std::string driveFileSystemTxt;
	std::string driveSpaceInfoTxt;
	sf::Vector2f freeSpaceRectSize;
	sf::Vector2f usedSpaceRectSize;
	float verticalSpacing=10;
	float horizontalSpacing = 10;

	static const sf::Color flatColorConcrete;
	static const sf::Color flatColorMidnightBlue;


	//Non Graphical 
	unsigned int driveType;
	std::string rootPath="";
	std::string label="";
	std::string fileSystemName="";
	unsigned long long capacity = 0;
	unsigned long long usedSpace = 0;
	unsigned long long freeSpace = 0;
};