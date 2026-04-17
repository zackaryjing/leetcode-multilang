// problem: https://leetcode.cn/problems/sum-of-all-odd-length-subarrays/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int> &arr) {
        int n = arr.size(), res = 0, a = 0, b = n - 1;
        for (int i = 0; i < n; ++i) {
            res += (1 + a / 2 + b / 2 + (a * b + 1) / 2) * arr[i];
            a++, b--;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.sumOddLengthSubarrays(temp_vector({1, 4, 2, 5, 3})) << endl;
}

//
// Created By ASUS At 2026-04-16 17:47
//
