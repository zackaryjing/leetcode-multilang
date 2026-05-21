// problem:
// https://leetcode.cn/problems/replace-all-digits-with-characters/description/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    string replaceDigits(string s) {
        int n = s.size();
        for (int i = 1; i < n; i += 2) {
            s[i] = s[i - 1] + (s[i] - '0');
        }
        return s;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.replaceDigits("a1c1e1") << endl;
    cout << test.replaceDigits("a1b2c3d4e") << endl;
}

//
// Created By jing At 2026-05-19 14:30
//
