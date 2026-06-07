// problem: https://leetcode.cn/problems/maximum-sum-of-m-non-overlapping-subarrays-i/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <deque>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    long long maximumSum(vector<int> &nums, int m, int l, int r) {
        int n = nums.size();
        vector dp(m + 1, vector<long long>(n, LONG_LONG_MIN));
        long long start = 0;
        for (int i = n - 1; i >= max(0, n - l); --i) {
            start += nums[i];
        }
        long long res = LONG_LONG_MIN;

        for (int j = 0; j < m; ++j) {
            long long second = start;
            for (int i = n - 1; i >= max(l - 1, 0); --i) {
                long long first = 0;
                long long val = second + first +  max((i - l >= 0 and j > 0 ? dp[j - 1][i - l] : 0),0LL);
                for (int k = i - l; k >= max(i - r + 1, 0); --k) {
                    first += nums[k];
                    val = max(val, second + first + max((k > 0 and j > 0 ? dp[j - 1][k - 1] : 0),0LL));
                }
                second -= nums[i];
                second += i >= l ? nums[i - l] : 0;
                dp[j][i] = max(val, j > 0 ? dp[j - 1][i] : LONG_LONG_MIN);
                res = max(res, dp[j][i]);
            }
            for (int i = 1;i< n;++i) {
                dp[j][i] = max(dp[j][i - 1],dp[j][i]);
            }
        }
        return res;
    }
};


class Solution {
public:
    long long maximumSum(vector<int> &nums, int m, int l, int r) {
        int n = nums.size();
        const long long NEG = LLONG_MIN / 4;

        vector dp(m + 1, vector<long long>(n, NEG));

        vector<long long> pre(n + 1);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + nums[i];
        }

        long long res = NEG;

        for (int j = 0; j < m; ++j) {
            vector<long long> bestEnd(n, NEG);
            deque<int> q;
            for (int i = 0; i < n; ++i) {
                int s = i - l + 1;
                if (s >= 0) {
                    long long cur = -pre[s];
                    if (j > 0 && s > 0) {
                        cur += max(dp[j - 1][s - 1], 0LL);
                    }
                    while (!q.empty()) {
                        int t = q.back();
                        long long old = -pre[t];
                        if (j > 0 && t > 0) {
                            old += max(dp[j - 1][t - 1], 0LL);
                        }
                        if (old >= cur) break;
                        q.pop_back();
                    }
                    q.push_back(s);
                }
                int left = i - r + 1;
                while (!q.empty() && q.front() < left) {
                    q.pop_front();
                }
                if (!q.empty()) {
                    int s = q.front();
                    long long cur = pre[i + 1] - pre[s];
                    if (j > 0 && s > 0) {
                        cur += max(dp[j - 1][s - 1], 0LL);
                    }
                    bestEnd[i] = cur;
                }
            }
            for (int i = n - 1; i >= max(l - 1, 0); --i) {
                long long val = bestEnd[i];
                dp[j][i] = max(val, j > 0 ? dp[j - 1][i] : NEG);
                res = max(res, dp[j][i]);
            }

            for (int i = 1; i < n; ++i) {
                dp[j][i] = max(dp[j][i - 1], dp[j][i]);
            }
        }

        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maximumSum(temp_vector({4, 1, -5, 2}), 2, 1, 3) << " e: 7" << endl << endl;;
    cout << test.maximumSum(temp_vector({1, 0, 3, 4}), 2, 1, 2) << " e: 8" << endl<< endl;
    cout << test.maximumSum(temp_vector({-1, 7, -4}), 1, 2, 3) << " e: 6" << endl<< endl;
    cout << test.maximumSum(temp_vector({-3, -4, -1}), 2, 1, 2) << " e: -1" << endl<< endl;
}

//
// Created By ASUS At 2026-06-07 10:57
//
