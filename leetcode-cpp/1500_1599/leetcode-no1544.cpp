// problem: https://leetcode.cn/problems/make-the-string-great/
#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        vector<int> nxt(n), last(n);
        std::iota(nxt.begin(), nxt.end(), 1);
        std::iota(last.begin(), last.end(), -1);
        int cur = 0, length = n, begin = 0;
        while (cur < n - 1) {
            int a = cur, b = nxt[cur];
            if (s[a] != s[b] and tolower(s[a]) == tolower(s[b])) {
                int prev = last[a];
                int next = nxt[b];
                if (prev >= 0) {
                    nxt[prev] = next;
                    cur = prev;
                } else {
                    cur = next;
                    begin = next;
                }
                if (next < n) {
                    last[next] = prev;
                }
                length -= 2;
            } else {
                cur = nxt[cur];
            }
        }
        if (length == 0) return "";
        string res(length, ' ');
        int c = begin;
        for (int i = 0; i < length; ++i) {
            res[i] = s[c];
            c = nxt[c];
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.makeGood("leEeetcode") << endl;
    cout << test.makeGood("abBAcC") << endl;
}

//
// Created By ASUS At 2026-04-23 15:59
//
