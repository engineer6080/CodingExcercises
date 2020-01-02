#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

/*
        Prints out matrix in a spiral order


 */

vector<vector<int> > generateMatrix(int A) {

        int n = 1;
        int row = 0, num = A;
        int col = 0;
        vector< vector<int> > res;
        res.resize(A, vector<int>(A, 0));

        while (n != (A * A) + 1) {

                // right iter row, colum
                int t;
                for (t = 0; t < num; t++, col++) {
                        res[row][col] = n;
                        n++;
                }
                // down ROW CHANGE, COLUMN SAME
                num--;
                col--;
                row++;
                for (t = 0; t < num; t++, row++) {
                        res[row][col] = n;
                        n++;
                }
                // left
                row--;
                col--;
                for (t = 0; t < num; t++, col--) {
                        res[row][col] = n;
                        n++;
                }

                num--;
                col++;
                row--;
                // up iter col,
                for (t = 0; t < num; t++, row--) {
                        res[row][col] = n;
                        n++;
                }
                row++;
                col++;
        }
        return res;
}

int main() {
        int in;
        cout << "Enter nxn matrix n: ";
        cin >> in;


        vector<vector<int> > vec = generateMatrix(in);

        for (int i = 0; i < vec.size(); i++) {
                for (int j = 0; j < vec[i].size(); j++) {
                        cout << setw(8) << vec[i][j];
                }
                cout << endl;
        }

        return 0;
}
