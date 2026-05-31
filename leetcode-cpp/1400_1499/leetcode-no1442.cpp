// problem:
// https://leetcode.cn/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int countTriplets(vector<int> &arr) {
        int n = arr.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int cur = arr[i];
            for (int j = i + 1; j < n; ++j) {
                cur ^= arr[j];
                res += (cur == 0) ? j - i : 0;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.countTriplets(temp_vector({7, 11, 12, 9, 5, 2, 7, 17, 22})) << endl;
    cout << test.countTriplets(temp_vector({1, 3, 5, 7, 9})) << endl;
}

//
// Created By jing At 2026-05-29 21:22
//
