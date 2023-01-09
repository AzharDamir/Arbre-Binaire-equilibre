#include "BalancedBinaryTree.h"

BalancedBinaryTree::BalancedBinaryTree()
{
    root = NULL;
   
}
Node* BalancedBinaryTree::balanceBST(int s, int e) {
    if (s > e)
        return NULL;
    int middle = s + (e - s) / 2;
    set<int>::iterator it = v.begin();
    Node* root = new Node(*it);
    v.erase(it);
    root->right = balanceBST(middle + 1, e);
    root->left = balanceBST(s, middle - 1);
    return root;
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

