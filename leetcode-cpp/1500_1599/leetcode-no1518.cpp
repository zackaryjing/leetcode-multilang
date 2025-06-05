// problem: https://leetcode.cn/problems/water-bottles/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = 0;
        while (numBottles >= numExchange) {
            const int temp = numBottles;
            const int empty = numBottles - numBottles % numExchange;
            res += empty;
            numBottles -= empty;
            numBottles += temp / numExchange;
        }
        res += numBottles;
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.numWaterBottles(9, 3) << endl;
    cout << test.numWaterBottles(15, 4) << endl;
}

//
// Created By Zackary At 2025-06-05 14:50:13
//
