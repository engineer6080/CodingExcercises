#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <iostream>
#include <cstdlib> //NULL
#include <utility> //std::move
                   //
//typedef void (*void (aClass::*function)(int, int)::*func)(void); // pointer to function with no args and void return
void dbg(int i) {
        std::cout << "oH " << i << std::endl;
}                                                           // debug function


template <class T> class LinkedList {


//NESTED CLASS*******************************************
class Node {
// friend class LinkedList<T>;
template <typename> friend class LinkedList;   // Node is private

private:
//size_t _count;           // number of nodes
Node *next;
Node *prev;
T _data;
LinkedList<T> *parent; //pointer to linkedlist that owns this node

public://Experimental
Node(const T &data, LinkedList<T>*x) : _data(data), next(NULL), prev(NULL), parent(x) {
        parent->_count++;
}

~Node() {
        //--_count;
        if(parent!=NULL) parent->_count--;

}
};
//*******************************************************************

private:
// int _count; // number of nodes
Node *_head;
Node *_tail;
size_t _count;

public:
LinkedList() : _head(NULL), _tail(NULL), _count(0) {
}
~LinkedList();
LinkedList(LinkedList &L); //copy constructor
// int getSize() { return _head->_count; }
void insert(const T &data);
void insertAfter(Node *n, Node *toin);
int remove(const T &data, Node *dat=NULL);
int print(int i = 0);   // Print (default)forward(0) or reverse
int bubbleSort();
int insertionSort();
clock_t timef(int (LinkedList<T>::*function)(void));
void nSwap(Node* a, Node* b);

//CTCI FUNCTIONS
void remove_dup();
void k_to_last(int k);
void partition_list(int x);
void reverse_list();

};


// template <class T> LinkedList<T>::LinkedList() {}
//template <class T> size_t Node::_count = 0; // initalize count (when count was static)

template <class T> // can time any class function
clock_t LinkedList<T>::timef(int (LinkedList<T>::*function)(void)){

        clock_t t;
        t = clock();
        ((*this).*function)();
        t = clock() - t;
        //std::cout << avg << " " << t <<  " " << total << std::endl;
        return t;
}

template <class T> LinkedList<T>::LinkedList(LinkedList &L) {
        //copy constructor
        std::cout << "copy contructor" << std::endl;

}

template <class T> LinkedList<T>::~LinkedList() {
        Node *temp = _head;

        while (_head->next) {
                _head = std::move(_head->next); //not calling Node destructor ? ?
                //(_head->next)->~Node();
                //delete(_head->next);
                //temp = temp->next; // save pointer to next
                //delete (_head); // delete head
                //_head = temp; // set to new one
                //_count--;
        }
        delete(_head);
}

template <class T> int LinkedList<T>::print(int i) {
        // Empty List
        if (!_head) {
                std::cout << "Err: Print Empty List!" << std::endl;
                return -1;
        }

        Node *temp = (i == 0) ? _head : _tail; // print direction

        std::cout << "Printing: " << _count << " item(s) in list" << std::endl;
        while (temp) {
                std::cout << temp->_data << std::endl;
                temp = (i == 0) ? temp->next : temp->prev; // save pointer to next
        }

        return 0;
}

// Insert in beginning of linked list
template <class T> void LinkedList<T>::insert(const T &data) {
        Node *element = new Node(data, this);
        // If empty
        if (!_head) {
                _head = element;
                _tail = element;
        } else {
                //[E] [C_H] []
                element->next = _head;
                _head->prev = element;
                element->prev = NULL;
                _head = element;
        }
        // _count++;
}

template <class T> int LinkedList<T>::remove(const T &data, Node *dat) {

        //deleting first occurance of specific data

        Node *curr;

        if(dat == NULL) {
                std::cout << "Attempting delete: " << data << std::endl;
                // Node<T> *temp;
                curr = _head;

                while (curr) { // find the node with data
                        if (curr->_data == data)
                                break;
                        curr = curr->next;
                }
        }
        else{ //supplied with specific node to delete
              //First parameter doesn't matter in this case
                curr = dat;
                //std::cout << "Node delete: " << curr->_data << std::endl;


        }

        if (!curr) { // not found or empty
                delete curr;
                return -1;
        } else {
                if (_head == _tail) { // only one element
                        _head = _tail = NULL;
                } else if (curr == _head) {
                        // temp = _head->next; // save pointer to next
                        // delete _head;       // delete head
                        //_head = temp;       // set new head
                        _head = std::move(_head->next); // []   [] []
                        _head->prev = NULL;
                } else if (curr == _tail) {
                        // temp = _tail->prev;
                        //  delete _tail;
                        // _tail = temp;
                        _tail = std::move(_tail->prev);
                        _tail->next = NULL;
                } else { // in between two nodes
                        curr->prev->next = curr->next;
                        curr->next->prev = curr->prev;
                }
                delete curr; // deleting the element
                // _count--;
        }
        return 0;
}

/* Swap */
template <class T> void LinkedList<T>::nSwap(Node* a, Node* b) {
        /* Behavior of std::swap
           T tmp(std::move(a)); This one is slower..
           a = std::move(b);
           b = std::move(tmp);
         */
        T temp = a->_data;
        a->_data = b->_data;
        b->_data = temp;

}

/*O(n^2)
   Done using swaps
   needs one whole pass without any swap
   to know it is sorted.
   The last element is in right place after each iteration
   Bubble to the top...
   Implementation Credit: Geeks for Geeks
 */
template <class T> int LinkedList<T>::bubbleSort(){
        if(!_head->next) return -1; //single element
        bool swapped = false;

        Node *ptr1;
        Node *lptr = NULL;

        do
        {
                swapped = false;
                ptr1 = _head;

                while (ptr1->next != lptr)
                {
                        if (ptr1->_data > ptr1->next->_data)
                        {
                                nSwap(ptr1, ptr1->next);
                                //std::swap(ptr1->_data, ptr1->next->_data);
                                swapped = 1;
                        }
                        //this->print();
                        ptr1 = ptr1->next;
                }
                lptr = ptr1;
        }
        while (swapped);
}

/*Insert After Given Node
        DOES NOT DELETE ORIGINAL
        NEEDS OPTIMIZATION
 */
template <class T> void LinkedList<T>::insertAfter(Node *n, Node *toin){

        if(!toin || !n) return; //NULL

        Node *temp;

        //check the node we are moving after
        //std::cout << n->_data << "-" << toin->_data << std::endl;

/*
        if(n == _head) {
                Node<T> *element = new Node<T>(toin->_data);
                temp = _head->next; // [head] [toin] [temp]
                _head->next = element;
                element->next = temp;
                element->prev = _head;
                if(temp) temp->prev = element;
        }
 */
        if(n == _tail) { //adding to end of list
                Node *element = new Node(toin->_data, this);
                _tail->next = element;
                element->prev = _tail;
                _tail = element; //update tail



        }
        else{ //inbetween two nodes
                Node *element = new Node(toin->_data, this);
                temp = n->next; // [n] [toin] [temp]
                n->next = element;
                element->next = temp;
                element->prev = n;
                if(temp) temp->prev = element;

        }



}


/* O(n^2) Needs Optimization.
   Finds right place, then creates duplicate node to insert
   deletes original node
   Think: inserting a card into a hand of card
   move it to the left until you hit the correct spot

 */
template <class T> int LinkedList<T>::insertionSort(){
        if(!_head->next) return -1; //single element

        Node *curr = _head->next; //goes forward

        while(curr) {

                Node *start = curr;
                Node *back = curr->prev;
                while(back && (start->_data < back->_data)) { //go backward

                        back = back->prev;

                }
                //Insert after back
                if(back) insertAfter(back,start);
                else{//Insert before head
                        Node *element = new Node(start->_data, this);
                        element->next = _head;
                        _head->prev = element;
                        _head = element;
                }

                curr = curr->next;
                remove(1,start);
                //dbg(1);


        }

}

#endif
