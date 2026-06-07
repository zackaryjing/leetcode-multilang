// problem:  https://leetcode.cn/problems/alternating-digit-sum/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int alternateDigitSum(int n) {
        int index = 0, res = 0;
        while (n > 0) {
            res += (n % 10) * (++index & 1 ? 1 : -1);
            n /= 10;
        }
        return index & 1 ? res : -res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.alternateDigitSum(521) << endl;
    cout << test.alternateDigitSum(111) << endl;
}

//
// Created By jing At 2026-06-02 15:29
//
