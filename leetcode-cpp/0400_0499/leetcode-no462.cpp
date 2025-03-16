// problem: minimum-moves-to-equal-array-elements-ii
#include <algorithm>
#include <ranges>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int> &nums) {
        ranges::sort(nums);
        int n = static_cast<int>(nums.size());
        int mid = n / 2;
        long long total = 0, top_part = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i];
            if (i >= mid) {
                top_part += nums[i];
            }
        }
        if (n % 2) {
            return static_cast<int>(2 * top_part - nums[mid] - total);
        }
        return static_cast<int>(2 * top_part - total);
    }
};

class Solution2 {
    // 过了，但是优化一下
public:
    int minMoves2(vector<int> &nums) {
        ranges::sort(nums);
        int n = static_cast<int>(nums.size());
        long long total = accumulate(nums.begin(), nums.end(), 0);
        if (n % 2) {
            int mid = n / 2;
            long long top_part = accumulate(nums.begin() + mid, nums.end(), 0);
            return nums[mid] * mid - (total - top_part) + top_part - (mid + 1) * nums[mid];
            // return 2 * top_part - nums[mid] - total;
        } else {
            int mid = n / 2;
            long long top_part = accumulate(nums.begin() + mid, nums.end(), 0);
            return nums[mid] * mid - (total - top_part) + top_part - mid * nums[mid];
            // return (int) (2 * top_part - total);
        }
    }
};


class Solution2 {
public:
    int minMoves2(vector<int> &nums) {
        ranges::sort(nums);
        int n = static_cast<int>(nums.size());
        int total = accumulate(nums.begin(), nums.end(), 0);
        int left = 0, right = total - n * nums[0];
        int i = 1;
        for (; i < n; i++) {
            cout << left << " , " << right << endl;
            left += i * (nums[i] - nums[i - 1]);
            right -= (n - i) * (nums[i] - nums[i - 1]);
            if (left > right) {
                break;
            }
        }
        cout << i << endl;
        int bottom = nums[i - 1];
        int top = nums[i];
        int upper = top;
        while (bottom != top) {
            int mid = (bottom + top + 1) / 2;
            int temp_right = (upper - mid) * (n - i) + right;
            int temp_left = left - (upper - mid) * i;
            if (temp_right > temp_left) {
            }
        }
        return 0;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    vector<int> eg1 = {1, 2, 2, 2, 3, 3, 3};
    test.minMoves2(eg1);
}


//
// Created by ASUS on 2025/3/15.
//
