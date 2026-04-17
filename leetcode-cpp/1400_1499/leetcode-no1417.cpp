// problem: https://leetcode.cn/problems/reformat-the-string/description/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    string reformat(string s) {
        int n = s.size();
        vector<char> digit, alpha;
        digit.reserve(n);
        alpha.reserve(n);
        for (const char c: s) {
            if (isdigit(c)) {
                digit.push_back(c);
            } else {
                alpha.push_back(c);
            }
        }
        if (std::abs(static_cast<int>(digit.size()) - static_cast<int>(alpha.size())) > 1) {
            return "";
        }
        string res(n, ' ');
        int offset = 0;
        if (alpha.size() > digit.size()) {
            res[0] = alpha[0];
            offset = 1;
        }
        for (int i = 0; i < n; ++i) {
            res[offset + i] = not(i & 1) ? digit[i / 2] : alpha[(i + offset) / 2];
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.reformat("a0b1c2") << endl;
    cout << test.reformat("leetcode") << endl;
}

//
// Created By ASUS At 2026-04-02 14:05
//
