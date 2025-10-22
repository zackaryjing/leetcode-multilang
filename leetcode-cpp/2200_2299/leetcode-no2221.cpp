// problem: https://leetcode.cn/problems/find-triangular-sum-of-an-array/?envType=daily-question&envId=2025-09-30
#include <iostream>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    int triangularSum(vector<int> &nums) {
        const int n = nums.size();
        vector<int> combine(n);
        combine[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j >= 1; --j) {
                combine[j] = (combine[j] + combine[j - 1]) % 10;
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += nums[i] * combine[i] % 10;
        }
        return res % 10;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.triangularSum(temp_vector({5})) << endl;
    cout << test.triangularSum(temp_vector({1, 2, 3, 4, 5})) << endl;
}

//
// Created By jing At 2025-09-30 17:57
//
