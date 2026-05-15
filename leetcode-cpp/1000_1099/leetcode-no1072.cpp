// problem:
// https://leetcode.cn/problems/flip-columns-for-maximum-number-of-equal-rows/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <c++/14/unordered_map>
#include <iostream>
#include <ranges>
#include <vector>

#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
        unordered_map<bitset<300>, int> occurs;
        int valid = 0, mx = 0, m = matrix[0].size();
        bitset<300> mask;
        mask.set();
        mask <<= 300 - m;
        mask >>= 300 - m;
        for (auto line: matrix) {
            bitset<300> l;
            for (int i = 0; i < m; ++i)
                if (line[i]) l.set(i);
            auto temp = l ^ mask;
            mx = max(mx, max(++occurs[temp], ++occurs[l]));
            if (not(temp.any() and l.any())) valid++;
        }
        return max(mx, valid);
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxEqualRowsAfterFlips(temp_vector({temp_vector({0, 1}), temp_vector({1, 1})})) << endl;
    cout << test.maxEqualRowsAfterFlips(temp_vector({temp_vector({0, 1}), temp_vector({1, 0})})) << endl;
    cout << test.maxEqualRowsAfterFlips(
            temp_vector({temp_vector({0, 0, 0}), temp_vector({0, 0, 1}), temp_vector({1, 1, 0})}))
         << endl;
}

//
// Created By jing At 2026-05-15 19:15
//
