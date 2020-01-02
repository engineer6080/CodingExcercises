#include <iostream>
#include <vector>

using namespace std;

/*
   Find missing number in array

 */

int main() {

        cout << "input size of array followed by array of numbers" << endl;

        int S=0;
        int N;
        cin >> N;

        int in;
        //Take in array input
        for(int j=0; j < N; j++) {
                cin >> in;
                S-= in;
                S+=(j+1);
        }
        S+=(N+1);
        cout << "missing number " << S << endl;

        return 0;
}
