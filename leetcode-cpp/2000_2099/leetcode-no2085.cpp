// problem: https://leetcode.cn/problems/count-common-words-with-one-occurrence/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int countWords(vector<string> &words1, vector<string> &words2) {
        pmr::unordered_map<string, pair<int, int>> cnts;
        for (auto word: words1) {
            cnts[word].first++;
        }
        for (auto word: words2) {
            cnts[word].second++;
        }
        int res = 0;
        for (auto &[k, v]: cnts) {
            if (v.first == v.second and v.first == 1) {
                res++;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.countWords(temp_vector({"leetcode", "is", "amazing", "as", "is"}),
                            temp_vector({"amazing", "leetcode", "is"}))
         << endl;
}

//
// Created By ASUS At 2026-05-08 18:12
//
