#include "ll.hpp"
#include <iostream>
#include <fstream>
#include <ctime>  /* clock_t, clock, CLOCKS_PER_SEC */


void genList(){
        std::ofstream myfile;
        srand(time(NULL));
        myfile.open("rnd_numbers.txt");
        myfile << (rand() % 100) << std::endl;
        myfile.close();

}
/*
   pointer to member function of LinkedList
   //Explicit Type template function for int (template specialization)
 */
template <typename T>
void testLL(int (LinkedList<T>::*function)(void), const char *x){
        const int RUNS = 5000;
        const int RNDNUMS = 500;
        float avg=0;
        std::cout << "Testing: " << x << std::endl;


        /* initialize random seed: */
        srand(time(NULL));

        for(int i=0; i < RUNS; i++) {
                LinkedList<int> list;
                srand(time(NULL));

                for (int j = 0; j < RNDNUMS; j++) {


                        rand(); rand(); rand();
                        list.insert((rand() % 100));
                        //list.timef(&LinkedList<int>::insert)
                }

                //list.print();
                avg += list.timef(function);
                //list.print();
        }

        avg /= RUNS;
        std::cout << "Trials: " << RUNS << " On Avg: " << x << " took "  << ((((float)avg)/CLOCKS_PER_SEC))
                  << " seconds"  << std::endl;

}

int main() {
        //genList();

        testLL(&LinkedList<int>::bubbleSort, "bubbleSort");
        testLL(&LinkedList<int>::insertionSort, "insertionSort");


        return 0;
}
