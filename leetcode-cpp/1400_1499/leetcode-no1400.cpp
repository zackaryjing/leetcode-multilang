// problem: https://leetcode.cn/problems/construct-k-palindrome-strings/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size()) {
            return false;
        }
        vector<int> cnts(26);
        for (const auto &c: s) {
            cnts[c - 'a']++;
        }
        int oddCnt = 0, evenCnt = 0;
        for (int cnt: cnts) {
            if ((cnt & 1) == 1) oddCnt++;
        }
        evenCnt = s.size() - oddCnt;
        return oddCnt <= k and oddCnt + evenCnt >= k;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.canConstruct("annabele", 2) << endl;
    cout << test.canConstruct("leetcode", 3) << endl;
    cout << test.canConstruct("true", 4) << endl;
    cout << test.canConstruct("yzyzyzyzyzyzyzy", 2) << endl;
    cout << test.canConstruct("aaa", 2) << endl;
}

//
// Created By jing At 2026-05-18 16:12
//
