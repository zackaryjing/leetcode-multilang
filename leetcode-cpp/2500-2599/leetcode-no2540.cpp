// problem: https://leetcode.cn/problems/minimum-common-value/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;
        while (i < n or j < m) {
            if (nums1[i] == nums2[j]) return nums1[i];
            if (nums1[i] > nums2[j]) {
                if (j++; j == m) return -1;
            } else if (nums1[i] < nums2[j]) {
                if (i++; i == n) return -1;
            }
        }
        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
}

//
// Created By jing At 2026-06-30 21:27
//
