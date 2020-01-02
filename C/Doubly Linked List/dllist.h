#ifndef _DLLIST_H
#define _DLLIST_H

typedef struct Node {

        void *data; //Generic Data Type Pointer
        struct Node* next; //pointer to next
        struct Node* prev; //pointer to previous

} Node;


typedef struct List {

        Node *head; //first element
        Node *tail; //last element
        int dat_size; //size of input data
        int num_items; //number of items in list

} List;

//Function Headers

List *initList(int indata_size); //initialize linked list
int lladd (List *llist, void *new_data); //Adding node to beginning of LinkedList
int lladdE (List *llist, void *new_data);  //Add to end of List List
int lladdA (List *llist, void *data, void *new_data); //Add after Data

int lldelete (List *llist, void *data); //Delete Data

int llprint (List *llist); //print linked list

int llreverse(List *llist); //reverse list

int destorylist (List *llist); //destoryList


#endif /* _LLIST_H */
