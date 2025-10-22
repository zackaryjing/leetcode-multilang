// problem: https://leetcode.cn/problems/height-checker/
#include <algorithm>
#include <iostream>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    int heightChecker(vector<int> &heights) {
        auto original = heights;
        ranges::sort(heights);
        int res = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (heights[i] != original[i]) {
                res++;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.heightChecker(temp_vector({5, 1, 2, 3, 4})) << endl;
    cout << test.heightChecker(temp_vector(temp_vector({1, 1, 4, 2, 1, 3}))) << endl;
}

//
// Created By jing At 2025-10-17 07:29
//
