#include <iostream>
#include "BTree.h"
#include "BTreeNode.h"
#include "LeafNode.h"
#include "InternalNode.h"
using namespace std;

BTree::BTree(int ISize, int LSize) : internalSize(ISize), leafSize(LSize)
{
        root = new LeafNode(LSize, NULL, NULL, NULL);
} // BTree::BTree()

/*
 * Sean's Rules:
 * 1)  Is there room to the left?
 * 2)  Is there room to the right?
 * 3)  If not, then split
 * 4)  Is there one root?
 * 5)  If not, create one
 * 6)  Update the minimum values
 */


void BTree::insert(const int value)
{
        BTreeNode *ptr = root->insert(value);
        if(ptr) // root split
        {
                InternalNode *IPtr = new InternalNode(internalSize, leafSize, NULL, NULL, NULL);
                IPtr->insert(root, ptr);
                root = IPtr;
        } // if root split
} // BTree::insert()


void BTree::print()
{
        BTreeNode *BTreeNodePtr;
        Queue<BTreeNode*> queue(1000);

        queue.enqueue(root);
        while(!queue.isEmpty())
        {
                BTreeNodePtr = queue.dequeue();
                BTreeNodePtr->print(queue);
        } // while
} // BTree::print()


void BTree::remove(int value)
{  // To be written by students
} // BTree::remove()
