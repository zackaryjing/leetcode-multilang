// problem: https://leetcode.cn/problems/redistribute-characters-to-make-all-strings-equal/?envType=problem-list-v2&envId=FeuPdeiM
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> cnts(26);
        for (const auto& word : words) {
            for (const auto c : word) {
                cnts[c - 'a'] ++;
            }
        }
        for (auto t : cnts) {
            if (t % words.size() != 0) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.makeEqual(temp_vector({"abc","aabc","bc"})) << endl;

}

//
// Created By jing At 2026-05-18 16:03
//