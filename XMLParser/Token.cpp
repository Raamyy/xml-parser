#include "Token.h"

Token::Token()
{
}

Token::Token(string text, TokenType type, int startIndex)
{
	this->text = text;
	this->type = type;
	this->startIndex = startIndex;
}

bool Token::operator<(const Token & otherToken) const
{
	return this->startIndex < otherToken.startIndex;
}

Token::~Token()
{
}
