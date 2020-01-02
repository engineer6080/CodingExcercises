#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "stack.h"



int main (){

        char select[2]; //3 byte selection input

        char input[2]; //user input

        //For measurement
        //clock_t start, end;

        //double cpu_time_used;


        while(strcmp(select,"q") != 0) {

                printf("1. Push\n");
                printf("2. Pop\n");
                printf("3. Print Stack\n");
                printf("Choose an option or type q to exit: ");

                fgets(select,3,stdin);

                select[strcspn(select, "\n")] = '\0'; //strcspn Returns index of that character

                switch(atoi(select)) {

                case 1: //Doubly Linked List Test

                        if(top == NULL) {
                                printf("Initialize Stack, enter data size (bytes)\n");

                                fgets(input,3,stdin);
                                input[strcspn(input, "\n")] = '\0'; //strcspn Returns index of that character

                                initStack(atoi(input));
                        }


                        printf("Add data:\n");

                        fgets(input,3,stdin);
                        input[strcspn(input, "\n")] = '\0'; //strcspn Returns index of that character

                        push(input);


                        break;
                case 2:
                        printf("Popped %s\n", (char *)pop());

                        break;
                case 3:
                        printstack();

                        break;
                case 4:
                        //lladdA(llist);
                        break;

                }

        }



        return 0;
}
