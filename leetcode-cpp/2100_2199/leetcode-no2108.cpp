// problem:
// https://leetcode.cn/problems/find-first-palindromic-string-in-the-array/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string> &words) {
        const auto check = [](string word) {
            int n = word.size();
            for (int i = 0; i < (n + 1) / 2; ++i) {
                if (word[i] != word[n - i - 1]) {
                    return false;
                }
            }
            return true;
        };
        for (const auto word: words) {
            if (check(word)) {
                return word;
            }
        }
        return "";
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.firstPalindrome(temp_vector({"abc", "car", "ada", "racecar", "cool"})) << endl;
}

//
// Created By jing At2026-05-07 20:25
//
