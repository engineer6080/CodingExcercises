#ifndef _QUEUE_H
#define _QUEUE_H

typedef struct  Node {

        void *data; //Generic Data Type Pointer
        struct Node* link; //pointer to next

} Node;


struct Node *front, *rear; //top node

//Function Headers

void initQueue(int indata_size); //initialize stack
int Enqueue (void *new_data); //Add to top of stack
void *Dequeue ();  //Remove top of stack and return
int printQueue (); //print linked list


#endif /* _QUEUE_H */
