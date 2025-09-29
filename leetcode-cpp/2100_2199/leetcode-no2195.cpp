// problem: https://leetcode.cn/problems/append-k-integers-with-minimal-sum/
#include <algorithm>
#include <iostream>
#include <queue>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"

using namespace std;

class Solution3 {
public:
    long long minimalKSum(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<int>> ordered(nums.begin(), nums.end());
        int cnt = 0;
        long long res = 0;
        long long last = ordered.top();
        ordered.pop();
        if (ordered.top() != 1) {
            const long long end = min(last, static_cast<long long>(k - cnt + 1));
            res += end * (end - 1) / 2;
            cnt += end - 1;
        }
        while (not ordered.empty() and cnt < k) {
            long long cur = ordered.top();
            ordered.pop();
            if (cur > last + 1) {
                const long long end = min(cur, last + k - cnt + 1);
                cnt += end - last - 1;
                res += (end - last - 1) * (end + last) / 2;
            }
            last = cur;
        }
        if (cnt < k) {
            const long long t = k - cnt;
            res += last * t + t * (t + 1) / 2;
        }
        return res;
    }
};


class Solution {
public:
    long long minimalKSum(vector<int> &nums, const int k) {
        ranges::sort(nums);
        const size_t n = nums.size();
        int cnt = 0;
        long long res = 0;
        if (nums[0] != 1) {
            const long long end = min(nums[0], k - cnt + 1);
            res += end * (end - 1) / 2;
            cnt += static_cast<int>(end) - 1;
        }
        for (int i = 1; i < n and cnt < k; ++i) {
            if (nums[i] > nums[i - 1] + 1) {
                const long long end = min(nums[i], nums[i - 1] + k - cnt + 1);
                const long long temp = end - nums[i - 1] - 1;
                cnt += static_cast<int>(temp);
                res += temp * (end + nums[i - 1]) / 2;
            }
        }
        if (cnt < k) {
            const long long t = k - cnt;
            res += nums[n - 1] * t + t * (t + 1) / 2;
        }
        return res;
    }
};

class Solution2 {
public:
    long long minimalKSum(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<int>> ordered(nums.begin(), nums.end());
        auto cur = 1;
        long long res = 0;
        int cnt = 0;
        while (cnt < k and not ordered.empty()) {
            while (cnt < k and ordered.top() > cur) {
                res += cur;
                cnt++;
                cur++;
            }
            while (not ordered.empty() and ordered.top() <= cur) {
                ordered.pop();
            }
            cur += 1;
        }
        while (cnt < k) {
            res += cur++;
            cnt++;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minimalKSum(temp_vector({1, 4, 25, 10, 25}), 2) << " e5 " << endl;
    cout << test.minimalKSum(temp_vector({1, 2, 3}), 3) << " e15 " << endl;
    cout << test.minimalKSum(temp_vector({5, 6}), 6) << " e25 " << endl;
    cout << test.minimalKSum(temp_vector({96, 44, 99, 25, 61, 84, 88, 18, 19, 33, 60, 86,  52, 19,
                                          32, 47, 35, 50, 94, 17, 29, 98, 22, 21, 72, 100, 40, 84}),
                             35)
         << " e794 " << endl;
}

//
// Created By jing At 2025-09-29 17:06
//
