// problem:
// https://leetcode.cn/problems/maximum-number-of-vowels-in-a-substring-of-given-length/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int vowel = 1 | 1 << 4 | 1 << 8 | 1 << 14 | 1 << 20;
        int cnt = 0, res = 0;
        for (int i = 0; i < k; ++i)
            if ((1 << (s[i] - 'a')) & vowel) cnt++;
        res = cnt;
        for (int i = k; i < s.size(); ++i) {
            if ((1 << (s[i] - 'a')) & vowel) cnt++;
            if ((1 << (s[i - k] - 'a')) & vowel) cnt--;
            res = max(res, cnt);
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxVowels("abciiidef", 3) << endl;
    cout << test.maxVowels("aeiou", 2) << endl;
}

//
// Created By jing At 2026-09-10 18:52
//
