// problem:
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    vector<int> decompressRLElist(vector<int> &nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i += 2) {
            for (int j = 0; j < nums[i]; ++j) {
                res.push_back(nums[i + 1]);
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.decompressRLElist(temp_vector({1, 2, 3, 4})));
}

//
// Created By ASUS At 2025-12-19 15:18
//
