#pragma once
#include<string>
#include<iostream>
using namespace std;
class Node
{
protected:
	string text;
	int level;
	void printTabs();
public:
	Node();
	Node(string text, int level);
	virtual void print() = 0;
	~Node();
};

