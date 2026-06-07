// problem:
// https://leetcode.cn/problems/count-the-number-of-vowel-strings-in-range/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int vowelStrings(vector<string> &words, int left, int right) {
        int vowel = 1 | 1 << 4 | 1 << 8 | 1 << 14 | 1 << 20;
        int res = 0;
        for (int i = left; i <= right; ++i) {
            const auto& word = words[i];
            if (((1 << (word[0] - 'a')) | vowel) == vowel and
                ((1 << (word.back() - 'a')) | vowel) == vowel) {
                res++;
            }
        }
        return res;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.vowelStrings(temp_vector({"are", "amy", "u"}), 0, 2) << endl;
}


//
// Created By jing At 2026-05-31 19:39
//
