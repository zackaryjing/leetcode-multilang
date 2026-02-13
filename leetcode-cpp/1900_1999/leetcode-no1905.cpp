// problem: https://leetcode.cn/problems/count-sub-islands/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
  public:
  vector<vector<int>> grid1;
  vector<vector<int>> grid2;
  int m, n;

  bool dfs(int y, int x) {
    bool valid = true;
    for (auto [ny, nx]: vector<pair<int, int>>{{y + 1, x}, {y - 1, x}, {y, x + 1}, {y, x - 1}}) {
      if (0 <= ny and ny < n and 0 <= nx and nx < m and grid2[ny][nx] == 1) {
        grid2[ny][nx] = 0;
        if (grid1[ny][nx] == 0) valid = false;
        if (not dfs(ny, nx)) valid = false;
      }
    }
    return valid;
  }

  int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
    this->grid1 = grid1;
    this->grid2 = grid2;
    n = static_cast<int>(grid1.size());
    m = static_cast<int>(grid1[0].size());
    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (this->grid2[i][j] == 1) {
          this->grid2[i][j] = 0;
          if (dfs(i, j) and grid1[i][j] == 1) {
            res++;
          }
        }
      }
    }
    return res;
  }
};

class Solution {
  public:
  vector<vector<int>> *grid1;
  vector<vector<int>> *grid2;
  int m, n;
  const int direction[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

  auto dfs(int y, int x) -> bool {
    bool valid = true;
    for (const auto dir: direction) {
      if (const int ny = y + dir[0], nx = x + dir[1];
          0 <= ny and ny < n and 0 <= nx and nx < m and (*grid2)[ny][nx] == 1) {
        (*grid2)[ny][nx] = 0;
        if ((*grid1)[ny][nx] == 0) valid = false;
        if (not dfs(ny, nx)) valid = false;
      }
    }
    return valid;
  }

  int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
    this->grid1 = &grid1;
    this->grid2 = &grid2;
    n = static_cast<int>(grid1.size());
    m = static_cast<int>(grid1[0].size());
    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if ((*this->grid2)[i][j] == 1) {
          (*this->grid2)[i][j] = 0;
          if (dfs(i, j) and grid1[i][j] == 1) {
            res++;
          }
        }
      }
    }
    return res;
  }
};


int main(int argc, char *argv[]) {
  Solution test;
  cout << test.countSubIslands(
          temp_vector({temp_vector({1, 1, 1, 0, 0}), temp_vector({0, 1, 1, 1, 1}), temp_vector({0, 0, 0, 0, 0}),
                       temp_vector({1, 0, 0, 0, 0}), temp_vector({1, 1, 0, 1, 1})}),
          temp_vector({temp_vector({1, 1, 1, 0, 0}), temp_vector({0, 0, 1, 1, 1}), temp_vector({0, 1, 0, 0, 0}),
                       temp_vector({1, 0, 1, 1, 0}), temp_vector({0, 1, 0, 1, 0})}))
       << endl;
}

//
// Created By ASUS At 2026-02-13 17:28
//
