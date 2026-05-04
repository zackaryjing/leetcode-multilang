// problem: https://leetcode.cn/problems/largest-3-same-digit-number-in-string/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        char last1 = ' ', last2 = ' ';
        int res = -1;
        for (const auto c: num) {
            if (c == last1 and c == last2) {
                res = max((c - '0') * 111, res);
            }
            last2 = last1;
            last1 = c;
        }
        return res >= 0 ? (res == 0 ? "000" : std::to_string(res)) : "";
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.largestGoodInteger("6777133339") << endl;
}

//
// Created By jing At 2026-05-04 20:47
//
