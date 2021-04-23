#include "XMLData.h"

XMLData::XMLData()
{
}

XMLData::XMLData(Node * root)
{
	this->root = root;
}

void XMLData::print()
{
	root->print();
}

string XMLData::toString()
{
	return root->toString();
}

XMLData::~XMLData()
{
}
