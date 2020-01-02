#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dllist.h"



int main (){

        char select[2]; //3 byte selection input

        //For measurement
        //clock_t start, end;

        //double cpu_time_used;

        List *llist;

        while(strcmp(select,"q") != 0) {

                printf("1. Doubly LinkedList\n");
//                printf("1. Doubly LinkedList\n");
                printf("Choose an option or type q to exit: ");

                fgets(select,3,stdin);

                select[strcspn(select, "\n")] = '\0'; //strcspn Returns index of that character

                switch(atoi(select)) {

                case 1: //Doubly Linked List Test

                        llist = initList(4); //Data Size in Bytes

                        printf("\n");

                        printf("Adding data\n");

                        int i;
                        for(i=0; i<10; i++) {
                                lladd(llist, &i);
                        }

                        llprint(llist);

                        printf("Add 99 to end of list\n");

                        getchar();

                        int x = 99;

                        lladdE(llist, &x);

                        llprint(llist);

                        printf("Add 100 after 3\n");

                        getchar();

                        x = 3;
                        int y = 100;

                        lladdA(llist, &x, &y);

                        llprint(llist);

                        printf("Delete List and Print\n");

                        getchar();

                        destorylist(llist);

                        llprint(llist);

                        printf("Adding 3 numbers to New List\n");

                        getchar();

                        //New List - DELETE TEST
                        llist = initList(4); //Data Size in Bytes

                        for(i=0; i<3; i++) { // [2 1 0]
                                lladd(llist, &i);
                        }

                        llprint(llist);

                        printf("Print Backwords\n");

                        getchar();

                        llreverse(llist);

                        getchar();

                        x = 0;
                        lldelete(llist, &x);
                        printf("Deleted 0\n");
                        llprint(llist);

                        getchar();

                        x = 1;
                        lldelete(llist, &x);
                        printf("Deleted 1\n");
                        llprint(llist);

                        getchar();

                        x = 2;
                        lldelete(llist, &x);
                        printf("Deleted 2\n");
                        llprint(llist);

                        getchar();

                        printf("Done\n");


                case 2:

                        break;
                case 3:
                        break;
                case 4:
                        //lladdA(llist);
                        break;

                }

        }



        return 0;
}
