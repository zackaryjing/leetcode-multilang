// problem: https://leetcode.cn/problems/first-letter-to-appear-twice/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    char repeatedCharacter(string s) {
        vector<bool> show(26);
        for (char c: s) {
            if (show[c - 'a']) {
                return c;
            }
            show[c - 'a'] = true;
        }
        return ' ';
    }
};

int main(int argc, char *argv[]) {
    Solution test;
}

//
// Created By jing At 2026-06-19 20:21
//
