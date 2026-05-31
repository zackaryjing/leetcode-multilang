// problem:
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>> &items, int budget) {
        int n = items.size();
        vector<int> values(n);
        for (int i = 0; i < n; ++i) {
            int f = items[i][0];
            for (int j = 0; j < n; ++j) {
                values[i] += items[j][0] % f  == 0 ? 1 : 0;
            }
        }
        // show_vector(values);
        vector dp(n + 1, vector<int>(budget + 1));
        for (int i = 1; i <= n; ++i) {
            int value = values[i - 1];
            int price = items[i - 1][1];
            for (int j = 0; j <= budget; ++j) {
                dp[i][j] = dp[i - 1][j];
            }
            for (int j = price; j <= budget; ++j) {
                dp[i][j] = max({dp[i - 1][j], dp[i][j - price] + 1});
            }
            for (int j = budget; j >= price ; --j) {
                dp[i][j] = max({dp[i - 1][j], dp[i][j - price] + value});
            }
        }
        // show_matrix(dp);
        return dp[n][budget];
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maximumSaleItems(temp_vector({temp_vector({2, 4}), temp_vector({3, 2}), temp_vector({4, 1}),
                                               temp_vector({6, 4}), temp_vector({12, 4})}),
                                  8)
         << endl;
    cout << test.maximumSaleItems(temp_vector({temp_vector({6, 2}), temp_vector({2, 6}), temp_vector({3, 4})}), 9)
         << endl;
}

//
// Created By ASUS At 2026-05-31 10:40
//
