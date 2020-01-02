#include <stdio.h>
#include <stdlib.h> //malloc

int global;

//Allocates space for pointer * p
//Take address of pointer pointer to pointer
void func(int **a) {
        *a = (int *)malloc(sizeof(int)); //allocate int
}

//Makes copy of pointer
void func2(int *b){
        //This copied pointer has been allocated
        b = (int *)malloc(sizeof(int));

}

int * func3(int *b){
        //allocate copied pointer
        b = (int *)malloc(sizeof(int));
        return b;
}

int main(void) {
        //pointer------------
        int *a; //= (int *)malloc(sizeof(int));
        //func(&a); //Pass address of pointer (double pointer)


        //Wrong -------------
        int *b;
        printf("Unintialized Pointer:\n");
        printf("Before: %p\n",b);
        func2(b);
        //*b = 4; //Derencing a NULL pointer will seg FAULT
        printf("After: %p\n",b);

        printf("\nInitialize pointer with function:\n");
        b = func3(b);
        printf("After: %p\n",b);



        printf("%d\n",*b ); //Derefencing the pointer a



        return 0;
}
