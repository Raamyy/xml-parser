#pragma once
#include "ParentNode.h"
class XMLData
{
	Node* root;
public:
	XMLData();
	XMLData(Node *);
	void print();
	~XMLData();
};

