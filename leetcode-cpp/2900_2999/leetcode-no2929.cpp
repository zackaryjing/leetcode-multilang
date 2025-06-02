// problem: https://leetcode.cn/problems/distribute-candies-among-children-ii/?envType=daily-question&envId=2025-06-02
#include <iostream>
#include <vector>
using namespace std;

// should use include-exclusion princple

class Solution2 {
public:
    long long cal(long long x) {
        if ( x < 0) {
            return 0;
        }
        return x * (x - 1) / 2;
    }
    long long distributeCandies(int n, int limit) {
        return cal(n + 2) - 3* cal(n - limit + 1) + 3 * cal(n - 2 * limit) - cal(n - 3 * limit - 1);
    }
};

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long res = 0;
        for (int mid = max(n - 2 * limit, 0); mid <= min(limit, n); ++mid) {
            res += min(mid + limit, n) - max(n - limit - mid, 0) - mid + 1;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.distributeCandies(5, 2) << endl;
    cout << test.distributeCandies(3, 3) << endl;
    cout << test.distributeCandies(257169, 765944) << endl;
}

//
// Created By Zackary At 2025-06-02 11:35:59
//
