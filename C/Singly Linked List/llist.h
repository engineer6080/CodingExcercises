#ifndef _LLIST_H
#define _LLIST_H

typedef struct Node {

        void *data; //Generic Data Type Pointer
        struct Node* next; //pointer to next

} Node;


typedef struct List {

        Node *head; //first element
        Node *tail; //last element
        int dat_size; //number of items in list

} List;

//Function Headers

List *initList(int indata_size); //initialize linked list
int lladd (List *llist, void *new_data); //Adding node to beginning of LinkedList
int lladdE (List *llist, void *new_data);  //Add to end of List List
int lladdA (List *llist, void *data, void *new_data); //Add after Data
int llprint (List *llist); //print linked list


#endif /* _LLIST_H */
