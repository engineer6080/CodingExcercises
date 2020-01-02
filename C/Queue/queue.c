#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "queue.h"

/*

   Queue Implementation using Linked List
   Vikram Sriram

   Insertion done in the back
   Deletion done in the front

   [Back] [] [] [] [] [Front]

   "standing in line"


 */


//1 byte
#define Byte uint8_t

//Global data size input
int indata_size = 4;


//Initialize stack, first function to be called

void initQueue(int indata_size){
        front = NULL;
        rear = NULL;
        indata_size = indata_size;

}


/*
   Adding node to the BACK of the Queue
 */

int Enqueue (void *new_data){

        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

        new_node->data = malloc(sizeof(Byte)*indata_size); //Allocate 4 byte inputs

        memcpy(new_node->data, new_data, indata_size); //copy 4 bytes

        new_node->link = NULL;

        //No elements in the Queue
        if(front == NULL) {
                front = new_node;
        }
        else{
                rear->link = new_node; //Add to back
        }

        rear = new_node; //new rear

        return 0;
}

/*
   Print Queue
 */
int printQueue (){

        Node *itr;

        if(front == NULL) {
                return -1;
        }
        printf("Front->");

        for(itr = front; itr != NULL; itr = itr->link) {
                printf(" -%s-", (char *)itr->data); //Casting the void * as an int * then dereference it
                //getchar();

        }

        printf(" <-Back\n");

        return 0;

}

/*
   Remove from FRONT of Queue
   and return data
 */
void * Dequeue (){

        //Empty
        if(front == NULL) {
                return NULL;
        }

        Node *temp;
        void *data;

        temp = front;
        data = temp->data;
        front = front->link;
        free(temp);

        return data;

}
