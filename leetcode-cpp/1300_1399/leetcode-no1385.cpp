// problem:
// https://leetcode.cn/problems/find-the-distance-value-between-two-arrays/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d) {
        ranges::sort(arr2);
        int n = arr1.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            auto closest = lower_bound(arr2.begin(), arr2.end(), arr1[i]);
            int dist = INT_MAX;
            if (closest != arr2.end()) {
                dist = min(dist, *closest - arr1[i]);
            }
            if (closest != arr2.begin()) {
                dist = min(dist, arr1[i] - *(closest - 1));
            }
            if (dist > d) res++;
        }
        return res;
    }
};

class Solution {
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d) {
        ranges::sort(arr2), ranges::sort(arr1);
        int n = arr1.size(), m = arr2.size(), index = 0, res = 0;
        for (const int &num: arr1) {
            while (index < m and arr2[index] <= num) index++;
            int dist = INT_MAX;
            if (index > 0) dist = num - arr2[index - 1];
            if (index < m) dist = min(dist, arr2[index] - num);
            if (dist > d) res++;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.findTheDistanceValue(temp_vector({4, 5, 8}), temp_vector({10, 9, 1, 8}), 2);
    cout << test.findTheDistanceValue(temp_vector({1, 4, 2, 3}), temp_vector({-4, -3, 6, 10, 20, 30}), 3);
}

//
// Created By jing At 2026-05-25 18:17
//
