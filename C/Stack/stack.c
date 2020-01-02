#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "stack.h"

/*

   Stack Implementation using Linked List
   Vikram Sriram

 */


//1 byte
#define Byte uint8_t

//Global data size input
int indata_size = 4;


//Initialize stack, first function to be called

void initStack(int indata_size){
        top = NULL;
        indata_size = indata_size;

}


/*
   Adding node to the top of the stack
 */

int push (void *new_data){

        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

        new_node->data = malloc(sizeof(Byte)*indata_size); //Allocate 4 byte inputs

        memcpy(new_node->data, new_data, indata_size); //copy 4 bytes

        new_node->link = top;
        top = new_node;

        return 0;
}

/*
   Print Stack
 */
int printstack (){

        Node *itr;

        if(top == NULL) {
                return -1;
        }

        for(itr = top; itr != NULL; itr = itr->link) {
                printf("-%s-\n", (char *)itr->data); //Casting the void * as an int * then dereference it
                //getchar();

        }

        return 0;

}

/*
   Remove top of stack
 */
void * pop (){

        //Empty
        if(top == NULL) {
                return -1;
        }

        Node *temp;
        void *data;

        temp = top;
        data = temp->data;
        top = top->link;
        free(temp);

        return data;

}
