// problem: https://leetcode.cn/problems/array-of-doubled-pairs/?envType=problem-list-v2&envId=3rBpGyas
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include <set>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int> &arr) {
        ranges::sort(arr, [](auto a, auto b) { return abs(a) == abs(b) ? a < b : abs(a) < abs(b); });
        const int n = arr.size();
        vector<bool> used(n);
        int left = 0, right = 1;
        for (int i = 0; i < n / 2; ++i) {
            const int target = arr[left] * 2;
            used[left] = true;
            bool found = false;
            for (int j = right; j < n; ++j)
                if (not used[j] and arr[j] == target) {
                    found = true;
                    used[j] = true;
                    right = j;
                    break;
                }
            if (not found)
                return false;
            while (left < n and used[left])
                left++;
        }
        return true;
    }
};

class Solution2 {
public:
    bool canReorderDoubled(vector<int> &arr) {
        const int n = arr.size();
        multiset nums(arr.begin(), arr.end(), [](auto a, auto b) {
            return abs(a) == abs(b) ? a < b : abs(a) < abs(b);
        });
        for (int i = 0; i < n / 2; ++i) {
            const int target = *nums.begin() * 2;
            nums.erase(nums.begin());
            auto pos = nums.find(target);
            if (pos != nums.end()) {
                nums.erase(pos);
            } else {
                return false;
            }
        }
        return true;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.canReorderDoubled(temp_vector({4, -2, 2, -4})) << " e:t" << endl;;
    // cout << test.canReorderDoubled(temp_vector({2, 1, 2, 6})) << " e:f" << endl;;
    // cout << test.canReorderDoubled(temp_vector({3, 1, 3, 6})) << " e:f" << endl;;
    // cout << test.canReorderDoubled(temp_vector({2, 4, 0, 0})) << " e:t" << endl;;
}

//
// Created By ASUS At 2026-02-12 15:59
//
