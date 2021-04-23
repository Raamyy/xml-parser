#pragma once
#include<string>
using namespace std;

enum TokenType {
	OpenTag, CloseTag, Text
};

class Token
{
public:
	string text;
	TokenType type;
	int startIndex;
	Token();
	Token(string text,TokenType type, int startIndex);
	bool operator < (const Token& otherToken) const;
	~Token();
};
