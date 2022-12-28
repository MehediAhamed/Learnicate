#pragma once
#include "Container.h"
#include "FolderView.h"
#include "TreeNode.h"
#include "Ribbon.h"



class FileExplorer
{
public:
	FileExplorer();
	~FileExplorer();

	void run();

private:
	void populateNode(TreeNode * ptr, sf::Texture & ft, sf::Font & f);
	void loadDrives(TreeNode * root, sf::Texture & ft, sf::Font & f);
private:
	FolderView folderView;
	Ribbon ribbon;

	sf::Texture folderIcon;
	sf::Texture thisPcIcon;
	sf::Texture driveIcon;
	sf::Font font;
};