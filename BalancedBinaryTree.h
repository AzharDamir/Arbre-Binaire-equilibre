#pragma once
#include "Node.h"
#include <set>
#include <vector>
#define SPACE 10
using namespace std;
class BalancedBinaryTree
{
public:
	Node* root;
	set<int> v;
	BalancedBinaryTree();
	Node* minValueNode(Node* node);
	Node* deleteNode(Node* r, int v);
	Node* recursiveSearch(Node* r, int val);
	bool isTreeEmpty();
	void print2D(Node* r, int space);
	Node* balanceBST( int s, int e);
};

