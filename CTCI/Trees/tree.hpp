#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>

//Generic Tree

class Tree {

private:
struct Node {
        int data;
        Node *left;
        Node *right;
};

Node *root;
size_t count;

public:

Tree();
~Tree();
void insert(const int &data);

};

Tree::Tree() : root(NULL){
        std::cout << "Sup" << '\n';
        root->left = NULL;
        root->right = NULL;
}

Tree::~Tree(){

}

void Tree::insert(const int &data){
        if(!root) {
                root = new Node;
                root->data = data;
        }
        else{

        }
}

#endif
