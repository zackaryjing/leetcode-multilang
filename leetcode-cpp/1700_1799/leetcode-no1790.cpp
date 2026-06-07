// problem:
// https://leetcode.cn/problems/check-if-one-string-swap-can-make-strings-equal/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        if (s2.size() != n) return false;
        char a = ' ', b = ' ';
        bool notEqualOnce = false, notEqualTwice = false;
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                if (notEqualTwice) return false;
                if (notEqualOnce) {
                    if (a != s2[i] or b != s1[i]) return false;
                    notEqualTwice = true;
                } else {
                    notEqualOnce = true;
                    a = s1[i], b = s2[i];
                }
            }
        }
        if (notEqualOnce and not notEqualTwice) return false;
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.areAlmostEqual("bank", "kanb") << endl;
}

//
// Created By jing At 20:15
//
