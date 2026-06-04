// problem:
// https://leetcode.cn/problems/compare-strings-by-frequency-of-the-smallest-character/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words) {
        const auto func = [](string s) {
            int cnt = 0;
            char mn = 127;
            for (const char c: s)
                if (c < mn)
                    mn = c, cnt = 1;
                 else if (c == mn)
                    cnt++;
            return cnt;
        };
        vector<int> allCnts;
        allCnts.reserve(words.size());
        for (const auto& word: words)
            allCnts.push_back(func(word));
        ranges::sort(allCnts);
        vector<int> res;
        const int n = queries.size();
        res.reserve(n);
        for (const auto& query: queries) {
            int target = func(query);
            res.push_back(allCnts.end() - ranges::upper_bound(allCnts, target));
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.numSmallerByFrequency(temp_vector({"cbd"}), temp_vector({"zaaaz"})));
}

//
// Created By jing At 2026-06-03 15:41
//
