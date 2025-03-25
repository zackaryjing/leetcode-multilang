// problem: row-with-maximum-ones
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int> > &mat) {
        int n = mat.size();
        int one_cnt = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int temp = accumulate(mat[i].begin(), mat[i].end(), 0);
            if (temp > one_cnt) {
                one_cnt = temp;
                ans = i;
            }
        }
        return {ans, one_cnt};
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    vector<vector<int> > eg1 = {{0, 1}, {1, 0}};
    auto t = test.rowAndMaximumOnes(eg1);
    cout << t[0] << ", " << t[1] << endl;
}


//
// Created by ASUS on 2025/3/22.
//
