// problem: https://leetcode.cn/problems/find-and-replace-pattern/?envType=problem-list-v2&envId=3rBpGyas
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
        vector<string> res;
        for (auto word: words) {
            if (word.size() != pattern.size()) {
                continue;
            }
            int n = word.size();
            vector<char> dict(26, 0);
            vector<bool> used(26);
            auto valid = true;
            for (int i = 0; i < n; ++i) {
                auto pos = pattern[i] - 'a';
                if (dict[pos] != 0) {
                    if (dict[pos] != word[i]) {
                        valid = false;
                        break;
                    }
                } else {
                    if (used[word[i] - 'a']) {
                        valid = false;
                        break;
                    }
                    dict[pos] = word[i];
                    used[word[i] - 'a'] = true;
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
    show_vector(test.findAndReplacePattern(temp_vector({"abc", "deq", "mee", "aqq", "dkd", "ccc"}), "abb"));
}

//
// Created By ASUS At 2025-12-19 14:52
//
