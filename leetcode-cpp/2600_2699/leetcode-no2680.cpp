// problem: maximum-or
#include <iostream>
#include <memory>
#include <numeric>
#include <vector>
#include <ranges>
#include <bits/ranges_algo.h>
#include <pstl/glue_numeric_defs.h>

#include "../utils/vector_helper.h"

using namespace std;

class Solution {
    // 为了用一下 ranges 库才这么写的，emm，官解没有缩小候选项的值，直接遍历得到的，不过维护后缀或者前缀上这点是一样的
public:
    long long maximumOr(vector<int> &nums, int k) {
        int max_num = *ranges::max_element(nums);
        int base = 1 << bit_width(static_cast<unsigned>(max_num)) - 1;
        auto candidates = nums | views::filter([base](int num) { return num >= base; }) | ranges::to<vector>();
        auto non_candidates = nums | views::filter([base](int num) { return num < base; }) | ranges::to<vector>();
        long long nc = accumulate(non_candidates.begin(), non_candidates.end(), 0LL,
                                  [](int a, int b) { return a | b; });
        int valid_cnt = static_cast<int>(candidates.size());
        vector<int> right;
        right.reserve(valid_cnt);
        int cur = 0;
        for (const auto num: candidates | views::reverse) {
            cur |= num;
            right.push_back(cur);
        }
        long long left_part = 0;
        long long ans = 0;
        auto right_part = ++right.rbegin();
        for (auto num: candidates) {
            ans = max(
                ans, left_part | static_cast<long long>(num) << k | (right_part != right.rend()
                                                                         ? *right_part
                                                                         : 0) | nc);
            left_part |= num;
            ++right_part;
        }
        return ans;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maximumOr(*make_unique<vector<int> >(vector{12, 9}), 1) << endl;
    cout << test.maximumOr(*make_unique<vector<int> >(vector{8, 1, 2}), 2) << endl;
}


//
// Created by ASUS on 2025/3/21.
//
