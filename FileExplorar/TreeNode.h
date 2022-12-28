#ifndef Tree_Node_H
#define Tree_Node_H

#include"Control.h"

class TreeNode : public Control
{
private:
	std::vector<TreeNode*>	childNode;
	TreeNode*			parent;
	std::string				name;
	sf::Text				text;
	sf::Sprite				icon;
	bool				isExpanded;
	sf::FloatRect			globalBounds;

	static sf::Texture		downArrow;
	static sf::Texture		rightArrow;
	static bool			isTextureLoaded;

	static const int nodeHeight = 25;
public:
	TreeNode(const std::string & title, const std::string & address, const sf::Texture & ico, const sf::Font & f);
	TreeNode(const TreeNode & ref);
	~TreeNode();

	TreeNode*	getChildNode(int index)	const;
	TreeNode*	getParent()				const;
	std::string		getText()				const;
	std::string		getName()				const;
	int			getNoOfChilds()			const;
	int			findNodeHeight()		const;
	bool		isNodeExpanded()		const;


	void addNode(const TreeNode & node);
	void removeAllNodes();
	void setParent(TreeNode * ptr);
	void setPosition(const sf::Vector2f & pos);
	void setIcon(const sf::Sprite & ico);
	void setText(const std::string & title);
	void setName(const std::string & address);
	void expandNode(bool val);


	virtual sf::FloatRect getGlobalBounds() const;
	virtual Control * clone() const;


	virtual Control * handleEvent(sf::Event event, sf::Vector2f mousePos);
	TreeNode * onClick(sf::Vector2f mouse);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	static void loadTextures();
};

#endif // !Tree_Node_H
