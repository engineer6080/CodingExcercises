#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <vector>
#include <iomanip>



class BinarySearchTree {

//**************************************************************
class TreeNode {

friend class BinarySearchTree;

int data;
TreeNode *leftChild;
TreeNode *rightChild;
public:
TreeNode(const int &data) : data(data), leftChild(NULL), rightChild(NULL){
}
~TreeNode();

TreeNode* find(const int &data){
        if(this->data == data) {
                return this;
        }
        if(data < this->data && leftChild != NULL) {
                return leftChild->find(data);
        }
        if(rightChild != NULL) {
                return rightChild->find(data);
        }

        return NULL;
}

TreeNode* insert(const int &data){
        if(data >= this->data) {
                if(this->rightChild == NULL) {
                        this->rightChild = new TreeNode(data);
                }
                else{
                        (this->rightChild)->insert(data);
                }
        }
        else{
                if(this->leftChild == NULL) {
                        this->leftChild = new TreeNode(data);
                }
                else{
                        (this->leftChild)->insert(data);
                }
        }
}


//Recursive Print function
void print(TreeNode *root, int space)
{
        int COUNT = 10;
        // Base case
        if (root == NULL)
                return;

        // Increase distance between levels
        space += COUNT;

        // Process right child first
        print(root->rightChild, space);

        // Print current node after space
        // count
        printf("\n");
        for (int i = COUNT; i < space; i++)
                printf(" ");
        printf("%d\n", root->data);

        // Process left child
        print(root->leftChild, space);
}

/*
   Recursive Post Order Traversal Print
   LRN
 */
void postorder(TreeNode *p){

        if (p == NULL) return;
        inorder(p->leftChild);
        inorder(p->rightChild);
        std::cout << p->data << std::endl;
}

/*
   Recursive Pre Order Traversal Print
   NLR
 */
void preorder(TreeNode *p){

        if (p == NULL) return;
        std::cout << p->data << std::endl;
        inorder(p->leftChild);
        inorder(p->rightChild);

}

/*
   Recursive In Order Traversal
   LNR
 */
void inorder(TreeNode *p){

        if (p == NULL) return;
        inorder(p->leftChild);
        std::cout << p->data << std::endl;
        inorder(p->rightChild);

}

//Checking using in order traversal LNR
bool checkBST(){
        static TreeNode *prev;

        if(this) {
                if(!this->leftChild->checkBST()) return false;
                if(prev!=NULL && this->data <= prev->data) return false;
                prev = this;

                return this->rightChild->checkBST();
        }

        return true;

}

//Recursive Get Max Height of Tree
int getHeight(){
        if(this==NULL) return -1;
        return std::max(this->leftChild->getHeight(),this->rightChild->getHeight())+1;
}



};
//**************************************************************

private:
TreeNode *root;
size_t _count;

public:
BinarySearchTree() : _count(0), root(NULL){
}
int find(const int &data);
void insert(const int &data);
void print(int i);
bool checkBST();
int getHeight();
int getCount();

};


//Checking using in order traversal LNR
bool BinarySearchTree::checkBST(){
        return root->checkBST();
}

int BinarySearchTree::getCount(){
        return _count;
}

int BinarySearchTree::getHeight(){
        return root->getHeight();
}

int BinarySearchTree::find(const int &data){
        TreeNode *temp = root;
        if(root != NULL) {
                temp = root->find(data);
                return temp->data;
        }
        return -1;
}

void BinarySearchTree::insert(const int &data){

        //Check if empty Tree
        if(root == NULL) {
                root = new TreeNode(data);
        }
        else{
                root->insert(data);
        }

        _count++;

}

void BinarySearchTree::print(int i=0){
        if(!root) return;
        //root->postorder(root);
        switch (i) {
        case 0:
                root->print(root,0);
                break;
        case 1:
                std::cout << "In Order Traversal: " << std::endl;
                root->inorder(root);
                break;
        case 2:
                std::cout << "Post Order Traversal: " << std::endl;
                root->postorder(root);
                break;
        case 3:
                std::cout << "Pre Order Traversal: " << std::endl;
                root->preorder(root);
                break;
        }


}


#endif
