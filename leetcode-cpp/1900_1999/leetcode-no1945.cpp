// problem: https://leetcode.cn/problems/sum-of-digits-of-string-after-convert/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        int res = 0;
        for (const auto c: s) {
            int temp = c - 'a' + 1;
            res += temp / 10 + (temp % 10);
        }
        for (int i = 1;i < k and res >= 10;++i) {
            // cout << "res: " << res << endl;
            int ns = 0;
            while (res > 0) {
                ns += res % 10;
                res /= 10;
            }
            res = ns;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.getLucky("iiii",1) << endl;
    cout << test.getLucky("leetcode",2) << endl;
}

//
// Created By jing At 2026-05-29 20:43
//
