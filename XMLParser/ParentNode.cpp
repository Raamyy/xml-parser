#include "ParentNode.h"



void ParentNode::print()
{
	printTabs();
	cout << "<" + text + ">"<<endl;
	for (auto child : children)
		child->print();
	printTabs();
	cout << "</" + text + ">" << endl;
}

void ParentNode::addChild(Node* node)
{
	children.push_back(node);
}

ParentNode::ParentNode()
{
}

ParentNode::ParentNode(string text, int level, vector<Node *>children): Node(text,level)
{
	this->children = children;
}


ParentNode::~ParentNode()
{
}
