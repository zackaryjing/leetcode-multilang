// problem: https://leetcode.cn/problems/maximum-total-value-of-covered-indices/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    long long maxTotal(vector<int> &nums, string s) {
        int n = nums.size();
        vector<long long> covered(n + 1);
        vector<long long> uncover(n + 1);
        for (int i = 1; i <= n; ++i) {
            int j = i - 1;
            if (s[j] == '1') {
                covered[i] = nums[j] + max(covered[i - 1], uncover[i - 1]);
                if (j > 0) {
                    uncover[i] = uncover[i - 1] + nums[j - 1];
                }
            } else {
                uncover[i] = max(covered[i - 1], uncover[i - 1]);
                covered[i] = max(covered[i - 1], uncover[i - 1]);
            }
        }
        return max(covered[n], uncover[n]);
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxTotal(temp_vector({9, 2, 6, 1}), "0101") << " e 15" << endl;
    cout << test.maxTotal(temp_vector({5, 1, 4}), "001") << " e 4" << endl;
    cout << test.maxTotal(temp_vector({9, 3, 5}), "011") << " e 14" << endl;
}

//
// Created By jing At 2026-06-06 22:55
//
