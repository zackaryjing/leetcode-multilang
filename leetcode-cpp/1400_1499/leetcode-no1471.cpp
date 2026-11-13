// problem:  https://leetcode.cn/problems/the-k-strongest-values-in-an-array/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    vector<int> getStrongest(vector<int> &arr, int k) {
        ranges::sort(arr);
        int n = arr.size();
        int mid = arr[(n - 1) / 2];
        // cout << "mid: " << mid << endl;
        ranges::sort(arr, [&](const auto &a, const auto &b) {
            const int diff1 = abs(mid - a), diff2 = abs(mid - b);
            if (diff1 == diff2) return a > b;
            return diff1 > diff2;
        });
        // show_vector(arr);
        return {arr.begin(), arr.begin() + k};
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.getStrongest(temp_vector({1, 2, 3, 4, 5}), 2));
    show_vector(test.getStrongest(temp_vector({1, 1, 3, 5, 5}), 2));
    show_vector(test.getStrongest(temp_vector({-7, 22, 17, 3}), 2));
}

//
// Created By jing At 2026-09-10 18:58
//
