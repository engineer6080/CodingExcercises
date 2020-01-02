#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tree.h"


int main (){

        char select[2]; //3 byte selection input

        char input[2]; //user input

        //For measurement
        //clock_t start, end;

        //double cpu_time_used;

        struct node * root = NULL;

        int in;

        in = 1;
        root = getnode(&in);
        in = 2;
        root->lchild = getnode(&in);
        in = 3;
        root->rchild = getnode(&in);
        in = 4;
        root->lchild->lchild = getnode(&in);
        in = 5;
        root->lchild->rchild = getnode(&in);
        in = 6;
        root->rchild->lchild = getnode(&in);


        while(strcmp(select,"q") != 0) {

                printf("1. PreOrder\n");
                printf("2. PostOrder\n");
                printf("3. Level Order\n");
                printf("4. In Order\n");
                printf("5. Display Tree\n");
                printf("Choose an option or type q to exit: ");

                fgets(select,3,stdin);

                select[strcspn(select, "\n")] = '\0'; //strcspn Returns index of that character

                switch(atoi(select)) {

                case 1:
                        preorder(root);

                        break;
                case 2:
                        postorder(root);

                        break;
                case 3:
                        inorder(root);

                        break;
                case 4:
                        //levelorder(root);
                        break;

                case 5:
                        displaytree(root,0);
                        printf("Height of tree is %d\n", height(root));
                        break;
                }

        }



        return 0;
}
