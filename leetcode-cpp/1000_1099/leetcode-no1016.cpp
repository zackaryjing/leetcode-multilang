// problem:
// https://leetcode.cn/problems/binary-string-with-substrings-representing-1-to-n/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <c++/14/unordered_set>
#include <iostream>
#include <ranges>
#include <vector>

#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    bool queryString(string s, int n) {
        int m = bit_width((unsigned) n);
        int lowerBound = 1 << (m - 1);
        if (s.size() < lowerBound) return false;
        pmr::unordered_set<int> occured;
        vector<int> item(m);
        vector<int> mask(m);
        for (int i = 0; i < m; ++i) {
            mask[i] = (1 << (i + 1)) - 1;
            for (int j = 0; j <= i; ++j) {
                item[i] = (item[i] << 1) | s[j] == '1';
            }
            occured.insert(item[i]);
        }
        int h = s.size();
        for (int i = 1; i < h; ++i) {
            for (int j = 0; j < m and i + j < h; ++j) {
                item[j] = ((item[j] << 1) & mask[j]) | (s[i + j] == '1');
                occured.insert(item[j]);
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (not occured.contains(i)) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.queryString("0110", 4) << endl;
    // cout << test.queryString("101101101111", 8) << endl;
}

//
// Created By jing At 2026-05-08 01:59
//
