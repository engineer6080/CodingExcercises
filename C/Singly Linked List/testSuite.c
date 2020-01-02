#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "llist.h"



int main (){

        char select[2]; //3 byte selection input

        //For measurement
        //clock_t start, end;

        //double cpu_time_used;

        List *llist;

        while(strcmp(select,"q") != 0) {

                printf("1. LinkedList\n");
                //("2. Doubly LinkedList\n");
                printf("Choose an option or type q to exit: ");

                fgets(select,3,stdin);

                select[strcspn(select, "\n")] = '\0'; //strcspn Returns index of that character

                switch(atoi(select)) {

                case 1: //Linked List Test

                        llist = initList(4); //Data Size in Bytes

                        printf("\n");

                        printf("Adding 5 numbers to List\n");

                        int i;
                        for(i=0; i<5; i++) {
                                lladd(llist, &i);
                        }

                        //Temporary use variables
                        int x = 12;
                        int y = 99;

                        printf("Add number after %d\n", x);

                        //start = clock();
                        lladdA(llist, &x, &y);
                        //end = clock();

                        //cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

                        //printf("\n");

                        //printf("Done %f\n", cpu_time_used);

                        printf("Add number to end of List\n");

                        lladdE(llist, &y);

                        llprint(llist);
                        printf("Done \n\n");
                        break;
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
