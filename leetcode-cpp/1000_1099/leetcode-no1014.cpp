// problem: https://leetcode.cn/problems/best-sightseeing-pair/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    int maxScoreSightseeingPair(vector<int> &values) {
        int n = values.size();
        int mx1 = 0;
        auto nv = values;
        nv[n - 1] -= n - 1;
        for (int j = n - 2; j >= 0; --j) {
            nv[j] = max(nv[j] - j, nv[j + 1]);
        }
        int res = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (values[i] + i >= mx1) {
                res = max(res, values[i] + i + nv[i + 1]);
            }
        }
        return res;
    }
};


class Solution {
public:
    int maxScoreSightseeingPair(vector<int> &values) {
        const int n = values.size();
        int res = 0;
        values[n - 1] -= n - 1;
        for (int j = n - 2; j >= 0; --j) {
            int &a = values[j];
            const int b = values[j + 1];
            res = max(res, a + j + b);
            a = max(a - j, b);
        }
        return res;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxScoreSightseeingPair(temp_vector({8, 1, 5, 2, 6})) << endl;
}

//
// Created By jing At 2026-05-22 00:42
//
