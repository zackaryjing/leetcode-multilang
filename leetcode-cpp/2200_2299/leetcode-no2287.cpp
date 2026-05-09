// problem:
// https://leetcode.cn/problems/rearrange-characters-to-make-target-string/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_map>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector cnts(26, 0);
        for (char c: s) {
            cnts[c - 'a']++;
        }
        vector tcnts(26, 0);
        for (char c: target) {
            tcnts[c - 'a']++;
        }
        int res = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            if (tcnts[i] != 0) {
                res = min(res, cnts[i] / tcnts[i]);
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.rearrangeCharacters("ilovecodingonleetcode", "code") << endl;
}

//
// Created By jing At 2026-05-04 20:59
//
