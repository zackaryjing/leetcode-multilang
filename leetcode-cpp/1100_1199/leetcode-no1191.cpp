// problem: https://leetcode.cn/problems/k-concatenation-maximum-sum/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    int kConcatenationMaxSum(vector<int> &arr, int k) {
        int n = arr.size();
        int mn = 0, mx = 0, preSum = 0, surSum = 0;
        int preMax = 0, surMax = 0;
        for (int i = 0; i < n; ++i) {
            preSum += arr[i];
            preMax = max(preMax, preSum);
            mx = max(mx, preSum - mn);
            mn = min(mn, preSum);
        }
        int64_t sum = preSum;
        for (int j = n - 1; j >= 0; --j) {
            surSum += arr[j];
            surMax = max(surMax, surSum);
        }
        return max(mx,
                   k > 1 ? max(static_cast<int>((sum * (k - 2) + preMax + surMax) % 1000000007), surMax + preMax) : 0) %
               1000000007;
    }
};


class Solution {
public:
    int kConcatenationMaxSum(vector<int> &arr, int k) {
        int64_t n = arr.size(), mn = 0, mx = 0, preSum = 0, surSum = 0, preMax = 0, surMax = 0;
        for (int i = 0; i < n; ++i) {
            preSum += arr[i];
            surSum += arr[n - 1 - i];
            preMax = max(preMax, preSum);
            surMax = max(surMax, surSum);
            mx = max(mx, preSum - mn);
            mn = min(mn, preSum);
        }
        return max(mx, k > 1 ? max((surSum * (k - 2) + preMax + surMax), surMax + preMax) : 0) % 1000000007;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.kConcatenationMaxSum(temp_vector({-9, 13, 4, -16, -12, -16, 3, -7, 5, -16, 16, 8, -1, -13, 15, 3}), 6)
         << endl;
    // cout << test.kConcatenationMaxSum(temp_vector({1, 2}), 3) << endl;
    // cout << test.kConcatenationMaxSum(temp_vector({1, -2, 1}), 5) << endl;
    // cout << test.kConcatenationMaxSum(temp_vector({-1, -2}), 7) << endl;
}

//
// Created By jing At 2026-05-22 22:42
//
