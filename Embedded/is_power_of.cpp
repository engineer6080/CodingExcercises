#include <iostream>
#include <cmath> //log
#include <ctime> //clock stuff

#include <iomanip> //printing floating point preicision

using namespace std;

/*
   float has 7 digts of preicision (32 bit)
   double has 16 digits of preicision (64 bit)
   long double (80 bit)

 */

#define RUNS 10000

typedef bool (*FUNCPTR)(int &x); //function pointer to type bool

void timef(FUNCPTR function, int arg, const char * name){

        double avg=0;
        bool ret;

        for(int i=0; i < RUNS; i++) {

                clock_t t;
                t = clock();
                ret = (*function)(arg);
                t = clock() - t;
                if(!ret) {
                        cout << "Err: False" << endl;
                        return;
                }
                avg+=t;

        }
        avg /= RUNS;
        std::cout << std::fixed;
        std::cout << std::setprecision(16);
        cout << name << " " << ((((double)avg)/CLOCKS_PER_SEC)) << endl;
        //std::cout << avg << " " << t <<  " " << total << std::endl;

}

/*

   Various ways to check if a number is a power of two

   n%2=0 won't work...
   34 is valid..
   2 * 2 * 2 * 2 * 2 = 32 *2 = 64...

 */

// Using Bit shifting
bool is_power (int &x){
        // return (x & (x - 1)) == 0; //VALID BUT DOESNT WORK FOR 0
        return (x != 0) && ((x & (x - 1)) == 0);
}


/*
   Using Log base 2
   Log     32 = 5
        2

 */

bool is_power2 (int &n)
{
        return (ceil(log2(n)) == floor(log2(n)));
}

/*


 */

bool is_power3(int &n){
        //Largest power of 3 (int)
        return 1162261467 % n == 0;
}


/*
   First argument is the number to check
   arg 0 is the file name

 */
int main (int argc, char** argv){

        int in;

        //for(int i=0; i < argc; i++) {
        //        cout << argv[i] << endl;
        //}

        in = atoi(argv[1]);

        timef(&is_power, in,  "        Log:");
        timef(&is_power2, in, "Bitshifting:");
        timef(&is_power3, in, "Power of Three:");


}
