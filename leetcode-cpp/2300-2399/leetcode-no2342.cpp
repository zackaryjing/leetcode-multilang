// problem:
// https://leetcode.cn/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int maximumSum(vector<int> &nums) {
        vector<pair<int, int>> ps(100);
        int res = -1;
        for (int num: nums) {
            int pos = 0,copy = num;
            while (num > 0) {
                pos += num % 10;
                num /= 10;
            }
            auto &item = ps[pos];
            // cout << "pos: " << pos << endl;
            if (copy >= item.first) {
                item.second = item.first;
                item.first = copy;
            } else if (copy > item.second) {
                item.second = copy;
            }
            if (item.second) {
                res = max(res, item.second + item.first);
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maximumSum(temp_vector({18, 43, 36, 13, 7})) << endl;
    cout << test.maximumSum(temp_vector({10, 12, 19, 14})) << endl;
}

//
// Created By ASUS At 2026-06-10 22:01
//
