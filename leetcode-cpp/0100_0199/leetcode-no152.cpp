#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        const int n = nums.size();
        int neg_max = 0, pos_max = 0;
        int ans = nums[0];
        if (nums[0] > 0) {
            pos_max = nums[0];
        } else {
            neg_max = nums[0];
        }
        int neg_max_temp, pos_max_temp;
        for (int i = 1; i < n; i++) {
            if (nums[i] == 0) {
                neg_max_temp = 0;
                pos_max_temp = 0;
            } else if (nums[i] > 0) {
                pos_max_temp = max(pos_max * nums[i], nums[i]);
                neg_max_temp = min(neg_max * nums[i], nums[i]);
            } else {
                neg_max_temp = min(pos_max * nums[i], nums[i]);
                pos_max_temp = max(neg_max * nums[i], nums[i]);
            }
            pos_max = pos_max_temp;
            neg_max = neg_max_temp;
            ans = max(ans, max(pos_max, neg_max));
        }
        return ans;
    }
};


class Solution2 {
    // 访存时间可以优化掉
public:
    int maxProduct(vector<int> &nums) {
        int n = nums.size();
        vector<int> neg_max(n, 0), pos_max(n, 0);
        int ans = nums[0];
        if (nums[0] > 0) {
            pos_max[0] = nums[0];
        } else {
            neg_max[0] = nums[0];
        }
        for (int i = 1; i < n; i++) {
            if (nums[i] == 0) {
                neg_max[i] = 0;
                pos_max[i] = 0;
            } else if (nums[i] > 0) {
                pos_max[i] = max(pos_max[i - 1] * nums[i], nums[i]);
                neg_max[i] = min(neg_max[i - 1] * nums[i], nums[i]);
            } else {
                neg_max[i] = min(pos_max[i - 1] * nums[i], nums[i]);
                pos_max[i] = max(neg_max[i - 1] * nums[i], nums[i]);
            }
            // cout << pos_max[i] << ", " << neg_max[i] << endl;
            ans = max(ans, max(pos_max[i], neg_max[i]));
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxProduct(*make_unique<vector<int> >(vector{-2, 3, -4})) << endl;;
    cout << test.maxProduct(*make_unique<vector<int> >(vector{2, 3, -2, 4})) << endl;;
    cout << test.maxProduct(*make_unique<vector<int> >(vector{-2, 0, -1})) << endl;;
}


//
// Created by ASUS on 2025/2/16.
//
