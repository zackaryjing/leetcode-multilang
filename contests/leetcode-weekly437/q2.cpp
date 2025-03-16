#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxWeight(vector<int> &pizzas) {
        sort(pizzas.begin(), pizzas.end());
        // ====================
        // for (auto k : pizzas) {
        //     cout << k << ", " ;
        // }
        // cout << endl;
        // ====================
        int n = pizzas.size();
        if (n <= 4) {
            return pizzas.back();
        }
        int exNums = n * 1 / 8;
        int start = (n - exNums - n * 1 / 4);
        long long ans = 0;
        for (int i = start; i < n; i++) {
            ans += pizzas[i];
        }
        for (int i = start + 1; i < start + exNums * 2; i += 2) {
            ans -= pizzas[i];
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxWeight(*make_unique<vector<int> >(vector{4, 2, 1, 5, 2, 5, 5, 4, 2, 3, 2, 1})) << endl;; // 14
    cout << test.maxWeight(*make_unique<vector<int> >(vector{1, 2, 3, 4, 5, 6, 7, 8})) << endl;; // 14
    cout << test.maxWeight(*make_unique<vector<int> >(vector{2, 1, 1, 1, 1, 1, 1, 1})) << endl;; // 3
    cout << test.maxWeight(*make_unique<vector<int> >(vector{2, 5, 2, 3})) << endl;; // 5
}


//
// Created by ASUS on 2025/2/16.
//
