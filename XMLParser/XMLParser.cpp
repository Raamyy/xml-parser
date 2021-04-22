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

void XMLParser::PrintNodes(vector<string>::iterator start, vector<string>::iterator end, int level)
{
		for (auto it = start; it < end; ) {
			it = PrintNode(it,level);
		}
}

vector<string>::iterator XMLParser::PrintNode(vector<string>::iterator& node, int level)
{
	if (IsOpenTag(*node)) {
		PrintWithTabs(*node, level);
		auto children = GetChildren(node);
		PrintNodes(children.first,children.second, level + 1);
		PrintWithTabs("</"+GetOpenTagName(*node)+">", level);
		return children.second+1;
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

pair<vector<string>::iterator, vector<string>::iterator> XMLParser::GetChildren(vector<string>::iterator& node)
{
	string openName = GetOpenTagName(*node);
	auto closingTagit = find(node, XMLLines.end(), "</" + openName + ">");
	return make_pair(node+1,closingTagit);
}


XMLData XMLParser::LoadFile(string filePath)
{
	/*ifstream XMLfile(filePath);
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

	else cout << "Unable to open file";*/

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


		PrintNodes(XMLLines.begin(),XMLLines.end(), 0);

		XMLfile.close();
	}

	else cout << "Unable to open file";
}
