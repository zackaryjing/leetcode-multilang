// problem: https://leetcode.cn/problems/determine-if-two-strings-are-close/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        vector<int> cnt1(26), cnt2(26);
        for (const auto c: word1) cnt1[c - 'a']++;
        for (const auto c: word2) cnt2[c - 'a']++;
        for (int i = 0; i < 26; ++i)
            if (cnt1[i] != 0 xor cnt2[i] != 0) return false;
        ranges::sort(cnt1), ranges::sort(cnt2);
        for (int i = 0; i < 26; ++i) {
            if (cnt1[i] != cnt2[i]) return false;
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.closeStrings("abc", "bca") << endl;
}

//
// Created By ASUS At 2026-05-26 16:25
//
