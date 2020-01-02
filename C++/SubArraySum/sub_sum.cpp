#include <iostream>
using namespace std;

/*

   Given an unsorted array A of size N of non-negative integers, find a continuous sub-array which adds to a given number S.
   Exercise from GeeksforGeeks

 */

void subA_sum(int *in, const int &N, const int &S){

        int t_index =0; //traveling index
        int i; //current index
        int sum = 0;

        //O(N)
        for(i=0; i < N; i++) {
                sum += *(in+i);

                while(sum > S) {
                        sum -= *(in+(t_index++));
                }
                if(sum == S) {
                        break;
                }
        }

        if(sum == S)
                cout << t_index+1 << " " << i+1 << endl;
        else
                cout << -1 << endl;

}

int main() {

        int t;
        cin >> t; //number of test cases

        int N, S; // Array size, Target Sum

        for(int i=0; i < t; i++) {
                cin >> N;
                cin >> S;

                int in[N];
                //Take in array input
                for(int j=0; j < N; j++) {
                        cin >> in[j];
                }

                subA_sum(in, N, S);
        }
        return 0;
}
