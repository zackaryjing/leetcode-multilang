#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int> &nums, int k) {
        int start = nums[0];
        int end = nums.back();
        int n = nums.size();
        if (k > n) {
            return -1;
        }
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }
        unordered_map<int, int> times;
        if (k == 1) {
            for (auto num: nums) {
                times[num]++;
            }
            int res = -1;
            for (auto &[k,v]: times) {
                if (v == 1) {
                    res = max(res, k);
                }
            }
            return res;
        }
        bool is_first = true, is_end = true;
        for (int i = 1; i < n; i++) {
            if (start == nums[i]) {
                is_first = false;
                break;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (end == nums[i]) {
                is_end = false;
                break;
            }
        }
        if (is_end and is_first) {
            return max(end, start);
        } else if (is_end) {
            return end;
        } else if (is_first) {
            return start;
        } else {
            return -1;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    vector<int> eg1 = {3, 9, 2, 1, 7};
    cout << test.largestInteger(eg1, 3) << endl;;
    vector<int> eg2 = {0, 0};
    cout << test.largestInteger(eg2, 2) << endl;;
    vector<int> eg3 = {0, 0};
    cout << test.largestInteger(eg3, 1) << endl;;
    vector<int> eg4 = {7, 5, 9, 10, 0, 12, 3, 12, 10};
    cout << test.largestInteger(eg4, 1) << endl;;
}


//
// Created by ASUS on 2025/3/2.
//
