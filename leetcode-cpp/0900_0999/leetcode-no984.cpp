// problem: https://leetcode.cn/problems/string-without-aaa-or-bbb/
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string res;
        res.reserve(a + b);
        int cnt[] = {a, b};
        int cur = a > b ? 0 : 1;
        do {
            res += static_cast<char>('a' + cur);
            if (cnt[cur ^ 1] < cnt[cur] && cnt[cur]-- > 1)
                res += static_cast<char>('a' + cur);
        } while (--cnt[(cur ^= 1) ^ 1] > 0 || cnt[cur] > 0);
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.strWithout3a3b(1, 2) << endl;
    cout << test.strWithout3a3b(4, 1) << endl;
}

//
// Created By ASUS At 2025-11-18 01:01
//
