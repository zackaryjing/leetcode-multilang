// problem:
// https://leetcode.cn/problems/check-if-number-has-equal-digit-count-and-digit-value/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    bool digitCount(string num) {
        auto cnts = vector<int>(10);
        auto occ = vector<int>(10);
        for (int i = 0; i < num.size(); ++i) {
            cnts[i] = num[i] - '0';
            occ[num[i] - '0']++;
        }
        for (int i = 0; i < 10; ++i) {
            if (cnts[i] != occ[i]) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.digitCount("1210") << endl;
}

//
// Created By jing At 2026-05-04 20:53
//
