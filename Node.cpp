#include "Node.h"
using namespace std;
Node::Node()
{
	data = 0;
	left = NULL;
	right = NULL;
}

Node::Node(int val)
{
	data = val;
	left = NULL;
	right = NULL;
}
