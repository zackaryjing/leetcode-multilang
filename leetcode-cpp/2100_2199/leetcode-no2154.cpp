// problem: https://leetcode.cn/problems/keep-multiplying-found-values-by-two/
#include <iostream>
#include <unordered_set>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    int findFinalValue(vector<int> &nums, int original) {
        auto numset = unordered_set(nums.begin(), nums.end());
        for (int i = 0; i < 11; ++i) {
            if (numset.contains(original)) {
                original *= 2;
            } else {
                break;
            }
        }
        return original;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.findFinalValue(temp_vector({5, 3, 6, 1, 12}), 3) << endl;
    cout << test.findFinalValue(temp_vector({5, 3, 6, 1, 12}), 4) << endl;
}

//
// Created By jing At 2025-09-30 17:48
//
