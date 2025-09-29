// problem: https://leetcode.cn/problems/distinct-points-reachable-after-substring-removal/description/
#include <iostream>
#include <set>
#include <vector>

using namespace std;
class Solution {
public:
    int distinctPoints(string s, int k) {
        int n = s.length();
        auto res = set<pair<int, int>>();
        vector<pair<int, int>> path;
        path.reserve(s.length() + 1);
        path.emplace_back(0, 0);
        int x = 0, y = 0;
        for (auto ch: s) {
            switch (ch) {
                case 'D':
                    y -= 1;
                    break;
                case 'U':
                    y += 1;
                    break;
                case 'L':
                    x -= 1;
                    break;
                case 'R':
                    x += 1;
                    break;
                default:
                    break;
            }
            path.emplace_back(x, y);
        }
        auto [lx, ly] = path[n - 1];
        for (int i = k; i <= n; ++i) {
            auto [sx, sy] = path[i - k];
            auto [ex, ey] = path[i];
            int mx = ex - sx;
            int my = ey - sy;
            res.emplace(lx - mx, ly - my);
        }

        return max(static_cast<int>(res.size()), 1);
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.distinctPoints("LUL", 1) << endl;
    cout << test.distinctPoints("UDLR", 4) << endl;
    cout << test.distinctPoints("UU", 1) << endl;
    cout << test.distinctPoints("UD", 1) << endl;
}

//
// Created By Zackary At 2025-09-27 23:23
//
