#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int max_hold = -prices[0];
        int max_freeze = 0;
        int max_unhold = 0;

        int n = prices.size();
        for (int i = 1; i < n; i++) {
            int max_hold_copy = max_hold;
            int max_freeze_copy = max_freeze;
            int max_unhold_copy = max_unhold;

            max_hold = max(max_unhold_copy - prices[i], max_hold_copy);
            max_freeze = max_hold_copy + prices[i];
            max_unhold = max(max_freeze_copy, max_unhold_copy);
        }
        return max(max_unhold, max_freeze);
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxProfit(*make_unique<vector<int> >(vector{1, 2, 3, 0, 2})) << endl;
}


//
// Created by ASUS on 2025/2/18.
//
