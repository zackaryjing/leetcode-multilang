#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > queensAttacktheKing(vector<vector<int> > &queens, vector<int> &king) {
        int diff = king[0] - king[1];
        int sum = king[0] + king[1];
        vector<vector<int> > eight(8);
        vector<int> dis = {INT_MIN,INT_MIN,INT_MIN,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MIN};
        for (auto queen: queens) {
            if (queen[1] == king[1]) {
                int y_diff = queen[0] - king[0];
                if (y_diff < 0) {
                    if (y_diff > dis[1]) {
                        eight[1] = queen;
                        dis[1] = y_diff;
                    }
                } else {
                    if (y_diff < dis[5]) {
                        eight[5] = queen;
                        dis[5] = y_diff;
                    }
                }
                continue;
            }

            if (queen[0] == king[0]) {
                int x_diff = queen[1] - king[1];
                if (x_diff < 0) {
                    if (x_diff > dis[7]) {
                        eight[7] = queen;
                        dis[7] = x_diff;
                    }
                } else {
                    if (x_diff < dis[3]) {
                        eight[3] = queen;
                        dis[3] = x_diff;
                    }
                }
                continue;
            }

            int q_diff = queen[0] - queen[1];
            if (q_diff == diff) {
                int y_diff = queen[0] - king[0];
                if (y_diff < 0) {
                    if (y_diff > dis[0]) {
                        eight[0] = queen;
                        dis[0] = y_diff;
                    }
                } else {
                    if (y_diff < dis[4]) {
                        eight[4] = queen;
                        dis[4] = y_diff;
                    }
                }
                continue;
            }
            int q_sum = queen[0] + queen[1];
            if (q_sum == sum) {
                int y_diff = queen[0] - king[0];
                if (y_diff < 0) {
                    if (y_diff > dis[2]) {
                        eight[2] = queen;
                        dis[2] = y_diff;
                    }
                } else {
                    if (y_diff < dis[6]) {
                        eight[6] = queen;
                        dis[6] = y_diff;
                    }
                }
            }
        }
        vector<vector<int> > ans;
        for (const auto &k: eight) {
            if (not k.empty()) {
                ans.push_back(k);
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    vector<vector<int> > eg1 = {{0, 0}, {1, 1}, {2, 2}, {3, 4}, {3, 5}, {4, 4}, {4, 5}};
    vector<int> eg1_k = {3, 3};
    auto res1 = test.queensAttacktheKing(eg1, eg1_k);
    for (auto k: res1) {
        cout << "[" << k[0] << " , " << k[1] << "]" << ", ";
    }
    cout << endl;
    vector<vector<int> > eg2 = {{0, 1}, {1, 0}, {4, 0}, {0, 4}, {3, 3}, {2, 4}};
    vector<int> eg2_k = {0, 0};
    auto res2 = test.queensAttacktheKing(eg2, eg2_k);
    for (auto k: res2) {
        cout << "[" << k[0] << " , " << k[1] << "]" << ", ";
    }
    cout << endl;
}


//
// Created by ASUS on 2025/2/24.
//
