// problem: https://leetcode.cn/problems/k-th-symbol-in-grammar/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int kthGrammar(int n, int k) {
        --k, --n;
        int base = 1;
        while (base <= k) base <<= 1;
        base /= 2;
        int res = 0;
        while (k >= 2) {
            k -= base;
            base >>= 1;
            while (base > k) base >>= 1;
            res = !res;
        }
        return res ^ k;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.kthGrammar(1, 1) << endl;
    cout << test.kthGrammar(2, 1) << endl;
    cout << test.kthGrammar(2, 2) << endl;
    cout << test.kthGrammar(3, 3) << endl;
    cout << test.kthGrammar(30, 434991989) << endl;
}

//
// Created By ASUS At 2026-07-07 13:58
//
