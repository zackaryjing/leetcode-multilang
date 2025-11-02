// problem: https://leetcode.cn/problems/surface-area-of-3d-shapes/?envType=problem-list-v2&envId=3rBpGyas 

namespace leetcodeNo892;

using System;

public class Solution {
    public int SurfaceArea(int[][] grid) {
        var n = grid.Length;
        var m = grid[0].Length;
        var mid = 0;
        var side = 0;
        var top = 0;
        for (var i = 0; i < n; ++i) {
            for (var j = 0; j < m; ++j) {
                if (grid[i][j] > 0)
                    top += 2;
                if (i == 0 || i == n - 1) {
                    if (n == 1)
                        side += grid[i][j] << 1;
                    else
                        side += grid[i][j];
                }

                if (j == 0 || j == m - 1) {
                    if (m == 1)
                        side += grid[i][j] << 1;
                    else
                        side += grid[i][j];
                }

                if (i < n - 1)
                    mid += Math.Abs(grid[i][j] - grid[i + 1][j]);
                if (j < m - 1)
                    mid += Math.Abs(grid[i][j] - grid[i][j + 1]);
            }
        }

        return mid + side + top;
    }

    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.SurfaceArea([[1]]));
        Console.WriteLine(s.SurfaceArea([[1, 1, 1]]));
        Console.WriteLine(s.SurfaceArea([[1, 1, 1], [1, 0, 1], [1, 1, 1]]));
        Console.WriteLine(s.SurfaceArea([[2, 2, 2], [2, 1, 2], [2, 2, 2]]));
    }
}

//
// Created By jing At 10/31/25 00:10:07
//