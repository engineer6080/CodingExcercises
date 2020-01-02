/*

   Multi Threaded Mergesort


 */

#include <iostream>
#include <vector>
#include <cstdlib> // rand
#include <ctime>
#include <random>
#include <thread>
#include <algorithm> //sort
#include <chrono> //timing


#include "semaphore.h"

using namespace std;
using namespace std::chrono;

//Globals
std::mutex m;

//Print
template<typename TContainer>
void printT (TContainer begin, TContainer end){
        TContainer i;
        for(i = begin; i != end; i++) {
                cout << *i << " ";
        }
        cout << endl;
}

//Fill with random numbers
template<typename TContainer>
void genRand(TContainer begin, TContainer end){
/**************ALTERNATE RND **********************/
        // First create an instance of an engine.
        random_device rnd_device;
        // Specify the engine and distribution.
        mt19937 mersenne_engine {rnd_device()}; // Generates random integers
        uniform_int_distribution<int> dist {1, 52};


        std::uniform_int_distribution<int> dist6(1,5000000); // distribution in range [1, 6]

        auto gen = [&dist, &mersenne_engine](){
                           return dist(mersenne_engine);
                   };
/*******************************************************/
        TContainer i;
        srand (time(NULL));
        for(i = begin; i != end; i++) {
                //*i = rand();
                *i = dist6(mersenne_engine);
        }
        cout << endl;
}

template<typename TContainer>
void merge(TContainer begin, TContainer end, int mid){
        int m = mid + 1;
//        int e = end + 1;
        TContainer midT = begin+m;//;(begin+(mid+1));
        TContainer endT = end+1;//(begin+(end+1));

        vector<unsigned int> one (begin,midT);
        vector<unsigned int> two (midT, endT);

        int a = 0;
        int b = 0;
        int index = 0;
        while (a < one.size() && b < two.size())
        {
                if (one[a] < two[b])
                        *(begin+(index++)) = one[a++];
                else
                        *(begin+(index++)) = two[b++];
        }
// merge the left-over elements
        while (a < one.size())
                *(begin+(index++)) = one[a++];
        while (b < two.size())
                *(begin+(index++)) = two[b++];
}

//Each Thread gets a portion to mergesort
template<typename TContainer>
void stlSort(TContainer begin, TContainer end){
        //m.lock();
        //TContainer i;
        //printT(begin, end);
        int mid = std::distance(begin, end)/2;
        stlSort<TContainer>(begin, begin+mid);
        stlSort<TContainer>(begin+mid+1, end);

        merge(begin, end, mid);
        //m.unlock();
}

//test thread function
void testT(){
        while(1);
}

int main(){

        srand((unsigned)time(NULL));
        vector<unsigned int> numbers(16);


        //vector<unsigned int> numbers = {2,1,4,3,6,5,8,7,10,9,12,11,14,13,16,15};

        genRand(numbers.begin(), numbers.end());
        //printT(numbers.begin(), numbers.end());

        vector<unsigned int> numberscopy(numbers.begin(),numbers.end());

        // Get number of threads
        unsigned concurentThreadsSupported = std::thread::hardware_concurrency();

        cout << concurentThreadsSupported << " Threads detected" << endl;

        //oncurentThreadsSupported = 4;
        unsigned threadcount = concurentThreadsSupported;

        std::vector<std::thread> threads;
        int begin = 0;
        int split = (numbers.size()/threadcount);
        int remain = numbers.size() % concurentThreadsSupported;
        int end = split;
        int ThreadID = 1;

/*
        for(int i = 0; i < threadcount; i++) {
                threads.push_back(std::thread(testT));
        }

        for(auto &thread: threads) {
                thread.join();
        }

        return 0;
 */

        while(split <= numbers.size()) {

                for(int i = 0; i < threadcount; i++) {
                        //cout << "B:" << begin << " E:" << end << " T:" << threadcount << " S:" << split << endl;
                        threads.push_back(std::thread(stlSort<vector<unsigned int>::iterator>, numbers.begin()+begin, numbers.begin()+end));
                        //printT(numbers.begin()+begin, numbers.begin()+end);
                        ThreadID++;
                        begin += split; //inclusive
                        if(i == threadcount - 2) {
                                end = numbers.size();
                                //split += remain;
                        }
                        else{
                                end = begin + split; //exclusive - 1
                        }

                        //end = min(end, (int)numbers.size());
                }

                //threads.empty();
                //cout << endl;
                split *=2;
                threadcount = numbers.size()/split;
                begin = 0;
                if(numbers.size()-split == remain) end = split + remain;
                else end = split;
        }

        auto start = high_resolution_clock::now();
        int size = concurentThreadsSupported;
        int idx = 0;
        int j = 0;

        while(size != 0) {
                for(j=0; j<size; ++j) {
                        threads[j+idx].join();
                }
                idx +=j;
                cout << "----" << endl;
                size/=2;
        }

        auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);

        cout << "Thread sorting: " << duration.count() << endl;

        start = high_resolution_clock::now();
        printT(numberscopy.begin(), numberscopy.end());
        std::sort(numberscopy.begin(), numberscopy.end());
        duration = duration_cast<microseconds>(high_resolution_clock::now() - start);

        cout << "STL sorting: " << duration.count() << endl;

        printT(numbers.begin(), numbers.end());
}
