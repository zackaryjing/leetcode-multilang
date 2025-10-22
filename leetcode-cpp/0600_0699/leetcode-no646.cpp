// problem: https://leetcode.cn/problems/maximum-length-of-pair-chain/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>> &pairs) {
        ranges::sort(pairs, [](const vector<int> &a, const vector<int> &b) {
            return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
        });
        const int n = static_cast<int>(pairs.size());
        vector<int> cnts(n);
        cnts[0] = 1;
        int lessIndex = 0;
        for (int i = 1; i < n; ++i) {
            const int curStart = pairs[i][0];
            int temp = lessIndex;
            while (temp < n and pairs[temp][1] < curStart) {
                lessIndex = temp;
                temp += 1;
            }
            if (pairs[lessIndex][1] < curStart) {
                cnts[i] = cnts[lessIndex] + 1;
            } else {
                cnts[i] = cnts[i - 1];
            }
        }
        return cnts[n - 1];
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    // cout << test.findLongestChain(temp_vector({{1, 2}, {2, 3}, {3, 4}})) << endl;
    // cout << test.findLongestChain(temp_vector({{1, 2}, {7, 8}, {4, 5}})) << endl;
    // cout << test.findLongestChain(temp_vector({{2, 5}, {1, 2}, {7, 8}, {4, 5}})) << endl;
    cout << test.findLongestChain(
                    temp_vector({{-10, -8}, {8, 9}, {-5, 0}, {6, 10}, {-6, -4}, {1, 7}, {9, 10}, {-4, 7}}))
         << endl;
}

//
// Created By jing At 2025-10-22 14:56
//
