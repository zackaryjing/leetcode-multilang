// problem: https://leetcode.cn/problems/max-dot-product-of-two-subsequences/
#include <chrono>
#include <iostream>
#include <vector>
#include "../utils/vector_helper.h"
using namespace std;


// time spent 52:05
class Solution {
public:
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector lastMax = vector(2, vector(n, 0));
        lastMax[0][0] = {nums1[0] * nums2[0]};
        for (int j = 1; j < n; j++) {
            lastMax[0][j] = max(lastMax[0][j - 1], nums1[j] * nums2[0]);
        }
        for (int i = 1; i < m; i++) {
            vector<int> &cur = lastMax[i & 1];
            vector<int> &last = lastMax[!(i & 1)];
            cur[0] = max(nums1[0] * nums2[i], last[0]);
            for (int j = 1; j < n; j++) {
                cur[j] = max({last[j], nums1[j] * nums2[i], last[j - 1] + nums1[j] * nums2[i], cur[j - 1]});
            }
        }
        return lastMax[((m - 1) % 2)][n - 1];
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxDotProduct(temp_vector({2, 1, -2, 5}), temp_vector({3, 0, -6})) << endl;
    cout << test.maxDotProduct(temp_vector({3, -2}), temp_vector({2, -6, 7})) << endl;
    cout << test.maxDotProduct(temp_vector({-1, -1}), temp_vector({1, 1})) << endl;
    cout << test.maxDotProduct(temp_vector({-5, -1, -2}), temp_vector({3, 3, 5, 5})) << endl;
}

//
// Created By Zackary At 2025-06-06 20:04:42
//
