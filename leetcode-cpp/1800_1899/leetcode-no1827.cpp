// problem:
// https://leetcode.cn/problems/minimum-operations-to-make-the-array-increasing/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums) {
        int res = 0, mx = 0;
        for (int num: nums) {
            res += max(0, mx + 1 - num);
            mx = max(mx + 1, num);
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minOperations(temp_vector({1, 1, 1})) << endl;
    cout << test.minOperations(temp_vector({1, 5, 2, 4, 1})) << endl;
}

//
// Created By jing At 20:03
//
