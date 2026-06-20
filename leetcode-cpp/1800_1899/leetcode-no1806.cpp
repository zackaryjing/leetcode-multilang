// problem:
// https://leetcode.cn/problems/minimum-number-of-operations-to-reinitialize-a-permutation/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int reinitializePermutation(int n) {
        int res = 1;
        int pos = 2;
        int half = n / 2;
        if (n == 2) return 1;
        while (pos != 1) {
            if (pos < half) {
                pos *= 2;
            } else {
                pos = (pos - half) * 2 + 1;
            }
            res++;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    for (int i = 2; i < 100; i += 2) {
        cout << "i: " << i << " " << test.reinitializePermutation(i) << endl;
    }
    // cout << test.reinitializePermutation(2) << endl;
    // cout << test.reinitializePermutation(4) << endl;
    // cout << test.reinitializePermutation(6) << endl;
}

//
// Created By jing At 2026-06-12 19:08
//
