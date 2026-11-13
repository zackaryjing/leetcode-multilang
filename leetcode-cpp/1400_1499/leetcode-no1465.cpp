// problem:
// https://leetcode.cn/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>


using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts) {
        long long hMax = 0, wMax = 0;
        long long lastH = 0, lastW = 0;
        const long long MOD = 1000000007;
        ranges::sort(horizontalCuts);
        ranges::sort(verticalCuts);
        for (const auto hc: horizontalCuts) hMax = max(hMax, hc - lastH), lastH = hc;
        hMax = max(hMax, h - lastH);
        for (const auto wc: verticalCuts) wMax = max(wMax, wc - lastW), lastW = wc;
        wMax = max(wMax, w - lastW);
        return hMax * wMax % MOD;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxArea(5, 4, temp_vector({1, 2, 4}), temp_vector({1, 3})) << endl;
}

//
// Created By jing At 2026-09-10 18:39
//
