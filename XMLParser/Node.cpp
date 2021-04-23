#include "Node.h"



void Node::printTabs()
{
	for (int i = 0; i < level; i++)
		cout << '\t';
}

string Node::getTabs()
{
	string tabs = "";
	for (int i = 0; i < level; i++)
		tabs += "\t";
	return tabs;
}

Node::Node()
{
}

Node::Node(string text, int level)
{
	this->text = text;
	this->level = level;
}

void Node::print()
{
	cout << toString();
}


Node::~Node()
{
}
