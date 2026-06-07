// problem: https://leetcode.cn/problems/pass-the-pillow/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    int passThePillow(int n, int time) {
        int cnt = (time) / (n - 1);
        if (cnt % 2 == 0) {
            return time % (n - 1) + 1;
        }
        return n - 1 - time % (n - 1) + 1;
    }
};


class Solution {
public:
    int passThePillow(int n, int time) {
        return time / (n - 1) % 2 ? n - time % (n - 1) : time % (n - 1) + 1;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.passThePillow(4, 5) << endl;
    cout << test.passThePillow(3, 2) << endl;
}

//
// Created By jing At 2026-05-31 19:27
//
