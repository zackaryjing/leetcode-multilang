#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        vector<int> buys = vector(k, -prices[0]);
        vector<int> sells = vector(k, 0);
        for (int i = 0; i < n; i++) {
            buys[0] = max(buys[0], -prices[i]);
            sells[0] = max(sells[0], buys[0] + prices[i]);
            for (int j = 1; j < k; j++) {
                buys[j] = max(buys[j], sells[j - 1] - prices[i]);
                sells[j] = max(sells[j], buys[j] + prices[i]);
            }
        }
        return sells[k - 1];
    }
};


int main() {
    Solution test;
    cout << test.maxProfit(2, *make_unique<vector<int>>(vector{2, 4, 1})) << endl;

    cout << test.maxProfit(2, *make_unique<vector<int>>(vector{3, 2, 6, 5, 0, 3})) << endl;
}


//
// Created by ASUS on 2025/2/10.
//
