#include "../utils/vector_helper.h"
#include <iostream>
#include <memory>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int n = nums.size();
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i];
            nums[i] = total;
        }
        nums.insert(nums.begin(), 0);
        bool has_ans = false;
        int i = 1;
        for (; i < n + 1; i++) {
            if (nums[i - 1] == (nums[n] - nums[i])) {
                has_ans = true;
                break;
            }
        }
        return has_ans ? i - 1 : -1;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.pivotIndex(*make_unique<vector<int> >(vector{1, 7, 3, 6, 5, 6})) << endl;
    cout << test.pivotIndex(*make_unique<vector<int> >(vector{1, 2, 3})) << endl;
    cout << test.pivotIndex(*make_unique<vector<int> >(vector{2, 1, -1})) << endl;
    cout << test.pivotIndex(*make_unique<vector<int> >(vector{-1, -1, -1, -1, -1, 0})) << endl;
    cout << test.pivotIndex(*make_unique<vector<int> >(vector{-1})) << endl;
    cout << test.pivotIndex(*make_unique<vector<int> >(vector{-1,-1})) << endl;
}


//
// Created by ASUS on 2025/2/20.
//
