#include <iostream>
#include <memory>
#include <vector>

using namespace std;

void show(vector<vector<int>> data) {
    for (auto line: data) {
        for (auto val: line) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// 暴力解
class Solution2 {
public:
    int maxProfit(vector<int> &prices) {
        const int n = prices.size();
        auto diff = vector(n, vector(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                diff[i][j] = prices[j] - prices[i];
            }
        }
        auto max_grid_top = vector(n, vector(n, 0));
        int max_val = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= i; --j) {
                max_grid_top[i][j] = max(max_val, diff[i][j]);
                max_val = max_grid_top[i][j];
            }
        }
        // show(max_grid_top);

        auto max_grid_down = vector(n, vector(n, 0));
        max_val = 0;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i <= j; i++) {
                max_grid_down[i][j] = max(max_val, diff[i][j]);
                max_val = max_grid_down[i][j];
            }
        }
        // show(max_grid_down);

        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, max_grid_down[i][i] + max_grid_top[i][i]);
        }
        return ans;
    }
};


// 暴力解
class Solution3 {
public:
    int maxProfit(vector<int> &prices) {
        const int n = prices.size();
        auto max_left = vector(n, 0);
        int max_val = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= i; --j) {
                max_val = max(max_val, prices[j] - prices[i]);
            }
            max_left[i] = max_val;
        }
        // show(max_grid_top);

        max_val = 0;
        int ans = 0;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i <= j; i++) {
                max_val = max(max_val, prices[j] - prices[i]);
            }
            ans = max(ans, max_left[j] + max_val);
        }
        return ans;
    }
};


class Solution4 {
public:
    int maxProfit(vector<int> &prices) {
        int max_first = 0;
        int n = prices.size();
        vector<int> max_nums(n, prices[n - 1]);
        vector<int> max_from(n, n - 1);
        int max_index = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            if (prices[i] >= max_nums[i + 1]) {
                max_nums[i] = prices[i];
                max_index = i;
            }
            max_from[i] = max_index;
        }

        vector<int> max_diff(n, 0);
        vector<int> diff(n, 0);

        for (int i = n - 2; i >= 0; i--) {
            diff[i] = max_nums[i] - prices[i];
            max_diff[i] = max(diff[i], max_diff[i + 1]);
        }


        int deal_one_max = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            deal_one_max = max(deal_one_max, diff[i]);
            for (int j = max_from[i] + 1; j < n; j++) {
                ans = max(ans, deal_one_max + max_nums[j] - prices[i]);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        int buy1 = -prices[0], sel1 = 0, buy2 = -prices[0], sel2 = 0;
        for (int i = 1; i < prices.size(); i++) {
            buy1 = max(buy1, -prices[i]);
            sel1 = max(sel1, buy1 + prices[i]);
            buy2 = max(buy2, sel1 - prices[i]);
            sel2 = max(sel2, buy2 + prices[i]);
        }
        return sel2;
    }
};

int main() {
    Solution test;
    cout << test.maxProfit(*make_unique<vector<int>>(vector{3, 3, 5, 0, 0, 3, 1, 4})) << endl;
    cout << test.maxProfit(*make_unique<vector<int>>(vector{1, 2, 3, 4, 5})) << endl;
    ;
} //
// Created by ASUS on 2025/2/9.
//
