// problem:
// https://leetcode.cn/problems/ways-to-split-array-into-three-subarrays/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int waysToSplit(vector<int> &nums) {
        int n = nums.size();
        int tot = 0;
        for (int i = 0; i < n; ++i) tot += nums[i];
        int lb = 1, ub = 1, r = 2;
        int rSum = tot - nums[0] - nums[1], uSum = nums[1], lSum = nums[1];
        const long long mod = 1000000007;
        long long res = 0LL;
        for (; r < n; ++r) {
            for (; lb < r - 1; ++lb) { // maximum middle part
                if (lSum <= rSum) break; // reduce lsum to less than rSum
                lSum -= nums[lb];
            }
            for (; ub < r - 1; ++ub) {
                int tuSum = uSum - nums[ub]; // minium middle part
                if (tuSum < (tot - tuSum - rSum)) break; // reduce uSum to roughly smaller to rSum
                uSum = tuSum;
            }
            if (ub == lb) {
                if (rSum >= uSum and uSum >= (tot - rSum - uSum)) {
                    res = (res + 1) % mod;
                }
            } else if (ub > lb) {
                res = (res + ub - lb + 1) % mod;
            }
            rSum -= nums[r];
            uSum += nums[r];
            lSum += nums[r];
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.waysToSplit(temp_vector({1, 1, 1})) << endl;
    cout << test.waysToSplit(temp_vector({1, 2, 2, 2, 5, 0})) << endl;
    cout << test.waysToSplit(temp_vector({3, 2, 1})) << endl;
    cout << test.waysToSplit(temp_vector({7, 0, 5})) << endl;
}

//
// Created By jing At 2026-06-04 16:23
//
