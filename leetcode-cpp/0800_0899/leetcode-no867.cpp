// problem: transpose-matrix
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > transpose(vector<vector<int> > &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector ans = vector(m, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[j][i] = matrix[i][j];
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
}


//
// Created by ASUS on 2025/3/14.
//
