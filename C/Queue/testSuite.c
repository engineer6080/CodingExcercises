#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "queue.h"



int main (){

        char select[2]; //3 byte selection input

        char input[10]; //user input

        //For measurement
        //clock_t start, end;

        //double cpu_time_used;


        while(strcmp(select,"q") != 0) {

                printf("1. Enqueue\n");
                printf("2. Dequeue\n");
                printf("3. Print Queue\n");
                printf("Choose an option or type q to exit: ");

                fgets(select,3,stdin);

                select[strcspn(select, "\n")] = '\0'; //strcspn Returns index of that character

                switch(atoi(select)) {

                case 1: //Doubly Linked List Test

                        if(front == NULL) {
                                printf("Initialize Queue, enter data size (bytes)\n");

                                fgets(input,3,stdin);
                                input[strcspn(input, "\n")] = '\0'; //strcspn Returns index of that character

                                initQueue(atoi(input));
                        }


                        printf("Add data:\n");

                        fgets(input,10,stdin);
                        input[strcspn(input, "\n")] = '\0'; //strcspn Returns index of that character

                        Enqueue(input);


                        break;
                case 2:
                        printf("Dequeued %s\n", (char *)Dequeue());

                        break;
                case 3:
                        printQueue();

                        break;
                case 4:
                        //lladdA(llist);
                        break;

                }

        }



        return 0;
}
