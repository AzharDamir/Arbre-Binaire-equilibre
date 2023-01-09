#pragma once
#include "Node.h"
#include <vector>
#define SPACE 10
using namespace std;
class BalancedBinaryTree
{
public:
	Node* root;

	BalancedBinaryTree();
	Node* insert(Node* new_node, Node* r);
	Node* minValueNode(Node* node);
	Node* deleteNode(Node* r, int v);
	Node* recursiveSearch(Node* r, int val);
	bool isTreeEmpty();
	void print2D(Node* r, int space);
	Node* balanceBSThelp1(vector<int>& v, int s, int e);
	void balanceBSThelp2(vector<int>& v, Node* root);
	Node* balanceBST(Node* root);
};

