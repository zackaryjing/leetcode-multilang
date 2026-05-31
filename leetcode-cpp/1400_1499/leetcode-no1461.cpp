// problem:
// https://leetcode.cn/problems/check-if-a-string-contains-all-binary-codes-of-size-k/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int cnt = 1 << k, n = s.size(), temp = 0, mask = (1 << k) - 1;
        vector<bool> occured(cnt);
        if (n < k) return false;
        for (int i = 0; i < k; ++i) temp = temp << 1 | s[i] - '0';
        occured[temp] = true;
        for (int j = k; j < n; ++j)
            occured[temp = (temp << 1 | s[j] - '0') & mask] = true;
        return ranges::all_of(occured, identity{});
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.hasAllCodes("00110110", 2) << endl;
    cout << test.hasAllCodes("0110", 2) << endl;
    cout << test.hasAllCodes("00110", 2) << endl;
}

//
// Created By jing At 2026-05-30 13:09
//
