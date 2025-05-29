// problem: https://leetcode.cn/problems/find-in-mountain-array/
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class MountainArray {
public:
    int get(int index) {
        return data[index];
    }

    int length() {
        return data.size();
    }

    vector<int> data;

    MountainArray(vector<int> data):
        data(data) {

    }
};

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int length = mountainArr.length();
        auto getCenter = [&]() {
            int left = 0;
            int right = length - 1;
            while (left < right) {
                int mid = left + (right - left) / 2;
                int first = mountainArr.get(mid);
                int second = mountainArr.get(mid + 1);
                if (first > second) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        };

        auto getTarget = [&](int left, int right, function<bool(int, int)> cmp) {
            while (left < right) {
                int mid = left + (right - left) / 2;
                int value = mountainArr.get(mid);
                if (cmp(value, target)) {
                    right = mid - 1;
                } else if (cmp(target, value)) {
                    left = mid + 1;
                } else {
                    return mid;
                }
            }
            if (target == mountainArr.get(left)) {
                return left;
            }
            return -1;
        };
        int m = getCenter();
        int l = getTarget(0, m, [](int a, int b) { return a > b; });
        if (l != -1) {
            return l;
        }
        int r = getTarget(m + 1, length - 1, [](int a, int b) { return a < b; });
        return r;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    // auto m1 = MountainArray(vector<int>({1, 2, 3, 4, 5, 3, 1}));
    // cout << test.findInMountainArray(1, m1) << endl;
    auto m2 = MountainArray(vector<int>({0, 5, 3, 1}));
    cout << test.findInMountainArray(1, m2) << endl;
    cout << "" << endl;
}

//
// Created By Zackary At 2025-05-28 17:55:57
//
