#include"TreeNode.h"

sf::Texture TreeNode::downArrow;
sf::Texture TreeNode::rightArrow;
bool TreeNode::isTextureLoaded = false;

TreeNode::TreeNode(const std::string & title, const std::string & address, const sf::Texture & ico, const sf::Font & f) :
	Control({ 0,0 }, { 200,(float)nodeHeight }),
	globalBounds({ 0,0 }, { 200,(float)nodeHeight }),
	icon(ico),
	name(address),
	text(title, f, 13)
{
	if (!isTextureLoaded)
	{
		loadTextures();
		isTextureLoaded = true;
	}

	icon.setScale({ 1.1f,1.1f });
	text.setFillColor(sf::Color::Black);

	text.getGlobalBounds();

	setSize({ 60 + text.getGlobalBounds().width,(float)nodeHeight });
	globalBounds.width = 60 + text.getGlobalBounds().width;

	Control::setBackgroundColor(sf::Color::Transparent);

	setPosition({ 0,0 });

	parent = nullptr;
	isExpanded = false;
}
TreeNode::TreeNode(const TreeNode & ref) :
	Control(ref),
	globalBounds(ref.globalBounds),
	icon(ref.icon),
	text(ref.text),
	name(ref.name)
{
	isExpanded = ref.isExpanded;
	parent = ref.parent;

	for (auto & node : ref.childNode)
	{
		node->parent = this;
		childNode.push_back(new TreeNode(*node));
	}

}
TreeNode::~TreeNode()
{
	for (auto & node : childNode)
	{
		delete node;
	}
	childNode.clear();
}
void TreeNode::addNode(const TreeNode & node)
{
	TreeNode * ptr = new TreeNode(node);
	ptr->parent = this;
	ptr->setPosition({ Control::getPosition().x + 10,Control::getPosition().y + nodeHeight });
	childNode.push_back(ptr);
}
void TreeNode::removeAllNodes()
{
	this->~TreeNode();
}
int TreeNode::getNoOfChilds() const
{
	return childNode.size();
}
TreeNode* TreeNode::getChildNode(int index) const
{
	return childNode[index];
}
sf::FloatRect TreeNode::getGlobalBounds() const
{
	return globalBounds;
}
bool TreeNode::isNodeExpanded() const
{
	return isExpanded;
}
TreeNode * TreeNode::getParent() const
{
	return parent;
}
std::string TreeNode::getText() const
{
	return text.getString();
}
void TreeNode::setText(const std::string & title)
{
	text.setString(title);
	setSize({ 60 + text.getGlobalBounds().width,(float)nodeHeight });
	globalBounds.width = 60 + text.getGlobalBounds().width;
}
int TreeNode::findNodeHeight() const
{
	int height = 0;
	if (isExpanded)
	{
		height += 25 * childNode.size();
		for (auto & node : childNode)
		{
			height += node->findNodeHeight();
		}
	}
	return height;
}
void TreeNode::expandNode(bool val)
{
	if (val)
	{
		isExpanded = val;
		int height = findNodeHeight();
		for (TreeNode * tn = this; tn != nullptr; tn = tn->parent)
		{
			tn->globalBounds.height += height;
		}
	}
	else
	{
		int height = findNodeHeight();
		for (TreeNode * tn = this; tn != nullptr; tn = tn->parent)
		{
			tn->globalBounds.height -= height;
		}
		isExpanded = val;
	}
}
void TreeNode::setParent(TreeNode * ptr)
{
	if (ptr != this)
		parent = ptr;
}
void TreeNode::setPosition(const sf::Vector2f & position)
{
	Control::setPosition(position);

	globalBounds.left = position.x;
	globalBounds.top = position.y;

	icon.setPosition({ position.x + 20,position.y + 0 });

	text.setPosition({

		icon.getTexture()->getSize().x * 1.1f + 5 + 20 + position.x
		,
		(icon.getTexture()->getSize().y * 1.1f) / 2 - text.getGlobalBounds().height / 2 - 2.0f + position.y

	});

}
void TreeNode::setIcon(const sf::Sprite & ico)
{
	icon = ico;
}
void TreeNode::loadTextures()
{
	downArrow.loadFromFile("resources/images/down.png");
	downArrow.setSmooth(true);

	rightArrow.loadFromFile("resources/images/right.png");
	rightArrow.setSmooth(true);


}
void TreeNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Sprite arrow;
	if (isExpanded)
		arrow.setTexture(downArrow);
	else
		arrow.setTexture(rightArrow);

	arrow.setScale({ 0.3f,0.3f });
	arrow.setPosition({ Control::getPosition().x + 5,Control::getPosition().y + 4 });

	Control::draw(target, states);
	target.draw(arrow, states);
	target.draw(icon, states);
	target.draw(text, states);


	if (isExpanded && childNode.size())
	{
		childNode[0]->setPosition({ Control::getPosition().x + 10, Control::getPosition().y + 25 });
		target.draw(*childNode[0], states);

		for (int i = 1; i < childNode.size(); i++)
		{
			float height = childNode[i - 1]->isExpanded ? childNode[i - 1]->globalBounds.height : 25;
			childNode[i]->setPosition({ Control::getPosition().x + 10, childNode[i - 1]->Control::getPosition().y + height });
			target.draw(*childNode[i], states);
		}
	}

}

Control * TreeNode::clone() const
{
	return new TreeNode(*this);
}
Control * TreeNode::handleEvent(sf::Event event, sf::Vector2f mousePos)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		return onClick(mousePos);
	}
	return nullptr;
}
TreeNode * TreeNode::onClick(sf::Vector2f mouse)
{
	if (Control::contains(mouse))
		return this;

	if (getGlobalBounds().contains(mouse) && isNodeExpanded())
	{
		for (auto & node : childNode)
		{
			TreeNode * ptr = node->onClick(mouse);
			if (ptr)
				return ptr;
		}
	}
	return nullptr;
}

std::string TreeNode::getName() const
{
	return name;
}
void TreeNode::setName(const std::string & address)
{
	name = address;
}
