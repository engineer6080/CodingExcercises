//numword.h

#ifndef _NUMWORD_H_
#define _NUMWORD_H_

#include <cstdint>
#include <cstring>


namespace bw {

const char * singles[] = {
        "0","one","two","three","four","five", "six", "seven", "eight", "nine"
};
const char * teens[] = {
        "ten","eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
        "eighteen", "nineteen"
};
const char * tens[] = {
        "NULL","NULL", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty",
        "ninty", "twenty"
};
const char * hundred = "hundred";

const char * powers[] = {
        "0", "thousand", "million", "billion", "trillion", "quadrillion"
};


class Number {
const uint64_t *n; //Pointer to input
public:
Number() : n(NULL) {
};                     //default constructor
Number(const uint64_t *in);        //Constructor
~Number(); //Deconstructor
const char * getWords(const uint64_t *in);
};

};






#endif /* _NUMWORD_H */
