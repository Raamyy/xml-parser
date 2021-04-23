#include "XMLParser.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <algorithm>
#include "Helpers.h"
#include "TextNode.h"
#include "ParentNode.h"
using namespace std;

pair<vector<Node*>, vector<Token>::iterator> XMLParser::GetChildren(vector<Token>::iterator open_token_it, int level)
{
	vector<Node*> children;
	auto closeTag_it = GetClosingTag(open_token_it);
	for (auto it = open_token_it + 1; it < closeTag_it;) {
		auto parseResult = parseNode(it, level);
		children.push_back(parseResult.first);
		it = parseResult.second;
	}
	return make_pair(children, closeTag_it);
}

vector<Token>::iterator XMLParser::GetClosingTag(vector<Token>::iterator open_token_it)
{
	string name = open_token_it->text;
	auto it = open_token_it;
	for (; it != OrderedTokens.end(); it++) {
		if (it->text == name && it->type == TokenType::CloseTag) return it;
	}
	throw "closing tag not found for " + open_token_it->text;
}


void XMLParser::initOrderedTokens(string xmlFileText)
{
	const std::regex re_openTags(R"!!(<([\w+]*)>)!!", std::regex::icase);
	const std::regex re_closedTags(R"!!(</([\w+]*)>)!!", std::regex::icase);
	const std::regex re_text(R"!!([>]([^<>]+)[<])!!", std::regex::icase);

	vector<Token> Tokens;

	add_tokens(re_openTags, xmlFileText, Tokens, TokenType::OpenTag);
	add_tokens(re_closedTags, xmlFileText, Tokens, TokenType::CloseTag);
	add_tokens(re_text, xmlFileText, Tokens, TokenType::Text);

	sort(Tokens.begin(), Tokens.end());

	this->OrderedTokens = Tokens;
}



XMLData XMLParser::parse(vector<Token>::iterator it, int level, ParentNode& parent)
{
	auto res = parseNode(it, level);
	//res.first->print();
	return XMLData(res.first);
}

pair<Node*, vector<Token>::iterator> XMLParser::parseNode(vector<Token>::iterator it, int level)
{
	Node * myNode = nullptr;
	vector<Token>::iterator newStart;
	if (it->type == TokenType::OpenTag) {
		auto children = GetChildren(it, level + 1);
		myNode = new ParentNode(it->text, level, children.first);
		newStart = children.second + 1;
	}
	else if (it->type == TokenType::Text) {
		myNode = new TextNode(it->text, level);
		newStart = it + 1;
	}
	else if (it->type == TokenType::CloseTag) {
		throw "Can't parse closing tag!";
	}
	return make_pair(myNode, newStart);
}

void XMLParser::add_tokens(const std::regex reg, string& text, vector<Token>& tokens, TokenType type) {
	std::regex_token_iterator<std::string::iterator> a(text.begin(), text.end(), reg);
	std::regex_token_iterator<std::string::iterator> rend;
	while (a != rend) {
		string myText = (*a).str();
		if (type == TokenType::Text) {
			myText = myText.substr(1, myText.size() - 2);
			tokens.push_back(Token(myText, type, std::distance(text.begin(), (a->first) + 1)));
		}
		else if (type == TokenType::OpenTag) {
			myText = myText.substr(1, myText.size() - 2);
			tokens.push_back(Token(myText, type, std::distance(text.begin(), a->first) + 1));
		}
		else if (type == TokenType::CloseTag) {
			myText = myText.substr(2, myText.size() - 3);
			tokens.push_back(Token(myText, type, std::distance(text.begin(), a->first + 2)));
		}
		a++;
	}
}

XMLData XMLParser::getData()
{
	return parse(OrderedTokens.begin(), 0, root);
}

XMLParser::XMLParser(string filePath)
{
	ifstream XMLfile(filePath);
	if (XMLfile.is_open())
	{
		string line;
		string fileData = "";
		while (getline(XMLfile, line))
		{
			trim(line);
			fileData += line;
		}
		initOrderedTokens(fileData);
		XMLfile.close();
	}

	else cout << "Unable to open file";
}
