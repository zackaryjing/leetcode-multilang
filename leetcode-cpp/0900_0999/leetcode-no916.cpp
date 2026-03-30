// problem: https://leetcode.cn/problems/word-subsets/?envType=problem-list-v2&envId=OOhHf3Bc
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
        unsigned char standard[26] = {};
        for (const auto &word: words2) {
            unsigned char cnt[26] = {};
            for (const char j: word) {
                cnt[j - 'a']++;
            }
            for (int k = 0; k < 26; ++k) {
                standard[k] = max(standard[k], cnt[k]);
            }
        }
        vector<string> res;
        for (const auto &word: words1) {
            unsigned char cnt[26] = {};
            for (const char j: word) {
                cnt[j - 'a']++;
            }
            bool valid = true;
            for (int k = 0; k < 26; ++k) {
                if (standard[k] > cnt[k]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                res.push_back(word);
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.wordSubsets(temp_vector({"amazon", "apple", "facebook", "google", "leetcode"}),
                                 temp_vector({"a", "e"})));
}

//
// Created By ASUS At 2026-02-08 16:48
//
