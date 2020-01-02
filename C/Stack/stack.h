#ifndef _STACK_H
#define _STACK_H

typedef struct  Node {

        void *data; //Generic Data Type Pointer
        struct Node* link; //pointer to next

} Node;


struct Node *top; //top node

//Function Headers

void initStack(int indata_size); //initialize stack
int push (void *new_data); //Add to top of stack
void *pop ();  //Remove top of stack and return
int printstack (); //print linked list


#endif /* _STACK_H */
