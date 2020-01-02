#include <iostream>
#include <stack>

using namespace std;

/*
   parenthesis checking different approach

 */

int main() {
        //code

        int t; //number of test cases
        cin >> t;

        // { [ (
        /*
           ( = 40, ) = 41, * = 43
           { = 123, { = 125
           [ = 91, ] = 93

         */
        stack<char> s;
        for(int i = 0; i < t; i++) {
                std::string in;

                cin >> in;
                if(in.size()%2 != 0) {
                        cout << "not balanced\n"; continue;
                };

                for(char c : in) {

                        //open
                        if(c == '[' || c == '{' || c == '(') s.push(c);

                        else if(s.empty()) {
                                cout << "not balanced\n";
                                break; continue;
                        }
                        //close
                        else if(int(c)-int(s.top()) > 2) {
                                cout << "not balanced\n";
                                break;
                        }
                        else{
                                s.pop();
                        }
                }

                if(s.empty())
                        cout << "balanced\n";

        }
        return 0;
}
