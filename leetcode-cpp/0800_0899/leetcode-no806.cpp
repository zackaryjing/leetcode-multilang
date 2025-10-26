// problem: https://leetcode.cn/problems/number-of-lines-to-write-string/?envType=problem-list-v2&envId=3rBpGyas
#include <iostream>
#include <vector>
#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int> &widths, string s) {
        int cur = 0;
        int lines = 0;
        for (const char ch: s) {
            // cout << ch << " " << cur << endl;
            cur += widths[ch - 'a'];
            if (cur > 100) {
                cur = widths[ch - 'a'];
                lines += 1;
            }
        }
        return {lines + 1, cur};
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.numberOfLines(temp_vector<int>({10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                                                     10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}),
                                   "abcdefghijklmnopqrstuvwxyz"));
    show_vector(test.numberOfLines(temp_vector({4,  10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                                                10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}),
                                   "bbbcccdddaaa"));
}

//
// Created By jing At 2025-10-24 20:21
//
