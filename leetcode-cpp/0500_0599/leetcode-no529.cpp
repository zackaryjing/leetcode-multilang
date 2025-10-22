// problem: https://leetcode.cn/problems/minesweeper/?envType=problem-list-v2&envId=3rBpGyas
#include <deque>
#include <iostream>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click) {
        const int n = board.size();
        const int m = board[0].size();
        int x = click[0];
        int y = click[1];
        char &c = board[x][y];
        if (c == 'M') {
            c = 'X';
            return board;
        }
        if (c == 'E') {
            constexpr int dirs[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
            vector sideBoard(n, vector<int>(m));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (board[i][j] == 'M') {
                        for (auto &[ni, nj]: dirs) {
                            const int nx = i + ni;
                            const int ny = j + nj;
                            if (0 <= nx and nx < n and 0 <= ny and ny < m) {
                                sideBoard[nx][ny]++;
                            }
                        }
                    }
                }
            }
            // show_matrix(sideBoard);
            if (const int num = sideBoard[x][y]; num != 0) {
                c = static_cast<char>(num + '0');
                return board;
            }
            deque<pair<int, int>> toVis = {{x, y}};
            board[x][y] = 'B';
            while (not toVis.empty()) {
                auto [cx, cy] = toVis.front();
                toVis.pop_front();
                for (auto &[ni, nj]: dirs) {
                    const int nx = cx + ni;
                    const int ny = cy + nj;
                    if (0 <= nx and nx < n and 0 <= ny and ny < m) {
                        const char ch = board[nx][ny];
                        const int num = sideBoard[nx][ny];
                        if (num == 0 and ch == 'E') {
                            toVis.emplace_back(nx, ny);
                            board[nx][ny] = 'B';
                        } else if (num != 0) {
                            board[nx][ny] = static_cast<char>(num + '0');
                        }
                    }
                }
            }
        }
        return board;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_matrix(test.updateBoard(temp_vector<vector<char>>({{'E', 'E', 'E', 'E', 'E'},
                                                            {'E', 'M', 'M', 'E', 'E'},
                                                            {'E', 'E', 'E', 'E', 'E'},
                                                            {'E', 'E', 'E', 'E', 'M'}}),
                                 temp_vector({3, 0})));
    show_matrix(test.updateBoard(temp_vector<vector<char>>({{'E', 'E', 'E', 'E', 'E'},
                                                            {'E', 'E', 'M', 'E', 'E'},
                                                            {'E', 'E', 'E', 'E', 'E'},
                                                            {'E', 'E', 'E', 'E', 'E'}}),
                                 temp_vector({3, 0})));
    return 0;
}

//
// Created By jing At 2025-10-21 14:21
//
