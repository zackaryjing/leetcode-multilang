// problem: https://leetcode.cn/problems/check-if-two-string-arrays-are-equivalent/description/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2) {
        int i1 = 0, i2 = 0, j2 = 0;
        for (; i1 < word1.size(); ++i1) {
            for (int j1 = 0; j1 < word1[i1].size(); ++j1) {
                if (i2 == word2.size() or word1[i1][j1] != word2[i2][j2]) {
                    return false;
                }
                j2++;
                if (j2 == word2[i2].size()) {
                    j2 = 0;
                    i2++;
                }
            }
        }
        if (i2 == word2.size()) {
            return true;
        }
        return false;
    }
};


int main() {
    Solution s;
    vector<string> test1 = {"a", "bcd"};
    vector<string> test2 = {"ab", "c"};
    auto res = s.arrayStringsAreEqual(test1, test2);
    cout << res << endl;
}

//
// Created By jing At 2026-04-01 23:31
//
