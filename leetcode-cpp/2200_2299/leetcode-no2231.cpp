// problem: https://leetcode.cn/problems/largest-number-after-digit-swaps-by-parity
#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_set>
#include <vector>
#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    int largestInteger(int num) {
        vector<int> odd;
        vector<int> even;
        unordered_set<int> inodd;
        int index = 0;
        while (num > 0) {
            int k = num % 10;
            if (k % 2 == 0) {
                even.push_back(k);
            } else {
                odd.push_back(k);
                inodd.insert(index);
            }
            num /= 10;
            index++;
        }
        ranges::sort(even);
        ranges::reverse(even);
        ranges::sort(odd);
        ranges::reverse(odd);
        int res = 0;
        int n = index;
        auto o = odd.data(), e = even.data();
        for (int i = 0; i < n; ++i) {
            res *= 10;
            if (inodd.contains(n - i - 1)) {
                res += *o;
                o++;
            } else {
                res += *e;
                e++;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.largestInteger(1234) << endl;
    cout << test.largestInteger(65875) << endl;
}

//
// Created By jing At 2026-04-29 19:58
//
