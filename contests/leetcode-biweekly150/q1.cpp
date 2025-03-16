#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Solution {
public:
    int sumOfGoodNumbers(vector<int> &nums, int k) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            bool is_good = true;
            if (i - k >= 0 and nums[i] <= nums[i - k] or i + k < n and nums[i] <= nums[i + k]) {
                is_good = false;
            }
            if (is_good) {
                ans += nums[i];
            }
        }
        return ans;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.sumOfGoodNumbers(*make_unique<vector<int> >(vector{1, 3, 2, 1, 5, 4}), 2) << endl;;
    cout << test.sumOfGoodNumbers(*make_unique<vector<int> >(vector{3,3}), 1) << endl;;
}

// Created by ASUS on 2025/2/15.
//
