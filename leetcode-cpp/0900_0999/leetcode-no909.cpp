// problem:
#include <deque>
#include <iostream>
#include <vector>
#include "../utils/vector_helper.h"
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int n = board.size();
        int sq = n * n;
        deque toVis = {1};
        vector dists(sq + 1, -1);
        dists[1] = 0;
        auto idToPos = [&](int k)-> pair<int, int> {
            k -= 1;
            int bottomRow = k / n;
            int row = n - 1 - bottomRow;
            int col = bottomRow & 1 ? n - 1 - k % n : k % n;
            return {row, col};
        };
        while (not toVis.empty()) {
            int cur = toVis.front();
            toVis.pop_front();
            // cout << "cur: " << cur << ", curR: " << curR << ", curC: " << curC << endl;
            auto dist = dists[cur];
            for (int i = cur + 1; i <= min(cur + 6, sq); ++i) {
                auto [nxtR,nxtC] = idToPos(i);
                int nxt = board[nxtR][nxtC];

                int target = i;
                if (nxt > 0) {
                    target = nxt;
                }
                if (target == sq) {
                    return dist + 1;
                }
                if (dists[target] < 0) {
                    dists[target] = dist + 1;
                    toVis.push_back(target);
                }
            }
        }
        return dists[sq];
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.snakesAndLadders(temp_vector({{-1, 1, 2, -1}, {2, 13, 15, -1}, {-1, 10, -1, -1}, {-1, 6, 2, 8}})) <<
            endl;
    cout << test.snakesAndLadders(temp_vector({{-1, 18, -1, -1, -1, -1, -1, -1, -1, 68, -1},
                                               {-1, -1, 99, 24, -1, -1, -1, -1, -1, -1, -1},
                                               {-1, -1, 109, -1, -1, -1, 4, 93, -1, 79, 103},
                                               {-1, -1, -1, -1, -1, -1, -1, -1, 107, -1, 107},
                                               {37, 34, -1, -1, 64, -1, -1, -1, -1, 119, 56},
                                               {-1, -1, -1, -1, -1, -1, 64, -1, -1, -1, -1},
                                               {-1, -1, -1, 96, -1, -1, -1, -1, 107, -1, -1},
                                               {-1, 91, -1, 103, 11, 54, -1, 114, 36, 121, -1},
                                               {-1, 72, 69, 42, -1, -1, -1, -1, -1, -1, 81},
                                               {79, -1, -1, -1, -1, 47, -1, 97, 75, 75, -1},
                                               {-1, -1, -1, -1, -1, -1, -1, 71, -1, -1, -1}})) <<
            endl;
    cout << test.snakesAndLadders(temp_vector({{-1, 4, -1}, {6, 2, 6}, {-1, 3, -1}})) << endl;
    cout << test.snakesAndLadders(temp_vector({{-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1},
                                               {-1, -1, -1, -1, -1, -1}, {-1, 35, -1, -1, 13, -1},
                                               {-1, -1, -1, -1, -1, -1}, {-1, 15, -1, -1, -1, -1}})) << endl;
    cout << test.snakesAndLadders(temp_vector({{-1, -1}, {-1, 3}})) << endl;
    cout << test.snakesAndLadders(temp_vector({{-1, -1, -1, 46, 47, -1, -1, -1}, {51, -1, -1, 63, -1, 31, 21, -1},
                                               {-1, -1, 26, -1, -1, 38, -1, -1}, {-1, -1, 11, -1, 14, 23, 56, 57},
                                               {11, -1, -1, -1, 49, 36, -1, 48}, {-1, -1, -1, 33, 56, -1, 57, 21},
                                               {-1, -1, -1, -1, -1, -1, 2, -1},
                                               {-1, -1, -1, 8, 3, -1, 6, 56}})) << endl;
}

//
// Created By Zackary At 2025-05-31 19:31:20
//
