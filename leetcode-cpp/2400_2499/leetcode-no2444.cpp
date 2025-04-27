// problem: https://leetcode.cn/problems/count-subarrays-with-fixed-bounds/?envType=daily-question&envId=2025-04-26
#include <iostream>
#include <vector>

#include "../utils/vector_helper.h"
using namespace std;

class Solution {
public:
    // [Official]
    long long countSubarrays(vector<int> &nums, int minK, int maxK) {
        int minPos = -1;
        int maxPos = -1;
        int bad = -1;
        long long res = 0;
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] < minK or nums[i] > maxK) {
                bad = i;
            }
            if (nums[i] == minK) {
                minPos = i;
            }
            if (nums[i] == maxK) {
                maxPos = i;
            }
            int diff = min(maxPos, minPos) - bad;
            if (diff > 0) {
                res += diff;
            }
        }
        return res;
    }
};

class Solution_2 {
    // [Pass] unstable.
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK) {
        int left = 0;
        int right = 0;
        int n = static_cast<int>(nums.size());
        vector<int> cur;
        pair cnts = {0, 0};
        long long res = 0;
        while (right <= n) {
            if (right < n and minK <= nums[right] and nums[right] <= maxK) {
                ++right;
            } else {
                int start = left;
                int end = left;

                while (end < right) {
                    if (nums[end] == minK) {
                        cnts.first++;
                    }
                    if (nums[end] == maxK) {
                        cnts.second++;
                    }
                    while (cnts.first and cnts.second) {
                        res += right - end;
                        if (nums[start] == minK) {
                            cnts.first--;
                        }
                        if (nums[start] == maxK) {
                            cnts.second--;
                        }
                        start++;
                    }
                    end++;
                }
                cnts = {0, 0};

                left = right + 1;
                right = left;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    // cout << test.countSubarrays(temp_vector<int>({1, 2, 3}), 1, 3) << endl;
    cout << test.countSubarrays(temp_vector<int>({1, 3, 5, 2, 7, 5}), 1, 5) << endl;
    cout << test.countSubarrays(temp_vector<int>({1, 1, 1, 1}), 1, 1) << endl;
    cout << test.countSubarrays(temp_vector<int>({265345, 989402, 916058, 203520, 473519, 491976, 916058, 9469, 943921,
                                                  161914, 792300, 916058, 91577, 916058, 91577, 971623, 806300, 916058,
                                                  916058, 916058, 437065, 389326, 790132, 680988, 793816, 91577, 377377,
                                                  916058, 641301, 91577, 91577, 93711, 916058, 757526, 91577, 91577,
                                                  986428, 545243, 91577, 175212, 498235, 916058, 302166, 916058, 916058,
                                                  579309, 91577, 254606, 914024, 829079, 91577, 745274, 539218, 882912,
                                                  4952, 578396, 916058, 91577, 916058, 916058, 91577, 916058, 91577,
                                                  916058, 91577, 28341, 119058, 916058, 91577, 813037, 916058, 570946,
                                                  733870, 91577, 91577, 916058, 753812, 916058, 647459, 91577, 548179,
                                                  892836, 916058, 916058, 866662, 415605, 91577, 916058, 91577,
                                                  916058}), 91577, 916058) << endl;
}

//
// Created By Zackary At 2025-04-26 13:49:03
//
