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
	string getTabs();
public:
	Node();
	Node(string text, int level);
	void print() ;
	virtual string toString() = 0;
	~Node();
};

