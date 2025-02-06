#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int sum1 = 0;
        int sum2 = 0;
        int sum3 = 0;
        int maxSum1 = 0;
        int maxSum2 = 0;
        int maxSum3 = 0;
        vector<int> ans = {0, k, 2 * k};
        int temp = 0;
        int first = 0;
        int second = 0;
        for (int i = k * 2; i < nums.size(); i++) {
            sum1 += nums[i - 2 * k];
            sum2 += nums[i - k];
            sum3 += nums[i];
            if (i >= k * 3) {
                sum1 -= nums[i - 3 * k];
                sum2 -= nums[i - 2 * k];
                sum3 -= nums[i - k];
            }
            if (i >= k * 3 - 1) {
                // cout << 1 << endl;
                if (sum1 > maxSum1) {
                    maxSum1 = sum1;
                    // cout << "here" << endl;
                    temp = i - 3 * k + 1;
                }
                if (maxSum1 + sum2 > maxSum2) {
                    maxSum2 = maxSum1 + sum2;
                    first = temp;
                    second = i - 2 * k + 1;
                }
                if (maxSum2 + sum3 > maxSum3) {
                    maxSum3 = maxSum2 + sum3;
                    ans[2] = i - k + 1;
                    ans[1] = second;
                    ans[0] = first;
                }
            }
            // cout << sum1 << " " << sum2 << " " << sum3 << endl;
        }
        return ans;
    }
};



int main() {
    Solution test;
    // auto ans1 = test.maxSumOfThreeSubarrays({1, 2, 1, 2, 6, 7, 5, 1}, 2);
    // auto ans1 = test.maxSumOfThreeSubarrays({7,13,20,19,19,2,10,1,1,19}, 3);
    // auto ans1 = test.maxSumOfThreeSubarrays({4,5,10,6,11,17,4,11,1,3}, 1);
    for (auto k: ans1) {
        cout << k << " ";
    }
}

//
// Created by ASUS on 2025/2/4.
//
