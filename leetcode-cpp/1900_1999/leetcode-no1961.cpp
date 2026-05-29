// problem: https://leetcode.cn/problems/check-if-string-is-a-prefix-of-array/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    bool isPrefixString(string s, vector<string> &words) {
        int index = 0, cnt = 0;
        for (const auto &word: words) {
            string_view sv(s.data() + index);
            if (not sv.starts_with(word)) {
                return false;
            }
            index += word.size();
            if (index == s.size()) {
                break;
            }
        }
        if (index != s.size()) return false;
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.isPrefixString("iloveleetcode", temp_vector({"i", "love", "leetcode", "apples"})) << endl;
}

//
// Created By jing At 2026-05-29 21:02
//
