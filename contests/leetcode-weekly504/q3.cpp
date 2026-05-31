// problem:
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    int maximumSaleItems(vector<vector<int>> &items, int budget) {
        int n = items.size();
        vector<int> values(n);
        for (int i = 0; i < n; ++i) {
            int f = items[i][0];
            for (int j = 0; j < n; ++j) {
                values[i] += (i != j and items[j][0] % f == 0 ? 1 : 0);
            }
        }
        vector dp(n + 1, vector<int>(budget + 1));
        for (int i = 1; i <= n; ++i) {
            int value = values[i - 1];
            int price = items[i - 1][1];
            for (int j = 0; j <= budget; ++j) {
                dp[i][j] = dp[i - 1][j];
            }
            int cnt = min(value, budget / price);
            for (int t = 0; t < cnt; ++t) {
                for (int j = budget; j >= price; --j) {
                    dp[i][j] = max(dp[i][j], dp[i][j - price] + 2);
                }
            }
            for (int j = price; j <= budget; ++j) {
                dp[i][j] = max(dp[i][j], dp[i][j - price] + 1);
            }
        }
        return dp[n][budget];
    }
};

class Solution3 {
public:
    int maximumSaleItems(vector<vector<int>> &items, int budget) {
        int n = items.size();
        vector<int> values(n);
        for (int i = 0; i < n; ++i) {
            int f = items[i][0];
            for (int j = 0; j < n; ++j) {
                values[i] += (i != j and items[j][0] % f == 0 ? 1 : 0);
            }
        }
        // vector dp(n + 1, vector<int>(budget + 1));
        vector dp(budget + 1, 0);
        for (int i = 1; i <= n; ++i) {
            int value = values[i - 1];
            int price = items[i - 1][1];
            int cnt = min(value, budget / price);
            for (int t = 0; t < cnt; ++t) {
                for (int j = budget; j >= price; --j) {
                    dp[j] = max(dp[j], dp[j - price] + 2);
                }
            }
            for (int j = price; j <= budget; ++j) {
                dp[j] = max(dp[j], dp[j - price] + 1);
            }
        }
        return dp[budget];
    }
};


class Solution {
public:
    int maximumSaleItems(vector<vector<int>> &items, int budget) {
        int n = items.size();
        vector<int> bonus(n);
        for (int i = 0; i < n; ++i) {
            int f = items[i][0];
            for (int j = 0; j < n; ++j)
                bonus[i] += i != j and items[j][0] % f == 0;
        }
        auto minPrice = ranges::min(items | views::transform([](const auto &v) { return v[1]; }));
        vector<int> good;
        for (int i = 0; i < n; ++i) {
            int price = items[i][1];
            if ((long long) price >= 2LL * minPrice)
                continue;
            int cnt = min(bonus[i], budget / price);
            for (int t = 0; t < cnt; ++t) {
                good.push_back(price);
            }
        }
        sort(good.begin(), good.end());
        long long cost = 0;
        int ans = budget / minPrice;
        for (int k = 1; k <= good.size(); ++k) {
            cost += good[k - 1];
            if (cost > budget)
                break;
            ans = max<long long>(ans, 2LL * k + (budget - cost) / minPrice);
        }
        return ans;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maximumSaleItems(temp_vector({temp_vector({1, 6}), temp_vector({2, 4}), temp_vector({3, 5})}), 19)
         << endl;
    cout << test.maximumSaleItems(temp_vector({temp_vector({2, 8}), temp_vector({1, 10}), temp_vector({6, 6}),
                                               temp_vector({4, 12}), temp_vector({5, 20}), temp_vector({5, 17})}),
                                  35)
         << endl;
}

//
// Created By ASUS At 2026-05-31 11:15
//
