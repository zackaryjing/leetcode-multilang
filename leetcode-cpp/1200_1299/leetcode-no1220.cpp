// problem: https://leetcode.cn/problems/count-vowels-permutation/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int countVowelPermutation(int n) {
        vector cnts(2, vector<long long>(5,1));
        long long MOD = 1000000007;
        int cur = 0, last = 0;
        for (int i = 1; i < n; ++i) {
            cur = i & 1, last = !cur;
            cnts[cur][0] = (cnts[last][1] + cnts[last][2] + cnts[last][4]) % MOD;
            cnts[cur][1] = (cnts[last][0] + cnts[last][2]) % MOD;
            cnts[cur][2] = (cnts[last][1] + cnts[last][3]) % MOD;
            cnts[cur][3] = (cnts[last][2]) % MOD;
            cnts[cur][4] = (cnts[last][2] + cnts[last][3]) % MOD;
        }
        return accumulate(cnts[cur].begin(), cnts[cur].end(), 0LL) % MOD;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.countVowelPermutation(1) << endl;
    cout << test.countVowelPermutation(2) << endl;
    cout << test.countVowelPermutation(5) << endl;
}

//
// Created By jing At 2026-09-11 19:57
//
