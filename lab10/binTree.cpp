#include<iostream>

struct treeNode {
  int val;
  treeNode *left;
  treeNode *right;
};

void initialize(treeNode *t, int n) {
  t->val = n;
  t->left = t->right = 0;
}

void insert(treeNode *t, int n) {
  std::cerr << "insert t " << t->val << " n " << n << std::endl;
  treeNode **child;
  if (n <= t->val) child = &(t->left);
  else child = &(t->right);
  if (0 == *child) {  // create new node and store value
    *child = new treeNode;
    initialize(*child, n);
  } else { // recurse on the correct branch
    insert(*child, n);
  }
}

void remove(treeNode *t) {
  std::cerr << "remove t " << t->val << std::endl;
  if (t->left) remove(t->left);  // get rid of left subtree
  if (t->right) remove(t->right); // get rid of right subtree
  delete t;
}

void preorderPrint( treeNode *t ) {
  // Print all the items in the tree to which t points.
  // The item in the root is printed first, followed by the
  // items in the left subtree and then the items in the
  // right subtree.
  if (t != NULL) { // (Otherwise, there's nothing to print.)
     std::cerr << t->val << " ";   // Print the root item.
     preorderPrint(t->left);  // Print items in left subtree.
     preorderPrint(t->right); // Print items in right subtree.
  }
}

void postorderPrint( treeNode *t ) {
  // Print all the items in the tree to which t points.
  // The items in the left subtree are printed first, followed 
  // by the items in the right subtree and then the item in the
  // root node.
  if (t != NULL) {  // (Otherwise, there's nothing to print.)
    postorderPrint(t->left);   // Print items in left subtree.
    postorderPrint(t->right);  // Print items in right subtree.
    std::cerr << t->val << " ";     // Print the root item.
  }
}

void inorderPrint( treeNode *t ) {
  // Print all the items in the tree to which t points.
  // The items in the left subtree are printed first, followed 
  // by the item in the root node, followed by the items in
  // the right subtree.
  if (t != NULL ) {  // (Otherwise, there's nothing to print.)
    inorderPrint(t->left);   // Print items in left subtree.
    std::cerr << t->val << " ";    // Print the root item.
    inorderPrint(t->right);  // Print items in right subtree.
  }
}

// treeContains
// Arguments:
//   t      a treeNode pointer
//   item   the int you are looking for in the tree
// Return:  A bool value, true if item is included in the tree, false otherwise.
bool treeContains(treeNode *t, int item) {
  if(t != NULL) {
    if(t->val == item) { return true; }
    if(treeContains(t->left, item)) { return true; }
    if(treeContains(t->right, item)) { return true; }
  }
  return false;
}

// isBST
// Arguments:
//   t      a treeNode pointer
//   min    an int representing the min value seen so far
//   max    an int representing the max value seen so far
// Return:  A bool value, true if the tree is a valid Binary Search Tree, false otherwise.
bool isBST(treeNode *t, int max, int min) {
  
}


int main() {
  treeNode *root = new treeNode;
  initialize(root, 5);
  insert(root, 3);
  insert(root, 4);
  preorderPrint(root);
  insert(root, 0);
  insert(root, 8);
  insert(root, 10);
  insert(root, 100);
  insert(root, 9);
  insert(root, 5);
  preorderPrint(root);
  std::cerr << std::endl;
  postorderPrint(root);
  std::cerr << std::endl;
  inorderPrint(root);
  std::cerr << std::endl;
  std::cerr << treeContains(root, 5) << std::endl;
  remove(root);
}
