#include "TextNode.h"



void TextNode::print()
{
	printTabs();
	cout << text;
	cout << endl;
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
