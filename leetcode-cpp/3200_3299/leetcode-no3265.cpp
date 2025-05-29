// problem: https://leetcode.cn/problems/count-almost-equal-pairs-i/
#include <chrono>
#include <iostream>
#include <vector>

#include "../utils/vector_helper.h"
using namespace std;

// time spent 22:08

class Solution {
public:
    int countPairs(vector<int> &nums) {
        int n = nums.size();
        auto check = [](int num1, int num2) {
            bool first = false;
            bool second = false;
            int a = 0, b = 0;
            while (num1 > 0 or num2 > 0) {
                if (num1 % 10 != num2 % 10) {
                    if (second) {
                        return false;
                    }
                    if (first) {
                        if (num1 % 10 == b and num2 % 10 == a) {
                            second = true;
                        } else {
                            return false;
                        }
                    } else {
                        first = true;
                        a = num1 % 10;
                        b = num2 % 10;
                    }
                }
                num1 /= 10;
                num2 /= 10;
            }
            return first ? second : true;
        };
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int first = nums[i];
                int second = nums[j];
                if (check(first,second)) {
                    res += 1;
                }
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.countPairs(temp_vector<int>({3,12,30,17,21})) << endl;;
    cout << test.countPairs(temp_vector<int>({1,1,1,1,1})) << endl;;
    cout << test.countPairs(temp_vector<int>({8,12,5,5,14,3,12,3,3,6,8,20,14,3,8})) << endl;;
    cout << "" << endl;
}

//
// Created By Zackary At 2025-05-28 22:24:58
//
