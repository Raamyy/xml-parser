#include "TextNode.h"

string TextNode::toString()
{
	return getTabs() + text + "\n";
}

TextNode::TextNode()
{
}

TextNode::TextNode(string text, int level): Node(text, level)
{
}


TextNode::~TextNode()
{
}
