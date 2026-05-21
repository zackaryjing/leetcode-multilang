// problem: https://leetcode.cn/problems/find-the-difference-of-two-arrays/description/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_set>
#include <vector>

#include "../utils/vector_helper.h"


using namespace std;


template<typename T>
unordered_set<T> operator-(const unordered_set<T> &a, const unordered_set<T> &b) {
    unordered_set<T> res;
    for (const auto item: a) {
        if (not b.contains(item)) {
            res.insert(item);
        }
    }
    return res;
}
class Solution2 {
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
        vector<vector<int>> res;
        unordered_set n1(nums1.begin(), nums1.end()), n2(nums2.begin(), nums2.end()), a = n1 - n2, b = n2 - n1;
        return {{a.begin(), a.end()}, {b.begin(), b.end()}};
    }
};


class Solution {
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
        const unordered_set n1(nums1.begin(), nums1.end()), n2(nums2.begin(), nums2.end());
        vector<vector<int>> res(2);
        res[0].reserve(1000);
        res[1].reserve(1000);
        for (int num: n1)
            if (not n2.contains(num)) res[0].push_back(num);
        for (int num: n2)
            if (not n1.contains(num)) res[1].push_back(num);
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
}

//
// Created By jing At 2026-05-21 23:36
//
