#pragma once
#include <string>
#include "Control.h"

class File:public Control
{
public:
	enum Type {Folder=0, Other};
	File(const std::string path,const std::string FileName, const Type t,unsigned long long int siz=0 );
	std::string getPath()const;
	Type getType()const;
	std::string getName() const;
	std::string getExtention()const;
	unsigned long long int getSizeInBytes() const;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	virtual sf::FloatRect getGlobalBounds() const;
	virtual Control * handleEvent(sf::Event event, sf::Vector2f mousePos);

	virtual Control * clone() const;

	~File();
private:
	void setSizeString();
	void loadResources();
	void toUpper(std::string & s);
private:
	//Graphical variales
	std::string sizeString;
	static sf::Texture fileIcons[2];
	static sf::Font fileFont[2];
	static bool isResourcesLoaded;
	int horizontalSpacing;
	int verticalSpacing;
	int characterSize;
	//non graphical
	Type type;
	std::string path;
	std::string name;
	std::string extension;
	unsigned long long int size;
};