// problem: https://leetcode.cn/problems/number-of-valid-clock-times/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int countTime(string time) {
        int hr1 = time[0] - '0', hr2 = time[1] - '0';
        int mn1 = time[3] - '0', mn2 = time[4] - '0';
        int res = 0;
        for (int hr = 0; hr < 24; ++hr) {
            for (int mn = 0; mn < 60; ++mn) {
                if ((hr1 > 10 || hr / 10 == hr1) and (hr2 > 10 || hr % 10 == hr2)) {
                    if ((mn1 > 10 || mn / 10 == mn1) and (mn2 > 10 | mn % 10 == mn2)) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.countTime("??:??") << endl;
    cout << test.countTime("0?:0?") << endl;
}

//
// Created By jing At 2026-05-07 20:49
//
