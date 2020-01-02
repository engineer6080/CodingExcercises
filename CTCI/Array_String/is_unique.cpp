//#include <cstdio> //gets, puts, printf, scanf
//#include <cstdlib> //atoi, free, malloc
#include <iostream> //cin, cout
#include <string>
#include <bitset>

#define SIZE 128 //ASCII 128 characters

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::bitset;

bool isunique(const string &str){
        bitset<SIZE> bset;

        for(const auto c : str) {
                //int val = (int)c - '0'; //convert to ASCII
                int val = c - '0'; // '0'->0, '1'->1
                if(bset.test(val))
                        return false;

                bset.set(val);

        }
        return true;
}

int main(){

        string in;
        printf("Enter Input: ");
        cin >> in;
        cout << "is unique = " << (isunique(in) ? "true" : "false") << endl;

        return 0;
}
