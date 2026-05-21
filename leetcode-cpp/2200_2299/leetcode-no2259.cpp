// problem:
// https://leetcode.cn/problems/remove-digit-from-number-to-maximize-result/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size(), tobeDelete = n - 1;
        for (int i = 0; i < n; ++i) {
            if (number[i] == digit and i + 1 < n and number[i + 1] != digit) {
                tobeDelete = i;
                if (number[i] < number[i + 1]) break;
            }
        }
        number.erase(number.begin() + tobeDelete);
        return number;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.removeDigit("123", '3') << endl;
    cout << test.removeDigit("1231", '1') << endl;
    cout << test.removeDigit("57577", '5') << endl;
    cout << test.removeDigit("73197", '7') << endl;
}

//
// Created By jing At 2026-05-06 19:01
//
