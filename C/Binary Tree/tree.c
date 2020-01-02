#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "tree.h"

/*

   Binary Tree Implementation using Linked List
   Vikram Sriram

   Properties:
   level i number of nodes = 2^i
   max number of nodes height h= (2^h) -1
   min height with n nodes= log base 2(n+1) (ceiling)

 # of edges = number of nodes - 1

   n0 = number of nodes with no child
   n2 = number of nodes with 2 children
   n0 = n2+1


 */


//1 byte
#define Byte uint8_t

//Global data size input
int indata_size = 4;

int front = -1, rear = -1; //variables to keep track of front and rear

/*
   recursive preorder traversal
   starts at root node
 */
int preorder (struct node *p){
        if(p==NULL)
                return -1;

        printx(p->Data);
        preorder(p->lchild);
        preorder(p->rchild);

        return 0;
}

/*
   recursive inorder traversal
 */
int inorder(struct node *p){
        if(p==NULL)
                return -1;

        inorder(p->lchild);
        printx(p->Data);
        inorder(p->rchild);

        return 0;
}

//generic print function
void printx(void * data){
        printf("%d\n", *(int *)data);
}

/*
   recursive postorder traversal
   root of tree
 */
int postorder(struct node *p){

        if(p == NULL)
                return -1;

        postorder(p->lchild);
        postorder(p->rchild);
        printx(p->Data);

        return 0;
}

/*
   recursively find height of tree
   called with root
 */

int height(struct node *p){
        int hL, hR;

        if(p==NULL)
                return -1;

        hL = height(p->lchild);
        hR = height(p->rchild);

        if(hL > hR)
                return 1+hL;
        else
                return 1+hR;
}

/*
   Allocates node
 */

struct node *getnode(void *data){

        struct node *new_node = (struct node *) malloc(sizeof(struct node));
        new_node->Data = malloc(sizeof(Byte)*indata_size); //Allocate 4 byte inputs
        memcpy(new_node->Data, data, indata_size);  //copy 4 bytes

        new_node->lchild = new_node->rchild = NULL;

        return new_node;
}

/*
   Insert into Queue (array implementation)
 */
void insertQ(struct node *item){
        if(rear==100-1)
        {
                printf("Overflow\n");
                return;
        }
        if(front == -1) /*Queue initially empty */
                front=0;
        rear+=1;
        queue[rear]=item;
}
/*
   Delete from Queue and return
 */
struct node *deleteQ(){
        struct node *item;
        if(front == -1 || front == rear+1)
        {
                printf("Queue Underflow\n");
                return 0;
        }
        item = queue[front];
        front+=1;
        return item;

}

/* Check if Queue is empty */

int qEmpty(){

        if(front == -1 || front == rear + 1)
                return 1;
        else
                return 0;
}

/* Display Tree recursively */

void displaytree(struct node *p, int level){
        int i;
        if(p==NULL)
                return;

        displaytree(p->rchild, level + 1);
        printf("\n");

        for(i=0; i<level; i++)
                printf("   ");
        printx(p->Data);

        displaytree(p->lchild, level+1);
}
