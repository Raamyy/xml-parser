#pragma once

#include <vector>
#include <string>
#include <regex>
#include "XMLData.h"
#include "Token.h"
using namespace std;

class XMLParser
{
	ParentNode root;
	vector<Token> OrderedTokens;
	vector<Token>::iterator GetClosingTag(vector<Token>::iterator open_token_it);
	pair<vector<Node*>, vector<Token>::iterator> GetChildren(vector<Token>::iterator open_token_it, int level);
	pair<Node*, vector<Token>::iterator> parseNode(vector<Token>::iterator it, int level);
	XMLData parse(vector<Token>::iterator it, int level, ParentNode & parent);
	void initOrderedTokens(string xmlFileText);
	void add_tokens(const std::regex reg, string& text, vector<Token>& tokens, TokenType type);
	string toString(XMLData data);
public:
	XMLParser(string filePath);
	XMLData getData();
	void saveData(string fileName);
};

