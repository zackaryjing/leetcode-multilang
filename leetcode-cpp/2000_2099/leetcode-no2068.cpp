// problem:
// https://leetcode.cn/problems/check-whether-two-strings-are-almost-equivalent/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> cnt1(26), cnt2(26);
        for (const auto c: word1) {
            cnt1[c - 'a']++;
        }
        for (const auto c: word2) {
            cnt2[c - 'a']++;
        }
        for (int i = 0; i < 26; ++i) {
            if (abs(cnt1[i] - cnt2[i]) > 3) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.checkAlmostEquivalent("aaaa", "bccb") << endl;
}

//
// Created By jing At 2026-04-29 23:35
//
