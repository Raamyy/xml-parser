#pragma once
#include "Node.h"
#include <vector>
using namespace std;

class ParentNode :
	public Node
{
public:
	string toString();
	vector<Node*> children;
	void addChild(Node* node);
	ParentNode();
	ParentNode(string text, int level, vector<Node *>children);
	~ParentNode();
};

