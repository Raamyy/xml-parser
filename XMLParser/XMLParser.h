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
	void PrintNodes(vector<string>::iterator start, vector<string>::iterator end, int level);
	vector<string>::iterator PrintNode(vector<string>::iterator& node, int level);
	void PrintWithTabs(string text, int level);
	pair<vector<string>::iterator, vector<string>::iterator> GetChildren(vector<string>::iterator& node);

	vector<string> XMLLines;

public:
	XMLData LoadFile(string filePath);
	XMLParser(string filePath);
};

