#include <cmath>

vector<int> Solution::plusOne(vector<int> &A) {

        uint64_t number = 0;

        int size = A.size() - 1;

        for(auto it = A.begin(); it !=A.end(); it++) {
                if(*it != 0) {
                        number += (*it) * pow(10,size);
                }
                size--;
        }

        //only the last digit changes
        //what if its nine or even 999

        number += 1;

        char buffer[500];

        sprintf(buffer, "%llu ", number);

        cout << buffer << endl;

        int i = 0;

        A.clear();

        while(buffer[i] != ' ') {
                A.push_back((buffer[i] - '0'));

                i++;
        }
        //cout << endl;

        return A;
}
