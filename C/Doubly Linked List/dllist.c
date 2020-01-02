#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "dllist.h"

/*

   Doubly Linked List for Generic Datatype

   Vikram Sriram

 */

List *initList(int indata_size){
        List *llist;
        llist = malloc(sizeof(List));
        llist->head = NULL;
        llist->tail = NULL;
        llist->dat_size = indata_size;
        llist->num_items = 0;
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
        //List is empty
        if(llist->head == NULL) {
                llist->head = new_node;
                llist->tail = new_node;
                llist->head->data = malloc(sizeof(Byte)*llist->dat_size); //Allocate 4 byte inputs
                memcpy(new_node->data, new_data, llist->dat_size); //copy 4 bytes
                llist->head->next = NULL; //first element
                llist->head->prev = NULL;
                llist->num_items++;
                return 0;
        }

        //void *temp = llist->head; //Save pointer to old head

        new_node->data = malloc(sizeof(Byte)*llist->dat_size); //Allocate 4 byte inputs

        memcpy(new_node->data, new_data, llist->dat_size); //copy 4 bytes

        new_node->next = llist->head; // [N] -> [O]

        new_node->prev = NULL; // Head doesn't have prev

        llist->head->prev = new_node; // [N]<- [O]

        llist->head = new_node; //set new Head Node

        llist->num_items++;

        return 0;
}

/*
   Print List
   Weird Bug with destroy
 */

int llprint (List *llist){

        Node *itr;

        printf("There are %d items in the list\n", llist->num_items);

        if(llist->num_items == 0) {
                return -1;
        } //empty list

        for(itr = llist->head; itr != NULL; itr = itr->next) {
                printf("-%d-\n", *(int *)itr->data); //Casting the void * as an int * then dereference it
                //getchar();

        }

        printf("Head is %d, Tail is %d\n", *(int *)llist->head->data,*(int *)llist->tail->data);

        return 0;

}


/*
        Reverse the linkedlist

 */

int llreverse (List *llist){

        Node *itr;

        for(itr = llist->tail; itr != NULL; itr = itr->prev) {
                printf("-%d-\n", *(int *)itr->data); //Casting the void * as an int * then dereference it

        }

        return 0;


}

/*
   Destroy List
 */

int destorylist (List *llist){

        Node *itr;

        for(itr = llist->head; itr != NULL; itr = itr->next) {
                free(itr->data); //Free the data
                //free(itr); //Free the node
                llist->num_items--;
        }

        llist->head = NULL;
        llist->tail = NULL;

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

        itr->next = new_node; // [O] -> [N]

        new_node->prev = itr; // [O]  <- [N]

        new_node->next = NULL; //New last element

        llist->tail = new_node;

        llist->num_items++;

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

        //In between two elements
        if(itr->next) { //[] [insert here] []

                //[itr][A] Make New Node
                struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

                new_node->data = malloc(sizeof(Byte)*llist->dat_size); //Allocate 4 byte inputs

                memcpy(new_node->data, new_data, llist->dat_size); //copy 4 bytes

                //we are trying to add after itr
                //[N] ->[ ]

                //new node's next is current's next
                new_node->next = itr->next; // [] []->[]

                //new node in center
                new_node->prev = itr;  // []<-[] []

                (itr->next)->prev = new_node; // [] []<-[]

                //update current one to point to new node
                itr->next = new_node; // []-> [] []

                llist->num_items++;

        }
        //It is the last element
        else{ // [] -> NULL

                //Add to end of list
                lladdE(llist,new_data);

        }


        return 0;
}

/*
        Delete element from Linked list
 */

int lldelete (List *llist, void *data){

        Node *itr;

        //Iterate through to find node
        itr = llist->head;

        while(*(int *)itr->data != *(int *)data) {

                if(itr->next) {
                        itr = itr->next;
                }
                else{ //Err Not in List
                        printf("Item not in List\n");
                        return -1;
                }
        }

        //Could be in the middle, could be head, or the last element

        //Single element. We are deleting the head
        if(llist->num_items == 1) {
                free(llist->head->data);
                llist->num_items--;

        }
        else if(llist->num_items > 1) {

                if(itr->prev == NULL) { //Head Element
                        (itr->next)->prev = NULL; //[NULL] <-[new head]
                        llist->head = itr->next;
                        free(itr->data);
                        llist->num_items--;
                }
                else if(itr->next == NULL) { //Tail

                        (itr->prev)->next = NULL; //[new tail]->[NULL]
                        llist->tail = itr->prev;
                        free(itr->data);
                        llist->num_items--;

                }
                else {  //In the Middle. next and prev not NULL
                        (itr->prev)->next = itr->next; // [] [itr] []
                        (itr->next)->prev = itr->prev;
                        free(itr->data);
                        llist->num_items--;

                }

        }


        return 0;


}
