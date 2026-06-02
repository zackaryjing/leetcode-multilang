// problem:  https://leetcode.cn/problems/vowel-consonant-score/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int vowelConsonantScore(string s) {
        int vowel = 1 | 1 << 4 | 1 << 8 | 1 << 14 | 1 << 20;
        int vcnt = 0;
        int ccnt = 0;
        for (char c: s) {
            if (isalpha(c)) {
                if (((1 << (c - 'a')) | vowel) == vowel) {
                    vcnt++;
                } else {
                    ccnt++;
                }
            }
        }
        if (ccnt == 0) {
            return 0;
        }
        return vcnt / ccnt;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.vowelConsonantScore("cooear") << endl;
}

//
// Created By jing At 2026-06-02 15:55
//
