#include "BalancedBinaryTree.h"

BalancedBinaryTree::BalancedBinaryTree()
{
    root = NULL;
}

Node* BalancedBinaryTree::balanceBSThelp1(vector<int>& v, int s, int e) {
    if (s > e)
        return NULL;
    int middle = s + (e - s) / 2;
    Node* root = new Node(v[middle]);
    root->right = balanceBSThelp1(v, middle + 1, e);
    root->left = balanceBSThelp1(v, s, middle - 1);
    return root;
}

void BalancedBinaryTree::balanceBSThelp2(vector<int>& v,Node* root) {
    if (!root) return;
    balanceBSThelp2(v,root->left);
    v.push_back(root->data);
    balanceBSThelp2(v, root->right);
}
Node* BalancedBinaryTree::balanceBST(Node* root) {
    vector<int> v;
    balanceBSThelp2(v, root);
    return balanceBSThelp1(v, 0, v.size() - 1);
}

Node* BalancedBinaryTree::insert(Node* new_node, Node* r)
{
    if (r == NULL) {
        r = new_node;
        cout << "Value inserted successfully" << endl;
        return r;
    }
    if (new_node->data < r->data) {
        r->left = insert( new_node, r->left);
    }
    else if (new_node->data > r->data) {
        r->right = insert( new_node, r->right);
    }
    else {
        cout << "No duplicate values allowed!" << endl;
        return r;
    }

    return balanceBST(r);
    
}

Node* BalancedBinaryTree::minValueNode(Node* node) {
    Node* current = node;
    
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* BalancedBinaryTree::deleteNode(Node* r, int v) {
    // base case 
    if (r == NULL) {
        return NULL;
    }
    else if (v < r->data) {
        r->left = deleteNode(r->left, v);
    }
    else if (v > r->data) {
        r->right = deleteNode(r->right, v);
    }
    // if key is same as root's key, then This is the node to be deleted 
    else {
        if (r->left == NULL) {
            Node* temp = r->right;
            delete r;
            return temp;
        }
        else if (r->right == NULL) {
            Node* temp = r->left;
            delete r;
            return temp;
        }
        else {
            Node* temp = minValueNode(r->right);
            r->data = temp->data;
            // Delete the inorder successor 
            r->right = deleteNode(r->right, temp->data);
            //deleteNode(r->right, temp->value); 
        }
    }
    return r;
}


bool BalancedBinaryTree::isTreeEmpty()
{
    if (root == NULL)
        return true;
    return false;
}

void BalancedBinaryTree::print2D(Node* r, int space)
{
    if (r == NULL)
        return;
    space += SPACE;
    print2D(r->right, space);
    cout << endl;
    for (int i = SPACE; i < space; i++) {
        cout << " ";
    }
    cout << r->data << "\n";
    print2D(r->left, space);
    cout << endl;
}

Node* BalancedBinaryTree::recursiveSearch(Node* r, int val) {
    if (r == NULL || r->data == val)
        return r;

    else if (val < r->data)
        return recursiveSearch(r->left, val);
    else
        return recursiveSearch(r->right, val);
}

