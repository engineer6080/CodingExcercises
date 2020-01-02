#include <iostream>
#include <string>
#include <bitset>
#include <cmath> //for findSetBit
#include <algorithm> //for remove_if

#define SIZE 128 //ASCII TABLE SIZE

#define DEBUG false

/*
   Need to check if at most one of each letter difference
   Tact Coa --> permutation of Taco Cat -> which is a palindrome

   The bitwise and of any power of 2 and any number 1 less than it will give 0. So we can verify if a number is power of 2 or not by using the expression, n&(n-1).
   It will fail when n=0, so we have to add an extra and condition.

 */

int findSetBit(std::uint32_t bits)
{
        if (!(bits && !(bits & (bits-1))))
                return 0;
        return log2(bits) + 1;
}


//Flipping the letter bit twice should leave it zero
//At most Binary can be 000 or 010 (one bit)

bool check(std::string &in){
        std::bitset<SIZE> bset;
        for(auto c : in) {
                int val = c - '0';
                bset.flip(val);
        }

        if(DEBUG) {
                std::string debug = bset.to_string<char,std::string::traits_type,std::string::allocator_type>();
                std::cout << debug << std::endl;
        }

        if(bset == 0 || bset.count() == 1) { //zero or one bit toggled
                return true;
        }

        return false;

}


int main(){

        std::string in;
        std::cout << "Enter input: ";
        //std::cin >> in;
        getline(std::cin, in);

        //Remove Space
        in.erase(std::remove_if(in.begin(), in.end(), isspace), in.end());  //isspace checks \n \t \f \r and character space ' '
        std::cout << in << std::endl;

        std::cout << "Is Permutation Palindrome? " << (check(in) ? "yes" : "no") << std::endl;

        return 0;

}
