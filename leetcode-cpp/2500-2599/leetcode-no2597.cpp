#include <iostream>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    int beautifulSubsets(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_set<int> vis;
        int n = static_cast<int>(nums.size());
        pmr::unordered_map<int, vector<int> > chain;
        int ans = 1;
        for (int i = 0; i < n; i++) {
            int last_temp = nums[i];
            if (vis.contains(last_temp)) {
                continue;
            }
            vis.insert(last_temp);

            int cnt = 1;
            while (i + 1 < n and nums[i + 1] == nums[i]) {
                i++, cnt++;
            }

            bool have_found = false;
            for (int j = i; j < n; j++) {
                if (nums[j] - last_temp == k) {
                    have_found = true;
                    chain[nums[i]].push_back(cnt);
                    last_temp = nums[j];
                    vis.insert(nums[j]);

                    cnt = 1;
                    while (j + 1 < n and nums[j + 1] == nums[j]) {
                        j++, cnt++;
                    }
                } else if (nums[j] > k + last_temp) {
                    break;
                }
            }
            if (have_found) {
                chain[nums[i]].push_back(cnt);
            } else {
                ans *= 0x1 << cnt;
            }
        }


        for (auto &[k,v]: chain) {
            int size = static_cast<int>(v.size());
            v[size - 1] = (0x1 << v[size - 1]) - 1;
            v[size - 2] = (0x1 << v[size - 2]) - 1;
            v[size - 2] += v[size - 1];

            for (int i = size - 3; i >= 0; i--) {
                v[i] = (0x1 << v[i]) - 1;
                v[i] = v[i] * v[i + 2] + v[i + 1] + v[i];
            }
            ans *= v[0] + 1;
        }
        return ans - 1;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.beautifulSubsets(*make_unique<vector<int> >(vector{1, 2, 2, 2, 4, 4, 6, 6, 6, 6, 6}), 2) << endl;;
    // cout << test.beautifulSubsets(*make_unique<vector<int> >(vector{2, 4, 6, 9, 11, 100, 102, 111, 1}), 2) << endl;;
    // cout << test.beautifulSubsets(*make_unique<vector<int> >(vector{1}), 1) << endl;;
    cout << test.beautifulSubsets(*make_unique<vector<int> >(vector{1}), 1) << endl;;
    cout << test.beautifulSubsets(*make_unique<vector<int> >(vector{
                                          1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
                                          1000, 1000, 1000, 1000, 1000
                                      }
                                  ), 1) << endl;;
    cout << test.beautifulSubsets(*make_unique<vector<int> >(vector{1, 2, 3, 3}), 1) << endl;;
}

class Solution2 {
    // 暴力解
public:
    int beautifulSubsets(vector<int> &nums, int k) {
        vector<unordered_set<int> > dp;
        const int n = static_cast<int>(nums.size());
        for (int i = 0; i < n; i++) {
            auto num = nums[i];
            int t = num + k, b = num - k;
            int size = static_cast<int>(dp.size());
            for (int j = 0; j < size; j++) {
                auto s = dp[j];
                if (not(s.contains(t) or s.contains(b))) {
                    s.insert(num);
                    dp.push_back(s);
                }
            }
            dp.emplace_back(unordered_set{num});
        }
        for (auto &s: dp) {
            for (auto h: s) {
                cout << h << " ";
            }
            cout << endl;
        }
        return dp.size();
    }
};


//
// Created by ASUS on 2025/3/7.
//
