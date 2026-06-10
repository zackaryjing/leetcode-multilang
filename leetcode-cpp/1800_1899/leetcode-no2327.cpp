// problem:
// https://leetcode.cn/problems/number-of-people-aware-of-a-secret/description/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> knows(forget);
        const long long mod = 1000000007;
        knows[0] = 1;
        for (int i = 0; i < n - 1; ++i) {
            long long firstKnow = 0;
            for (int j = forget - 1; j >= delay; --j) {
                knows[j] = knows[j - 1];
                firstKnow = (firstKnow + knows[j - 1]) % mod;
            }
            for (int j = delay - 1; j >= 1; --j) {
                knows[j] = knows[j - 1];
            }
            knows[0] = firstKnow;
        }
        long long res = 0;
        for (const auto num: knows) {
            res = (res + num) % mod;
        }
        return res;
    }
};


class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> knows(forget);
        const long long mod = 1000000007;
        long long preSum = 0;
        knows[0] = 1;
        for (int i = 1; i < n; ++i) {
            preSum = (preSum + knows[(i + forget - delay) % forget] - knows[i % forget] + mod) % mod;
            knows[i % forget] = preSum;
        }
        return accumulate(knows.begin(), knows.end(), 0LL) % mod;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.peopleAwareOfSecret(6, 2, 4) << endl;
    cout << test.peopleAwareOfSecret(4, 1, 3) << endl;
}

//
// Created By ASUS At 2026-06-10 21:12
//
