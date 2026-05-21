// problem: https://leetcode.cn/problems/minimum-remove-to-make-valid-parentheses/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        const int n = s.size();
        int lcnt = 0, rcnt = 0, ecnt = 0, pos = 0;
        for (int i = 0; i < n; ++i)
            if (s[i] == '(')
                lcnt++;
            else if (s[i] == ')') {
                if (lcnt == 0)
                    s[i] = '_', ecnt++;
                else
                    lcnt--;
            }
        for (int j = n - 1; j >= 0; --j)
            if (s[j] == ')')
                rcnt++;
            else if (s[j] == '(') {
                if (rcnt == 0)
                    s[j] = '_', ecnt++;
                else
                    rcnt--;
            }
        string res(n - ecnt, ' ');
        for (int i = 0; i < n; ++i)
            if (s[i] != '_') res[pos++] = s[i];
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minRemoveToMakeValid("lee(t(c)o)de)") << endl;
    cout << test.minRemoveToMakeValid("a)b(c)d") << endl;
    cout << test.minRemoveToMakeValid("))((") << endl;
}

//
// Created By ASUS At 2026-05-22 04:20
//
