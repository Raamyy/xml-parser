#include "ParentNode.h"



string ParentNode::toString()
{
	string ret;
	ret += getTabs();
	ret += "<" + text + ">"+'\n';
	for (auto child : children)
		ret += child->toString();
	ret += getTabs();
	ret +="</" + text + ">" + '\n';
	return ret;
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
