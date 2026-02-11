// problem: https://leetcode.cn/problems/minimum-insertions-to-balance-a-parentheses-string/?envType=problem-list-v2&envId=OOhHf3Bc
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int balance = 0, i = 0, res = 0;
        while (i < s.length()) {
            const char c = s[i];
            if (c == '(') {
                balance++;
            } else if (c == ')') {
                balance--;
                if (i < s.length() - 1 && s[i + 1] == ')') {
                    i++;
                } else {
                    res++;
                }
                if (balance < 0) {
                    res++;
                    balance++;
                }
            }
            i++;
        }
        return res + balance * 2;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minInsertions("(()))") << endl;
    cout << test.minInsertions("())") << endl;
    cout << test.minInsertions("))())(") << endl;
    cout << test.minInsertions("))())(") << endl;
    cout << string(20, '-') << endl;
}

//
// Created By ASUS At 2026-02-09 14:10
//
