// problem: https://leetcode.cn/problems/search-suggestions-system/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <queue>
#include <ranges>
#include <set>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord) {
        set words(products.begin(), products.end());
        int n = searchWord.size();
        vector<vector<string>> res;
        for (int i = 1; i <= n; ++i) {
            string prefix = searchWord.substr(0, i);
            erase_if(words, [&prefix](string word) { return not word.starts_with(prefix); });
            vector<string> temp;
            auto start = words.begin();
            for (int j = 0; j < min(3, static_cast<int>(words.size())); ++j) {
                temp.push_back(*start++);
            }
            res.push_back(temp);
        }
        return res;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    show_matrix(test.suggestedProducts(temp_vector({"mobile", "mouse", "moneypot", "monitor", "mousepad"}), "mouse"));
}

//
// Created By jing At 2026-05-05 16:25
//
