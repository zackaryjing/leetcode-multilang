// problem: https://leetcode.cn/problems/peak-index-in-a-mountain-array/?envType=problem-list-v2&envId=3rBpGyas
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int> &arr) {
        const int n = arr.size();
        int left = 0;
        int right = n - 2;
        while (left < right) {
            if (const int mid = (left + right + 1) / 2; arr[mid] < arr[mid + 1]) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left + 1;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.peakIndexInMountainArray(temp_vector({0, 10, 5, 2})) << endl;
    cout << test.peakIndexInMountainArray(temp_vector({0, 1})) << endl;
    cout << test.peakIndexInMountainArray(temp_vector({0, 2, 1, 0})) << endl;
}

//
// Created By ASUS At 2025-12-19 13:09
//
