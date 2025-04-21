// problem: https://leetcode.cn/problems/count-the-number-of-good-subarrays/?envType=daily-question&envId=2025-04-16
#include <iostream>
#include <unordered_map>
#include <vector>
#include "../utils/vector_helper.h"
using namespace std;

class Solution {
public:
    long long countGood(vector<int> &nums, int k) {
        unordered_map<int, int> times;
        int n = nums.size();
        int left = 0;
        int right = -1;
        long long total = 0;
        long long res = 0;
        for (left = 0; left < n; ++left) {
            if (total >= k) {
                res += n - right;
            } else {
                if (right >= n - 1) {
                    break;
                }
                while (right < n - 1) {
                    ++right;
                    total += times[nums[right]];
                    times[nums[right]]++;
                    // cout << "t: " << total << " m: " << times[nums[right]] << " r: " << right << endl;
                    if (total >= k) {
                        res += n - right;
                        break;
                    }
                }
            }
            // cout << "good" << endl;
            total -= times[nums[left]] - 1;
            times[nums[left]]--;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    auto test = Solution();
    cout << test.countGood(temp_vector<int>({1, 1, 1, 1, 1}), 10) << endl;
    cout << test.countGood(temp_vector<int>({3, 1, 4, 3, 2, 2, 4}), 2) << endl;
}

//
// Created by zhiya on 2025/4/16.
//
