// problem: https://leetcode.cn/problems/count-the-digits-that-divide-a-number/?envType=problem-list-v2&envId=FeuPdeiM
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int countDigits(int num) {
        int res = 0;
        int ori = num;
        while (num > 0) {
            if (ori % (num % 10) == 0) res++;
            num /= 10;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.countDigits(7) << endl;
    cout << test.countDigits(121) << endl;
    cout << test.countDigits(1248) << endl;
}

//
// Created By jing At 2026-06-18 16:28
//