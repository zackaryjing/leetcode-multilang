// problem: https://leetcode.cn/problems/number-of-closed-islands/?envType=problem-list-v2&envId=3rBpGyas 

namespace leetcodeNo1254;

using System;

public class Solution {
    private int[][] _grid;
    private int[,] _vis;
    private int n;
    private int m;
    private bool touchingEdge = false;
    readonly int[,] dirs = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };


    public int ClosedIsland(int[][] grid) {
        _grid = grid;
        n = grid.Length;
        m = grid[0].Length;
        _vis = new int [n, m];
        var res = 0;
        for (var i = 0; i < n; ++i) {
            for (var j = 0; j < m; ++j) {
                if (_vis[i, j] == 0 && grid[i][j] == 0) {
                    touchingEdge = false;
                    find(i, j);
                    if (!touchingEdge) {
                        res += 1;
                    }
                }
            }
        }

        return res;
    }

    private void find(int i, int j) {
        _vis[i, j] = 1;
        if (i == n - 1 || i == 0 || j == 0 || j == m - 1) {
            touchingEdge = true;
        }

        for (int d = 0; d < 4; ++d) {
            int ni = i + dirs[d, 0];
            int nj = j + dirs[d, 1];
            if (0 <= ni && ni < n && 0 <= nj && nj < m && _vis[ni, nj] == 0 && _grid[ni][nj] == 0) {
                find(ni, nj);
            }
        }
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.ClosedIsland([
            [1, 1, 1, 1, 1, 1, 1, 0], [1, 0, 0, 0, 0, 1, 1, 0], [1, 0, 1, 0, 1, 1, 1, 0], [1, 0, 0, 0, 0, 1, 0, 1],
            [1, 1, 1, 1, 1, 1, 1, 0]
        ]));
    }
}

//
// Created By ASUS At 11/8/2025 18:11:54
//