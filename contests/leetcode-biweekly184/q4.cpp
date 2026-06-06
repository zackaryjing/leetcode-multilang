// problem: https://leetcode.cn/contest/biweekly-contest-184/problems/maximum-score-with-co-prime-element/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_map>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    int maxScore(vector<int> &nums, int maxVal) {
        const auto gcd = [](int a, int b) {
            while (b != 0) {
                int oldb = b;
                b = a % b;
                a = oldb;
            }
            return a;
        };
        int n = nums.size();
        int res = 0;
        if (n == 1)
            return max(nums[0], maxVal - 1);
        for (int i = maxVal; i >= 1; --i) {
            int cnts = 0;
            bool hasSame = false;
            for (int j = 0; j < n; ++j) {
                if (i == nums[j]) {
                    hasSame = true;
                }
                if (gcd(i, nums[j]) > 1) {
                    cnts++;
                }
            }
            // cout << "i: " << i << endl;
            // cout << "cnts: " << cnts << endl;
            // res = max(res, hasSame ? i - cnts + 1 : (cnts >= 1 ? i - cnts : i - cnts - 1));
            res = max(res, hasSame ? i - cnts + 1 : i - max(cnts, 1));
            // res = max(res, i - cnts - 1);
        }
        // cout << "res : " << res << endl;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > maxVal) {
                int temp = nums[i];
                int cnts = 0;
                bool hasSame = false;
                for (int j = 0; j < n; ++j) {
                    if (temp == nums[j]) {
                        hasSame = true;
                    }
                    if (gcd(temp, nums[j]) > 1) {
                        cnts++;
                    }
                }
                // cout << "hasSame: " << hasSame << endl;
                res = max(res, hasSame ? temp - cnts + 1 : temp - cnts);
            }
        }
        return res;
    } // 976
};


class Solution {
public: // 980
    // Seems to be correct but [TLE].
    int maxScore(vector<int> &nums, int maxVal) {
        unordered_map<long long, bool> cache;
        const auto gcd = [](int a, int b) -> bool {
            while (b != 0) {
                int oldb = b;
                b = a % b;
                a = oldb;
            }
            return a > 1;
        };
        int n = nums.size();
        int res = 0;
        ranges::sort(nums);
        ranges::reverse(nums);
        if (n == 1)
            return max(nums[0], maxVal - 1);
        for (int i = maxVal; i >= 1; --i) {
            int cnts = 0;
            bool hasSame = false;
            if (i <= res)
                break;
            for (int j = 0; j < n; ++j) {
                if (i == nums[j])
                    hasSame = true;
                if (gcd(i, nums[j]))
                    cnts++;
            }
            res = max(res, hasSame ? i - cnts + 1 : i - max(cnts, 1));
        }
        for (int i = 0; i < n; ++i) {
            const int temp = nums[i];
            if (temp > maxVal and temp > res) {
                int cnts = 0;
                for (int j = 0; j < n; ++j) {
                    if (gcd(temp, nums[j]))
                        cnts++;
                }
                res = max(res, temp - cnts + 1);
            } else {
                break;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxScore(temp_vector({3, 4, 6}), 5) << " e 4" << endl;
    cout << test.maxScore(temp_vector({1, 2, 3}), 4) << " e 3" << endl;
    cout << test.maxScore(temp_vector({2, 2}), 1) << " e 1" << endl;
    cout << test.maxScore(temp_vector({3, 4, 6}), 5) << " e 4" << endl;
    cout << test.maxScore(temp_vector({1, 2, 3}), 4) << " e 3" << endl;
    cout << test.maxScore(temp_vector({458, 915}), 709) << " e 915" << endl;
    cout << test.maxScore(temp_vector({42}), 312) << " e 311" << endl;
    cout << test.maxScore(temp_vector({943, 56, 478, 754, 535, 283, 869, 539, 447}), 943) << " e 943" << endl;
    cout << test.maxScore(temp_vector({216, 243}), 386) << " e 385" << endl;
    cout << test.maxScore(temp_vector({160, 438, 177}), 477) << " e 475" << endl;
}

//
// Created By jing At 2026-06-06 23:16
//
