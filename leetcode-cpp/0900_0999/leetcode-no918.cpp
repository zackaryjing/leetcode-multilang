#include "../utils/vector_helper.h"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int> &nums) {
        int n = nums.size();
        if (nums.empty()) {
            return 0;
        }
        vector<int> sum_max(n);
        int ans = nums[0];
        int last = nums[0];
        sum_max[0] = last;

        int left_sum = nums[0];
        for (int i = 1; i < n; i++) {
            last = max(last + nums[i], nums[i]);
            ans = max(last, ans);
            left_sum += nums[i];
            sum_max[i] = max(left_sum, sum_max[i - 1]);
        }
        // show_vector(sum_max);
        // cout << "last_end: " << start_index[n - 1] << endl;
        int right_sum = 0;
        for (int k = n - 1; k >= 1; k--) {
            right_sum += nums[k];
            ans = max(sum_max[k - 1] + right_sum, ans);
        }
        // show_vector(sum_mx);
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxSubarraySumCircular(*make_unique<vector<int> >(vector{-2, 2, -2, 9})) << endl;
    cout << test.maxSubarraySumCircular(*make_unique<vector<int> >(vector{1, -2, 3, -2})) << endl;
    cout << test.maxSubarraySumCircular(*make_unique<vector<int> >(vector{5, -3, 5})) << endl;
    cout << test.maxSubarraySumCircular(*make_unique<vector<int> >(vector{-3, -2, -3})) << endl;
}


//
// Created by ASUS on 2025/2/17.
//
