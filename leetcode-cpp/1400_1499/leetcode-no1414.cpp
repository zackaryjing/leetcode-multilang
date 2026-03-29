// problem:  https://leetcode.cn/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/?envType=problem-list-v2&envId=3rBpGyas
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    int findMinFibonacciNumbers(int k) {
        int first = 1, second = 1;
        vector fibonacci = {1};
        while (second <= k) {
            fibonacci.push_back(second);
            second = first + second;
            first = second - first;
        }
        int res = 0, pos = fibonacci.size() - 1;
        while (k > 0) {
            while (k < fibonacci[pos]) {
                pos--;
            }
            k -= fibonacci[pos];
            res++;
        }
        return res;
    }
};


class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int first = 1, second = 1, res = 0;
        while (second <= k)
            second += first, first = second - first;
        for (; k > 0; k -= second, res++)
            while (k < second)
                first = second - first, second -= first;
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.findMinFibonacciNumbers(7) << endl;
    cout << test.findMinFibonacciNumbers(10) << endl;
    cout << test.findMinFibonacciNumbers(19) << endl;
}

//
// Created By ASUS At 2026-02-11 23:30
//
