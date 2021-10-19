// Name: Alisha Agrawal
// ID: aa3se
// Date: 03/25/2021
// AVLTree.cpp

#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
  root = insert(root, x);
}

// helper for insert to allow recursion over different nodes
AVLNode*  AVLTree::insert(AVLNode* n, const string& x) {
  AVLNode* newNode = new AVLNode();
  newNode->value = x;
  // insert like BST
  if(n==NULL){
    return(newNode);
  }
  if(x < n->value) {
    n->left = insert(n->left, x);
  }
  else if (x > n->value) {
    n->right = insert(n->right, x);

  }
  else {
    return n;
  }

  // update height (since we inserted a new node)
  // height has to be the biggest of the two subtrees
  n->height = 1 + max(height(n->left), height(n->right));
  
  // balance node if necessary
  balance(n);

  return n;
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
  return pathTo(root, x);
}

// helper for pathTo to allow recursion over different nodes
string AVLTree::pathTo(AVLNode* n, const string& x) const {
  string path = "";
  path += n->value; 

  if(find(x) == true){
    if(x < n->value) {
      path += " " + pathTo(n->left, x);
    }
    if(x > n->value) {
      path += " " + pathTo(n->right, x);
    }
    return path;
  }
  else {
    return ""; 

  }
  
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
  return find(root, x); 
}

// helper for find to allow recursion over different nodes
bool AVLTree::find(AVLNode* n, const string& x) const {
  // exact same as BST
  
  if(n == NULL){
    return false;
  }
  if(x == n->value) {
    return true;
  }
  if(x > n->value && n->right != NULL) {
    return find(n->right, x);
  }
  if(x < n->value && n->left != NULL) {
    return find(n->left, x);
  }
  
  return false; 
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
  return numNodes(root);
}

// helper for numNodes to allow recursion over different nodes
int AVLTree::numNodes(AVLNode* n) const {
  // exact same as BST
  
  int count = 1;
  
  if(n == NULL){
    count = 0;
  }
  
  if(n->left != NULL) {
    count += numNodes(n->left);
  }
  if(n->right != NULL) {
    count += numNodes(n->right);

  }
  return count;
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
  // get balance factor of node
  int bf = getBalance(n);

  // Right Heavy
  if (bf == 2) {
    // check for double rotation (right child balance factor is negative)
    // (R)L Rotation
    if(getBalance(n->right) < 0) {
      n->right = rotateRight(n->right);
    }
    // R(L) Rotation
    // RR Rotation
      n = rotateLeft(n);
  }
  // Left Heavy
  if (bf == -2) {
    // check for double rotation (left child balance factor is positive)
    // (L)R Rotation
    if(getBalance(n->left) > 0) {
      n->left = rotateLeft(n->left);
    }
    // L(R) Rotation
    // LL Rotation
      n = rotateRight(n);
  }
}

// HELPER: returns balance factor of node n
int AVLTree::getBalance(AVLNode* n) {
  if(n == NULL) {
    return 0;

  }
  // balance factor is assumed to be
  // height of right subtree - height of left subtree
  return height(n->right) - height(n->left);
}

  
// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
  AVLNode *top = new AVLNode(); // new "root"
  AVLNode *rootRight = new AVLNode(); 
  
  top = n->right; 
  rootRight = top->left; 
 
  top->left = n; 
  n->right = rootRight; 

  // update heights 
  n->height = 1 + max(height(n->left), height(n->right)); 
  top->height = 1 + max(height(top->left), height(top->right)); 

  return top; 
				
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
  AVLNode *top = new AVLNode(); // new "root"
  AVLNode *rootLeft = new AVLNode(); 
  
  top = n->left; 
  rootLeft = top->right; 
 
  top->right = n; 
  n->left = rootLeft;

  //update heights
  n->height = 1 + max(height(n->left), height(n->right)); 
  top->height = 1 + max(height(top->left), height(top->right)); 

  return top; 
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
