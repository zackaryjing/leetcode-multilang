// problem: https://leetcode.cn/problems/find-the-maximum-length-of-a-good-subsequence-i/
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include "../utils/vector_helper.h"
using namespace std;

class Solution {
    // [Offical] if having chances, please [redo].
public:
    int maximumLength(vector<int> &nums, int k) {
        unordered_map<int, vector<int>> fs;
        vector<array<int, 3>> records(k + 1);
        for (auto num: nums) {
            auto &f = fs[num];
            f.resize(k + 1);
            for (int j = k; j >= 0; --j) {
                f[j]++;
                if (j) {
                    auto r = records[j - 1];
                    f[j] = max(f[j], (num == r[2] ? r[1] : r[0]) + 1);
                }

                const int v = f[j];
                if (auto &p = records[j]; v > p[0]) {
                    if (num != p[2]) {
                        p[2] = num;
                        p[1] = p[0];
                    }
                    p[0] = v;
                } else if (num != p[2] and v > p[1]) {
                    p[1] = v;
                }
            }
        }
        return records[k][0];
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maximumLength(temp_vector({1, 2, 1, 1, 3}), 2) << endl;
    cout << test.maximumLength(temp_vector({1, 2, 3, 4, 5, 1}), 0) << endl;
}

//
// Created By Zackary At 2025-06-12 21:38:34
//
