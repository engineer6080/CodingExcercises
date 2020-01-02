#include <iostream>
#include <random>
#include <fstream>
#include <algorithm> //sort, rotate,
#include <set>
#include <map>
#include <string>


#include <pthread.h>
#include <mutex>

/*
   Testing Various Sorting Algorithms
 */


/* Random generation technique from stack overflow */
typedef std::mt19937 MyRNG;   // the Mersenne Twister with a popular choice of parameters
uint32_t seed_val;            // populate somehow
MyRNG rng;                    // e.g. keep one global instance (per thread)

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;


#define DEBUG 0
#define CUSTOM 0

//CHOOSE SWAP. STL little bit slower
#define sswap swap

#if DEBUG == 1
        #define RUNS 1
        #define NUM_INTS 10
#else
        #define RUNS 1000
        #define NUM_INTS 1000
#endif


void initialize()
{
        rng.seed(seed_val);
}

void genList(){
        std::ofstream myfile;
        std::uniform_int_distribution<uint32_t> uint_dist10(0,100); // range [0,100]
        myfile.open ("numbers.txt");

        //Fill with 10 random elements
        for(int i = 0; i < NUM_INTS; i++) {
                myfile << uint_dist10(rng) << "\n";
        }

        myfile.close();
}

void print(std::vector<int> &v){

        for(int i : v) {
                std::cout << i << " ";
        }

        std::cout << std::endl;

}

void swap(int &xp, int &yp)
{
        if (&xp == &yp) // Check if the two addresses are same
                return;
        xp = xp + yp;
        yp = xp - yp;
        xp = xp - yp;
}

/*
   inserting to a mini list
   keep moving back until right place

   3, 2, 1
   2, 3, 1
   1, 2, 3


   1, 2, 3

   1, 2, 3, 5, 4

   Done with SWAPS
 */
void insertion_sort(std::vector<int> v){
        for(int i = 1; i < v.size(); i++) {
                for(int j = i; j != 0 && v[j] < v[j-1]; j--) {
                        sswap(v[j],v[j-1]);
                        //std::swap(v[j],v[j-1]); Little bit slower
                }
        }
        if(DEBUG) print(v);
}

/*
   Using std::rotate and std::upper_bound
   From GeeksforGeeks
   O(n^2)
 */
void insertionSort(std::vector<int> v)
{
        for (auto it = v.begin(); it != v.end(); it++)
        {
                // Searching the upper bound, i.e., first
                // element greater than *it from beginning
                auto const insertion_point =
                        std::upper_bound(v.begin(), it, *it);

                if(DEBUG) std::cout << "Insertion point " << *insertion_point << " num " << *it << std::endl;
                /*
                   Shifting the unsorted part
                   Move *it over to the insertion point (up to it+1)
                 */
                std::rotate(insertion_point, it, it+1);
                if(DEBUG) print(v);
        }
}
/*
   Start and then move forward to find next lowest number
   amongst the rest of the list
   then swap that value with the current index of the main loop
    O(n^2)
 */
void selection_sort(std::vector<int> v){
        int *localMin;
        for(int i = 0; i < v.size(); i++) {
                int j = i+1;
                localMin = &v[i];
                while(j < v.size()) {
                        localMin = v[j] <= *localMin ? &v[j] : localMin;
                        j++;
                }
                sswap(v[i],*localMin);
        }
}

/*
   Bubble up elements
   last becomes sorted
   O(n^2)
   Iterate up to last unsorted element (j-1)
 */
void bubble_sort(std::vector<int> v){

//        std::cout << "BEFORE" << '\n';
//        print(v);

        bool swapped = false;
        int j = v.size();
        do {
                swapped = false;
                for(int i = 1; i < j-1; i++) {
                        if(v[i] > v[i+1]) sswap(v[i],v[i+1]);
                        swapped = true;
                }
                j--;
        }
        while (swapped);

        if(DEBUG) print(v);
}
/*
   BUILT in QUICK SORT
   which is variation of IntroSort
   O(N Log N)
 */
void std_sort(std::vector<int> v){
        std::sort(v.begin(),v.end());
}

/*
   Built in Sort
   O(N  Log N)
   implemented using MergeSort

 */
void std_stable_sort(std::vector<int> v){
        std::stable_sort(v.begin(),v.end());
}

clock_t timef(void (*function)(std::vector<int> v), std::vector<int> v){
        clock_t t;
        //pthread_mutex_lock( &mtx );
        t = clock();
        (*function)(v);
        t = clock() - t;
        //pthread_mutex_unlock( &mtx );
        //std::cout << avg << " " << t <<  " " << total << std::endl;
        return t;
}


/*
        Experimental
        Sorted by inserting into multiset
        Implemented probably by balanced tree
        like AVL Tree or Red-Black Tree
 */
void set_sort(std::vector<int> v){

        //std::multiset<int> st;
        std::multimap<int,int>st;

        for(int i : v) {
                st.insert(std::pair<int,int>(i,i));
                //        st.insert(i);
        }

        if(DEBUG) {
                for(auto it = st.begin(); it != st.end(); it++) {
                        std::cout << it->second << ' ';
                }
                std::cout << std::endl;
        }
}

/*
        Divide and Conquer


 */
void quick_sort(std::vector<int> v){


}




/*
   Get average value

 */
float calc(std::vector<int> v, void (*function)(std::vector<int> v)){

        float avg = 0;
        //std::cout << name << std::endl;
        for(int i = 0; i < RUNS; i++) {
                //pass by value
                avg+=timef(function,v);
        }
        avg/=RUNS;
        return ((((float)avg)/CLOCKS_PER_SEC));
}


struct args
{
        std::vector<int> &v;
        std::multimap<double, std::string> *results;
        const char* name;
        void (*sortF)(std::vector<int> v);
};

typedef struct args argst;

void *t_func(void *a){

        argst *b;
        b = (argst*)a; //casting argument struct typestruct timespec start, finish;

        struct timespec start, finish;
        double elapsed;

        clock_gettime(CLOCK_MONOTONIC, &start);


//        results.insert(std::pair<float,std::string> (calc(v, set_sort), "Set Sort"));
//        pthread_mutex_lock( &mtx );
        double ret = calc(b->v,b->sortF);
        clock_gettime(CLOCK_MONOTONIC, &finish);
        elapsed = (finish.tv_sec - start.tv_sec);
        elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

        b->results->insert(std::pair<double,std::string> (elapsed, b->name));
//        pthread_mutex_unlock( &mtx );

//        calc(b->v,b->sortF);;
}


int main(int argc, char ** argv){


        std::vector<int> v;

        initialize();
        std::uniform_int_distribution<uint32_t> uint_dist10(0,100); // range [0,100]

        if(CUSTOM) {
                v = {1,4,5,3,2,1};
        }
        else{
                for(int i = 0; i < NUM_INTS; i++) {
                        v.push_back(uint_dist10(rng));
                }
        }


        std::cout << NUM_INTS << " numbers " << RUNS << " trials\n";

        std::multimap<double, std::string>results;

//        a->results = &results;

        // 8 threads maximum
        // 4 core * 2 threads per

        pthread_t threads[8];

        //TIME ENTIRE OPERATION
        struct timespec start, finish;
        double elapsed;
        clock_gettime(CLOCK_MONOTONIC, &start);

        //Currently debugging
        if(DEBUG) {
                //        std::cout << calc(v, quick_sort, "Quick Sort") << '\n';
                //results.insert(std::pair<float,std::string> (calc(v, set_sort), "Set Sort"));

                //        a->name = "Set Sort";
//                a->sortF = set_sort;

//                pthread_create(&threads[0], NULL, t_func, (void *)a);

        }
        else{
                argst a = {v, &results, "Bubble Sort", bubble_sort};
                pthread_create(&threads[0], NULL, t_func, (void *)&a);

                argst b = {v, &results, "Bubble Sort", bubble_sort};
                pthread_create(&threads[1], NULL, t_func, (void *)&b);

                argst c = {v, &results, "Quick Sort", quick_sort};
                pthread_create(&threads[2], NULL, t_func, (void *)&c);

                /*
                   results.insert(std::pair<float,std::string> (calc(v, insertion_sort), "Insertion Sort using swaps"));
                   results.insert(std::pair<float,std::string> (calc(v, insertionSort), "Insertion Sort using std::rotate and std::upper_bound"));
                   results.insert(std::pair<float,std::string> (calc(v, std_sort), "STL(Quick) Sort"));
                   results.insert(std::pair<float,std::string> (calc(v, std_stable_sort), "STL (Merge) Sort"));
                   results.insert(std::pair<float,std::string> (calc(v, selection_sort), "Selection Sort"));
                   results.insert(std::pair<float,std::string> (calc(v, bubble_sort), "Bubble Sort"));
                   results.insert(std::pair<float,std::string> (calc(v, set_sort), "Set Sort"));
                 */
        }


        //Wait for thread to finish
        pthread_join(threads[0], NULL);
        pthread_join(threads[1], NULL);
        pthread_join(threads[2], NULL);

        clock_gettime(CLOCK_MONOTONIC, &finish);
        elapsed = (finish.tv_sec - start.tv_sec);
        elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

        //Print out results in sorted order
        for(auto it = results.begin(); it != results.end(); it++) {
                std::cout << it->second << '\n';
                std::cout << it->first << '\n';
        }

        std::cout << "Total Time: " << elapsed << '\n';

        /*
           do
           {
                std::cout << uint_dist10(rng);
           }
           while (getchar() != 'q');
         */



        return 0;


}
