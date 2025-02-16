#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ans = 0;
        for (int i = 1; i < prices.size(); ++i) {
            ans += max(prices[i] - prices[i - 1], 0);
        }
        return ans;
    }
};

int main() {
    Solution test;
    cout << test.maxProfit(*make_unique<vector<int> >(vector{7, 1, 5, 3, 6, 4})) << endl;
    cout << test.maxProfit(*make_unique<vector<int> >(vector{1, 2, 3, 4, 5})) << endl;
    cout << test.maxProfit(*make_unique<vector<int> >(vector{7, 6, 4, 3, 1})) << endl;
}

//
// Created by ASUS on 2025/2/9.
//
