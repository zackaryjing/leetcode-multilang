// problem: https://leetcode.cn/problems/determine-the-minimum-sum-of-a-k-avoiding-array/
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumSum(int n, int k) {
        int half = k / 2;
        int ans = 0;
        for (int i = 1; i <= min(half, n); i++) {
            ans += i;
            // cout << i << endl;
        }
        for (int j = half; j < n; j++) {
            ans += k;
            // cout << k << endl;
            k++;
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minimumSum(5, 4) << endl;
    cout << test.minimumSum(2, 6) << endl;
}

//
// Created by ASUS on 2025/3/26.
//
