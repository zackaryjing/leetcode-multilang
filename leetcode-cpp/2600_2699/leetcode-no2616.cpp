// problem: https://leetcode.cn/problems/minimize-the-maximum-difference-of-pairs/description/?envType=daily-question&envId=2025-06-13
#include <iostream>
#include <algorithm>
#include <vector>

#include "../utils/vector_helper.h"
using namespace std;

class Solution {
public:
    int minimizeMax(vector<int> &nums, int p) {
        ranges::sort(nums);
        auto check = [&](int mx) {
            int cnt = 0;
            for (int i = 0; i + 1 < nums.size(); ++i) {
                if (nums[i + 1] - nums[i] <= mx) {
                    cnt += 1;
                    i++;
                }
            }
            return cnt >= p;
        };

        int left = -1;
        int right = nums.back() - nums[0];
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minimizeMax(temp_vector({10, 1, 2, 7, 1, 3}), 2) << endl;
}

//
// Created By Zackary At 2025-06-13 11:48:04
//
