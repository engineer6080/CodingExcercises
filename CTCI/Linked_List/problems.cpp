#include <iostream>
#include <vector>
#include "ll.hpp"
#include <unordered_set>


void prnt(const char * n){

        std::cout << "Running " <<  n << std::endl;

}


/* O(n) Solution
   Remove Duplicates from Linked List
 */
template <typename T>
void LinkedList<T>::remove_dup(){

        std::cout << "Removing duplicates" << std::endl;

        std::unordered_set<int> st;
        Node *ptr = _head;

        while(ptr != NULL) {
                if(st.count(ptr->_data)) { //if in set already
                        remove(ptr->_data); //remove first occurance of that element
                }
                else{
                        st.insert(ptr->_data);
                }
                ptr = ptr->next;
        }

}
/*
   O(n) iterative solution
   Return K to the last element
   Assume: Singly Linked no Tail

   [] [] [ptr] [] [] []

   ptr2 doesn't make it all the way to the end
   it will be set back by how many ever forward ptr1 started with (k)
   so ptr2 will be k back
 */
template <typename T>
void LinkedList<T>::k_to_last(int k){
        Node *ptr = _head;
        Node *ptr2 = _head;

        for(int i=0; i < k; i++) {
                if(ptr == NULL) return; //out of bounds
                ptr = ptr->next;
        }//move ptr k elements forward

        while(ptr != NULL) {
                ptr = ptr->next;
                ptr2 = ptr2->next;
        }

        std::cout << k << " from the last element is " << ptr2->_data << std::endl;
}

/*
   Parition a value around int x
   CTCI has node to pivot element
   Insert everything greater to the head
        Adding to tail makes it go forever lol

        Element X does not need to be in middle
 */

template <typename T>
void LinkedList<T>::partition_list(int x){

        Node *ptr = _head; //iterate through list
        Node *temp;

        std::cout << "Partitioning list around:" << x << std::endl;

        while(ptr!=NULL) {
                if(ptr->_data >= x) {
                        insert(ptr->_data); //insert before head
                        temp = ptr->next; //save pointer to next
                        remove(1,ptr); //delete ptr (fixes gap)
                        ptr = temp; //resume pointer to next
                }
                else{
                        ptr = ptr->next;
                }
                //print();
        }

}


/*
   Reverse a Doubly Linked List


 */
template <typename T>
void LinkedList<T>::reverse_list(){

        std::cout << "Reversing List" << std::endl;

        Node *curr = _head;
        Node *temp;
        //Node<T> * prev = NULL;
        //Node<T> * next;


/* SINGLY LINKED LIST
        while(curr != NULL) {
                next = curr->next; // [prev] [curr] [next]
                curr->next = prev;
                prev = curr; //reset
                curr = next; //reset
        }//curr is NULL

        head = prev;

 */
        _tail = _head;

        //DOUBLY LINKED LIST
        while (curr !=  NULL) {
                temp = curr->prev;
                curr->prev = curr->next;
                curr->next = temp;
                curr = curr->prev;
        }

/* Before changing head, check for the cases like empty
   list and list with only one node */
        if(temp != NULL )
                _head = temp->prev;


}


int main(int argc, char ** argv){

        LinkedList<int>list;
        //LinkedList<int>list2;

        //std::vector<int> v = {2,2,2,3,4,5,6,6,7,8};
        std::vector<int> v = {1,2,3,4,5,6,6,7,8,8,9};
        //std::vector<int> v = {1,2,3};

        for (int &i : v) {
                list.insert(i);
                //list2.insert(i);
        }



        list.print();

        list.k_to_last(2);
        list.partition_list(5);
        list.print();
        list.remove_dup();
        list.reverse_list();
        list.print();
        list.insertionSort();
        list.print();



        //list.print();
        //list.partition_list(5);
        //list.print();

}
