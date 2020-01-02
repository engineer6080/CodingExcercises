#include <iostream>

//#include <unistd.h>
using namespace std;

/*
   Change all even bits to zero

   Input : 30
   Output : 10
   Binary representation of 11110.
   After making all of them 0, we get 01010

 */

#define NUM 0b10101010101010101010101010101010

#define HEXNUM 0xaaaaaaaa

//Sample Input
#define THIRTY 0b11110


int change_even_bits(int &in){
        cout << "All even bits to zero: ";
        in &= HEXNUM;
        cout << in << endl;

        return in;
}

/* count number of set bits

   n =  9 (1001)
   count = 0

   Since 9 > 0, subtract by 1 and do bitwise & with (9-1)
   n = 9&8  (1001 & 1000)
   n = 8
   count  = 1

   Since 8 > 0, subtract by 1 and do bitwise & with (8-1)
   n = 8&7  (1000 & 0111)
   n = 0
   count = 2

   Since n = 0, return count which is 2 now.
 */

int count_set_bits(int &n){
        cout << "Number of set bits: ";
        //int count =  __builtin_popcount(n); //BUILT IN METHOD
        unsigned int count = 0;
        while (n)
        {
                n &= (n-1);
                count++;
        }
        cout << count << endl;

        return count;
}


int main(int argc, char **argv) {

        int in;

        in = atoi(argv[1]);

        //change_even_bits(in);
        count_set_bits(in);



        return 0;
}
