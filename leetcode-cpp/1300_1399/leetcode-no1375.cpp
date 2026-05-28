// problem: https://leetcode.cn/problems/number-of-times-binary-string-is-prefix-aligned/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int numTimesAllBlue(vector<int> &flips) {
        int n = flips.size(), mx = 0, res = 0;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, flips[i]);
            if (mx == i + 1) {
                res++;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.numTimesAllBlue(temp_vector({3,2,4,1,5})) << endl;
}

//
// Created By jing At 2026-05-25 16:32
//
