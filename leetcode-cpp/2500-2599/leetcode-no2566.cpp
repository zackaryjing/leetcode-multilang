// problem:
#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

// time spent: 37:41

class Solution {
public:
    int minMaxDifference(int num) {
        int numCopy = num;
        int maxNum = 0, minNum = 0;
        const int n = 1000000000;
        int first = -1;
        bool inNum = false;
        for (auto k = n; k >= 1; k /= 10) {
            maxNum *= 10;
            int digit = num / k;
            num %= k;
            if (digit > 0) {
                inNum = true;
            }
            if (inNum and first < 0 and digit < 9) {
                first = digit;
            }
            if (digit == first) {
                maxNum += 9;
            } else {
                maxNum += digit;
            }
        }
        num = numCopy;
        first = -1;
        inNum = false;
        for (auto k = n; k >= 1; k /= 10) {
            minNum *= 10;
            int digit = num / k;
            num %= k;
            if (digit > 0) {
                inNum = true;
            }
            if (inNum and first < 0) {
                first = digit;
            }
            if (digit != first) {
                minNum += digit;
            }
        }
        return maxNum - minNum;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minMaxDifference(11891) << ", 99009" << endl;
    cout << test.minMaxDifference(90) << ", 99" << endl;
}

//
// Created By Zackary At 2025-06-14 12:43:31
//
