// problem: https://leetcode.cn/contest/biweekly-contest-183/problems/count-non-adjacent-subsets-in-a-rooted-tree/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_set>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
    // failed attempt
public:
    int countValidSubsets(vector<int> &parent, vector<int> &nums, int k) {
        unordered_set<int> cannot;
        int n = parent.size();
        // cout << 1 << endl;
        for (int i = 1; i < n; ++i) {
            int par = parent[i];
            cannot.insert(i | (par << 15));
            cannot.insert(par | (i << 15));
        }
        // cout << 2 << endl;
        // cout << cannot.size() << endl;
        vector dp(n, vector<int>(k, 0));
        cout << "invalid: ";
        for (const auto c: cannot) {
            cout << format("{:b}", c) << ", ";
        }
        cout << endl;
        dp[0][nums[0] % k] = 1;
        dp[0][0] = 1;
        for (int i = 1; i < n; ++i) {
            // dp[i][nums[i] % k] += 1;
            dp[i] = dp[i - 1];
            for (int j = 0; j < k; ++j) {
                // cout << i << " " << j << endl;
                cout << format(" validator: {:b} ({},{})", (i | (j << 15)), i, j) << endl;
                if (not cannot.contains(i | (j << 15))) {
                    // cout << (j + nums[i]) % k << endl;
                    cout << "from:  " << j << " to " << (j + nums[i]) % k << endl;
                    dp[i][(j + nums[i]) % k] += dp[i - 1][(j + nums[i]) % k];
                }
            }
            cout << endl;
        }
        show_matrix(dp);
        // cout << 3 << endl;
        return dp[n - 1][0] - 2;
    }
};


class Solution {
public:
    int countValidSubsets(vector<int> &parent, vector<int> &nums, int k) {
        unordered_set<int> cannot;
        const uint64_t MOD = 1000000007;
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; ++i) {
            children[parent[i]].push_back(i);
        }
        vector dp0(n, vector<uint64_t>(k, 0LL));
        vector dp1(n, vector<uint64_t>(k, 0LL));
        auto merge = [&](const vector<uint64_t> &a, const vector<uint64_t> &b) {
            vector<uint64_t> res(k);
            for (int i = 0; i < k; ++i) {
                if (a[i] == 0)
                    continue;
                for (int j = 0; j < k; ++j) {
                    if (b[j] == 0)
                        continue;
                    res[(i + j) % k] = (res[(i + j) % k] + a[i] * b[j]) % MOD;
                }
            }
            return res;
        };
        const auto dfs = [&](this auto &&dfs, int u) -> void {
            dp0[u][0] = 1;
            dp1[u][nums[u] % k] = 1;
            for (int v: children[u]) {
                dfs(v);
                vector<uint64_t> childTotal(k);
                for (int r = 0; r < k; ++r) {
                    childTotal[r] = (dp0[v][r] + dp1[v][r]) % MOD;
                }
                dp0[u] = merge(dp0[u], childTotal);
                dp1[u] = merge(dp1[u], dp0[v]);
            }
        };
        dfs(0);
        uint64_t res = (dp0[0][0] + dp1[0][0] - 1 + MOD) % MOD;
        return res;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.countValidSubsets(temp_vector({-1, 0, 0, 0}), temp_vector({2, 1, 2, 1}), 3) << endl;
    cout << test.countValidSubsets(temp_vector({-1, 0, 1}), temp_vector({1, 2, 3}), 3) << endl;
}

//
// Created By jing At 2026-05-23 23:27
//
