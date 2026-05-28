// problem: https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    int minOperations(vector<int> &nums, int x) {
        int n = nums.size();
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < x) return -1;
        if (sum == x) return n;
        int temp = 0, left = 0, right = 0;
        for (int i = 0; i < n; ++i) {
            temp += nums[i];
            if (temp >= x) {
                left = i;
                break;
            }
        }
        temp = 0;
        for (int j = n - 1; j >= 0; --j) {
            temp += nums[j];
            if (temp >= x) {
                right = j;
                break;
            }
        }
        int rc = right, lc = right, cur = nums[rc], res = INT_MAX;
        while (lc <= n and rc <= left + n) {
            if (cur >= x) {
                if (cur == x) {
                    res = min(rc - lc + 1, res);
                }
                cur -= nums[lc % n];
                lc++;
            } else {
                rc++;
                cur += nums[rc % n];
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};


class Solution3 {
public:
    int minOperations(vector<int> &nums, int x) {
        const int n = nums.size();
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < x) return -1;
        if (sum == x) return n;
        int left = 0, right = n - 1;
        for (int temp = nums[0]; left < n - 1 and temp < x; ++left, temp += nums[left]) {
        }
        for (int temp = nums[n - 1]; right > 0 and temp < x; --right, temp += nums[right]) {
        }
        int rc = right, lc = right, cur = nums[rc], res = INT_MAX;
        while (lc <= n and rc <= left + n) {
            if (cur >= x) {
                if (cur == x) res = min(rc - lc + 1, res);
                cur -= nums[lc++ % n];
            } else {
                cur += nums[++rc % n];
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};


class Solution {
public:
    int minOperations(vector<int> &nums, int x) {
        const int n = nums.size();
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < x) return -1;
        if (sum == x) return n;
        int rc = 0, lc = 0, cur = nums[rc], res = INT_MAX;
        while (lc <= n and rc - lc < n) {
            if (cur >= x) {
                if (cur == x and rc >= n - 1) res = min(rc - lc + 1, res);
                cur -= nums[lc++ % n];
            } else {
                cur += nums[++rc % n];
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};


class Solution4 {
public:
    int minOperations(vector<int> &nums, int x) {
        const int n = nums.size();
        int rc = 0, lc = 0, cur = nums[rc], res = INT_MAX;
        while (lc <= n and rc - lc < n)
            if (cur >= x) {
                if (cur == x and rc >= n - 1) res = min(rc - lc + 1, res);
                cur -= nums[lc++ % n];
            } else
                cur += nums[++rc % n];
        return res == INT_MAX ? -1 : res;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minOperations(temp_vector({1, 1, 4, 2, 3}), 5) << endl;
    cout << test.minOperations(temp_vector({5, 6, 7, 8, 9}), 4) << endl;
    cout << test.minOperations(temp_vector({3, 2, 20, 1, 1, 3}), 10) << endl;
}


//
// Created By ASUS At 2026-05-26 16:51
//
