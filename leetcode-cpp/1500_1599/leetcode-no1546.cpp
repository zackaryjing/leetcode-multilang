#include <algorithm>
#include <iostream>
#include <memory>
#include <unordered_set>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    int maxNonOverlapping(vector<int> &nums, int target) {
        size_t n = nums.size();
        unordered_set<int> show = {0};
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (show.contains(sum - target)) {
                ans += 1;
                show = {0};
                sum = 0;
            } else {
                show.insert(sum);
            }
        }
        return ans;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxNonOverlapping(*make_unique<vector<int> >(vector{0, 0, 0}), 0) << endl;
    cout << test.maxNonOverlapping(*make_unique<vector<int> >(vector{-2, 6, 6, 3, 5, 4, 1, 2, 8}), 10) << endl;
    cout << endl;
}


//
// Created by ASUS on 2025/2/24.
//
