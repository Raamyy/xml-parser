#pragma once
#include "Node.h"
class TextNode :
	public Node
{
public:
	void print();
	TextNode();
	TextNode(string text, int level);
	~TextNode();
};

