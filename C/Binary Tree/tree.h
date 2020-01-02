#ifndef _TREE_H
#define _TREE_H
/*
   Full Binary Tree(max#ofnodes) with height h = (2^h)-1
   height = log base 2(n+1)

   for any Node k
        Left child = 2k
        Right child = 2k+1
        Parent is floor(k/2)

   Complete Binary tree- all levels full except last one
        k = node number
        if k=1, then node is root node
        if (2k>n) no left child, otherwise leftchild = 2k
        same but (2k+1) for right child

        Visiting root node- N
        Traversing its left subtree- L
        Traversing its right subtree- R

        NLR (preorder), LNR (InOrder), LRN (PostOrder)

        Level order traversal - level by level (can be implemented with queue)

 */

typedef struct  node {

        void *Data; //Generic Data Type Pointer
        struct node *lchild; //left child
        struct node *rchild; //right child

} node;

//Function Headers

int preorder(struct node *p); //preorder traversal
int inorder(struct node *p); //inorder traversal
int postorder(struct node *p); //postorder traversal
int height(struct node *p); //find height of binary tree
void displaytree(struct node *p, int level); //print tree

void printx(void *data);//print stdout

struct node *getnode(void *data);

void levelorder(struct node *root); //traversal using Queue
struct node *queue[100]; //Array of queue nodes

void insertQ(struct node *item); /* insert into Queue */
struct node *deleteQ(); /* delete from Q and return item */

int qEmpty(); //returns if queue is empty

void display(struct node *p, int level); //display tree


#endif /* _TREE_H */
