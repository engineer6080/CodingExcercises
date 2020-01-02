#include <iostream>
#include <string>

//#include <cstring> //c-style strings

#define DEBUG false

/*
   Given two strings, write a function to check
   if they are one edit away

   pale, ple -> true ---- one bit toggled
   pales, pale -> true --- one bit toggled
   pale, bale -> true --- two bit toggled is okay when they are the same size
   pale, bae -> false --two bit toggled

 */


/*
   s1 > s2
   check if there one difference
   ORDER MATTERS SO CANT USE BISET

   S2 cant go out of bounds because

 */
bool one_away (std::string &s1, std::string &s2){
        int j = 0;
        bool one_diff = false;

        for(int i=0; i<s1.length(); ) {
                if(s1[i] != s2[j]) { //check if letter different
                        if(one_diff) return false;
                        //we want to increment the larger string (if both are different sizes)
                        if(s1.length() != s2.length()) i++;
                        else {i++; j++;}
                        one_diff = true;
                }
                else{
                        i++;
                        j++;
                }
        }

        return true;

}


int main (int argc, char** argv){

        std::string word1;
        std::string word2;

        std::cout << "Enter two words separated by space: ";
        std::cin >> word1;
        std::cin >> word2;

        bool ret;

        /*
           if(word1.length() > word2.length())
                ret = one_away(word1, word2);
           else
                ret = one_away(word2, word1);
         */

        ret = word1.length() > word2.length() ? one_away(word1, word2) : one_away(word2, word1);

        std::cout << std::boolalpha; //toggle it so it prints true and false instead of 0 and 1

        std::cout << word1 << " and " << word2 << " are one edit away? " << ret << std::endl;

        if(DEBUG) std::cout << word1 << "\n" << word2 << std::endl;



}
