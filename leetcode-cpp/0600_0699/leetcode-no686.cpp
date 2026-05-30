// problem: https://leetcode.cn/problems/repeated-string-match/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        const int sb = b.size(), sa = a.size();
        int cnt = (sb + sa) / sa + 1;
        string na;
        na.reserve(cnt * sa);
        for (int i = 0; i < cnt; ++i) {
            na.append(a);
        }
        auto pos = na.find(b);
        if (pos == string::npos) return -1;
        return (sb + pos + sa - 1) / sa;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.repeatedStringMatch("abcd", "cdabcdab") << endl;
    cout << test.repeatedStringMatch("a", "aa") << endl;
    cout << test.repeatedStringMatch("abc", "wxyz") << endl;
}

//
// Created By jing At 2026-05-30 17:13
//
