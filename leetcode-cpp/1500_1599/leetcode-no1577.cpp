// problem: https://leetcode.cn/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/
#include <algorithm>
#include <format>
#include <iostream>
#include <ranges>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    int find_match(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<long long, int> nums_second;
        for (auto num2: nums2) {
            nums_second[num2]++;
        }
        int res = 0;
        for (auto num: nums1) {
            long long target = static_cast<long long>(num) * static_cast<long long>(num);
            for (auto [num2, cnt]: nums_second) {
                if (target % num2 == 0) {
                    long long to_find = target / num2;
                    auto p = nums_second.find(to_find);
                    if (p == nums_second.end()) {
                        continue;
                    }
                    int cnt2 = p->second;
                    if (cnt2 > 0) {
                        if (num2 * num2 == target) {
                            res += cnt2 * (cnt2 - 1);
                        } else {
                            res += cnt * cnt2;
                        }
                    }
                }
            }
        }
        return res / 2;
    }
    int numTriplets(vector<int> &nums1, vector<int> &nums2) {
        return find_match(nums1, nums2) + find_match(nums2, nums1);
    }
};

class Solution2 {
public:
    int find_match(vector<int> &nums1, vector<int> &nums2) {
        int res = 0;
        int n = nums1.size();
        int m = nums2.size();
        for (int i = 0; i < n; ++i) {
            int second_pos = m - 1;
            int first_pos = 0;
            long long target = static_cast<long long>(nums1[i]) * static_cast<long long>(nums1[i]);
            while (first_pos < second_pos) {
                long long first_num = nums2[first_pos];
                if (target % first_num == 0) {
                    long long goal = target / first_num;
                    while (second_pos > first_pos) {
                        int second_num = nums2[second_pos];
                        if (second_num < goal) {
                            break;
                        }
                        if (second_num == goal) {
                            // cout << "i: " << i << " d: " << first_pos << " " << second_pos << std::endl;
                            res += 1;
                        }
                        second_pos -= 1;
                    }
                }
                second_pos = m - 1;
                first_pos += 1;
            }
        }
        return res;
    }

    int numTriplets(vector<int> &nums1, vector<int> &nums2) {
        int res = 0;
        ranges::sort(nums1);
        ranges::sort(nums2);
        res += find_match(nums1, nums2);
        res += find_match(nums2, nums1);
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.numTriplets(temp_vector({7, 4}), temp_vector({5, 2, 8, 9})) << endl;
    cout << test.numTriplets(temp_vector({1, 1}), temp_vector({1, 1, 1})) << endl;
    cout << test.numTriplets(temp_vector({7, 7, 8, 3}), temp_vector({1, 2, 9, 7})) << endl;
    cout << test.numTriplets(temp_vector({43024, 99908}), temp_vector({1864})) << endl;
}

//
// Created By jing At 2025-09-28 17:56
//
