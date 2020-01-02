#include "bst.hpp"
#include <cstring>

using namespace std;

#define MANUAL 0

int main(){

        //std::vector<int> v = {50,49,51,35,50,52};

        std::vector<int> v = {10,5,4,3,12,11,14};

        BinarySearchTree tree;

        int in=0;


        if(MANUAL) {
                while(in!=-1) {
                        std::cout << "Enter int(-1 to stop): ";
                        std::cin >> in;
                        if(in<0) break;
                        tree.insert(in);
                        tree.print(); //visual pretty print
                }
        }
        else{

                for(int &i : v) {
                        tree.insert(i);
                }
                tree.print();

        }

        tree.print(1);
        tree.print(2);
        tree.print(3);
        tree.checkBST() ? std::cout << "This Tree is valid BST" : std::cout << "This Tree is not valid BST";
        std::cout << std::endl;
        std::cout << "Height of Tree is " << tree.getHeight() << std::endl;
        std::cout << "Number of Nodes: " << tree.getCount() << std::endl;



        /*

               char txt[] = "abbcdca";

               int c = txt[0];
               for(int i = 1; i < strlen(txt); i++) {
                       c ^= (int)txt[i];
                       //cout << c << endl;

               }
               char x = 'c' ^ 'd' ^ 'c';

               cout << (char)c << endl;

         */

        return 0;

}
