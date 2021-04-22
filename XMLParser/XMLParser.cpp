#include "XMLParser.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <algorithm>
#include "Helpers.h"
using namespace std;

string XMLParser::GetOpenTagName(const string line)
{
	regex re("<(\\w+)>");
	smatch match;
	if (regex_search(line.begin(), line.end(), match, re)) {
		return match[1];
	}
	return "";
}

bool XMLParser::IsOpenTag(const string line)
{
	regex re("<(\\w+)>");
	smatch match;
	if (regex_search(line.begin(), line.end(), match, re)) {
		return match[1] != "";
	}
	return false;
}

bool XMLParser::IsCloseTag(const string line)
{
	regex re("</(\\w+)>");
	smatch match;
	if (regex_search(line.begin(), line.end(), match, re)) {
		return match[1] != "";
	}
	return false;
}

void XMLParser::PrintNodes(vector<string>& nodes, int level)
{
		for (auto it = nodes.begin(); it != nodes.end(); ) {
			it = PrintNode(it,level);
		}
}

vector<string>::iterator XMLParser::PrintNode(vector<string>::iterator& node, int level)
{
	if (IsOpenTag(*node)) {
		PrintWithTabs(*node, level);
		auto children = GetChildren(node);
		PrintNodes(children, level + 1);
		PrintWithTabs(*node, level);
		PrintWithTabs("</"+GetOpenTagName(*node)+">", level);
		return children.end();
	}
	else{
		PrintWithTabs(*node, level);
		return node + 1;
	}
}

void XMLParser::PrintWithTabs(string text, int level)
{
	for (int i = 0; i < level; i++)
		cout << "\t";
	cout << text << endl;
}

vector<string> XMLParser::GetChildren(vector<string>::iterator& node)
{
	string openName = GetOpenTagName(*node);
	auto closingTagit = find(node, XMLLines.end(), "</" + openName + ">");
	vector<string> children(node + 1, closingTagit);
	return children;
}


XMLData XMLParser::LoadFile(string filePath)
{
	ifstream XMLfile(filePath);
	vector<string> XMLLines;
	if (XMLfile.is_open())
	{
		string line;
		while (getline(XMLfile, line))
		{
			trim(line);
			XMLLines.push_back(line);
		}
		PrintNodes(XMLLines, 0);

		XMLfile.close();
	}

	else cout << "Unable to open file";

	return XMLData();
}

XMLParser::XMLParser(string filePath)
{
	ifstream XMLfile(filePath);
	if (XMLfile.is_open())
	{
		string line;
		while (getline(XMLfile, line))
		{
			trim(line);
			XMLLines.push_back(line);
		}


		PrintNodes(XMLLines, 0);

		XMLfile.close();
	}

	else cout << "Unable to open file";
}
