// problem: https://leetcode.cn/problems/string-matching-in-an-array/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string> &words) {
        ranges::sort(words, [](const auto &a, const auto &b) { return a.size() < b.size(); });
        int n = words.size();
        vector<string> res;
        for (int i = 0; i < n; ++i) {
            auto word1 = words[i];
            for (int j = i + 1; j < n; ++j) {
                if (words[j].find(word1) != string::npos) {
                    res.push_back(word1);
                    break;
                }
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.stringMatching(temp_vector({"mass", "as", "hero", "superhero"})));
}

//
// Created By ASUS At 2026-05-26 15:56
//
