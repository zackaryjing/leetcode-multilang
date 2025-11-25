// problem: https://leetcode.cn/contest/biweekly-contest-169/problems/count-subarrays-with-majority-element-ii/

#include <deque>
#include <iostream>
#include <numeric>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;
class Solution {
public:
    long long countMajoritySubarrays(vector<int> &nums, int target) {
        int n = static_cast<int>(nums.size());
        vector times(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                times[i + 1] = times[i] + 1;
            } else {
                times[i + 1] = times[i];
            }
        }
        int res = 0;
        for (int i = 1; i < n + 1; ++i) {
            int j = i;
            while (j < n + 1) {
                int count = times[j] - times[i - 1];
                if (count > (j - i + 1) / 2) {
                    res++;
                } else {
                    j += (j - i + 1) - 2 * count;
                }
                j++;
            }
        }
        return res;
    }
};


class Solution2 {
public:
    long long countMajoritySubarrays(vector<int> &nums, int target) {
        int n = static_cast<int>(nums.size());
        vector times(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                times[i + 1] = times[i] + 1;
            } else {
                times[i + 1] = times[i];
            }
        }
        int res = 0;
        int j = 0;
        deque<int> valid;
        deque<int> invalid;
        iota(valid.begin(), valid.end(), 1);
        int predict = 0;
        for (int i = 1; i < n + 1; ++i) {
            if (i > 1 and nums[i] != target) {
                predict = max(i, predict);
                while (not invalid.empty()) {
                    int j = invalid.front();
                    if (j > predict) {
                        int count = times[j] - times[i - 1];
                        if (count > (j - i + 1) / 2) {
                            res++;
                        } else {
                            j += (j - i + 1) - 2 * count;
                        }
                        j++;
                    }
                }
            } else {
            }
        }
        return res;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.countMajoritySubarrays(temp_vector<int>({1, 2, 2, 3}), 2) << " e5" << endl;
    cout << test.countMajoritySubarrays(temp_vector<int>({1, 1, 1, 1}), 1) << " e10" << endl;
    cout << test.countMajoritySubarrays(temp_vector<int>({1, 2, 3}), 4) << " e0" << endl;
}

//
// Created by: ASUS At: 11/8/2025 11:07 PM
//