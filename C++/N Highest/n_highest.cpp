#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<string> split(const string &str) {
        vector<string> tokens;

        string::size_type start = 0;
        string::size_type end = 0;

        while ((end = str.find(" ", start)) != string::npos) {
                tokens.push_back(str.substr(start, end - start));

                start = end + 1;
        }

        tokens.push_back(str.substr(start));

        return tokens;
}

string ltrim(const string &str) {
        string s(str);

        s.erase(
                s.begin(),
                find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
                );

        return s;
}

string rtrim(const string &str) {
        string s(str);

        s.erase(
                find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
                s.end()
                );

        return s;
}

int main(){


        string nq_temp;
        getline(cin, nq_temp);

        vector<string> nq = split(rtrim(nq_temp));

        vector<int> input;

        for (int i = 0; i < nq.size(); i++) {
                input.push_back(stoi(nq[i]));

        }

        std::sort (input.begin(), input.end());

        //for(auto i = input.begin(); i != input.end(); i++) {
        //        cout << *i << " ";
        //}
        cout << "Enter nth index:";
        int x;
        cin >> x;

        cout << x << " highest is " << input[input.size()-x] << endl;


}
