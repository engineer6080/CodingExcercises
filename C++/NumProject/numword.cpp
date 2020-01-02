#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include "numword.h"

using namespace bw;


//Constructor with args
Number::Number(const uint64_t *in) : n(in){
        puts("hello");
}

//Deconstructor
Number::~Number(){

}

//Avoid local copy of pointer
//Pointer to the pointer
bool textprocess(const char *in){
        if(*in != '0') {
                return true;
        }
        else {
                return false;
        }

}

const char * Number::getWords( const uint64_t *in){

        //printf("%ld\n",*in);

        char buf[50];

        uint64_t temp = *in;

        sprintf(buf, "%ld", *in);

        int strsize=0;

        //Count number of characters
        for(char * cp = buf; *cp; ++cp) {
                strsize++;
        }

        //Log then modulus 3

        char *x = buf;
        int i=0;

        while(temp != 0) {

                // 524 234

                //uint64_t thousand_exp = intlog(1000,temp);
                uint64_t thousand_exp = (uint64_t)(log(temp) / log(1000));
                uint64_t power = pow(1000, thousand_exp);
                //1,000,000,000,000,000,000

                //first few [xxx] digits
                int first;

                if(power > 0) {
                        first = (temp/power);
                }
                else{
                        first = 0;
                }

                //reset pointer
                x = buf;
                //printf("%ld\n",(temp/power) );

                //Hundred or single digit
                //[100],000,001 [1],000,000

                // 1, 492
                // [123], 042, 002
                // 123,000,000,000
                // 999,999,999,999,999,999 = 18

                //999,999,999,999,999

                if(first < 10 || first > 98) {

                        //Skips Zeros
                        //if(textprocess(singles[*x - '0'])) {
                        std::cout << singles[*x - '0']; //1
                        //}

                        if(first > 98) {
                                if(first % 100 != 0) {
                                        std::cout << " hundred and ";
                                }
                                else{ // 100
                                        std::cout << " hundred ";
                                        x++;
                                }
                        }

                        x++;
                }

                //20, 21, 22, 23
                if(first > 19) {
                        //[2]
                        if(textprocess(x)) {
                                std::cout << tens[*x - '0'];//twenty
                        }
                        x++;

                        //[3]
                        if(textprocess(x)) {
                                std::cout << "-";
                                std::cout << singles[*x - '0']; //four
                        }
                        x++;
                }
                //11, 12, 13
                else if((first - 10) >= 0) {
                        //10, 11 tweleve thirteen
                        std::cout << teens[first-10];
                        x++;
                        x++;
                }

                //thousand, billion, trillion, quadrillion
                if(textprocess(powers[thousand_exp])) {
                        std::cout << " " << powers[thousand_exp] << " ";
                }

                //123,042,002 - 123,000,000 = 42,002
                temp -= (first * power);

                memset(buf, 0, sizeof(buf));

                sprintf(buf, "%ld", temp);

                //printf("%ld\n",(temp/power)* power);

                //6%3 = 0
                if(strsize % 3 == 0 && strsize !=0) {
                        strsize -= 3;
                }
                else{ //1%3
                        strsize -= strsize % 3;
                }

                if(strsize==0 || temp == 0) {
                        std::cout << std::endl;
                        return "done";
                }


        }

}




//Temporary main
int main(){
        bw::Number nw;
        uint64_t n;

        n = 2;
        //n = 474,142,398,123;


        n = 524054254;
        n = 3; printf("n is %ld\n", n); nw.getWords(&n);
        n = 47; printf("n is %ld\n", n); nw.getWords(&n);
        n = 73; printf("n is %ld\n", n); nw.getWords(&n);
        n = 1492; printf("n is %ld\n", n); nw.getWords(&n);
        n = 10012; printf("n is %ld\n", n); nw.getWords(&n);
        n = 100073; printf("n is %ld\n", n); nw.getWords(&n);
        n = 1000000; printf("n is %ld\n", n); nw.getWords(&n);


        n = 1000000001; printf("n is %ld\n", n); nw.getWords(&n);


        n = 123000000000; printf("n is %ld\n", n); nw.getWords(&n);
        n = 474142398123; printf("n is %ld\n", n); nw.getWords(&n);
        n = 1474142398007; printf("n is %ld\n", n); nw.getWords(&n);

        n = 999000000000000; printf("n is %ld\n", n); nw.getWords(&n);
        n = 999999999999999; printf("n is %ld\n", n); nw.getWords(&n);

        //n = 999999999999999999; printf("n is %ld\n", n); nw.getWords(&n);
        //n = 1000000000000000000; printf("n is %ld\n", n); nw.getWords(&n);



        return 0;
}
