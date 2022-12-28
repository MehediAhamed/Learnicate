#include "FileExplorer.h"

FileExplorer::FileExplorer():folderView(sf::Vector2f(350, 600)),ribbon(&folderView, sf::Vector2f(600, 100))
{
	folderView.attachRibbon(&ribbon);
	folderView.setBackgroundColor(sf::Color::White);

	folderView.setPosition(sf::Vector2f(0, 0));
	ribbon.setPosition(sf::Vector2f(0, 0));

	folderIcon.loadFromFile("resources/images/smallFolder.png");
	thisPcIcon.loadFromFile("resources/images/thisPc.png");
	driveIcon.loadFromFile("resources/images/smallDrive.png");

	font.loadFromFile("resources/fonts/segoeuil.ttf");

}

FileExplorer::~FileExplorer()
{
}

void FileExplorer::run()
{
	sf::Vector2f winSize = { 600,600 };
	sf::RenderWindow window(sf::VideoMode(winSize.x, winSize.y), "FileExplorer");

	sf::View mainView(sf::FloatRect({ 0, 0 }, winSize));
	mainView.setViewport(sf::FloatRect(0, 0, 1, 1));

	TreeNode treeView("This PC", "", thisPcIcon, font);
	loadDrives(&treeView, driveIcon, font);
	treeView.expandNode(true);


	Container leftPanel({ 0,100,250,winSize.y - 100 }, treeView, winSize);
	Container rightPanel({ 250,100,winSize.x - 250,winSize.y - 100 }, folderView, winSize);

	Control * oldEvent = nullptr;

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == event.Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::Resized)
			{
				winSize = { float(event.size.width) , float(event.size.height) };
				leftPanel.resize({ 0,100,250,winSize.y - 100 }, winSize);
				rightPanel.resize({ 250,100,winSize.x - 250,winSize.y - 100 }, winSize);

				ribbon.setSize(sf::Vector2f(window.getSize().x, 100));
				ribbon.positionButtons();

				folderView.setSize(sf::Vector2f(window.getSize().x - 250, window.getSize().y - 100));
				folderView.positionFiles();
				folderView.positionDrives();

				mainView.reset(sf::FloatRect({ 0, 0 }, winSize));
			}
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				if (oldEvent)
				{
					oldEvent->setBackgroundColor(sf::Color::Transparent);
					oldEvent = nullptr;
				}
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				if (leftPanel.contains({ (float)mousePos.x,(float)mousePos.y }))
				{
					TreeNode * ptr = (TreeNode*)leftPanel.handleEvent(window, event, mousePos);
					if (ptr)
					{
						oldEvent = ptr;
						if (!ptr->getNoOfChilds())
						{
							populateNode(ptr, folderIcon, font);
						}
						ptr->expandNode(!ptr->isNodeExpanded());
						ptr->setBackgroundColor(sf::Color(51, 190, 198, 150));

						leftPanel.updateControlSize({ treeView.getGlobalBounds().width, treeView.getGlobalBounds().height });

						std::string address = "\\";
						for (TreeNode * tn = ptr; tn != nullptr; tn = tn->getParent())
						{
							address = "\\" + tn->getName() + address;
						}
						address.replace(0, 2, "");

						folderView.loadDirectory(address);
				


						rightPanel.updateControlSize({ folderView.getGlobalBounds().width,folderView.getGlobalBounds().height });
					}
				}
			}
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			if (leftPanel.contains({ (float)mousePos.x,(float)mousePos.y }))
			{
				leftPanel.handleEvent(window, event, mousePos);
			}
			else if (rightPanel.contains({ (float)mousePos.x,(float)mousePos.y }))
			{
				rightPanel.handleEvent(window, event, mousePos);
				rightPanel.updateControlSize({ folderView.getGlobalBounds().width,folderView.getGlobalBounds().height });
			}
			else /*if (ribbon.contains({ (float)mousePos.x,(float)mousePos.y }))*/
			{
				ribbon.handleEvent(event, { (float)mousePos.x,(float)mousePos.y });
			}
		}

		window.clear(sf::Color(250, 250, 250, 1));
		window.draw(leftPanel);
		window.draw(rightPanel);
		window.setView(mainView);
		window.draw(ribbon);
		window.display();
	}

}

void FileExplorer::populateNode(TreeNode * ptr, sf::Texture & ft, sf::Font & f)
{
	std::string address = "\\";
	for (TreeNode * tn = ptr; tn != nullptr; tn = tn->getParent())
	{
		address = "\\" + tn->getName() + address;
	}
	address.replace(0, 2, "");
	std::vector<std::string> list = FileSystem::getDirectoriesList(address);

	for (auto& str : list)
	{
		ptr->addNode(TreeNode(str, str, ft, f));
	}
}

void FileExplorer::loadDrives(TreeNode * root, sf::Texture & ft, sf::Font & f)
{
	std::vector<std::string> list = FileSystem::getDrivesList();
	for (auto & str : list)
	{
		str.pop_back();
		root->addNode(TreeNode(str, str, ft, f));
	}
}

