#include <iostream>
#include <memory>
#include <ranges>
#include <unordered_map>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    long long beautifulSubarrays(vector<int> &nums) {
        int n = nums.size();
        int cur = 0;
        long long ans = 0LL;
        unordered_map<int, long long> times;
        for (int i = 0; i < n; i++) {
            times[cur]++;
            cur ^= nums[i];
        }
        times[cur]++;
        for (const long long v: views::values(times)) {
            ans += v * (v - 1) / 2;
        }
        return ans;
    }
};


class Solution2 {
    // 超时
public:
    long long beautifulSubarrays(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        long long ans = 0LL;
        for (int i = 0; i < n; i++) {
            dp[i] = nums[i];
            if (dp[i] == 0) {
                ans += 1;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                dp[j] = dp[j] ^ nums[j + i];
                if (dp[j] == 0) {
                    ans += 1;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.beautifulSubarrays(*make_unique<vector<int> >(vector{4, 3, 1, 2, 4})) << endl;
    cout << test.beautifulSubarrays(*make_unique<vector<int> >(vector{1, 10, 4})) << endl;
}


//
// Created by ASUS on 2025/3/6.
//
