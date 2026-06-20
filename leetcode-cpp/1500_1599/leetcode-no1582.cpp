// problem: https://leetcode.cn/problems/special-positions-in-a-binary-matrix/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> pos;
        pos.reserve(n);
        for (int i = 0; i < n; ++i) {
            int ocnt = 0;
            int p = 0;
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 1) {
                    p = j;
                    ocnt++;
                }
            }
            if (ocnt == 1) pos.push_back(p);
        }
        int res = 0;
        for (const auto &col: pos) {
            int ocnt = 0;
            for (int i = 0; i < n; ++i) {
                ocnt += (mat[i][col] == 1);
            }
            if (ocnt == 1) {
                res++;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
}

//
// Created By ASUS At 2026-04-10 22:09
//
