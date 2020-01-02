#include <cstdio>
#include <iostream>
#include <vector>
#include <climits> //INTMIN

using namespace std;

#define max(a,b) \
        ({ __typeof__ (a)_a = (a); \
           __typeof__ (b)_b = (b); \
           _a > _b ? _a : _b; })

int max_sub(int arr[], int n);

int main(){
        int arr[] = {-1, -2, 5, 6, 4, -3};

        int sol = max_sub(arr, 6);

        cout << sol << endl;

        return 0;
}


//Recursive solution
//Similar to MergeSort
//O(n log n)
int max_sub(int arr[], int n){

        if(n == 1)
        {
                return arr[0];
        }
        int m = n/2;
        int left_mss = max_sub(arr, m);
        cout << "lm: " << left_mss << endl;
        int right_mss = max_sub(arr+m,n-m);

        cout << "rm: " << right_mss << endl;

        int leftsum = INT_MIN, rightsum = INT_MIN, sum = 0;

        cout << left_mss << ":" << right_mss << endl;
        cin.get();

        for(int i = m; i < n; i++) {
                sum += arr[i];
                rightsum = max(rightsum, sum);
        }
        cout << "rsum: " << rightsum << " sum: " << sum << endl;
        cin.get();

        sum = 0;
        for(int i = (m-1); i >= 0; i--) {
                sum += arr[i];
                leftsum = max(leftsum, sum);
        }
        cout << "lsum: " << leftsum << " sum: " << sum << endl;
        cin.get();

        int ans = max(left_mss, right_mss);
        return max(ans, leftsum+rightsum);
}
