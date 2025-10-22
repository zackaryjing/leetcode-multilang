// problem: https://leetcode.cn/problems/largest-triangle-area/?envType=problem-list-v2&envId=3rBpGyas
#include <cmath>
#include <iostream>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>> &points) {
        int n = points.size();
        double res = 0;
        for (int i = 0; i < n; ++i) {
            const double x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                const double x2 = points[j][0], y2 = points[j][1];
                const double as = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                for (int k = j + 1; k < n; ++k) {
                    const double x3 = points[k][0], y3 = points[k][1];
                    const double bs = (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2);
                    const double cs = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);
                    res = max(res, 2 * (as * bs + as * cs + bs * cs) - as * as - bs * bs - cs * cs);
                }
            }
        }
        return sqrt(res) / 4.0;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.largestTriangleArea(temp_vector({{1, 0}, {0, 0}, {0, 1}})) << endl;
    cout << test.largestTriangleArea(temp_vector({{0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}})) << endl;
}

//
// Created By jing At 2025-10-21 22:39
//
