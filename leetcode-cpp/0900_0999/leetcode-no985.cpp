// problem: https://leetcode.cn/problems/sum-of-even-numbers-after-queries/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <c++/13/numeric>
#include <iostream>
#include <ranges>
#include <vector>

#include "../utils/vector_helper.h"


using namespace std;


class Solution3 {
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            sum += nums[i] % 2 == 0 ? nums[i] : 0;
        }
        vector<int> res;
        res.reserve(queries.size());
        for (const auto &query: queries) {
            const int val = query[0], index = query[1];
            auto &num = nums[index];
            num += val;
            if (not(num & 1))
                sum += val & 1 ? num : val;
            else if (val & 1)
                sum -= (num - val);
            res.push_back(sum);
        }
        return res;
    }
};


class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries) {
        auto sum = ranges::fold_left(nums | views::filter([](const auto &p) { return p % 2 == 0; }), 0, plus{});
        return queries | views::transform([&nums, &sum](const auto &query) -> int {
                   const int val = query[0], index = query[1];
                   auto &num = nums[index];
                   num += val;
                   if (not(num & 1))
                       sum += val & 1 ? num : val;
                   else if (val & 1)
                       sum -= (num - val);
                   return sum;
               }) |
               ranges::to<vector>();
    }
};

class Solution2 {
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries) {
        vector<int> res;
        res.reserve(queries.size());
        auto sum = ranges::fold_left(nums | views::filter([](const auto &p) { return p % 2 == 0; }), 0, plus{});
        for (auto query: queries) {
            auto &num = nums[query[1]];
            if ((num + query[0]) % 2 == 0) {
                if (num % 2 == 0) {
                    sum += query[0];
                } else {
                    sum += num + query[0];
                }
            } else if (num % 2 == 0) {
                sum -= num;
            }
            num += query[0];
            res.push_back(sum);
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
}

//
// Created By jing At 2026-05-28 20:32
//
