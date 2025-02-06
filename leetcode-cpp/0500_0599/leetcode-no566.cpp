#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > matrixReshape(vector<vector<int> > &mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();
        if (r * c != n * m or n <= 0 or m <= 0) {
            return mat;
        }
        vector<vector<int> > ans = vector(r, vector<int>(c));
        for (int i = 0; i < n; i++) {
            int line_base = (i * m);
            for (int k = 0; k < m; k++) {
                int pos = line_base + k;
                // cout << i << ": " << k << "pos: " << pos << endl;
                // cout << pos / c << ", " << pos % c << endl;;
                ans[pos / c][pos % c] = mat[i][k];
            }
        }
        return ans;
    }
};


int main() {
    vector<vector<int>> eg1 = {{1},{2},{3},{4}};
    Solution test;
    auto res = test.matrixReshape(eg1,2,2);
    for (auto k : res) {
        for (auto j : k) {
            cout << j << " ";
        }
        cout << endl;
    }
}

//
// Created by ASUS on 2025/2/5.
//
