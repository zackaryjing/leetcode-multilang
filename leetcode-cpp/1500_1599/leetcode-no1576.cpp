// problem:
// https://leetcode.cn/problems/replace-all-s-to-avoid-consecutive-repeating-characters/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

// real garbage, tired

class Solution {
public:
    string modifyString(string s) {
        const auto next = [](char c) -> char { return ((c + 1) - 'a') % 26 + 'a'; };
        int n = s.size();
        for (int i = 0; i < s.size(); ++i) {
            auto &c = s[i];
            char forbiden1 = i > 0 ? s[i - 1] : ' ', forbiden2 = i < n - 1 ? s[i + 1] : ' ';
            if (c == '?') {
                char goal = 'a';
                if (isalpha(forbiden1)) {
                    if (goal == forbiden1) {
                        goal = next(goal);
                    }
                }
                if (isalpha(forbiden2)) {
                    if (goal == forbiden2) {
                        goal = next(goal);
                    }
                }
                if (isalpha(forbiden1)) {
                    if (goal == forbiden1) {
                        goal = next(goal);
                    }
                }
                c = goal;
            }
        }
        return s;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.modifyString("?zs") << endl;
    cout << test.modifyString("ubv?w") << endl;
    cout << test.modifyString("?????") << endl;
    cout << test.modifyString("b?a") << endl;
}

//
// Created By ASUS At 2026-04-08 15:59
//
