// problem: https://leetcode.cn/problems/check-if-n-and-its-double-exist/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int> &arr) {
        auto exist = vector<bool>(5000);
        int zcnt = 0;
        for (int i: arr) {
            exist[i + 2500] = true;
            if (i == 0) zcnt += 1;
        }
        if (zcnt >= 2) return true;
        for (int i: arr) {
            if (i and not(i & 1) and exist[i / 2 + 2500]) {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
}

//
// Created By jing At 2026-05-25 16:38
//
