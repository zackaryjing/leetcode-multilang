// problem:
// https://leetcode.cn/problems/largest-substring-between-two-equal-characters/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector firstPos(26, -1);
        int res = -1;
        for (int i = 0; i < s.size(); ++i) {
            const int c = s[i] - 'a';
            if (firstPos[c] < 0) {
                firstPos[c] = i;
            } else {
                res = max(res, i - firstPos[c] - 1);
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxLengthBetweenEqualCharacters("aa") << endl;
    cout << test.maxLengthBetweenEqualCharacters("czab") << endl;
    cout << test.maxLengthBetweenEqualCharacters("cabbac") << endl;
}

//
// Created By jing At 2026-05-17 00:18
//
