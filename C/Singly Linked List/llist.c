#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "llist.h"

/*

   Singly Linked List for Generic Datatype
   Vikram Sriram

 */

//Linked List
//List *llist;

List *initList(int indata_size){
        List *llist;
        llist = malloc(sizeof(List));
        llist->head = NULL;
        llist->dat_size = indata_size;
        return llist;
}

//1 byte
#define Byte uint8_t


/*
   Adding node to beginning of LinkedList
   Most recently added is head
 */

int lladd (List *llist, void *new_data){

        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

        //Checking if head exists
        if(llist->head == NULL) {
                llist->head = new_node;
                llist->head->data = malloc(sizeof(Byte)*llist->dat_size); //Allocate 4 byte inputs
                memcpy(new_node->data, new_data, llist->dat_size); //copy 4 bytes
                llist->head->next = NULL; //first element
                return 0;
        }

        //void *temp = llist->head; //Save pointer to old head

        new_node->data = malloc(sizeof(Byte)*llist->dat_size); //Allocate 4 byte inputs

        memcpy(new_node->data, new_data, llist->dat_size); //copy 4 bytes

        new_node->next = llist->head;

        llist->head = new_node; //set new Head Node

        return 0;
}

/*
   Print List and then destory it
 */
int llprint (List *llist){

        Node *itr;

        for(itr = llist->head; itr != NULL; itr = itr->next) {
                printf("-%d-\n", *(int *)itr->data); //Casting the void * as an int * then dereference it
                free(itr->data);
                //getchar();

        }

        free(llist);

        return 0;

}

/*
   Adding node to end of list
 */
int lladdE (List *llist, void *new_data){

        Node *itr;

        //Iterate through to find node
        itr = llist->head;

        while(itr->next != NULL) {

                itr = itr->next; //iterate to the last node
        }

        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

        new_node->data = malloc(sizeof(Byte)*llist->dat_size); //Allocate 4 byte inputs

        memcpy(new_node->data, new_data, llist->dat_size); //copy 4 bytes

        //Assign current new next
        itr->next = new_node;

        //New last element
        new_node->next = NULL;

        return 0;

}

/*
   Insert after specified node
   Assuming the node exists in linkedlist

 */
int lladdA (List *llist, void *data, void *new_data){

        Node *itr;

        //Iterate through to find node
        itr = llist->head;

        while(*(int *)itr->data != *(int *)data) {

                if(itr->next) {
                        itr = itr->next;
                }
                else{   //Err Not in List
                        printf("Item not in List\n");
                        return -1;
                }
        }

        //[itr][A] Make New Node
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

        new_node->data = malloc(sizeof(Byte)*llist->dat_size); //Allocate 4 byte inputs

        memcpy(new_node->data, new_data, llist->dat_size); //copy 4 bytes

        //new node's next is current's next
        new_node->next = itr->next;

        //update current one to point to new node
        itr->next = new_node;

        return 0;
}
