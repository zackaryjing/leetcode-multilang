// problem:
// https://leetcode.cn/problems/equal-sum-arrays-with-minimum-number-of-operations/description/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    int minOperations(vector<int> &nums1, vector<int> &nums2) {
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        if (sum1 == sum2) return 0;
        if (sum2 < sum1) {
            swap(nums1, nums2);
        }
        int diff = abs(sum1 - sum2);
        ranges::sort(nums1);
        ranges::sort(nums2);
        ranges::reverse(nums2);
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;
        int tot = 0;
        while (i < n or j < m) {
            if (i < n and j < m) {
                int offer1 = 6 - nums1[i];
                int offer2 = nums2[j] - 1;
                if (offer1 >= offer2) {
                    i++;
                    tot += offer1;
                } else {
                    j++;
                    tot += offer2;
                }
            } else if (i < n) {
                tot += 6 - nums1[i++];
            } else if (j < m) {
                tot += nums2[j++] - 1;
            }
            if (tot >= diff) {
                return i + j;
            }
        }
        return -1;
    }
};


class Solution {
public:
    int minOperations(vector<int> &nums1, vector<int> &nums2) {
        vector<int> bucket1(6), bucket2(6);
        int sum1 = 0, sum2 = 0;
        int n = nums1.size(), m = nums2.size();
        for (int i = 0; i < n; ++i) {
            sum1 += nums1[i];
            bucket1[nums1[i] - 1]++;
        }
        for (int j = 0; j < m; ++j) {
            sum2 += nums2[j];
            bucket2[nums2[j] - 1]++;
        }
        if (sum1 == sum2) return 0;
        if (sum2 < sum1) {
            swap(bucket1, bucket2);
        }
        int diff = abs(sum1 - sum2);
        int res = 0;
        for (int i = 0; i < 5; ++i) {
            int offer = (bucket1[i] + bucket2[5 - i]) * (5 - i);
            if (offer >= diff) {
                res += (diff + (5 - i - 1)) / (5 - i);
                diff -= offer;
                break;
            }
            res += bucket1[i] + bucket2[5 - i];
            diff -= offer;
        }
        return diff <= 0 ? res : -1;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minOperations(temp_vector({1, 2, 3, 4, 5, 6}), temp_vector({1, 1, 2, 2, 2, 2})) << endl;
}

//
// Created By ASUS At 2026-06-07 15:16
//
