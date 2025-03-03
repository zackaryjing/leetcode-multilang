#include <iostream>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int> > &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> zero_cnt(n);
        for (int i = 0; i < n; i++) {
            auto &line = grid[i];
            int cnt = 0;
            for (int j = m - 1; j >= 0; j--) {
                if (not line[j]) {
                    cnt++;
                } else {
                    break;
                }
            }
            zero_cnt[i] = cnt;
        }

        int ans = 0;
        bool valid = true;
        for (int i = 0; i < n; i++) {
            // show_vector(zero_cnt);
            int k = i;
            // cout << i << endl;
            while (k < n and zero_cnt[k] < n - i - 1) {
                k++;
            }
            if (k >= n) {
                valid = false;
                break;
            }
            // cout << k << endl;

            int temp = zero_cnt[k];
            for (int j = k; j >= i + 1; j--) {
                zero_cnt[j] = zero_cnt[j - 1];
            }
            zero_cnt[i] = temp;
            ans += k - i;
        }
        return valid ? ans : -1;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    vector<vector<int> > grid1 = {{0, 0, 1}, {1, 1, 0}, {1, 0, 0}};
    cout << test.minSwaps(grid1) << endl;
    vector<vector<int> > grid2 = {{0, 1, 1, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}};
    cout << test.minSwaps(grid2) << endl;
    vector<vector<int> > grid3 = {{1, 0, 0}, {1, 1, 0}, {1, 1, 1}};
    cout << test.minSwaps(grid3) << endl;
}


//
// Created by ASUS on 2025/2/24.
//
