// problem:
// https://leetcode.cn/problems/minimum-deletions-to-make-string-balanced/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> bcnts(n);
        int bcnt = 0;
        int res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'b') {
                bcnt++;
            }
            bcnts[i] = bcnt;
        }
        res = min(n - bcnt, res);
        int acnt = 0;
        for (int j = n - 1; j >= 0; --j) {
            res = min(res, bcnts[j] + acnt);
            if (s[j] == 'a') {
                acnt++;
            }
        }
        return res;
    }
};


class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(), bcnt = 0, cnt = 0;
        for (const char c: s) bcnt += c - 'a';
        const int acnt = n - bcnt;
        int res = min(bcnt, acnt);
        if (res == 0) return 0;
        for (int i = 0; i < n; ++i) {
            res = min(res, acnt - i + (cnt << 1));
            cnt += s[i] - 'a';
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minimumDeletions("aababbab") << endl;
    cout << test.minimumDeletions("a") << endl;
}

//
// Created By ASUS At 2026-05-26 16:05
//
