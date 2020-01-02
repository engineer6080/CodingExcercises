#ifndef _BTREE_H
#define _BTREE_H
#include <iostream>
/*
   m= maximum # of children for internal nodes


 */

class BTreeNode {
private:
  int *keys; // array of keys
  int t;     // minimum degree (defines range for number of keys)

  BTreeNode **C; // An array of child pointers
  int n;         // current number of keys
  bool leaf;     // boolean to check if it is leaf;

public:
  BTreeNode(int _t, bool _leaf); // Constructor

  // A utility function to insert a new key in the subtree rooted with
  // this node. The assumption is, the node must be non-full when this
  // function is called
  void insertNonFull(int k);

  // A utility function to split the child y of this node. i is index of y in
  // child array C[].  The Child y must be full when this function is called
  void splitChild(int i, BTreeNode *y);

  // Fuction to traverse all nodes in subtree with node
  void traverse();

  // function to search a key in the subtree roooted with node
  BTreeNode *search(int k); // returns NULL if k is not present

  // Make the BTree friend of this so that we can access private members of this
  // class in BTree functions
  friend class BTree;
};

class BTree {
  BTreeNode *root; // pointer to root node
  int t;           // mimimum degree
public:
  BTree(int _t) {
    root = NULL;
    t = _t;
  }
  // function to traverse the tree
  void traverse() {
    if (root != NULL)
      root->traverse();
  }

  // function to search a key in this tree
  BTreeNode *search(int k) { return (root == NULL) ? NULL : root->search(k); }

  // The main function that inserts a new key in this B-Tree
  void insert(int k);
};

#endif /* _TREE_H */
