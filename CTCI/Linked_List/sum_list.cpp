#include <iostream>

using namespace std;
struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {
        }
};

ListNode* addTwoNumbers(ListNode* A, ListNode* B) {
        //Digits are stored reverse order
        //Solution is also stored in reverse..
        ListNode *S = new ListNode(0); //first element is 0
        ListNode *head = S; //pointer to head
        int carry = 0;
        int val;

        while(1) {
                val = (A->val + B->val + carry);

                if(A->next || B->next) {

                        S->next = new ListNode(val%10);

                        carry = val /10;
                }
                else{ //last element
                        if((val/10)) { //check if we need extra digit
                                S->next = new ListNode(val%10);
                                S = S->next;
                                S->next = new ListNode(val/10);
                        }
                        else{ //no carry
                                S->next = new ListNode(val);
                        }

                        break;
                }
                // A = A->next;
                //cout << S->val << " " << A->val << " " << B->val << " " << endl;
                if(A->next) A = A->next; else A->val = 0;
                if(B->next) B = B->next; else B->val = 0;
                //if(!A->next && !B->next) break; //end condition
                S = S->next;
        }

        return head->next;

}

int main(){


        ListNode*A = new ListNode(7);
        ListNode *Ahead = A;
        A->next = new ListNode(1);
        A = A->next;
        A->next = new ListNode(6);
        A = A->next;

        ListNode*B = new ListNode(5);
        ListNode *Bhead = B;
        B->next = new ListNode(9);
        B = B->next;
        B->next = new ListNode(2);
        B = B->next;

        ListNode *S = addTwoNumbers(Ahead, Bhead);

        while (S) {
                cout << S->val << " ";
                S = S->next;
        }
        cout << endl;

}
