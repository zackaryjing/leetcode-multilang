// problem:
// https://leetcode.cn/problems/minimum-time-to-type-word-using-special-typewriter/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int minTimeToType(string word) {
        int res = 0;
        char cur = 'a';
        for (const char c: word) {
            res += min((c - cur + 26) % 26, (cur - c + 26) % 26) + 1;
            cur = c;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minTimeToType("abc") << endl;
    cout << test.minTimeToType("bza") << endl;
}

//
// Created By ASUS At 2026-04-21 21:27
//
