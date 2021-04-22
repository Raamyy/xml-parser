#pragma once

#include "XMLData.h"
#include <vector>
#include <string>
using namespace std;

class XMLParser
{
	string GetOpenTagName(string line);
	bool IsOpenTag(string line);
	bool IsCloseTag(string line);
	void PrintNodes(vector<string> nodes, int level);
	void PrintNode(vector<string>::iterator node, int level);
	void PrintWithTabs(string text, int level);
	vector<string> GetChildren(vector<string>::iterator node);

	vector<string> XMLLines;

public:
	XMLData LoadFile(string filePath);
	XMLParser(string filePath);
};

