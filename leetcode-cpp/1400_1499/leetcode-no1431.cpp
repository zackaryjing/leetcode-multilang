// problem:
// https://leetcode.cn/problems/kids-with-the-greatest-number-of-candies/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
        int mx = *ranges::max_element(candies), limit = mx - extraCandies;
        int n = candies.size();
        vector<bool> res;
        res.reserve(n);
        for (const auto candy: candies) {
            if (candy >= limit) {
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
        int mx = *ranges::max_element(candies), limit = mx - extraCandies;
        auto view = candies | views::transform([&](int candy) { return candy >= limit; });
        return {view.begin(), view.end()};
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.kidsWithCandies(temp_vector({2, 3, 5, 1, 3}), 3));
}

//
// Created By jing At 2026-05-27 17:05
//
