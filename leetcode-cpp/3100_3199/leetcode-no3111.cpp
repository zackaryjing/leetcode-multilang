// problem: https://leetcode.cn/problems/minimum-rectangles-to-cover-points/
#include <algorithm>
#include <iostream>
#include <vector>
#include "../utils/vector_helper.h"
using namespace std;

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>> &points, int w) {
        const int n = points.size();
        vector<int> points_x;
        points_x.reserve(n);
        transform(points.begin(), points.end(), back_inserter(points_x),
           [](const vector<int> &point) { return point[0]; });
        ranges::sort(points_x);
        vector<int> cnts(n + 1);
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            while (points_x[i] - points_x[cur] > w) {
                cur++;
            }
            cnts[i + 1] = cnts[cur] + 1;
        }
        return cnts[n];
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minRectanglesToCoverPoints(temp_vector({{2, 1}, {1, 0}, {1, 4}, {1, 8}, {3, 5}, {4, 6}}), 1) << endl;
    cout << test.minRectanglesToCoverPoints(temp_vector({{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}}), 2) <<
            endl;
    cout << test.minRectanglesToCoverPoints(temp_vector({{2, 3}, {1, 2}}), 0) << endl;
}

//
// Created By Zackary At 2025-05-30 21:52:30
//
