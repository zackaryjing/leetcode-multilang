// problem: https://leetcode.cn/problems/champagne-tower/?envType=problem-list-v2&envId=3rBpGyas
#include <iostream>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;


class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector cnts(2, vector(query_row + 1, 0.0));
        int cur = 0;
        cnts[cur][0] = poured;
        for (int i = 1; i <= query_row; ++i) {
            const int last = cur;
            cur ^= 1;
            cnts[cur][0] = 0;
            for (int j = 0; j < i; ++j) {
                if (cnts[last][j] > 1) {
                    const double diff = (cnts[last][j] - 1.0) / 2;
                    cnts[cur][j] += diff;
                    cnts[cur][j + 1] = diff;
                } else {
                    cnts[cur][j + 1] = 0;
                }
            }
        }
        return min(cnts[cur][query_glass], 1.0);
    }
};

class Solution2 {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector cnts(2, vector(query_row + 1, 0.0));
        int cur = 0;
        cnts[cur][0] = poured;
        for (int i = 1; i <= query_row; ++i) {
            const int last = cur;
            cur ^= 1;
            cnts[cur][0] = 0;
            if (cnts[last][0] > 1) {
                cnts[cur][0] = (cnts[last][0] - 1) / 2;
            }
            for (int j = 1; j <= i; ++j) {
                cnts[cur][j] = 0;
                if (cnts[last][j] > 1) {
                    cnts[cur][j] += (cnts[last][j] - 1) / 2;
                }
                if (cnts[last][j - 1] > 1) {
                    cnts[cur][j] += (cnts[last][j - 1] - 1) / 2;
                }
            }
        }
        return min(cnts[cur][query_glass], 1.0);
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.champagneTower(25, 6, 1) << endl;
    cout << test.champagneTower(1, 1, 1) << endl;
    cout << test.champagneTower(100000009, 33, 17) << endl;
}

//
// Created By jing At 2025-10-21 20:08
//
