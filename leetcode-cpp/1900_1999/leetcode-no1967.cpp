// problem:
// https://leetcode.cn/problems/number-of-strings-that-appear-as-substrings-in-word/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int numOfStrings(vector<string> &patterns, string word) {
        int n = word.size();
        int cnt = 0;
        for (const auto p: patterns) {
            auto pattern = string_view(p);
            int s = p.size();
            for (int i = 0; i <= n - s; ++i) {
                if (string_view(word.data() + i, s) == pattern) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.numOfStrings(temp_vector({"a", "b", "c"}), "aaaaabbbbb") << endl;
    cout << test.numOfStrings(temp_vector({"a","abc","bc","d"}) , "abc") << endl;
}

//
// Created By ASUS At 2026-04-21 21:37
//
