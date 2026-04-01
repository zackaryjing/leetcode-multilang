// problem: https://leetcode.cn/problems/maximum-nesting-depth-of-the-parentheses/description/
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;


class Solution {
public:
    int maxDepth(string s) {
        int left = 0,res = 0;
        for (int i = 0;i < s.length();++i) {
            if (s[i] == '(') {
                left++;
            } else if (s[i] == ')') {
                left--;
            }
            res = max(res, left);
        }
        return res;
    }
};


int main() {
    Solution s;
    cout << s.maxDepth("()") << endl;
}

//
// Created By jing At 2026-04-01 23:22
//