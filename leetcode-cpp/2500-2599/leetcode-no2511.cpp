// problem:
// https://leetcode.cn/problems/maximum-enemy-forts-that-can-be-captured/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int captureForts(vector<int> &forts) {
        int cnt = 0, last = 2, res = 0;
        for (auto fort: forts) {
            if (fort) {
                if (last != fort and last != 2) res = max(res, cnt);
                last = fort, cnt = 0;
            } else {
                cnt++;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.captureForts(temp_vector({1, 0, 0, -1, 0, 0, 0, 0, 1})) << endl;
    cout << test.captureForts(temp_vector({0, 0, 1, -1})) << endl;
}

//
// Created By jing At 2026-06-19 21:46
//
