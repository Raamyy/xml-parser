#include "Node.h"



void Node::printTabs()
{
	for (int i = 0; i < level; i++)
		cout << '\t';
}

Node::Node()
{
}

Node::Node(string text, int level)
{
	this->text = text;
	this->level = level;
}


Node::~Node()
{
}
