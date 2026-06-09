// problem: https://leetcode.cn/problems/longest-nice-substring/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        int mxSize = 0;
        int start = 0;
        for (int i = 0; i < n; ++i) {
            int occurs1 = 0;
            int occurs2 = 0;
            for (int j = i; j < n; ++j) {
                const char c = s[j];
                if ('a' <= c and c <= 'z') {
                    occurs1 |= 1 << (c - 'a');
                } else if ('A' <= c and c <= 'Z') {
                    occurs2 |= 1 << (c - 'A');
                }
                if (not(occurs1 ^ occurs2)) {
                    if (j - i + 1 > mxSize) {
                        mxSize = j - i + 1;
                        start = i;
                    }
                }
            }
        }
        if (mxSize == 0) return "";
        return s.substr(start, mxSize);
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.longestNiceSubstring("YazaAay") << endl;
    cout << test.longestNiceSubstring("Bb") << endl;
    cout << test.longestNiceSubstring("c") << endl;
    cout << test.longestNiceSubstring("dDzeE") << endl;
}

//
// Created By jing At 2026-06-09 19:54
//
