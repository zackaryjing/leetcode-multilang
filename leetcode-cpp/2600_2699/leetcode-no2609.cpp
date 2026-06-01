// problem:
// https://leetcode.cn/problems/find-the-longest-balanced-substring-of-a-binary-string/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int res = 0, index = 0, n = s.size();
        while (index < n) {
            int zcnt = 0, ocnt = 0;
            char c = s[index];
            while (c == '0') {
                zcnt++;
                index++;
                c = s[index];
            }
            while (c == '1') {
                ocnt++;
                index++;
                c = s[index];
            }
            res = max(res,min(zcnt, ocnt));
        }
        return res * 2;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.findTheLongestBalancedSubstring("01000111") << endl;
}

//
// Created By jing At 2026-05-31 17:52
//
