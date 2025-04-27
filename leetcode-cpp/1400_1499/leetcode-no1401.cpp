// problem: https://leetcode.cn/problems/circle-and-rectangle-overlapping/
#include <algorithm>
#include <functional>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int dx = clamp(xCenter, x1, x2) - xCenter;
        int dy = clamp(yCenter, y1, y2) - yCenter;
        return dx * dx + dy * dy <= radius * radius;
    }
};


class Solution_2 {
public:
    // [Pass] too complex
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        auto check = [&](int x_center, int y_center, int x_sq, int y_low, int y_high)-> bool {
            int inner = radius * radius - (x_center - x_sq) * (x_center - x_sq);
            // cout << "inner: " << inner << endl;
            if (inner < 0) {
                return false;
            }
            double t = sqrt(inner);
            double y3 = t + y_center;
            double y4 = -t + y_center;
            // cout << 1 << endl;
            if (static_cast<double>(y_low) <= y3 and y3 <= static_cast<double>(y_high)) {
                // cout << x_sq << ", " << y_low << " " << y_high << endl;
                return true;
            }
            // cout << 2 << endl;
            if (static_cast<double>(y_low) <= y4 and y4 <= static_cast<double>(y_high)) {
                return true;
            }
            return false;
        };

        double xmid = static_cast<double>(x1 + x2) / 2.0f;
        double ymid = static_cast<double>(y1 + y2) / 2.0f;
        if ((xmid - xCenter) * (xmid - xCenter) + (ymid - yCenter) * (ymid - yCenter) < radius * radius) {
            return true;
        }
        if (x1 <= xCenter and xCenter <= x2 and y1 <= yCenter and yCenter <= y2) {
            return true;
        }

        return check(xCenter, yCenter, x1, y1, y2) or check(xCenter, yCenter, x2, y1, y2) or
               check(yCenter, xCenter, y1, x1, x2) or check(yCenter, xCenter, y2, x1, x2);

    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.checkOverlap(4, 9, 3, 1, 5, 2, 10) << endl;
    cout << test.checkOverlap(1, 0, 0, 1, -1, 3, 1) << endl;
    cout << test.checkOverlap(1, 1, 1, 1, -3, 2, -1) << endl;
    cout << test.checkOverlap(1, 0, 0, -1, 0, 0, 1) << endl;
}

//
// Created By Zackary At 2025-04-25 20:32:17
//
