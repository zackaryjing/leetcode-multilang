// problem: https://leetcode.cn/contest/weekly-contest-503/problems/password-strength/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_set>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> pass(password.begin(), password.end());
        int res = 0;
        for (const auto &c: pass) {
            if ('a' <= c and c <= 'z') {
                res += 1;
            } else if ('A' <= c and c <= 'Z') {
                res += 2;
            } else if ('0' <= c and c <= '9') {
                res += 3;
            } else if (c == '!' or c == '@' or c == '#' or c == '$') {
                res += 5;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.passwordStrength("aA1!") << endl;
    cout << test.passwordStrength("bbB11#") << endl;
}

//
// Created By ASUS At 2026-05-24 10:42
//
