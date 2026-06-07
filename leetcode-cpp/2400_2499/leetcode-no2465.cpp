// problem: https://leetcode.cn/problems/number-of-distinct-averages/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_set>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int distinctAverages(vector<int> &nums) {
        ranges::sort(nums);
        unordered_set<int> cnts;
        int n = nums.size();
        for (int i = 0; i < n / 2; ++i) {
            cnts.insert(nums[i] + nums[n - i - 1]);
        }
        return cnts.size();
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.distinctAverages(temp_vector({4, 1, 4, 0, 3, 5})) << endl;
    cout << test.distinctAverages(temp_vector({1, 100})) << endl;
}

//
// Created By jing At 18:18
//
