// problem: https://leetcode.cn/problems/slowest-key/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    char slowestKey(vector<int> &releaseTimes, string keysPressed) {
        int n = releaseTimes.size(), mxTime = releaseTimes[0];
        char res = keysPressed[0];
        for (int i = 1; i < n; ++i) {
            int time = releaseTimes[i] - releaseTimes[i - 1];
            if (time > mxTime || (time == mxTime and keysPressed[i] > res)) {
                mxTime = time;
                res = keysPressed[i];
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.slowestKey(temp_vector({9, 29, 49, 50}), "cbcd") << endl;
}

//
// Created By ASUS At 2026-05-09 17:53
//
