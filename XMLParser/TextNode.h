#pragma once
#include "Node.h"
class TextNode :
	public Node
{
public:
	string toString();
	TextNode();
	TextNode(string text, int level);
	~TextNode();
};

